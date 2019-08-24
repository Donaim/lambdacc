module Main where

import Lib

import Tokenizer
import CompilerConfig
import FileSys
import Parser

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
	text <- getFileText "example/script.ini"
	case text of
		Just text -> do
			let toks = tokenize cfg text
			-- let parsed = parse cfg text
			-- print $ sum $ map (\c -> if c == 'a' then 1 else 0) text
			-- print $ sum $ map lineno toks
			-- putStrLn $ foldr (++) "" $ map ('\n' : ) (map show toks)
			putStrLn $ "len = " ++ show (length toks)
			-- putStrLn $ "parsed = " ++ (foldr (++) "" $ map ('\n' : ) (map show parsed))
			-- print $ "last: \n" ++ show (head toks)
			return ()
		Nothing ->
			putStrLn "Error reading text"
