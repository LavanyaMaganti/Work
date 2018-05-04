<?php

//if(isset($_POST['submit']))
//{
//$servername = "localhost";
//$username = "root";
//$password = "Tony7089";
//$dbname = "student";

// Create connection
$conn = mysql_connect('localhost:3306','root','Tony7089');
// Check connection
if (!$conn) {
    die("Connection failed: " . mysql_error());
}
print"Connection Established";
/*

mysql_select_db('student');

// sql to create table
$sql = "INSERT INTO STUDENT(FirstName,LastName,Email,Dept) VALUES ('$_POST[firstname]','$_POST[lastname]','$_POST[email]','$_POST[course]')";


if (mysql_query($sql, $conn)) {
    echo "Table MyGuests created successfully";
} else {
    echo "Error creating table: " . mysqli_error($conn);
}

mysql_close($conn);
}*/
?>

