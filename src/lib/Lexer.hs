
module Lexer where

import Utils
import Parser
import Tokenizer
import Exept
import ParserConfig

import Debug.Trace

data Identifier = Argument String | BindingTok String (Maybe Leaf)
	deriving (Show, Eq)

data Leaf =
	Lambda String [Leaf] |
	SubExpr [Leaf] |
	Variable Identifier
	deriving (Eq)

type Scope = [String]

lexString :: ParserConfig -> String -> Leaf
lexString cfg s = s |> tokenize cfg |> stripUseless |> lexGroup

lexGroup :: [Token] -> Leaf
lexGroup toks = toks |> makeTree [] |> fst |> lexTree []

lexTree :: Scope -> Tree -> Leaf
lexTree scope (Node t) =
	lexName scope (text t)
lexTree scope (Branch []) =
	error "WTF"
lexTree scope (Branch all@(Node a : Node b : ts)) =
	case kind b of
		LambdaSymbol -> Lambda arg $ map (lexTree (arg : scope)) ts
		_            -> SubExpr $ map (lexTree scope) all
	where
		arg = text a
lexTree scope (Branch all) =
	SubExpr $ map (lexTree scope) all

lexName :: Scope -> String -> Leaf
lexName scope tex =
	if tex `elem` scope
	then Variable $ Argument tex
	else Variable $ BindingTok tex Nothing

data Tree =
	Branch [Tree] | Node Token
	deriving (Eq)

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
			else Branch $ reverse nodesBuff


-- UTILITY --

instance Show Tree where
	show t = showTree 0 t

showTree :: Int -> Tree -> String
showTree tabs (Node t)  = 
	'\n' : (take tabs $ repeat '\t')  ++ text t

showTree tabs (Branch []) = []
showTree tabs (Branch ((Node t) : ts)) =
	'\n' : (take tabs $ repeat '\t')  ++ text t ++ (showTree tabs $ Branch ts)
showTree tabs (Branch ((Branch ts) : tss)) =
	'\n' : (take tabs $ repeat '\t') ++ (showTree (tabs + 1) (Branch ts)) ++ (showTree tabs (Branch tss))

instance Show Leaf where
	show t = showLeaf 0 t

showLeaf :: Int -> Leaf -> String
showLeaf tabs (Variable t)  = 
	case t of
		Argument name ->
			prefixed name
		BindingTok name expr ->
			case expr of
				Just x  ->
					prefixed $ "{" ++ name ++ "}"
				Nothing ->
					prefixed $ "{" ++ name ++ " (?)}"
	where
		prefixed name = (take tabs $ repeat '\t') ++ name ++ "\n"

showLeaf tabs (SubExpr ts) =
	foldr (++) "" $ map (showLeaf (tabs + 1)) ts
	where
		prefixed name = (take tabs $ repeat '\t') ++ name ++ "\n"

showLeaf tabs (Lambda arg ts) =
	"Lambda of [" ++ arg ++ "]:\n" ++ (foldr (++) "" $ map (showLeaf (tabs + 1)) ts)
	where
		prefixed name = (take tabs $ repeat '\t') ++ name ++ "\n"
