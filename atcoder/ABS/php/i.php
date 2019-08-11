<?php

fscanf(STDIN,"%d %d",$n,$y);

$a=-1;$b=-1;$c=-1;

for($i=0;$i*1e4<=$y;$i++){
  for($j=0;$i*1e4+$j*5e3<=$y;$j++){
    $k=($y-($i*1e4+$j*5e3))/1e3;
    if($i+$j+$k==$n){
      $a=$i;
      $b=$j;
      $c=$k;
    }
  }
}

print $a.' '.$b.' '.$c."\n";

?>

