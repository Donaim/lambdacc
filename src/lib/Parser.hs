module Parser where

import Data.List
import Utils
import Exept
import ParserConfig

findFirstChar :: String -> [Char] -> Maybe Int
findFirstChar s stops = findFirstCharR s 0
	where
		findFirstCharR :: String -> Int -> Maybe Int
		findFirstCharR []     _     = Nothing
		findFirstCharR (x:xs) index =
			if x `elem` stops
			then Just index
			else findFirstCharR xs (succ index)

findFirstSub :: String -> [String] -> Maybe Int
findFirstSub s subs = findFirstSubR s 0
	where
		findFirstSubR :: String -> Int -> Maybe Int
		findFirstSubR []     _     = Nothing
		findFirstSubR (x:xs) index =
			if any (`isPrefixOf` s) subs
			then Just index
			else findFirstSubR xs (succ index)

findNextBracket :: String -> Either Int Int
findNextBracket s = findNextBracketR s 0 0
	where
		findNextBracketR :: String -> Int -> Int -> Either Int Int
		findNextBracketR []         _     count =
			Left (-count)

		findNextBracketR ('(' : xs) index count =
			findNextBracketR xs (succ index) (succ count)
		findNextBracketR (')' : xs) index 0 =
			Left 1
		findNextBracketR (')' : xs) index 1 =
			Right index
		findNextBracketR (')' : xs) index count =
			findNextBracketR xs (succ index) (pred count)

		findNextBracketR (x:xs) index count =
			findNextBracketR xs (succ index) count


data BranchType = 
	LambdaBranch | 
	TokenBranch | -- A binding or constant expression
	ArgBranch
	deriving (Show, Eq)

data Branch = Branch String [Branch] BranchType
	deriving (Show, Eq)

branchParse :: ParserConfig -> String -> ParseResult Branch
branchParse cfg sraw = do
	if null s
	then Bad $ SyntaxError "Empty branch"
	else return ()

	return $ Branch "Hello" [] TokenBranch

	where
		isLambda = (lambdaDecl cfg) `isPrefixOf` s
		s = trim sraw
		lambaArg = (tail) s
