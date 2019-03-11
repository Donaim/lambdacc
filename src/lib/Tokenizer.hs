module Tokenizer where

-- This module will split text into dumb context unaware tokens

import ParserConfig
import Exept
import Utils

import qualified Data.Char as C
import Data.List
import Data.Maybe

data TokenType =
	OpenBracket | CloseBracket | LambdaDecl | LambdaSymbol | Name | Newline | Space | Comment | Quote
	deriving (Show, Eq)

data Token =
	Token
	{ text       :: String
	, kind       :: TokenType
	, lineno     :: Int
	, charno     :: Int
	}
	deriving (Show, Eq)

type TokenizeResponce  = Maybe (TokenType, Int)
type TokenizeTransform = String -> TokenizeResponce
type TokenizeFulltype  = ParserConfig -> [TokenizeTransform] -> TokenizeTransform

tokenizeLambdaDecl :: TokenizeFulltype
tokenizeLambdaDecl cfg _ s =
	if (lambdaDecl cfg) `isPrefixOf` s
	then Just (LambdaDecl, split)
	else Nothing
	where split = length (lambdaDecl cfg)

tokenizeLambdaSymbol :: TokenizeFulltype
tokenizeLambdaSymbol cfg _ s =
	if (lambdaSymbol cfg) `isPrefixOf` s
	then Just (LambdaSymbol, split)
	else Nothing
	where split = length (lambdaSymbol cfg)

tokenizeOpenBracket :: TokenizeFulltype
tokenizeOpenBracket _ _ ('(' : xs ) = Just ( OpenBracket, 1 )
tokenizeOpenBracket _ _ _ = Nothing

tokenizeCloseBracket :: TokenizeFulltype
tokenizeCloseBracket _ _ (')' : xs ) = Just ( CloseBracket, 1 )
tokenizeCloseBracket _ _ _ = Nothing

tokenizeNewline :: TokenizeFulltype
tokenizeNewline _ _ ('\n' : xs ) = Just ( Newline, 1 )
tokenizeNewline _ _ _ = Nothing

tokenizeSpace :: TokenizeFulltype
tokenizeSpace _ _ (' ' : xs )  = Just ( Space, 1 )
tokenizeSpace _ _ ('\t' : xs ) = Just ( Space, 1 )
tokenizeSpace _ _ _ = Nothing

tokenizeQuote :: TokenizeFulltype
tokenizeQuote _ _ ('\'' : xs ) = Just (Quote, 1 + lenQuote xs False)
tokenizeQuote _ _ _            = Nothing

tokenizeComment :: TokenizeFulltype
tokenizeComment _ _ ('#' : xs ) = Just ( Comment, 1 + countWhile (/= '\n') xs)
tokenizeComment _ _ (';' : xs ) = Just ( Comment, 1 + countWhile (/= '\n') xs)
tokenizeComment _ _ _ = Nothing

tokenizeName :: TokenizeFulltype
tokenizeName cfg tokenizers s =
	if split == 0
	then Nothing
	else Just (Name, split)
	where
		split = count s

		count [] = 0
		count s  =
			if any isJust $ map (\t -> t s) tokenizers
			then 0
			else 1 + count (tail s)

type TransformerState = ([Token], Int, Int, String)

-- State transformer
-- `Maybe (TokenType, Int)' is the "delta"
transformer :: [Token] -> Int -> Int -> String -> TokenizeResponce -> TransformerState
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

sometokenizers = [tokenizeOpenBracket, tokenizeCloseBracket, tokenizeSpace, tokenizeLambdaSymbol, tokenizeNewline]

tokenize :: ParserConfig -> String -> [Token]
tokenize cfg str =
	cycle [] 0 0 str
	where
		tokersRaw    =
			sometokenizers ++ 
			(if parseQuotes cfg then [tokenizeQuote] else []) ++
			(if parseComments cfg then [tokenizeComment] else []) ++
			(if null $ lambdaDecl cfg then [] else [tokenizeLambdaDecl])

		tokersNoName = map (\f -> f cfg []) tokersRaw
		tokers       = tokersNoName ++ [tokenizeName cfg tokersNoName]

		folder :: TokenizeTransform -> TransformerState -> TransformerState
		folder ftoken (toks, charno, lineno, str) = transformer toks charno lineno str (ftoken str)

		cycle toks charno lineno []  = toks
		cycle toks charno lineno str =
			cycle newtoks newcharno newlineno newstr
			where
				(newtoks, newcharno, newlineno, newstr) = foldr folder (toks, charno, lineno, str) tokers
