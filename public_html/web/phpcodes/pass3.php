#!/usr/bin/php
<?php
 include_once "config.php";
 include_once "pass1.php";

  $fd = fopen("sal.txt", "r");
  while ($line = fgets($fd)) {
  list($lname,$fname,$salary) = explode(',',trim($line));
  $myconn->query("UPDATE `people` SET salary=$salary WHERE lname='$lname' AND fname='$fname'");
     }
  fclose($fd);

  $fd = fopen("pho.txt","r");
  while ($line = fgets($fd)) {
  list($fini,$lname,$ext) = explode(' ',trim($line));
  $myconn->query("INSERT INTO contacts (`lname`, `ext`) VALUES ('$lname', '$ext')");
  }
  fclose($fd);

  $fd = fopen("ppl.txt", "r");
  while($line = fgets($fd)) {
  $f = explode(' ', trim($line));
  $n = count($f);
  $myconn->query("UPDATE contacts SET fname='{$f[0]}' WHERE lname='{$f[1]}'");

  $res1 = $myconn->query("SELECT * FROM people WHERE fname='{$f[0]}' AND lname='{$f[1]}'");
  $row1 = $res1->fetch_assoc();
  $empid = $row1['empid'];

  $myconn->query("UPDATE contacts SET empid='$empid' WHERE lname='{$f[1]}'");
}

  $res2 = $myconn->query("SELECT deptid='$deptid' FROM people JOIN depts WHERE deptid='$deptid'");

  //$row2 = $res2->fetch_assoc();
  //$prefix = $row2['prefix'];

  $res3 = $myconn->query("SELECT * FROM depts WHERE deptid='$deptid' AND prefix='$prefix'");

  echo "$deptid";

  /*$myconn->query("SELECT * FROM depts WHERE fname='{$f[0]}' AND lname='{$f[1]}'");*/

  $row3 = $res3->fetch_assoc();
  $prefix = $row3['prefix'];

  //$pre = $prefix;
  //$exp = $row3['email'];

  echo "$prefix";
  $exp = "$fini{$f[1]}@$prefix.abc.com";
  $myconn->query("UPDATE contacts SET email='$exp' WHERE lname='{$f[1]}'");

?>
