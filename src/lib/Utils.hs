module Utils where

import Data.Maybe
import Data.Char as C

import Debug.Trace

(|>) :: a -> (a -> b) -> b
(|>) x f = f x
infixl 0 |>

mhead []     = Nothing
mhead (x:xs) = Just x

mapPart :: ([a] -> b) -> [a] -> [b]
mapPart f all@(_:xs) =
	(f all) : (mapPart f xs)
mapPart _ _ = []

mapPartCxt :: (z -> [a] -> (z, b)) -> z -> [a] -> [b]
mapPartCxt f ctx all@(_:xs) =
	x : (mapPartCxt f newCtx xs)
	where (newCtx, x) = f ctx all
mapPartCxt _ _ _ = []

padWith :: Char -> Int -> String -> String
padWith padS padN str =
	str ++ (replicate (max 0 $ padN - length str) padS)

trim xs = dropSpaceTail "" $ dropWhile C.isSpace xs
	where
		dropSpaceTail maybeStuff "" = ""
		dropSpaceTail maybeStuff (x:xs)
			| isSpace x = dropSpaceTail (x:maybeStuff) xs
			| null maybeStuff = x : dropSpaceTail "" xs
			| otherwise       = reverse maybeStuff ++ x : dropSpaceTail "" xs

tracePeek :: (Show a) => a -> a
tracePeek x =
	traceShow ("TRACE: [" ++ show x ++ "]") x

tracePeekS :: String -> String
tracePeekS x =
	trace ("TRACE: [" ++ x ++ "]") x

countWhile :: (a -> Bool) -> [a] -> Int
countWhile p [] = 0
countWhile p (x : xs) =
	if p x
	then 1 + countWhile p xs
	else 0

lenQuote :: String -> Bool -> Int
lenQuote []                 escaped = 0
lenQuote ('\\' : '\'' : xs) False   = 2 + lenQuote xs False
lenQuote ('\\' : '\'' : xs) True    = 2
lenQuote ('\\' : xs)        escaped = 1 + lenQuote xs (not escaped)
lenQuote ('\'' : xs)        escaped = 1
lenQuote (x : xs)           escaped = 1 + lenQuote xs escaped
