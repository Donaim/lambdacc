module CGenerator where

import Utils
import Parser
import CompilerConfig
import Tokenizer
import FileSys
import Lexer
import Encoding


defineS :: String -> String
defineS = (++) "#define "

genFlags :: CompilerConfig -> [String]
genFlags cfg =
	pairs |> filter filt |> map snd |> map defineS
	where
		pairs = [ (countTotalExecs, "COUNT_TOTAL_EXEC")
		        , (trackAllocs,     "TRACK_ALLOCS")
		        , (trackPoolAllocs, "TRACK_POOL_ALLOCS")
		        ]
		filt (f, _) = f cfg

