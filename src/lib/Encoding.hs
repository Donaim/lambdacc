module Encoding where


import Utils
import Parser
import Tokenizer
import Exept
import ParserConfig
import Lexer

import Debug.Trace
import Data.List

getUniqueName :: [Leaf] -> [Char]
getUniqueName leafs = (concat $ encode leafs) ++ "_E"
	where
	encode :: [Leaf] -> [[Char]]
	encode []       = []
	encode (x : xs) = current : encode xs
		where
		current :: [Char]
		current = case x of
			Variable scope id ->
				getVariableName scope id
			Lambda scope arg leafs ->
				'_' : 'L' : getUniqueName leafs
			SubExpr scope leafs ->
				'_' : 'S' : getUniqueName leafs

getVariableName :: Scope -> Identifier -> [Char]
getVariableName scope (Argument name) =
	'_' : 'A' : findBump name scope
	where
		findBump :: String -> Scope -> [Char]
		findBump _    []       = error "Argument not found"
		findBump name (x : xs) =
			if x == name
			then "0"
			else charBump $ findBump name xs

getVariableName scope (BindingTok name _) =
	'_' : 'B': (concat $ map countDownEnd name)
	where
		countDown :: Char -> [Char]
		countDown x = if x == '\NUL' then "0"  else charBump $ countDown (pred x)

		countDownEnd :: Char -> [Char]
		countDownEnd x = '_' : 'C' : countDown x

charBump :: [Char] -> [Char]
charBump []         = "1"
charBump ('9' : xs) = 'a' : xs
charBump ('z' : xs) = 'A' : xs
charBump ('Z' : xs) = '0' : charBump xs
charBump (x : xs) = (succ x) : xs
