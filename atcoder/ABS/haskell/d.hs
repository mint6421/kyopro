
import Control.Applicative

main :: IO ()
main = do

  n <- getLine
  list <- map read . words <$> getLine

  print $ count list

count :: [Int] -> Int
count list = minimum[(solve x)| x <- list]

solve :: Int -> Int
solve x | even x = 1+solve(div x 2)
        | otherwise = 0

