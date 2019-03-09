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
	text <- getFileText "example/script.inline.ini"
	case text of
		Just text -> do
			let toks = tokenize cfg text
			-- print $ sum $ map (\c -> if c == 'a' then 1 else 0) text
			-- print $ sum $ map lineno toks
			putStrLn $ "len = " ++ show (length toks)
			-- print $ "last: \n" ++ show (head toks)
			return ()
		Nothing ->
			putStrLn "Error reading text"
