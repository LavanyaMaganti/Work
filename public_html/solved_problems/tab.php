<?php include 'header.php'; ?>
<?php 

/* class MyDB extends SQLite3
{
  function __construct()
  {
    $this->open('student.db');
  }
}*/



/*$db = new SQLiteDataBase('student.db');
if (!$db)
  {
    echo $db->lastErrorMsg();
  }
else
  {
    echo "Opened database successfully\n";
*/
/*$con=sqlite_open('student.db')or die('problem');

 $sql="
      CREATE TABLE Student (
       ID   INT  NOT NULL AUTO INCREMENT PRIMARY KEY,
       FirstName VARCHAR (20)  NOT NULL,
       LastName VARCHAR (20) NOT NULL,
       Email VARCHAR(20) NOT NULL,
       Course VARCHAR(20) NOT NULL,
       Address  CHAR (25) ,
       Zip INT NOT NULL,
       )'";
sqlite_exec($con,$sql)or or die('problem create');


$sql2=" 
       insert into Student(ID,FirstName,LastName,Email,Course,Address,Zip) values('1','LAV','MAG','lav@gmail.com','CS','asjfajjdg','46378');
       ";
   sqlite_exec($con,$sql);
  */     
/*$res=$db->query($sql);
while($row=$res->fetchArray())  {
var_dump($row);
echo "hiii";
}or die('problem');
}*/
//sqlite_exec($con,$sql2)or or die('problem insert');

if(!exec(sqlite3))
echo "ERROR0";
if(!exec('.open student.db'))
echo "ERROR1";
else "success";

?>
