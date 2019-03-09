
module Exept where

import Control.Applicative
import Control.Monad

data ParseError = SyntaxError String | LogicError String
	deriving (Show, Eq)

data ParseResult a = Ok a | Bad ParseError
	deriving (Show, Eq)

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
