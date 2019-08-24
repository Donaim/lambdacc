module CGenerator where

import Utils
import Parser
import CompilerConfig
import Tokenizer
import FileSys
import Lexer
import Encoding

import Data.List
import System.IO

defineS :: String -> String
defineS = (++) "#define "

genFlags :: CompilerConfig -> [String]
genFlags cfg =
	pairs |> filter applyfst |> map snd |> map defineS
	where
		pairs = [ (countTotalExecs, "COUNT_TOTAL_EXEC")
		        , (trackAllocs,     "TRACK_ALLOCS")
		        , (trackPoolAllocs, "TRACK_POOL_ALLOCS")
		        ]
		applyfst (f, _) = f cfg


getPrefix :: String -> String
getPrefix = (++) "lambdacc_"

getInitName :: String -> String
getInitName uniqueName = getPrefix "init_" ++ uniqueName

getExecName :: String -> String
getExecName uniqueName = getPrefix "exec_" ++ uniqueName

getTypeid :: String -> String
getTypeid uniqueName = getPrefix "typeid_" ++ uniqueName

getInitDecl :: String -> String
getInitDecl initName = "ff " ++ initName ++ " (ff parent)"

getExecDecl :: String -> String
getExecDecl execName = "ff " ++ execName ++ " (ff me, ff x)"

data StructField = 
	StructField
	{ leaf :: Leaf
	, index :: Int
	}

getFields :: Leaf -> [StructField]
getFields l =
	case l of
		(Lambda scope argname leafs) ->
			collect leafs 0
		(SubExpr scope leafs) ->
			collect leafs 0
		(Variable scope id) ->
			error "Getting field of argument"
	where
		collect :: [Leaf] -> Int -> [StructField]
		collect [] index = []
		collect (v@(Variable scope id) : xs) index =
			StructField { leaf = v, index = -1 } : collect xs index
		collect (l : xs) index =
			StructField { leaf = l, index = index } : collect xs (index + 1)

genTypeuuid :: CompilerConfig -> Leaf -> String -> [String]
genTypeuuid cfg lambda uniqueName =
	if useTypeid cfg then
		["const int " ++ (getTypeid uniqueName) ++ " = __COUNTER__;"]
	else []

genInitFunc :: CompilerConfig -> Leaf -> String -> [String]
genInitFunc cfg lambda uniqueName =
	[ decl ++ " {"
	, "\tff me = ALLOC_GET(sizeof(struct fun));"
	, "\tme->parent = parent;"
	, "\tme->eval_now = " ++ execName ++ ";"
	, "\tme->customsize = 0;"
	, typeuuid
	, "\treturn me"
	, "}"
	]
	where
		initName = getInitName uniqueName
		execName = getExecName uniqueName
		decl = getInitDecl initName

		-- fields = getFields lambda
		-- numLeafs = 1 + (foldl max (-1) $ map index fields)

		typeuuid :: String
		typeuuid =
			if useTypeid cfg then
				let typeidName = getTypeid uniqueName
				in "\tme->typeuuid = " ++ typeidName ++ ";"
			else []

getArgNameByParents :: CompilerConfig -> Scope -> String -> String
getArgNameByParents cfg scope name =
	case elemIndex name scope of
		Just n ->
			"me->" ++ (repeat "parent->" |> take n |> foldl (++) "") ++ "x"
		Nothing ->
			error "Argument not found by parents"

getArgName :: CompilerConfig -> Leaf -> String
getArgName cfg lambda =
	case lambda of
		(Variable scope id) ->
			case id of
				(Argument name) ->
					getArgNameByParents cfg scope name
				(BindingTok name body) ->
					getInitName (getUniqueName lambda) ++ "(me)"
		_ ->
			getInitName (getUniqueName lambda) ++ "(me)"

genExecReturnPart :: CompilerConfig -> Leaf -> String -> String
genExecReturnPart cfg lambda uniqueName =
	forfield fields
	where
		fields :: [StructField]
		fields = getFields lambda

		forfield :: [StructField] -> String
		forfield list =
			case list of
				[last] ->
					name
				(x : xs) ->
					"eval(" ++ name ++ ", " ++ (forfield xs) ++ ")"
			where
				name = getArgName cfg (leaf (head list))

genExecReturnStatement :: CompilerConfig -> Leaf -> String -> String
genExecReturnStatement cfg lambda uniqueName =
	let ret = genExecReturnPart cfg lambda uniqueName
	in case lambda of
		(Lambda scope argname leafs) ->
			"\treturn " ++ ret ++ ";"
		(SubExpr scope leafs) ->
			"\treturn eval(" ++ ret ++ ", x);"
		(Variable scope id) ->
			case id of
				(Argument name) ->
					error "Unexpected type Argument"
				(BindingTok name body) ->
					"\treturn eval(" ++ ret ++ ", x);"

genExecFunc :: CompilerConfig -> Leaf -> String -> [String]
genExecFunc cfg lambda uniqueName =
	[ decl ++ "{"
	, returnStatement
	, "}"
	]
	where
		execName = getExecName uniqueName
		decl = getExecDecl execName
		returnStatement = genExecReturnStatement cfg lambda uniqueName

getDeclsHelper :: (String -> String) -> [String] -> [String]
getDeclsHelper f uniqueNames =
	map ((flip (++) ";") . f) uniqueNames

genInitDecls :: CompilerConfig -> [String] -> [String]
genInitDecls cfg uniqueNames = getDeclsHelper (getInitDecl . getInitName) uniqueNames

genExecDecls :: CompilerConfig -> [String] -> [String]
genExecDecls cfg uniqueNames = getDeclsHelper (getExecDecl . getExecName) uniqueNames

genToplevel :: CompilerConfig -> TopLevel -> [[[String]]]
genToplevel cfg top =
	case top of
		(Expr leaf) ->
			map
			($ leaf)
			[ leafTypeids
			, leafInits
			, leafExecs
			]
		(Binding name leaf) ->
			undefined
	where
		x = 2
		uniqueNames = undefined

		genAllF :: (Leaf -> [String]) -> Leaf -> [[String]]
		genAllF f leaf =
			foldLeaf
				(\x acc ->
					if leafIsArgument x
					then acc
					else (f x) : acc)
				[]
				leaf

		leafInits :: Leaf -> [[String]]
		leafInits leaf = genAllF f leaf
			where f leaf = genInitFunc cfg leaf (getUniqueName leaf)

		leafExecs :: Leaf -> [[String]]
		leafExecs leaf = genAllF f leaf
			where f leaf = genExecFunc cfg leaf (getUniqueName leaf)

		leafTypeids :: Leaf -> [[String]]
		leafTypeids leaf = genAllF f leaf
			where f leaf = genTypeuuid cfg leaf (getUniqueName leaf)

writeAll :: String -> [[[String]]] -> IO ()
writeAll destination arr = do
	file <- openFile destination WriteMode
	mapM_ (write2 file) arr
	hClose file
	where
		write2 :: Handle -> [[String]] -> IO ()
		write2 file blocks = mapM_ (write1 file) blocks

		write1 :: Handle -> [String] -> IO ()
		write1 file lines = mapM_ (hPutStrLn file) lines

showAll :: [[[String]]] -> String
showAll xs = xs |> concat |> concat |> unlines
