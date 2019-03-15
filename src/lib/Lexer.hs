
module Lexer where


import Utils
import Parser
import Tokenizer

data Identifier = Argument String | Binding String (Maybe Leaf)

data Leaf =
	Lambda String [Leaf] |
	SubExpr [Leaf] |
	Variable Identifier


getNextBracket :: Int -> Int -> [Token] -> Int
getNextBracket count index []       = -count
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
