<?php include 'header.php'; ?>

<?php 

//if ($_POST["Submit"])
  //{
try {  
          $conn = new PDO ('/u1/class/cs55917/public_html/Student.db') or die ("DB connection Failed");
     $conn->exec("CREATE TABLE Dogs (Id INTEGER PRIMARY KEY, Breed TEXT, Name TEXT, Age INTEGER);");
$conn->exec("INSERT INTO Dogs (Breed, Name, Age) VALUES ('Labrador', 'Tank', 2);");
$result = $conn->query('SELECT * FROM Dogs');
foreach($result as $row)
{
print "<tr><td>".$row['Id']."</td>";
print "<td>".$row['Breed']."</td>";
print "<td>".$row['Name']."</td>";
print "<td>".$row['Age']."</td></tr>";
}
print "</table>";
$conn=NULL;
}
catch{PDOException $e)
{
print 'Exception : ' .$e->getMessage();
}
 //}
                                    ?>
                                    
