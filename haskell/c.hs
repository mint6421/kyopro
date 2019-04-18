
import Control.Applicative

main :: IO ()

main = do

  s <- getLine

  putStrLn $ show$length$filter(=='1') s

