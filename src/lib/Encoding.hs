module Encoding where


import Utils
import Parser
import Tokenizer
import Exept
import CompilerConfig
import Lexer

import Debug.Trace
import Data.List

getUniqueName :: Leaf -> [Char]
getUniqueName (Variable scope id) =
	getVariableName scope id
getUniqueName (Lambda scope arg leafs) =
	'_' : 'L' : (concatMap getUniqueName leafs) ++ "_E"
getUniqueName (SubExpr scope leafs) =
	'_' : 'S' : (concatMap getUniqueName leafs) ++ "_E"

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
	if all (`elem` allowedChars) name
	then '_' : 'B' : '_' : name
	else '_' : 'B' : 'I' : (concatMap countDownEnd name)
	where
		countDown :: Char -> [Char]
		countDown x = if x == '\NUL' then "0"  else charBump $ countDown (pred x)

		countDownEnd :: Char -> [Char]
		countDownEnd x = '_' : 'C' : countDown x

		allowedChars :: [Char]
		allowedChars = ['0' .. '9'] ++ ['a' .. 'z'] ++ ['A' .. 'Z']

charBump :: [Char] -> [Char]
charBump []         = "1"
charBump ('9' : xs) = 'a' : xs
charBump ('z' : xs) = 'A' : xs
charBump ('Z' : xs) = '0' : charBump xs
charBump ( x  : xs) = (succ x) : xs
