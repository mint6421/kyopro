<?php

function f($d){
  $sum=0;
  while($d>0){
    $sum+=$d%10;
    $d/=10;
  }
  return $sum;
}

list($n,$a,$b)=fscanf(STDIN,"%d %d %d");

$ans=0;

for($i=1;$i<=$n;$i++){
  if($a<=f($i)&&f($i)<=$b)
    $ans+=$i;
}

print $ans;

?>

