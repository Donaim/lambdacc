module Main where

import Lib

import Tokenizer
import ParserConfig
import FileSys

cfg = ParserConfig 
	{ lambdaDecl    = "\\"
	, lambdaSymbol  = "->"
	, parseComments = True
	, parseQuotes   = True
	}

main :: IO ()
main = do
	text <- getFileText "example/script.ini"
	case text of
		Just text ->
			print $ (\toks -> toks !! (length toks - 1)) (tokenize cfg text)
		Nothing ->
			putStrLn "Error reading text"
