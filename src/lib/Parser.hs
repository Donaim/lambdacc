module Parser where

import Data.List
import Utils
import Exept
import CompilerConfig
import Tokenizer
import Lexer

import Debug.Trace

data RTopLevel = RBinding String [Token] | RExpr [Token]
	deriving (Eq)

instance Show RTopLevel where
	show (RBinding name toks) = "{ RBinding '" ++ name ++ "' " ++ (foldr (++) "" $ map (' ' :) $ map text toks) ++ " }"
	show (RExpr toks)         = "{ RExpr " ++ (foldr (++) "" $ map (' ' :) $ map text toks) ++ " }"

data TopLevel = Binding String Leaf | Expr Leaf
	deriving (Eq)

instance Show TopLevel where
	show (Binding name leaf) = "{ Binding \'" ++ name ++ "':\n" ++ show leaf ++ "}"
	show (Expr leaf)         = "{ Expr " ++ "':\n" ++ show leaf  ++ "}"

rparse :: CompilerConfig -> [Token] -> [RTopLevel]
rparse cfg toks = groupTokens cfg toks |> map classifyGroup

classifyGroup :: [Token] -> RTopLevel
classifyGroup all@(x : y : xs) =
	if text y == "="
	then RBinding (text x) xs
	else RExpr all
classifyGroup all = RExpr all

-- Also strips off spaces and newlines and comments
groupTokens :: CompilerConfig -> [Token] -> [[Token]]
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

