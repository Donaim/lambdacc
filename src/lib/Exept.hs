
module Exept where

import Control.Applicative
import Control.Monad

data SyntaxError = SyntaxError String

data ParserResult a = Ok a | Bad SyntaxError

instance Functor ParserResult where
	fmap = liftM
instance Applicative ParserResult where
	pure  = return
	(<*>) = ap
instance Monad ParserResult where
	(Bad x) >>= f = Bad x
	(Ok  x) >>= f = f x
	return        = Ok
