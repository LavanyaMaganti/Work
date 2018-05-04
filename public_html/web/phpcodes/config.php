<?php 

// Fill in the following with your database information:
$db = "cs47928";
$db_user= "cs47928";
$db_pass= "wcnsmkos";
$db_host= "localhost";
$myconn = new mysqli($db_host, $db_user, $db_pass, $db); 
if ($myconn->connect_error) {
  die("Failed to connect to database (" . $myconn->connect_errorno . "): " .
    $myconn->connect_error);
}
?>
