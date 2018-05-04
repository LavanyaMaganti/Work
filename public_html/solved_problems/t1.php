<?php include 'header.php'; ?> /*
 * PHP SQLite3 - Open a database, create a table and insert rows */ //Open the database mydb 
 $db = new SQLite3('mydb'); //Create a basic users table 
 $db->exec('CREATE TABLE users (username varchar(255), password varchar (255))'); 
 echo "Table users has been created <br />"; //Insert some rows 
 $db->exec('INSERT INTO users (username, password) VALUES ("admin","adminpass")'); 
 echo "Inserted row into table users <br />"; 
 $db->exec('INSERT INTO users (username, password) VALUES ("user","userpass")'); 
 echo "Inserted row into table users <br />"; //drop the table $db->exec('DROP TABLE users');
?>
