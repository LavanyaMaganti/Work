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

$myconn->query("CREATE TABLE IF NOT EXISTS `loginuser` (
 `name`             VARCHAR(64)  NOT NULL DEFAULT '',
 `email`            VARCHAR(64)  NOT NULL DEFAULT '',
 `newpassword`      VARCHAR(64)  NOT NULL DEFAULT '',
 `confirmpassword`  VARCHAR(64)  NOT NULL DEFAULT '',
 PRIMARY KEY (`email`)
 )");
 echo "connected";

  $sql = "INSERT INTO loginuser (name,email,newpassword,confirmpassword) VALUES ('divz','n@gmail.com','manisha07','manisha07')";
     if($myconn->query($sql)){
     echo "New record created successfully";
     }else{
     echo "error" . $sql . "<br>" . mysqli_error($myconn);
     }
   mysqli_close($myconn);
?>

<!DOCTYPE html>
<html>

<head>
<title> Signup form </title>
<meta charset='utf-8'>
<style>
body
{
  background-image:url(intro5.jpg);
   background-repeat:no-repeat;
   background-size:cover;
}
h3
{
font-size:25pt;
}
.con
{
font-size:15pt;
height:300px;
width:1500px;
}
.box
{
height:25px;
}
.but
{
font-size:16pt;
height:30px;
margin:5px 100px 0px 450px;
padding:5px 100px 35px 100px;
float: center;
}

</style>
</head>

<body>
<form name="myForm" method="POST" action="">
<br><br><br><h3 align='center'> <b> Create an account </b> </h3>
<table class="con">
<tbody>
  <tr> <td align='right'> Your Name: </td> <td align='left'> <input type="text" class="box" placeholder="Full name" name="name" id="name"  size=50>
  </td>
  <tr> <td align='right'> Email: </td> <td> <input type="text" name="email" id="email" class="box" placeholder="someone@host" size=50>
  </td>
  <tr> <td align='right'> New Password: </td> <td> <input type="password" class="box" placeholder="minimum 8 characters" name="p1" id="p1" size=50> 
  </td>
  <tr> <td align='right'> Confirm password: </td> <td> <input type="password" class="box" name="p2" id="p2" size=50> </td>
</tbody>
</table>
&nbsp;<button type="submit" onclick="passmatch();" class="but" name="submit" id="submit" value="submit"> Create your account </button>
</form>

<script>

function passmatch()
{
var p1=document.getElementById('p1').value;
var p2=document.getElementById('p2').value;
if(p1!=p2)
alert("passwords not match");

var x = document.forms["myForm"]["email"].value;
var at = x.indexOf("@");
var dot = x.lastIndexOf(".");
if (at<1 || dot<at+2 || dot+2>=x.length) {
alert("Invalid email");
return false;
}
}
</script>


</body>
</html>


