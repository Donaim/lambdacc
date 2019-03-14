module Parser where

import Data.List
import Utils
import Exept
import ParserConfig
import Tokenizer

import Debug.Trace

data Toplevel = Binding String [Token] | Expr [Token]
	deriving (Show, Eq)

parse :: ParserConfig -> [Token] -> (Toplevel, [Token])
parse cfg [] = error "Empty"
parse cfg (t : xs) =
	case kind t of
		Name -> undefined
		_ -> undefined

	where
		afterEqual :: [Token] -> [Token]
		afterEqual _  = []

		dropSpaces = dropWhile isSpace
		isSpace t =
			case kind t of
				Space -> True
				_     -> False

groupTokens :: ParserConfig -> [Token] -> [[Token]]
groupTokens _   [] = []
groupTokens cfg toks =
	if isEmpty
	then groupTokens cfg recur
	else  cur : groupTokens cfg recur
	where
		curLen  = map kind toks |> takeExpr
		cur     = take curLen toks
		recur   = drop curLen toks
		isEmpty = all isEmptyCheck cur

		isEmptyCheck :: Token -> Bool
		isEmptyCheck t = kind t == Space || kind t == Newline

takeExpr :: [TokenType] -> Int
takeExpr [] = 0

takeExpr (Newline : Space : xs) = 2 + takeExpr xs
takeExpr (Newline : xs)         = 1
takeExpr (x : xs)               = 1 + takeExpr xs

