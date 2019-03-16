
module Lexer where

import Utils
import Parser
import Tokenizer
import Exept

data Identifier = Argument String | BindingTok String (Maybe Leaf)
	deriving (Show, Eq)

data Leaf =
	Lambda String [Leaf] |
	SubExpr [Leaf] |
	Variable Identifier
	deriving (Show, Eq)

type Scope = [String]

lexe :: Scope -> Tree -> Leaf
lexe scope (Node t) =
	lexName scope (text t)
lexe scope (Head []) =
	error "WTF"

lexe scope (Head all@(Node a : Node b : ts)) =
	case kind b of
		LambdaSymbol -> Lambda arg $ map (lexe (arg : scope)) ts
		_            -> SubExpr $ map (lexe scope) all
	where
		arg = text a
lexe scope (Head all) =
	SubExpr $ map (lexe scope) all

lexName :: Scope -> String -> Leaf
lexName scope tex =
	if tex `elem` scope
	then Variable $ Argument tex
	else Variable $ BindingTok tex Nothing

data Tree =
	Head [Tree] | Node Token
	deriving (Eq)

instance Show Tree where
	show t = showTree 0 t

showTree :: Int -> Tree -> String
showTree tabs (Node t)  = 
	'\n' : (take tabs $ repeat '\t')  ++ text t

showTree tabs (Head []) = []
showTree tabs (Head ((Node t) : ts)) =
	'\n' : (take tabs $ repeat '\t')  ++ text t ++ (showTree tabs $ Head ts)
showTree tabs (Head ((Head ts) : tss)) =
	'\n' : (take tabs $ repeat '\t') ++ (showTree (tabs + 1) (Head ts)) ++ (showTree tabs (Head tss))

-- Tree and left-overs
makeTree :: [Tree] -> [Token] -> (Tree, [Token])
makeTree nodesBuff toks =
	if null toks
	then (close, [])
	else
		case kind t of
			CloseBracket ->
				(close, ts)
			OpenBracket  ->
				makeTree (childNode : nodesBuff) childRight
			_            ->
				makeTree (curNode : nodesBuff) ts

	where
		t  = head toks
		ts = tail toks

		curNode = Node t
		(childNode, childRight) = makeTree [] ts

		close :: Tree
		close =
			if null $ tail nodesBuff
			then head $ reverse nodesBuff
			else Head $ reverse nodesBuff

