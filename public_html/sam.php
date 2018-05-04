<?php 

class MyDB extends SQLite3
{
  function __construct()
  {
    $this->open('test.db');
  }
}

$db = new MyDB();
if (!$db)
  {
    echo $db->lastErrorMsg();
  }
else
  {
    echo "Opened database successfully\n";
  }
if (isset($_POST["id1"])) {
$id = $_POST["id1"];
$id = $_POST["firstname"];
$lastname = $_POST["lastname"];
$email = $_POST["email"];
$course = $_POST["course"];

$sql =<<<EOF
INSERT INTO STUDENT( ID , FirstName , LastName , Email , Course )
VALUES( $id ,'$firstname' , '$lastname' , '$email' , '$course' );
EOF;
$ret = $db->exec($sql);
if (!$ret)
  {
    echo $db->lastErrorMsg();
  }
else
  {
    echo "Records inserted successfully\n";
  }
}
$db->close();
?>
