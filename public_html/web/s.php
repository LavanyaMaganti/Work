<?php

$db = "cs47928";
$db_user= "cs47928";
$db_pass= "wcnsmkos";
$db_host= "localhost";
$myconn = new mysqli($db_host, $db_user, $db_pass, $db);
if ($myconn->connect_error) {
  die("Failed to connect to database (" . $myconn->connect_errorno . "): " .
  $myconn->connect_error);
  }
  echo "connected successfully";
  $myconn->query("CREATE TABLE `loginuser` (
 `name`             VARCHAR(64)  NOT NULL DEFAULT '',
 `email`            VARCHAR(64)  NOT NULL DEFAULT '',
 `newpassword`      VARCHAR(64)  NOT NULL DEFAULT '',
 `confirmpassword`  VARCHAR(64)  NOT NULL DEFAULT '',
 PRIMARY KEY (`email`)
 )");
 echo "connected";
 $escape=addslashes($email);
 $myconn->query("INSERT INTO loginuser(name,email,newpassword,confirmpassword) VALUES('$name','$escape','$newpassword','$confirmpassword')";
 if($conn->query($conn)===TRUE){
 echo "New record created successfully";
 }else{
 echo "error";
 }
 $conn->close();
 ?>
