

<!DOCTYPE html>
<html>
<head>
<title> browser.php </title>
<meta charset='utf-8'>
<style>
.bor {
      font-family:"monospace";
      font-size:28pt;
     border: 3px solid black;
      border-collapse:collapse;
      width:756px;
      }

div{
      width:694px;
      height:600px;
      overflow-x:hidden;
      overflow-y:scroll;
}

.borrt {
      font-family:"monospace";
      border-bottom:none;
      border: 3px solid black;
      border-collapse:collpase;
      line-height:1;
      width:750px;
}
table, td{
      border-right:1px solid black;
      border-collapse:collapse;
      padding:3px;
}
.bordr {
     font-size:20pt;
     border-bottom:1px solid black;
      border-collapse:collapse;
     background-color:lightblue;
     }

d{color:blue;}
f{color:green;}

</style>
</head>

<body>
<table class="bor">
<tbody>
<col width="310">
<col width="110">
<col width="210">

 <tr>
 <th colspan="3" class="bordr" align="left"> /net/web </th>
 </tr>
 <tr>
 <th align="left" class="bordr"> Name </th>
 <th align="left" class="bordr">Size </th>
 <th align="left" class="bordr"> Mtime </th>
 </tr>
</tbody>
</table>


<div class="borrt">
<table>
<tbody>
<col width="400">
<col width="140">
<col width="280">

<?php
$root = '/net/web';
$path='http://cs.indstate.edu';
$files = scandir($root);
foreach($files as $file) {
$real = "$root/$file";
$size = filesize($real);
$time = date("M D Y H:i:s",filemtime($real));

   if ($file == "." || $file == ".." || $file[0] =="." ) continue;
    elseif(is_dir($real)){
    echo "<tr>";
    echo "<td> <a href='$path/$file'> <d> $file </d>  </a> </td>";
    echo "<td align='left'> $size </td>";
    echo  "<td> $time </td>";
    echo "</tr>";
    }
    else {
    echo "<tr>";
    echo "<td> <a href='$path/$file'> <f> $file </f></a> </td>";
    echo "<td align='left'> $size </td>";
    echo  "<td> $time </td>";
    echo "</tr>";
    }
    }
?>

</tbody>
</table>
</div>
</body>
</html>
