#!/usr/bin/php
<?php
 include_once "config.php";

// $myconn->query("DROP TABLE IF EXISTS `people`");
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

 //$myconn->query("DROP TABLE IF EXISTS `depts`");
 $myconn->query("CREATE TABLE `depts` (
 `deptid`      INT(8)          UNSIGNED NOT NULL AUTO_INCREMENT,
 `name`        VARCHAR(64)     NOT NULL DEFAULT '',
 `prefix` VARCHAR(32) NOT NULL DEFAULT '',
 `head`        INT(9)          NOT NULL DEFAULT 0,
  PRIMARY KEY ( `deptid`)
  ) AUTO_INCREMENT=1");

 $fd = fopen("sen-sorted.txt", "r");
 while ($line = fgets($fd)) {
 list($name,$sen) = explode(':',trim($line));
 list($fname,$lname) = explode(' ',$name);
 //   safe_query("people", "INSERT INTO people (`fname`, `lname`, `seniority`) VALUES
 //     ('$fname', '$lname', $sen)", "WRITE");
 $myconn->query("INSERT INTO people (`fname`, `lname`, `seniority`) VALUES('$fname', '$lname', '$sen')");
  }
 fclose($fd);

 $fd = fopen("sal.txt", "r");
 while ($line = fgets($fd)) {
 list($lname,$fname,$salary) = explode(',',trim($line));
 $myconn->query("UPDATE `people` SET salary=$salary WHERE lname='$lname' AND fname='$fname'");
 $myconn->query("UPDATE `contacts` SET fname=$fname WHERE lname='$lname'");
  }
 fclose($fd);

 $fd = fopen("dep.txt","r");
 while ($line = fgets($fd)) {
 list($name,$prefix) = explode(":", trim($line));
 $myconn->query("INSERT INTO depts (`name`, `prefix`) VALUES ('$name', '$prefix')");
 }
 fclose($fd);

 $fd = fopen("pho.txt","r");
 while ($line = fgets($fd)) {
 list($fini,$lname,$ext) = explode(' ',trim($line));
 $myconn->query("INSERT INTO contacts (`lname`, `ext`) VALUES ('$lname', '$ext')");
 }
 fclose($fd);

 $fd = fopen("pho.txt", "r");
 while($line = fgets($fd)) {
 $f = explode(' ', trim($line));
 $n = count($f);

  $res1 = $myconn->query("SELECT * FROM people WHERE lname='{$f[1]}'");
  $row1 = $res1->fetch_assoc();
  $empid = $row1['empid'];

  $myconn->query("UPDATE contacts SET empid='$empid' WHERE lname='{$f[1]}'");
}

 $fd = fopen("sal.txt", "r");
 while ($line = fgets($fd)) {
 list($lname,$fname,$salary) = explode(',',trim($line));
 $myconn->query("UPDATE `contacts` SET fname=$fname WHERE lname='$lname'");
  }
 fclose($fd);


 $fd = fopen("pho.txt", "r");
 while($line = fgets($fd)) {
 $f = explode(' ', trim($line));
 $n = count($f);
/*
  $res2 = $myconn->query("SELECT * from people where lname='{f[1]}' AND deptid='$deptid'");
  $row2 = $res2->fetch_assoc();
  $deptid = $row2['deptid'];
  $d = $deptid;

  $myconn->query("SELECT * from people LEFT JOIN depts ON people.deptid=depts.deptid WHERE people.lname='{$f[1]}'");
  $myconn->query("SELECT empid,fname,lname,salary,seniority,people.deptid FROM people JOIN depts ON people.deptid=depts.deptid WHERE lname={$f[1]}");
  echo "SELECT people.deptid='$deptid' from people WHERE people.lname='{$f[1]}'";
*/
  /*
  $res3 = $myconn->query("SELECT prefix='$prefix' from depts where deptid='$d'");
  echo "SELECT prefix='$prefix' from depts where deptid='$deptid'";

  $res3 = $myconn->query("SELECT prefix='$prefix' from depts where deptid='$d'");
  $row3 = $res3->fetch_assoc();
  $prefix = $row3['prefix'];
       echo "$prefix";
  */
$res2 = $myconn->query("SELECT people.lname,people.deptid,depts.deptid from `people` AS a INNER JOIN `depts` AS b ON people.deptid=depts.deptid WHERE people.lname='{$f[1]}'");
//  $row2 = $res2->fetch_assoc();
  $deptid = $row2['deptid'];
  $d = $deptid;

  $res3 = $myconn->query("SELECT prefix='$prefix' from depts where deptid='$d'");
  $row3 = $res3->fetch_assoc();
  $prefix = $row3['prefix'];
       echo "$prefix";

  $exp = "{$f[0]}{$f[1]}@$prefix.abc.com";
  $myconn->query("UPDATE contacts SET email='$exp' WHERE lname='{$f[1]}'");
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

 $myconn->query("UPDATE `people` SET deptid='$deptid' WHERE fname='{$f[0]}' AND lname='{$f[1]}'");

 if ($dh) {
      $res = $myconn->query("SELECT * FROM people WHERE fname='{$f[0]}' AND lname='{$f[1]}'");
      $row = $res->fetch_assoc();
      $empid = $row['empid'];
      $myconn->query("UPDATE depts SET head = $empid WHERE deptid = $deptid");
      }
}
/*
  $myconn->query("UPDATE contacts SET fname='{$f[0]}' WHERE lname='{$f[1]}'");

  $res1 = $myconn->query("SELECT * FROM people WHERE fname='{$f[0]}' AND lname='{$f[1]}'");
  $row1 = $res1->fetch_assoc();
  $empid = $row1['empid'];

  $myconn->query("UPDATE contacts SET empid='$empid' WHERE lname='{$f[1]}'");
-------------
     $res2 = $myconn->query("SELECT deptid='$deptid' FROM people JOIN depts WHERE deptid='$deptid'");

   //$row2 = $res2->fetch_assoc();
   //$prefix = $row2['prefix'];

     $res3 = $myconn->query("SELECT * FROM depts WHERE deptid='$deptid' AND prefix='$prefix'");

   //echo "$res2";

  //$myconn->query("SELECT * FROM depts WHERE fname='{$f[0]}' AND lname='{$f[1]}'");

     $row3 = $res3->fetch_assoc();
     $prefix = $row3['prefix'];

   //$pre = $prefix;
   //$exp = $row3['email'];

     echo "$prefix";
     $exp = "$fini{$f[1]}@$prefix.abc.com";
     $myconn->query("UPDATE contacts SET email='$exp' WHERE lname='{$f[1]}'");
}*/
?>
