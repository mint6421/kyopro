import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
  n <- readLn
  txy <- replicateM n $ map read.words<$>getLine
  putStrLn $ if solve ([0,0,0]:txy)
    then "Yes"
    else "No"

solve [a,b] = reach a b
solve (a:b:xs) = reach a b && solve (b:xs)


reach [t1,x1,y1] [t2,x2,y2] = 
 ((t2-t1) >= (x2-x1) + (y2-y1)) && ( mod ((t2-t1) - (x2-x1) - (y2-y1)) 2 == 0)

