<?php

// Fill in the following with your database information:
$db	= "test";
$db_user= "test";
$db_pass= "testpw";
$db_host= "localhost";

$myconn = new mysqli($db_host, $db_user, $db_pass, $db);
if ($myconn->connect_error) {
  die("Failed to connect to database (" . $myconn->connect_errorno . "): " .
    $myconn->connect_error);
}
?>
