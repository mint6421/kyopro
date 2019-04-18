import Control.Applicative
import Control.Monad

main :: IO () 
main = do 
  [a,b,c,x] <- map read <$> replicateM 4 getLine
  print $ solve a b c x


solve :: Int -> Int -> Int -> Int -> Int
solve a b c x = length $ filter 
  (x == )
  [i*500+j*100+k*50|i<-[0..a],j<-[0..b],k<-[0..c]]

