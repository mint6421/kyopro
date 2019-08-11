<?php

$n = fgets(STDIN);
$a = explode(" ",trim(fgets(STDIN)));

rsort($a);

$sum=0;

for($i=0;$i<$n;$i++){
  if($i%2==0){
    $sum+=$a[$i];
  }else{
    $sum-=$a[$i];
  }
}

print $sum;

?>
