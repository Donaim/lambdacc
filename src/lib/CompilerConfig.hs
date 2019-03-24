
module CompilerConfig where

data CompilerConfig = CompilerConfig 
	{ lambdaSymbol  :: String
	, parseComments :: Bool
	, parseQuotes   :: Bool
	}
	deriving (Show, Eq)
