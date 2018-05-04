
<?php
$dir    = '/net/web';
$files1 = scandir($dir);
print_r($files1);
$arraylength = count($files1);
echo nl2br($arraylength."\n");

for($i = 0;$i < $arraylength; $i++)
{
$file = $files1[$i];
if($file == "." || $file == "..")
{
  continue;
}
if(is_dir($file))
{
$size = filesize($file);
    echo "Is a Directory--:". $file;
    echo  "Size--:".$size;
    echo nl2br("MTime--:".date ("F d Y H:i:s.", filemtime($file))."\n");


}
else
{
    echo "Is a file--:".$file;
    echo "Size--:".filesize($file);
    echo nl2br("MTime--:".date("F d Y H:i:s.", filemtime($file))."\n");
}
}

?>

