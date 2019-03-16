
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

lexe :: Scope -> [Token] -> [Leaf]
lexe scope toks = lexeSplit toks |> map (lexOne scope)

lexOne :: Scope -> [Token] -> Leaf
lexOne scope (t : ts) =
	case kind t of
		LambdaDecl  -> Lambda (text $ head ts) (lexe (tex : scope) (tail ts))
		OpenBracket -> error "WTF"
		Name        -> SubExpr $ (lexName scope tex) : lexe scope ts
		_           -> SubExpr $ lexe scope ts

	where tex = text t

lexName :: Scope -> String -> Leaf
lexName scope tex =
	if tex `elem` scope
	then Variable $ Argument tex
	else Variable $ BindingTok tex Nothing

-- Split body into parts based on brackets
-- Result will not have brackets anymore
lexeSplit :: [Token] -> [[Token]]
lexeSplit []   = []
lexeSplit toks =
	result : lexeSplit next
	where
		nextBracket = getNextBracket 0 0 toks
		result      =
			if nextBracket >= 0
			then take nextBracket toks
			else toks
		next        =
			if nextBracket >= 0
			then drop nextBracket toks
			else []
		stripped =
			if (kind $ head result) == OpenBracket
			then init $ tail result
			else result

getNextBracket :: Int -> Int -> [Token] -> Int
getNextBracket count index []       =
	if count > 0
	then -count
	else index
getNextBracket count index (t : ts) =
	case kind t of
		OpenBracket ->
			getNextBracket (count + 1) (index + 1) ts
		CloseBracket ->
			if count == 0
			then index
			else getNextBracket (count - 1) (index + 1) ts
		_ ->
			getNextBracket count (index + 1) ts

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

