
module Exept where

import Control.Applicative
import Control.Monad

data ParseError = SyntaxError String | LogicError String
	deriving (Eq, Show, Read)

data ParseResult a = Ok a | Bad ParseError
	deriving (Eq, Show, Read)

instance Functor ParseResult where
	fmap = liftM
instance Applicative ParseResult where
	pure  = return
	(<*>) = ap
instance Monad ParseResult where
	(Ok          x) >>= f = f x
	(Bad         x) >>= f = Bad x

	return                = Ok

guard :: Bool -> ParseError -> ParseResult ()
guard b r =
	if b
	then Bad r
	else Ok ()
