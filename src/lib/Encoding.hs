module Encoding where


import Utils
import Parser
import Tokenizer
import Exept
import ParserConfig
import Lexer

import Debug.Trace
import Data.List

encodeBodyAsVector :: [Leaf] -> [Char]
encodeBodyAsVector leafs = (concat $ encode leafs) ++ ['_']
	where
	encode :: [Leaf] -> [[Char]]
	encode []       = []
	encode (x : xs) = current : encode xs
		where
		current :: [Char]
		current = case x of
			Variable scope id ->
				getVariableInt scope id
			Lambda scope arg leafs ->
				'_' : 'L' : encodeBodyAsVector leafs
			SubExpr scope leafs ->
				'_' : 'S' : encodeBodyAsVector leafs

getVariableInt :: Scope -> Identifier -> [Char]
getVariableInt scope (Argument name) =
	case elemIndex name scope of
		Just index -> undefined
		Nothing    -> error "Not found index"
getVariableInt scope (BindingTok name _) =
	undefined

charbump :: [Char] -> [Char]
charbump ('9' : xs) = 'a' : xs
charbump ('z' : xs) = 'A' : xs
charbump ('Z' : xs) = '0' : charbump xs
charbump (x : xs) = (succ x) : xs
