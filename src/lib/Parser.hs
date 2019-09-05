module Parser where

import Data.List
import Utils
import Exept
import CompilerConfig
import Tokenizer
import Lexer

import Debug.Trace

data RTopLevel = RBinding String [Token] | RExpr [Token]
	deriving (Eq, Show, Read)

stringifyRTopLevel :: RTopLevel -> String
stringifyRTopLevel (RBinding name toks) = "{ RBinding '" ++ name ++ "' " ++ (concatMap (' ' :) $ map text toks) ++ " }"
stringifyRTopLevel (RExpr toks)         = "{ RExpr " ++ (concatMap (' ' :) $ map text toks) ++ " }"

data TopLevel = Binding String Leaf | Expr Leaf
	deriving (Eq, Show, Read)

stringifyTopLevel :: TopLevel -> String
stringifyTopLevel (Binding name leaf) = "{ Binding \'" ++ name ++ "':\n" ++ stringifyLeaf leaf ++ "}"
stringifyTopLevel (Expr leaf)         = "{ Expr:\n" ++ stringifyLeaf leaf  ++ "}"

parse :: CompilerConfig -> [Token] -> [TopLevel]
parse cfg toks = rparse cfg toks |> map transformRaw

transformRaw :: RTopLevel -> TopLevel
transformRaw (RBinding name toks) = Binding name (lexGroup toks)
transformRaw (RExpr toks)         = Expr (lexGroup toks)

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
stripUseless = filter (isUseful . kind)
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

