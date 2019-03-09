module Main where

import Lib

import Tokenizer
import ParserConfig

cfg = ParserConfig 
	{ lambdaDecl    = "\\"
	, lambdaSymbol  = "->"
	, parseComments = True
	, parseQuotes   = True
	}

main :: IO ()
main =
	print $ tokenize cfg "hello ! there bro!"
