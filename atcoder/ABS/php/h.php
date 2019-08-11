<?php

$n = fgets(STDIN);

$d = array();
for($i=0;$i<$n;$i++){
  $d[]=fgets(STDIN);
}

print count(array_unique($d));

?>

