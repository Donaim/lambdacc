import TestUtil

import Parser
import CompilerConfig
import Tokenizer
import FileSys
import Lexer
import Encoding
import Utils

cfg = CompilerConfig 
	{ lambdaSymbol = "->"
	, parseComments = True
	, parseQuotes = True
	, countTotalExecs = True
	, trackAllocs = True
	, trackPoolAllocs = True
	, useTypeid  = True
	, headerString = "#include \"example/header.h\""
	}

main :: IO ()
main = do
	text <- getText
	putBox "Test suite not yet implemented"
	-- showGroup
	-- showTopLevel
	-- showLeafs
	putBox $ showUniqueNames text

getText :: IO String
getText = do
	text <- getFileText "test/.test.ini"
	case text of
		Just text -> do
			return text
		Nothing ->
			error "Could not read text"

simpleText :: String
simpleText =
	unlines
	[ "; comment"
	, "# also comment"
	, ""
	, "# defition of identity"
	, "id = x -> x"
	, ""
	, "# lambda calculus booleans"
	, "true = a -> b -> a"
	, "false = a -> b -> b"
	]

simpleExprs :: [String]
simpleExprs =
	[ "x -> x"
	, "a b -> a"
	, "a b -> b"
	, "a b -> b a"
	, "a b -> a (b b)"
	, "a b -> a (x -> x) b"
	, "a -> a (a SomeB++inding a)"
	]

lexString :: CompilerConfig -> String -> Leaf
lexString cfg s = s |> tokenize cfg |> stripUseless |> lexGroup

type VisualFunc = String -> String

showGroup :: VisualFunc
showGroup s =
	fout
	where
		toks   = tokenize cfg s
		groups = groupTokens cfg toks
		out    = (map (\t -> foldr (++) "" $ map text t) groups) :: [String]
		prefix = (take 20 $ repeat '-') ++ "\n"                  :: String
		fout   = foldr (++) "" $ map ('\n' :) $ map (prefix ++) $ out

showTopLevel :: VisualFunc
showTopLevel s =
	undefined
	where
		toks   = tokenize cfg s
		tops   = rparse cfg toks

		-- sequence $ map print tops
		-- let out    = (map (\t -> foldr (++) "" $ map text t) groups) :: [String]

showLeafs :: VisualFunc
showLeafs s =
	show $ ss
	where
		toks   = tokenize cfg s
		groups = groupTokens cfg toks
		leafs  = map lexGroup groups

		ss     =  sum $ map countVariables leafs
		-- sequence $ map print leafs

showUniqueNames :: VisualFunc
showUniqueNames s =
	show uniqs
	where
		toks       = tokenize cfg s
		groups     = groupTokens cfg toks
		classified = map classifyGroup groups
		leafs      = map lexClassified classified
		uniqs      = map getUnique leafs

		lexClassified :: RTopLevel -> (String, Leaf)
		lexClassified (RBinding name toks) = (name , lexGroup toks)
		lexClassified (RExpr toks)         = ([],    lexGroup toks)

		getUnique :: (String, Leaf) -> (String, String)
		getUnique (name, leaf) = (name, getUniqueName leaf)

