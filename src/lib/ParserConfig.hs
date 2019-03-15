
module ParserConfig where

data ParserConfig = ParserConfig 
	{ lambdaSymbol  :: String
	, lambdaDecl    :: String
	, parseComments :: Bool
	, parseQuotes   :: Bool
	}
	deriving (Show, Eq)
