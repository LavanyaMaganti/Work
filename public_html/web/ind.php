<?php
 $cols = array("username", "password", "uid", "gid", "gcos", "home", "shell");
 $dirs = array("ASC", "DESC");
 include_once "config.php";
 $page = isset($_GET['page'])? (int)$_GET['page'] : 0;
 $page = isset($_GET['jump']) && $_GET['jump'] != ''? (int)$_GET['jump'] : $page;
 $order = isset($_GET['order'])? (int)$_GET['order'] : "uid";
 $dir = isset($_GET['dir'])? (int)$_GET['dir'] : 0;
 $uri = "page=$page";
 ?>
 <!DOCTYPE html>
 <html>
 <head>
 <title> User </title>
 <meta charset='utf-8'>
 <style>
  table { min-width: 800px; }
  th { background-color: lightblue; }
  tr:nth-child(even) td { background-color: lightgreen; }
  td:first-child, tr:nth-child(even) td:first-child { background-color: lightgray; }
  </style>
  </head>
  <body>
  <table>
  <thead>
  <tr>
  <th>
   <?php
   $headers = array("Username", "Password", "UID", "GID",  "GCOS", "Home", "Shell");
   $idx=0;
   foreach($headers as $heading) {
   $d = $idx == $order? !$dir : 0;
   $cr = $idx == $order? ($dir == 1? "&utrif;" : "&dtrif;") : "&dtrif;";
   echo "<th><a href='?order=$idx&page=$page&dir=$d'> $heading </a> $cr";
   $idx++;
 }
 ?>
 </thead>
 <tbody>
 <?php
  $res = safe_query("user", "SELECT count(*) FROM user", "READ");
  $row = $res->fetch_row();
  $total = (int)$row[0];
  $res->free();

  $totpages = (int)(($total+29)/30)-1;
  $page = max(0, min($page, $totpages));
  $offset = $page * 30;

  $idx = $offset;
  $res = safe_query("user", "SELECT * FROM user ORDER BY {$cols[$order]} {$dirs[$dir]} LIMIT $offset,30", "READ");
  while ($row = $res->fetch_assoc()) {
    echo "<tr><td> $idx </td>";
    foreach($row as $k => $v) {
      if ($k == "gcos") {
      $f = explode(",", $v);
      $v = $f[0];
      }
      echo "<td> $v </td>";
    }
    echo "</tr>\n";
    $idx++;
  }
?>
 <tbody>
 <tfoot>
 <tr>
 <td colspan=8>
 <form method='GET'>
   <?php
    if (isset($_GET['order'])) echo "<input type=hidden name='order' value='$order'>";
    if (isset($_GET['dir'])) echo "<input type=hidden name='dir' value='$dir'>";
    if ($page) echo "<button style='float:left;' name='page' value='".($page-1)."'> Prev </button>";
    if ($page < $totpages) echo "<button style='float:right;' name='page' value='".($page+1)."'> Next </button>";
    echo "<span style='float: right;'> Displaying page $page of $totpages <input type='number' name='jump' size=5></span>";
   ?>
 </form>
 </tfoot>
 </table>
 </body>
 </html>
