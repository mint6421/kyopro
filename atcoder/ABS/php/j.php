<?php

$s = trim(fgets(STDIN));

$words = array("erase","dream","eraser","dreamer");

while($s){
  for($i=0;$i<5;$i++){
    if($i==4){
      print "NO\n";
      return;
    }else{
      $len = strlen($words[$i]);
      $subs =substr($s,-($len));
      //print $subs." ".$words[$i]."\n";
      if(strcmp($subs,$words[$i])==0){

        $s=substr($s,0,-$len);
        break;
      }
    }
  }
}

print "YES\n";

?>

