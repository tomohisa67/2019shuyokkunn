<?php
 $fp = fopen("applelog.txt", "r");
 while($line = fgets($fp)) {
    print($line);
 }
 fclose($fp);
?> 