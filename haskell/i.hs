import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
  [n,y] <- map read.words<$> getLine
  let ans = [[a,b,n-a-b]|a<-[0..n],b<-[0..n-a],10000*a+5000*b+1000*(n-a-b)==y]
  let res = if null ans
      then [-1,-1,-1]
      else head ans

  putStrLn $ unwords $ map show res

