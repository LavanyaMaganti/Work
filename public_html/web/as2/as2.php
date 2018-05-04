<?php
$Sender = isset($_POST['Sender'])? $_POST['Sender'] : "";
$Major = isset($_POST['Major'])? $_POST['Major'] : "";
$Year = isset($_POST['Year'])? $_POST['Year'] : "";
$GS = isset($_POST['GS'])? $_POST['GS'] : "";
$GPA = isset($_POST['GPA'])? $_POST['GPA'] : "No";
$Telephone = isset($_POST['Telephone'])? $_POST['Telephone'] : "";
$Email = isset($_POST['Email'])? $_POST['Email'] : "";
$Message = isset($_POST['Message'])? $_POST['Message'] : "";
?>
<!DOCTYPE html>
<html>
<head>
<title> Form submission </title>
<meta charset='utf-8'>
<style>

body
{
  background-color:#FFFFFF;
}

table
{
    border: 1px solid black;
}

pre
{
border:1px solid black;
<
}
</style>

</head>
<body>
<table>
<tbody>
<tr>
<tr><b><h1> Thank you for your Request </h1></b>
<tr>Results of your request:
<br><br>
<tr>
<th align='right'> Real name=
<td> <?php echo "$Sender"; ?>
<tr>
<th align='right'> Major=
<td> <?php echo "$Major"; ?>
<tr>
<th align='right'> Year=
<td> <?php echo "$Year"; ?>
<tr>
<th align='right'> Grad=
<td> <?php echo "$GS"; ?>
<tr>
<th align='right'> GPA=
<td> <?php echo "$GPA"; ?>
<tr>
<th align='right'> Telephone=
<td> <?php echo "$Telephone"; ?>
<tr>
<th align='right'> Email=
<td> <?php echo "$Email"; ?>
<tr>
<th align='right'> Message=
<td> <pre> <?php echo "$Message"; ?> </pre>
</tbody>
</table>
</body>
</html>

