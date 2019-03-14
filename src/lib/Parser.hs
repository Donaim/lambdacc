module Parser where

import Data.List
import Utils
import Exept
import ParserConfig
import Tokenizer

import Debug.Trace

data Toplevel = Binding String [Token] | Expr [Token]
	deriving (Show, Eq)

parse :: ParserConfig -> [Token] -> [Toplevel]
parse cfg []   = error "Empty"
parse cfg toks = groupTokens cfg toks |> map classifyGroup

classifyGroup :: [Token] -> Toplevel
classifyGroup all@(x : y : xs) =
	if text y == "="
	then Binding (text x) xs
	else Expr all
classifyGroup all = Expr all

-- Also strips off spaces and newlines and comments
groupTokens :: ParserConfig -> [Token] -> [[Token]]
groupTokens _   [] = []
groupTokens cfg toks =
	if null useful
	then groupTokens cfg recur
	else  useful : groupTokens cfg recur
	where
		curLen  = map kind toks |> takeExpr
		cur     = take curLen toks
		useful  = stripUseless cur
		recur   = drop curLen toks

stripUseless :: [Token] -> [Token]
stripUseless toks = filter (isUseful . kind) toks
	where
		isUseful :: TokenType -> Bool
		isUseful Space   = False
		isUseful Newline = False
		isUseful Comment = False
		isUseful _       = True
		
takeExpr :: [TokenType] -> Int
takeExpr [] = 0
takeExpr (Newline : Space : xs) = 2 + takeExpr xs
takeExpr (Newline : xs)         = 1
takeExpr (x : xs)               = 1 + takeExpr xs

