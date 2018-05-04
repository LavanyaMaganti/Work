<?php
$root="/u1/h7/sbaker/public_html/cs479/code";
$path=isset($_GET['file'])? $_GET['file'] : ".";
if ($path != ".") {
  $fullpath = realpath($root . "/" . $path);
  if (strncmp($root, $fullpath, strlen($root)) != 0) die("Invalid path");
}
else $fullpath=$root;
if ($fullpath != null) {
?>
<!DOCTYPE html>
<html>
<head>
 <title> Index of /~sbaker/cs479/code </title>
 <meta charset='utf-8'>
 </head>
 <body>
 <h1>Index of /~sbaker/cs479/code</h1>
 <ul>
 <li><a href='/~sbaker/cs479/'> Parent Directory</a>
 <?php
 $files = scandir($path);
 foreach($files as $file) {
   if ($file == "." || $file == "..") continue;
   echo "<li><a href='?file=$path/$file'> $file </a>\n";
 }
?>
</ul>
</body>
</html>
<?php
} else {
}
?>
