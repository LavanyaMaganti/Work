<html>
<body>
<p>This is to check dATA CONNECTIVITY</p>

<?php
class MyDB extends SQLite3
   {
      function __construct()
      {
         $this->open('test.db');
      }
   }
   
$db = new MyDB();
   if(!$db){
      echo $db->lastErrorMsg();
?>
	<p>connection failed</p>
<?php 
   } 
else {
      echo "Opened database successfully\n";
?>
<p>Connection succesfull </p>
<?php  
 }

 $sql =<<<EOF
      INSERT INTO COMPANY (NAME,AGE,ADDRESS,SALARY)
      VALUES ( 'Paul', 32, 'California', 20000.00 );

      INSERT INTO COMPANY (NAME,AGE,ADDRESS,SALARY)
      VALUES ( 'Allen', 25, 'Texas', 15000.00 );

      INSERT INTO COMPANY (NAME,AGE,ADDRESS,SALARY)
      VALUES ( 'Teddy', 23, 'Norway', 20000.00 );

      INSERT INTO COMPANY (NAME,AGE,ADDRESS,SALARY)
      VALUES ( 'Mark', 25, 'Rich-Mond ', 65000.00 );
EOF;

   $ret = $db->exec($sql);
   if(!$ret){
      echo $db->lastErrorMsg();
   } else {
      echo "Records created successfully\n";
   }
   $db->close();
?>
</body>
</html>
