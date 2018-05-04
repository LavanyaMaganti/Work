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
 else
    echo "Connected successfully\n";

$query = "CREATE TABLE `user` (
`username` VARCHAR(64) NOT NULL DEFAULT '',
`password` VARCHAR(1024) NOT NULL DEFAULT '',
`UID`  INTEGER(8) UNSIGNED NOT NULL AUTO_INCREMENT,
`GID`  INTEGER(8) UNSIGNED NOT NULL DEFAULT 0,
`GECOS` VARCHAR(64) NOT NULL DEFAULT '',
`DIRECTORY`  VARCHAR(64) NOT NULL DEFAULT '',
`SHELL` VARCHAR(64) NOT NULL DEFAULT '',
INDEX(`UID`),
PRIMARY KEY(`username`)
)";

if($myconn->query($query))
{
echo "Table created successfully";
}

$fd = fopen("op.txt","r");
while ($line = fgets($fd)) {
  list($username,$password,$uid,$gid,$gecos,$directory,$shell) = explode(':',trim($line));

  $query1 = "INSERT INTO user (`username`,`password`,`GID`,`GECOS`,`DIRECTORY`,`SHELL`)
            VALUES('$username','$password','$gid','$gecos','$directory','$shell')";
  $myconn->query($query1);
  }
fclose($fd);

$myconn->close();
?>

