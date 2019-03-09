
module Exept where

import Control.Applicative
import Control.Monad

data ParseResult a = Ok a | SyntaxError String | LogicError String

instance Functor ParseResult where
	fmap = liftM
instance Applicative ParseResult where
	pure  = return
	(<*>) = ap
instance Monad ParseResult where
	(Ok          x) >>= f = f x
	(SyntaxError x) >>= f = SyntaxError x
	(LogicError  x) >>= f = LogicError x

	return                = Ok
