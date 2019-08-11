<?php

fscanf(STDIN,"%d",$n);

$array = explode(" ",fgets(STDIN));
$ans = 100000;

foreach($array as $a){
  $res=0;
  while($a%2==0){
    $a=$a/2;
    $res++;
  }
  $ans=min($ans,$res);
}

print $ans."\n";

?>
