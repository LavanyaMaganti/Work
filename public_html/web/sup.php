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
  `name`  VARCHAR(64)  NOT NULL DEFAULT '',
  `email`  VARCHAR(64)  NOT NULL DEFAULT '',
  `newpassword`  VARCHAR(64)  NOT NULL DEFAULT '',
  `confirmpassword`  VARCHAR(64)  NOT NULL DEFAULT '',
   PRIMARY KEY (`email`)
     )");
 echo "connected";

if(isset($_POST['submit'])) {
$name = $_POST['name'];
$email = $_POST['email'];
$p1 = $_POST['p1'];
$p2 = $_POST['p2'];

if($name !=''||$email !='') {

$query = mysql_query("INSERT INTO LOGINUSER(name, email, newpassword, confirmpassword) values ('$name', '$email', '$p1', '$p2')");
echo "Data inserted successfully";
}
else {
echo "Insertion failed";
}
}
mysql_close($myconn);
?>

