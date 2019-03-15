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
type TokenizeFulltype  = ParserConfig -> TokenizeTransform

tokenizeLambdaDecl :: TokenizeFulltype
tokenizeLambdaDecl cfg s =
	if (lambdaDecl cfg) `isPrefixOf` s
	then Just (LambdaDecl, split)
	else Nothing
	where split = length (lambdaDecl cfg)

tokenizeLambdaSymbol :: TokenizeFulltype
tokenizeLambdaSymbol cfg s =
	if (lambdaSymbol cfg) `isPrefixOf` s
	then Just (LambdaSymbol, split)
	else Nothing
	where split = length (lambdaSymbol cfg)

tokenizeOpenBracket :: TokenizeFulltype
tokenizeOpenBracket _ ('(' : xs ) = Just ( OpenBracket, 1 )
tokenizeOpenBracket _ _ = Nothing

tokenizeCloseBracket :: TokenizeFulltype
tokenizeCloseBracket _ (')' : xs ) = Just ( CloseBracket, 1 )
tokenizeCloseBracket _ _ = Nothing

tokenizeNewline :: TokenizeFulltype
tokenizeNewline _ ('\n' : xs ) = Just ( Newline, 1 )
tokenizeNewline _ _ = Nothing

isSpace :: Char -> Bool
isSpace ' '  = True
isSpace '\t' = True
isSpace _    = False

tokenizeSpace :: TokenizeFulltype
tokenizeSpace _ (' '  : xs) = Just ( Space, 1 + countWhile isSpace xs)
tokenizeSpace _ ('\t' : xs) = Just ( Space, 1 + countWhile isSpace xs)
tokenizeSpace _ _ = Nothing

tokenizeQuote :: TokenizeFulltype
tokenizeQuote _ ('\'' : xs ) = Just (Quote, 1 + lenQuote xs False)
tokenizeQuote _ _            = Nothing

tokenizeComment :: TokenizeFulltype
tokenizeComment _ ('#' : xs ) = Just ( Comment, 1 + countWhile (/= '\n') xs)
tokenizeComment _ (';' : xs ) = Just ( Comment, 1 + countWhile (/= '\n') xs)
tokenizeComment _ _ = Nothing

type TransformerState = (Int, Int, String)

-- State transformer
-- `Maybe (TokenType, Int)' is the "delta"
transformer :: TransformerState -> TokenizeResponce -> (Maybe Token, TransformerState)
transformer state Nothing = (Nothing, state)
transformer (charno, lineno, str) (Just (kind, split)) =
	(Just tok, (nextcharno, nextlineno, rest))
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
	cycle 0 0 "" str
	where
		tokersRaw    =
			sometokenizers ++ 
			(if parseQuotes cfg then [tokenizeQuote] else []) ++
			(if parseComments cfg then [tokenizeComment] else []) ++
			(if null $ lambdaDecl cfg then [] else [tokenizeLambdaDecl])

		tokers = map (\f -> f cfg) tokersRaw

		folder :: TransformerState -> [TokenizeTransform] -> (Maybe Token, TransformerState)
		folder state [] = (Nothing, state)
		folder p@(charno, lineno, str) (tokenizer : xs) =
			if isJust current
			then result
			else folder p xs
			where
				current = tokenizer str
				result  = transformer p current

		cycle :: Int -> Int -> String -> String -> [Token]
		cycle charno lineno carryStr str =
			if null str
			then
				if null carryStr
				then []
				else [nameTok]
			else
				case tok of
					Just t  ->
						if null carryStr
						then t : cycle newcharno newlineno "" newstr
						else nameTok : t : cycle newcharno newlineno "" newstr
					Nothing -> cycle (succ newcharno) newlineno (head str : carryStr) (tail str)
			where
				(tok, (newcharno, newlineno, newstr)) = folder (charno, lineno, str) tokers
				nameTok = Token
					{ text = reverse carryStr
					, kind = Name
					, lineno = lineno
					, charno = charno - length carryStr
					}