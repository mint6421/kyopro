import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
  n <- readLn
  a <- replicateM n readLn
  print $ length $ nub (a::[Int])

