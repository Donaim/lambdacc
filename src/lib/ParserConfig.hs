
module ParserConfig where

data ParserConfig = ParserConfig 
	{ lambdaSymbol  :: String
	, parseComments :: Bool
	, parseQuotes   :: Bool
	}
	deriving (Show, Eq)
