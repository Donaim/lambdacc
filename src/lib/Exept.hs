
module Exept where

import Control.Applicative
import Control.Monad

data ParserResult a = Ok a | SyntaxError String | LogicError String

instance Functor ParserResult where
	fmap = liftM
instance Applicative ParserResult where
	pure  = return
	(<*>) = ap
instance Monad ParserResult where
	(Ok          x) >>= f = f x
	(SyntaxError x) >>= f = SyntaxError x
	(LogicError  x) >>= f = LogicError x

	return                = Ok
