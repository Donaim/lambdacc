
module Lib where

import Data.List

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
