<?php
 header("Context-type: text/plain; charset=UTF-8");
 if (isset($_POST['state']))
 {
    $state = $_POST['state'];

    $fp = fopen("applelog.txt", "w");
    fwrite($fp,$state);
    fclose($fp);
  }
?>
