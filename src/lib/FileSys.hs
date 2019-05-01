module FileSys where

import Data.List
import Data.Char
import Control.Exception

getFileText :: FilePath -> IO (Maybe String)
getFileText file =
	let
		catchf :: SomeException -> Maybe ()
		catchf _ = Just ()
	in do
	re <- tryJust catchf (readFile file)
	case re of
		Left  _ -> return Nothing
		Right x -> return $ Just x

getFileTextCont :: FilePath -> [(String -> a)] -> IO Bool
getFileTextCont filepath conts = do
	mtext <- getFileText filepath
	case mtext of
		Nothing ->
			return False
		Just text ->
			return $ map ($ text) conts `seq` True
