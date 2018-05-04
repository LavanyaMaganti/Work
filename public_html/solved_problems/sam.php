<html>
<head>
<body>
<?php
class MyDB extends SQLite3
{
  function __construct()
  {
    $this->open ('test.db');
  }
}

$db = new MyDB();
if (!$db)
  {
    echo $db->lastErrorMsg();
?>
<p>databse connection cannot be established </p>
<?php
  }
else
  {
    echo "Opened database successfully\n";
?>
<p>databse connection established</p>
<?php
  }
$db->close();
?>
</body>
</html>
