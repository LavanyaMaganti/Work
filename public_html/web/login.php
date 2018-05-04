<?php
  include_once "config.php";
?>
<!DOCTYPE html>
<html>

<head>
<title> Login form </title>
<meta charset='utf-8'>
<style>
body
{
  background-color:#D3D3D3;
  /* background-image:url(intro5.jpg);
   background-repeat:no-repeat;
   background-size:cover;*/
}
h3
{
font-size:25pt;
}
.con
{
font-size:15pt;
height:150px;
margin:20px 50px 0px 450px;
}
.box
{
margin:0px;
height:30px;
}
.but
{
 font-size:16pt;
 height:30px;
 margin:0px;
 padding:5px 100px 35px 100px;
}
</style>
</head>

<body>
<form name="myForm" method="post">

<?php

session_start();

  if(isset($_POST["submit"])){
    $email = $_POST["email"];
    $pass = $_POST["password"];

    $emailSession=$_SESSION['email']=$email;
    $passSession=$_SESSION['pass']=$pass;

    $sql = "SELECT email,newpassword FROM loginuser WHERE email='$email'";

    $res = $myconn->query($sql);
    $row = $res->fetch_assoc();
    if(($email==$row["email"])&&($pass==$row["newpassword"])){
      echo "Login Successful";
      header("Location: project.html");
    }else {
      echo "Invalid Login";
    }
   $myconn->close();
  }
  session_destroy();
?>

<br><br><br><h3 align='center'> <b> Sign in </b> </h3>
<table class="con">
<tbody>
<tr align='right'> <td> Email: </td> <td> <input type="text" class="box" value="<?php echo $emailSession?>" placeholder="someone@host" name="email" size=50 
required>
<tr align='right'> <td> Password: </td> <td> <input type="password" class="box" value="<?php echo $passSession?>" name="password" size=50 required>
<tr> <td colspan='2'> <button type="submit" name="submit" class="but">Sign in </button></td>
</tbody>
</form>
</body>


