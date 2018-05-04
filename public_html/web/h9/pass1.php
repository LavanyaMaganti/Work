#!/usr/bin/php
<?php
 include_once "config.php";

 $myconn->query("DROP TABLE IF EXISTS `people`");
 $myconn->query("CREATE TABLE `people` (
  `empid`       INT(9)          UNSIGNED NOT NULL AUTO_INCREMENT,
  `fname`       VARCHAR(64)     NOT NULL DEFAULT '',
  `lname`       VARCHAR(64)     NOT NULL DEFAULT '',
  `salary`      DECIMAL(10,2)   NOT NULL DEFAULT 0,
  `seniority`   INT(4)          UNSIGNED NOT NULL DEFAULT 0,
  `deptid`      INT(8)          UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`empid`),
  INDEX `name` ( `fname`, `lname` ),
  INDEX `dept` ( `deptid` )
 ) AUTO_INCREMENT=991000001");

 $myconn->query("DROP TABLE IF EXISTS `contacts`");
 $myconn->query("CREATE TABLE `contacts` (
  `empid`       INT(9)          UNSIGNED NOT NULL DEFAULT 0,
  `fname`       VARCHAR(64)     NOT NULL DEFAULT '',
  `lname`       VARCHAR(64)     NOT NULL DEFAULT '',
  `ext`         CHAR(9)         NOT NULL DEFAULT '',
  `email`       VARCHAR(64)     NOT NULL DEFAULT '',
  INDEX `name` ( `fname`, `lname` ),
  INDEX `email` (`email`)
 )");

 $myconn->query("DROP TABLE IF EXISTS `depts`");
 $myconn->query("CREATE TABLE `depts` (
  `deptid`      INT(8)          UNSIGNED NOT NULL AUTO_INCREMENT,
  `name`        VARCHAR(64)     NOT NULL DEFAULT '',
  `prefix`	VARCHAR(32)	NOT NULL DEFAULT '',
  `head`        INT(9)          NOT NULL DEFAULT 0,
  PRIMARY KEY ( `deptid`)
 )");


 $fd = fopen("sen-sorted.txt", "r");
 while ($line = fgets($fd)) {
   list($name,$sen) = explode(':',trim($line));
   list($fname,$lname) = explode(' ', $name);
//   safe_query("people", "INSERT INTO people (`fname`, `lname`, `seniority`) VALUES
//     ('$fname', '$lname', $sen)", "WRITE");
   $myconn->query("INSERT INTO people (`fname`, `lname`, `seniority`) VALUES
     ('$fname', '$lname', $sen)");
 }
 fclose($fd);



 $fd = fopen("dep.txt","r");
 while ($line = fgets($fd)) {
   list($name,$prefix) = explode(":", trim($line));
   $myconn->query("INSERT INTO depts (`name`, `prefix`) VALUES ('$name', '$prefix')");
 }



 $fd = fopen("ppl.txt", "r");
 while($line = fgets($fd)) {
   $f = explode(' ', trim($line));
   $n = count($f);
   if ($f[$n-2] == "dept") {
     $dh = true;
     $n -= 2;
   } else $dh = false;
   $dept = $f[2];
   if ($n > 3) $dept .= ' '.$f[3];

   $res = $myconn->query("SELECT * FROM depts WHERE name = '$dept'");
   $row = $res->fetch_assoc();
   $deptid = $row['deptid'];

   $myconn->query("UPDATE `people` SET deptid='$deptid'
      WHERE fname='{$f[0]}' AND lname='{$f[1]}'");

   if ($dh) {
      $res = $myconn->query("SELECT * FROM people
        WHERE fname='{$f[0]}' AND lname='{$f[1]}'");
      $row = $res->fetch_assoc();
      $empid = $row['empid'];
      $myconn->query("UPDATE depts SET head = $empid WHERE deptid = $deptid");
   }
 }

?>
