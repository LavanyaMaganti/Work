<html>

<head>

<title> Lavanya Maganti</title>
<meta content="noindex, nofollow" name="robots">
<link href="https://getbootstrap.com/dist/css/bootstrap.min.css" rel="stylesheet">
<link href="pdef.css" rel="stylesheet" type="text/css">
<link href="sam.php" rel="stylesheet">
<?php include 'header.php'; ?>

<script type="text/javascript">
function formValidation() {
var id = document.getElementById('id');
var firstname = document.getElementById('firstname');
var lastname = document.getElementById('lastname');
var email = document.getElementById('email');
var course = document.getElementById('course');
var errorMsg="";

var reg1 = /^[0-9]+$/;
if (!id.value.match(reg1)) {
errorMsg+="Invalid Id\n";
//alert("Invalid ID");
return false;
}
return true;
}

</script>
</head>

<body>
<div class="panel-heading">
<a href="http://www.indstate.edu/"> <img id="univLogo" src="ISU.png" alt="logo"></a>
<b><font size=50px>INDIANA STATE UNIVERSITY</font></b>
<p align="center"> <font color="#2874A6" size=35px><marquee position:absolute><B>  Student Registration Form </B></marquee></font></p>

</div>

<div style="padding-left:10px">

<p id="head"></p>
<center>

<form name="form" method="POST" action="sam.php" onSubmit="return formValidation()">

<table>

<tr>
<td>
<label>ID:</label></td>
<td><input id='id' name="id1" type='text'>
<p id="p1"></p>
</td>
</tr>

<tr>
<td><label>First Name:</label></td>
<td><input id='firstname' name="firstname" type='text' >
<p id="p2"></p>
</td>
</tr>

<tr><td>
<label>Last Name:</label></td>
<td><input id='lastname' name="lastname" type='text' >
<p id="p3"></p>
</td></tr>

<tr>
<td><label>Email:</label></td>
<td><input id='email' type='text' name="email">
<p id="p6"></p>
</td>

<tr>
<td><label>Course:</label></td>
<td><input id='course' type='text' name="course">
<p id="p7"></p>
</td></tr>

<tr>
<td><label>State:</label></td>
<td><select id='state' >
<option>
Please Choose
</option>
<option>
America
</option>
<option>
Australia
</option>
<option>
Sweden
</option>
<option>
Africa
</option>
</select>
<p id="p8"></p>
</td></tr>

<tr>
<td><label>Address:</label></td>
<td><textarea id='address' rows="2" cols="21"> </textarea>
<p id="p9"></p>
</td></tr>

<tr>
<td><label>Zip Code:</label></td>
<td><input id='zip' type='text'>
<p id="p10"></p>
</td></tr>

<tr>
<td></td>
<td><input id='submit' type='submit' value='Submit' ></td></tr>
</table>
</form>
</center>
</div>

 <div class="panel-footer">
 <a class="tagline" href="http://mathcs.indstate.edu">Computer Science</a>
 <p align="center">Copyright &copy by Lavanya Maganti </p>        
</div>


</body>
</html>

