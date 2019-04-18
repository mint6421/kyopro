import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
  s <- getLine
  putStrLn $ if solve (reverse s)
    then "YES"
    else "NO"

solve :: [Char] -> Bool
solve s
  | s == "" = True
  | take 5 s == reverse "dream" = solve $ drop 5 s
  | take 7 s == reverse "dreamer" = solve $ drop 7 s
  | take 5 s == reverse "erase" = solve $ drop 5 s
  | take 6 s == reverse "eraser" = solve $ drop 6 s
  | otherwise = False

