module Main where

import Lib

import Tokenizer
import CompilerConfig
import FileSys
import Parser
import CGenerator

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
	fullCycle cfg "test/.test.ini" "helladadad.c"
