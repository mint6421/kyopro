import Control.Applicative
import Control.Monad

main :: IO ()
main = do
  [n,a,b] <- map read . words <$> getLine
  print $ sum [x|x<-[1..n],solve a (digit x) b]
 
solve :: Int -> Int -> Int -> Bool
solve a b c = a<= b && b<= c

digit :: Int -> Int
digit a
  | a == 0 = 0
  | otherwise = mod a 10 + digit(div a 10)

