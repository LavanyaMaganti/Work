<?php

 include_once "config.php";
?>

<!DOCTYPE html>
<html>

<head>
<title> Signup form </title>
<meta charset='utf-8'>
<style>
body
{
  background-color:#D3D3D3;
  /*background-image:url(intro4.jpg);
   background-repeat:no-repeat;
   background-size:cover;*/
}
.home {
font-size:18pt;
margin:0px 30px 0px 10px;
border:2px solid black;
border-radius:4px;
text-decoration:none;
padding:4px;
margin:20px;
}
#sec {
border:3px solid black;
height:550px;
margin:30px 250px 0px 250px;
}
h3
{
margin:10px 0px 0px 0px;
font-size:25pt;
}
.con
{
font-size:15pt;
height:300px;
width:550px;
}
.box
{
margin:0px 0px 0px 10px;
height:25px;
}
.but
{
font-size:16pt;
height:30px;
width:360px;
margin:10px 200px 0px 250px;
padding:5px 50px 35px 50px;
float: center;
}
</style>
</head>

<body>
<form name="myForm" method="post" action="signup.php" >

<?php
  session_start();
  if(isset($_POST["submit"])){
    $name = $_POST["name"];  $pass = $_POST["pass"]; $confPass = $_POST["confPass"]; $email = $_POST["email"];

    $nameSession=$_SESSION['name']=$name;
    $passSession=$_SESSION['pass']=$pass;
    $confPassSession=$_SESSION['confPass']=$confPass;
    $emailSession=$_SESSION['email']=$email;


    if( isset( $_SESSION['counter'] ) ) {
      $_SESSION['counter'] += 1;
    }else {
      $_SESSION['counter'] = 1;
    }

    echo $msg. "<br>";
    if(($name!="")&&($email!="")&&($pass!="")&&($confPass!="")){
       if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
          $err = "Invalid email format:";
       }else {
          if($pass==$confPass) {
            $sql = "INSERT INTO loginuser (name,email,newpassword,confirmpassword) VALUES ('$name','$email','$pass','$confPass')";
            if($myconn->query($sql)){
              $err= "New record created successfully";
              unset($nameSession); unset($passSession); unset($emailSession); unset($confPassSession);
            }else{
              //$err =  "error" . $sql . "<br>" . mysqli_error($myconn);
              $err = "Email-ID which you have entered is already registered please enter a new one!";
            }
          mysqli_close($myconn);
         }else {
              $err = "Passwords doesnot Match";
         }
       }
    }else {
      echo "Fill Details";
    }
  }
  session_destroy();
?>
<a href="project.html"<button type="text" class="home" > Homepage </button></a>
<section id="sec">
<br><br><br><h3 align='center'> <b> Create an account </b> </h3>
<br><table class="con" align="center">
<tbody>
<col width="40%">
<col width="20%">

  <tr> <td align='right'> Your Name*: </td> <td> <input type="text" class="box" value="<?php echo $nameSession;?>" placeholder="Full name" name="name" id="name" 
  size=50 required>
  <tr> <td align='right'> Email*: </td> <td> <input type="text" name="email" id="email" class="box" value="<?php echo $emailSession;?>" 
  placeholder="someone@host" size=50 required>
  <tr> <td align='right'> New Password*: </td> <td> <input type="password" class="box" value="<?php echo $passSession;?>" placeholder="minimum 8 characters" 
  name="pass" id="pass" size=50 required>
  <tr> <td align='right'> Confirm password*: </td> <td> <input type="password" class="box" value="<?php echo $confPassSession;?>" name="confPass" id="confPass" 
  size=50 required> </td>
</tbody>
</table>
&nbsp;<button type="submit" class="but" name="submit" id="submit" value="submit"> Create your account </button>
<span><?php echo $err;?> </span>
</section>
</form>

<script>

</body>
</html>


