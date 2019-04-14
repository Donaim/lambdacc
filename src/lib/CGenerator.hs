module CGenerator where

import Utils
import Parser
import CompilerConfig
import Tokenizer
import FileSys
import Lexer
import Encoding

import Data.List

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
		undefined
	else []

genInitFunc :: CompilerConfig -> Leaf -> String -> [String]
genInitFunc cfg lambda uniqueName =
	body
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

		body = [ decl ++ " {"
		       , "\tff me = ALLOC_GET(sizeof(struct fun));"
		       , "\tme->parent = parent;"
		       , "\tme->eval_now = " ++ execName ++ ";"
		       , "\tme->customsize = 0;"
		       , typeuuid
		       , "\treturn me"
		       , "}"
		       ]

getArgNameByParents :: CompilerConfig -> Leaf -> String
getArgNameByParents cfg (Variable scope id) =
	case id of
		Argument name ->
			case elemIndex name scope of
				Just n ->
					"me->" ++ (repeat "parent->" |> take n |> foldl (++) "") ++ "x"
				Nothing ->
					error "Argument not found by parents"
		_ ->
			error "Wrong variable type in getArgNameByParents"
getArgNameByParents cfg _ =
	error "Wrong type in getArgNameByParents"

genExecReturnPart :: CompilerConfig -> Leaf -> String -> String
genExecReturnPart cfg lambda =
	undefined
	where
		fields :: [StructField]
		fields = getFields lambda

		forfield (x : xs) buf =
			undefined
			where
				name = getUniqueName (leaf x)
				initName = getInitName name

genExecReturnStatement :: CompilerConfig -> Leaf -> String -> String
genExecReturnStatement cfg lambda uniqueName =
	undefined
	where
		x = 2

genExecFunc :: CompilerConfig -> Leaf -> String -> [String]
genExecFunc cfg lambda uniqueName =
	undefined
	where
		execName = getExecName uniqueName
		decl = getExecDecl execName


