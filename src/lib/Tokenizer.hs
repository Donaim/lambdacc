module Tokenizer where

-- This module will split text into dumb context unaware tokens

import ParserConfig
import Utils

import qualified Data.Char as C
import Data.List

data TokenType =
	LambdaDecl | LambdaSymbol | Name | Newline | Space | Comment | Quote
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

tokenizeLambdaSymbol :: ParserConfig -> String -> Maybe (TokenType, Int)
tokenizeLambdaSymbol cfg s =
	if (lambdaSymbol cfg) `isPrefixOf` s
	then Just (LambdaSymbol, split)
	else Nothing
	where split = length (lambdaSymbol cfg)

tokenizeNewline :: ParserConfig -> String -> Maybe (TokenType, Int)
tokenizeNewline _ ('\n' : xs ) = Just ( Newline, 1 )
tokenizeNewline _   _ = Nothing

tokenizeSpace :: ParserConfig -> String -> Maybe (TokenType, Int)
tokenizeSpace _ (' ' : xs )  = Just ( Space, 1 )
tokenizeSpace _ ('\t' : xs ) = Just ( Space, 1 )
tokenizeSpace _   _ = Nothing

tokenizeQuote :: ParserConfig -> String -> Maybe (TokenType, Int)
tokenizeQuote _ ('\'' : xs ) = Just (Quote, 1 + lenQuote xs False)
tokenizeQuote _ _            = Nothing

tokenizeComment :: ParserConfig -> String -> Maybe (TokenType, Int)
tokenizeComment _ ('#' : xs ) = Just ( Comment, countWhile (/= '\n') xs)
tokenizeComment _ (';' : xs ) = Just ( Comment, countWhile (/= '\n') xs)
tokenizeComment _   _ = Nothing

tokenizeName :: ParserConfig -> String -> Maybe (TokenType, Int)
tokenizeName _ s =
	if split == 0
	then Nothing
	else Just (Name, split)
	where
		split = countWhile C.isAlpha s

-- State transformer
-- `Maybe (TokenType, Int)' is the "delta"
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


