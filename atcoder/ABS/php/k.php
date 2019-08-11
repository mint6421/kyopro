<?php

fscanf(STDIN,"%d",$n);

list($time,$a,$b) =[0,0,0];


while($n--){
  list($t,$x,$y) = explode(" ",fgets(STDIN));

  $d = abs($a-$x)+abs($b-$y);

  if(!($t-$time>=$d&&($t-$time)%2==$d%2)){
    print"No\n";
    return;
  }
  $time=$t;
  $a=$x;
  $b=$y;
}

print "Yes\n";

?>

