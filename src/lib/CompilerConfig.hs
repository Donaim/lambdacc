
module CompilerConfig where

data CompilerConfig = CompilerConfig 
	{ lambdaSymbol    :: String
	, parseComments   :: Bool
	, parseQuotes     :: Bool
	, countTotalExecs :: Bool
	, trackAllocs     :: Bool
	, trackPoolAllocs :: Bool
	, useTypeid       :: Bool
	}
	deriving (Show, Eq)