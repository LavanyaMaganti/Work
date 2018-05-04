<?php
$db = "test";
$db_user= "test";
$db_pass= "testpw";
$db_host= "localhost";
$myconn = new mysqli($db_host, $db_user, $db_pass, $db);
if ($myconn->connect_error) {
  die("Failed to connect to database (" . $myconn->connect_errorno . "): " .
    $myconn->connect_error);
}
function my_query($q) {
  global $myconn;
  $res = $myconn->query($q) or die("Error querying database: ($q) ". $myconn->error);
  return $res;
}
$last_insert_id = 0;
function safe_query($tbl, $safequery, $action, $update_li = false) {
  global $last_insert_id, $myconn;

  $l = "";
  if (gettype($tbl) == "array") {
    foreach($tbl as $t) {
      if (strlen($l) > 0) $l .= ", ";
      $l .= "`$t` $action";
    }
  } else if (gettype($tbl) == "string") $l = "`$tbl` $action";
  else die("safe_query: table specification not string or array of strings.\n");

  my_query("LOCK TABLES $l");
  $results = my_query($safequery);
  if ($update_li) $last_insert_id = $myconn->insert_id;
  my_query("UNLOCK TABLES");

  return $results;
}
function safe_print($tbl, $safequery, $action) {
  echo $safequery;
}
function my_escape($s) {
  global $myconn;
  return $myconn->real_escape_string($s);
}
?>
