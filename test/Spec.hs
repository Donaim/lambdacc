import TestUtil

import Parser
import ParserConfig

main :: IO ()
main = do
	putBox "Test suite not yet implemented"
	putBox $ show p
	where
		p = branchParse
			(ParserConfig { lambdaDecl = "\\", lambdaSymbol = "->" })
			"Hehehehe"


