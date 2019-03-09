module TestUtil where

import Utils

boxedStringMaxLinelen = 170

boxedString :: String -> String
boxedString [] = []
boxedString str =
	'╔' : (padWith '═' (mx + 2) "") ++ "╗\n" ++
		joined ++
			'╚' : (padWith '═' (mx + 2) "") ++ "╝"
	where
		noTabsDo :: String -> String
		noTabsDo []        = []
		noTabsDo ('\t':xs) = "    " ++ (noTabsDo xs)
		noTabsDo (x:xs)    = x : noTabsDo xs
		noTabs = noTabsDo str
		lns = lines noTabs
		mx = min boxedStringMaxLinelen $ foldr max 0 (map length lns)
		surroundClose s =
			if length s > boxedStringMaxLinelen then
				(padWith ' ' mx (take boxedStringMaxLinelen s)) ++ "\n  " ++ surroundClose (drop boxedStringMaxLinelen s)
			else
				(padWith ' ' mx s) ++ " ║"
		surround s = '║' : ' ' : surroundClose s
		surrounded = map surround lns
		joined = unlines surrounded

pboxedString :: String -> String
pboxedString str =
	unlines $ map ('\t':) (lines $ boxedString str)

putBox = putStr . pboxedString

unwrap :: Maybe a -> a
unwrap (Just x) = x
unwrap Nothing  = error "Tried to unwrap Nothing!"
