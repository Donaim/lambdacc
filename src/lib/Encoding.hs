module Encoding where


import Utils
import Parser
import Tokenizer
import Exept
import ParserConfig
import Lexer

import Debug.Trace
import Data.List

-- UNIQNESS --

encodedBegin    = 2
encodedVariable = 3
encodedLambda   = 4
encodedSubExpr  = 5
encodedEnd      = 6

encodedLift :: Int -> Int
encodedLift = (encodedEnd +)

encodeBodyAsVector :: [Leaf] -> [Int]
encodeBodyAsVector leafs = encodedBegin : (concat $ encode leafs) ++ [encodedEnd]
	where
	encode :: [Leaf] -> [[Int]]
	encode []       = []
	encode (x : xs) = current : encode xs
		where
		current :: [Int]
		current = case x of
			Variable scope id ->
				getVariableInt scope id
			Lambda scope arg leafs ->
				encodedLambda : encodeBodyAsVector leafs
			SubExpr scope leafs ->
				encodedSubExpr : encodeBodyAsVector leafs

getVariableInt :: Scope -> Identifier -> [Int]
getVariableInt scope (Argument name) =
	case elemIndex name scope of
		Just index -> [encodedVariable, encodedLift index]
		Nothing    -> error "Not found index"
getVariableInt scope (BindingTok name _) =
	0 : (stringToVector name) ++ [0]

stringToVector :: String -> [Int]
stringToVector = undefined

vectorToString :: [Int] -> String
vectorToString = undefined
