#!/usr/bin/php
<?php
$query1 = "CREATE TABLE `user`(
`username` VARCHAR(64) NOT NULL DEFAULT '',
`password` VARCHAR(1024) NOT NULL DEFAULT '',
`UID` INT(8) UNSIGNED NOT NULL AUTO_INCREMENT,
`GID` INT(8) UNSIGNED NOT NULL DEFAULT 0,
`GCOS` VARCHAR(64) NOT NULL DEFAULT '',
`HOME` VARCHAR(64) NOT NULL DEFAULT '',
`SHELL` VARCHAR(64) NOT NULL DEFAULT '',
INDEX (`UID`),
PRIMARY KEY(`username`)
);";
echo "$query1";
$fd = fopen("/etc/passwd","r");
while($line = fgets($fd)) {
  list($username,$password,$UID,$GID,$GCOS,$HOME,$SHELL) = explode(':',trim($line));
  $GCOS = addslashes($GCOS);
  $query2 = "INSERT INTO user (`username`,`password`,`UID`,`GID`,`GCOS`,`HOME`,`SHELL`) VALUES('$username','$password',$UID,$GID,'$GCOS','$HOME','$SHELL');\n";
  echo "$query2";
}
fclose($fd);
?>
