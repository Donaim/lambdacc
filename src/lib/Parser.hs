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

