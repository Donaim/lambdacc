import TestUtil

import Parser
import ParserConfig
import Tokenizer

main :: IO ()
main = do
	putBox "Test suite not yet implemented"
	putBox $ show p
	putBox $ show (tokenize cfg "hello there bro")
	where
		p = branchParse
			cfg
			"a   ->   a"
		cfg =  (ParserConfig { lambdaDecl = "\\", lambdaSymbol = "->" })


