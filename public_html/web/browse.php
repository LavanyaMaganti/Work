<!DOCTYPE html>
<html>
<title> browse.php </title>

<head>
<style>
table {
border: 2px solid black;
}
.border1 {
border-bottom: 1px solid black;
border-collapse:collapse
}

.border2 {
bprder-bottom

}

</style>
<body>
<table>
<tr>
<td colspan="3" class="border"> <b> /net/web </b></td>
</tr>
<tr>
<td class="border"><b>Name</b></td>
<td class="border"><b>Size</b></td>
<td class="border"><b>MTime</b></td>
</tr>
<?php
$root    = "/net/web";
$files1 = scandir($root);
foreach ($files1 as $file) {
$realpath = "$root/$file";
$fileinfo = stat($realpath);
$size = $fileinfo['size'];
$time = date ("M d Y H:i:s.", filemtime($realpath));
if ($file == "." || $file == "..") continue;
elseif(is_dir($realpath)) 
echo "<tr> <td>DIR  $file</td> <td>$size</td> <td>$time</td></tr> "; 
else
echo "<tr> <td>FILE  $file</td> <td>$size</td> <td>$time</td></tr> ";
}
?>
</table>
</body>
</html>
