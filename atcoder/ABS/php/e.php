<?php
fscanf(STDIN,"%d",$a);
fscanf(STDIN,"%d",$b);
fscanf(STDIN,"%d",$c);
fscanf(STDIN,"%d",$x);

$ans=0;

for($i=0;$i<=$a&&500*$i<=$x;$i++){
  for($j=0;$j<=$b&&500*$i+100*$j<=$x;$j++){
    $res=($x-500*$i-100*$j)/50;
    if($res<=$c) $ans++;
  }
}

print $ans."\n";

?>
