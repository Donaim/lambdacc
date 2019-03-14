import TestUtil

import Parser
import ParserConfig
import Tokenizer
import FileSys

cfg = ParserConfig 
	{ lambdaDecl    = "\\"
	, lambdaSymbol  = "->"
	, parseComments = True
	, parseQuotes   = True
	}

main :: IO ()
main = do
	showGroup
	putBox "Test suite not yet implemented"

getText :: IO String
getText = do
	text <- getFileText "example/script.ini"
	case text of
		Just text -> do
			return text
		Nothing ->
			error "Could not read text"

showGroup :: IO ()
showGroup = do
	s <- getText
	let toks   = tokenize cfg s
	let groups = groupTokens cfg toks
	let out    = (map (\t -> foldr (++) "" $ map text t) groups) :: [String]
	let prefix = (take 20 $ repeat '-') ++ "\n"                  :: String
	let fout   = foldr (++) "" $ map ('\n' :) $ map (prefix ++) $ out

	putStrLn fout

	return ()
