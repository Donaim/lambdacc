module Tokenizer where

import ParserConfig
import Utils

import qualified Data.Char as C
import Data.List

data TokenType =
	LambdaDecl | LambdaSymbol | LambdaArgument | Variable | Newline | Space | Comment
	deriving (Show, Eq)

data Token =
	Token
	{ text       :: String
	, kind       :: TokenType
	, lineno     :: Int
	, charno     :: Int
	}
	deriving (Show, Eq)

tokenizeLambdaDecl :: ParserConfig -> String -> Maybe (TokenType, Int)
tokenizeLambdaDecl cfg s =
	if (lambdaDecl cfg) `isPrefixOf` s
	then Just (LambdaDecl, split)
	else Nothing
	where split = length (lambdaDecl cfg)

transformer :: [Token] -> Int -> Int -> String -> Maybe (TokenType, Int) -> ([Token], Int, Int, String)
transformer toks charno lineno str Nothing =
	(toks, charno, lineno, str)
transformer toks charno lineno str (Just (kind, split)) =
	(tok : toks, nextcharno, nextlineno, rest)
	where
		cur  = take split str
		rest = drop split str
		tok  = Token
			{ text = cur
			, kind = kind
			, lineno = lineno
			, charno = charno
			}

		nextcharno = case kind of
					Newline -> 0
					_       -> charno + split
		nextlineno = case kind of
					Newline -> lineno + 1
					_       -> lineno

-- tokenizeSpace :: String -> Maybe (String, RTok)
-- tokenizeSpace s@(c:cs) =
-- 	if C.isSpace c then
-- 		Just $ collect (c, 1) cs
-- 	else
-- 		Nothing
-- 	where
-- 		collect :: (Char, Int) -> String -> (String, RTok)
-- 		collect (cha, count) []       =
-- 			([], Space cha count)
-- 		collect (cha, count) s@(c:cs) =
-- 			if c == cha then
-- 				collect (cha, succ count) cs
-- 			else
-- 				(s, Space cha count)

-- tokenizeNewline :: String -> Maybe (String, RTok)
-- tokenizeNewline s@(c:cs) =
-- 	if c == '\n' then Just (cs, Newline)
-- 	else Nothing

-- tokenizeSymbol :: String -> Maybe (String, RTok)
-- tokenizeSymbol (x:xs) = Just (xs, Symbol x)
-- tokenizeSymbol []     = Nothing

-- tokenizeNumber :: String -> Maybe (String, RTok)
-- tokenizeNumber s =
-- 	if null buf then Nothing
-- 	else Just (drop (length buf) s, Number buf)
-- 	where
-- 		buf = takeWhile C.isDigit s

-- tokenizeS :: String -> Maybe (String, RTok)
-- tokenizeS s =
-- 	if null buf then Nothing
-- 	else Just (drop (length buf) s, Text buf)
-- 	where
-- 		buf = takeWhile C.isAlpha s

-- tokenize :: String -> [RTok]
-- tokenize s = joinMaybeSeq s [tokenizeNewline, tokenizeSpace, tokenizeNumber, tokenizeS, tokenizeSymbol]
	
