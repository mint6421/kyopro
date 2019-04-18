import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
  n <- getLine
  s <- reverse . sort . map read . words<$> getLine
  print $ solve s

solve :: [Int] -> Int
solve s = sum[x|(i,x)<- zip[0..] s,even i] - sum[x|(i,x)<- zip[0..] s,odd i]

