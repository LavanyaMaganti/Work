<!DOCTYPE html> 
<html> 
<title> sac.php 
</title> 
<meta charset='utf-8'> 
<head>
<style>
table {
  border-collapse:collapse; font-size: 115%;
 }
tr:nth-child(even) {
  background : #D3D3D3;
}
   
tr:nth-child(2) {
   background : #D3D3D3;
}
tr:nth-child(1) {
  background : #D3D3D3;
}
td:nth-child(3) {
  background: white;
}
meter {
  width: 100%;
}
</style>
</head>
<body>
<table>
<col width='50'>
<col width='50'>
<col width='450'>
<?php
$op = `sac -ah`;
$keywords = explode("\n", $op);
//$keywords = preg_split('/(?=[0-9][0-9]-:*)/i', $op);
$count =0;
$j=0;
foreach ($keywords as $value) {
  if($count <2)
   {
     echo "<tr> <td colspan='4'> $value </td> </tr>";
     $count = $count +1;
   }
  else
   {
     $key2 = preg_split('/\s+/', $value);
     $arr0[$j] = $key2[0];
     $arr1[$j] = $key2[1];
     $arr2[$j] =strlen($key2[2]);
     $j = $j +1;
   }
 }
  $m1 = max($arr1);
  $m2 = max($arr2);
  for($i=0;$i<($j-1);$i++)
  {
    echo "<tr>";
    echo "<td> $arr0[$i]</td><td>$arr1[$i]</td><td><meter value='$arr2[$i]' max='$m2'></meter></td>";
    echo "</tr>";
  }
 ?>
 </table>
 </body>
 </html>
                                                                          
