
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
lexe scope toks = undefined

lexOne :: Scope -> [Token] -> Leaf
lexOne scope [tok] =
	case kind tok of
		Name       -> lexName scope (text tok)
		_          -> error "Unexpected variable name"

lexOne scope (t : ts) =
	case kind t of
		LambdaDecl -> Lambda tex (lexe (tex : scope) (tail ts))
		OpenBracket -> SubExpr $ lexe scope (init ts)
		_          -> SubExpr $ lexe scope ts

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
			if count == 1
			then index
			else getNextBracket (count - 1) (index + 1) ts
		_ ->
			getNextBracket count (index + 1) ts

