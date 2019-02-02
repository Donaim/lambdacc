import qualified Prelude

true a b = a
false a b = b
not b = b false true

cond bool a b = bool a b

assert b =
    cond b (Prelude.True) (Prelude.False)
refude b =
    assert (not b)

id x = x
zero = (true, id)
is_zero (a, b) = a

succ n = (false, n)
pred (is_z, n) = n

eq :: (a -> b) -> (a -> b) -> (c -> d -> e)
eq a b =
    cond (is_zero a) (cond (is_zero b) true false) false


