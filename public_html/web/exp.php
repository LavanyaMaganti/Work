<?php
 $cols = array("empid", "fname", "lname", "salary", "seniority", "deptid");
 $cols1 = array("empid", "fname", "lname", "ext", "email");
 $cols2 = array("deptid", "name", "prefix", "head");
 $dirs = array("ASC", "DESC");
 include "config.php";
 $page = isset($_GET['page'])? (int)$_GET['page'] : 0;
 $page = isset($_GET['jump']) && $_GET['jump'] != ''? (int)$_GET['jump'] : $page;
 $order = isset($_GET['order'])? (int)$_GET['order'] : "0";
 $dir = isset($_GET['dir'])? (int)$_GET['dir'] : 0;
 $uri = "page=$page";
 ?>
 <!DOCTYPE html>
 <html>
 <head>
 <title> PCD </title>
 <meta charset='utf-8'>
 <style>
  table {
  min-width: 720px;
  border-collapse: collapse;
  font-family:"Raleway";
  font-size: 10.8pt;
  border: 3px solid black;
  }
  th {
  font-size: 13.2pt;
  background-color: lightblue;
  }
  div {
  font-family:"monospace";
  font-size: 15pt;
  }
  tr:nth-child(4n+3),tr:nth-child(4n+4) td { background-color: lightblue; }
  td:first-child, tr:nth-child(even) td:first-child { background-color: lightgray; }

  ul.tab {
  list-style-type: none;
  margin: 0;
  padding: 0 40px;
  }

  .content {
  display: none;
  }

  ul.tab .link {
  display: inline-block;
  text-align: center;
  padding: 3px 12px;
  font-size: 16px;
  }

  </style>
  </head>
  <body>
 <ul class="tab">
 <input type="button" id="defaultOpen" class="link" onclick="table('People')" value="People">
 <input type="button" class="link" onclick="table('Contacts')" value="Contacts">
 <input type="button" class="link" onclick="table('Departments')" value="Departments">
 </ul>

 <div id="People" class="content">
  <table>
  <thead>
  <tr>
  <th>
   <?php
   $headers = array("Employee ID", "First Name", "Last Name", "Salary", "Seniority", "Dept. ID");
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
  $res = safe_query("people", "SELECT count(*) FROM people", "READ");
  $row = $res->fetch_row();
  $total = (int)$row[0];
  $res->free();

  $totpages = (int)(($total+29)/30)-1;
  $page = max(0, min($page, $totpages));
  $offset = $page * 30;

  $idx = $offset;
  $res = safe_query("people", "SELECT * FROM people ORDER BY {$cols[$order]} {$dirs[$dir]} LIMIT $offset,30", "READ");
  while ($row = $res->fetch_assoc()) {
    echo "<tr><td> $idx </td>";
    foreach($row as $k => $v) {
      if ($k == " ") {
      $f = explode(" ", $v);
      $v = $f[0];
      }
      echo "<td> $v </td>";
    }
    echo "</tr>\n";
    $idx++;
  }
?>
 </tbody>
 <tfoot>
 <tr><td colspan=7>
  <form method='GET'>
   <?php
    if (isset($_GET['order'])) echo "<input type=hidden name='order' value='$order'>";
    if (isset($_GET['dir'])) echo "<input type=hidden name='dir' value='$dir'>";
    if ($page) echo "<button style='float:left;' name='page' value='".($page-1)."'> Prev </button>";
    if ($page < $totpages) echo "<button style='float:right;' name='page' value='".($page+1)."'> Next </button>";
    echo "<span style='float: right;'> Displaying page $page of $totpages <input type='number' name='jump' size=20></span>";
   ?>
 </form>
 </tfoot>
 </table>
 </div>

 <div id="Contacts" class="content">
  <table>
  <thead>
  <tr>
  <th>
   <?php
   $headers = array("Employee ID", "First Name", "Last Name", "Extension", "E-Mail");
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
  $res = safe_query("contacts", "SELECT count(*) FROM contacts", "READ");
  $row = $res->fetch_row();
  $total = (int)$row[0];
  $res->free();

  $totpages = (int)(($total+29)/30)-1;
  $page = max(0, min($page, $totpages));
  $offset = $page * 30;

  $idx = $offset;
  $res = safe_query("contacts", "SELECT * FROM contacts ORDER BY {$cols1[$order]} {$dirs[$dir]} LIMIT $offset,30", "READ");
  while ($row = $res->fetch_assoc()) {
    echo "<tr><td> $idx </td>";
    foreach($row as $k => $v) {
      if ($k == " ") {
      $f = explode(" ", $v);
      $v = $f[0];
      }
      echo "<td> $v </td>";
    }
    echo "</tr>\n";
    $idx++;
  }
?>
 </tbody>
 <tfoot>
 <tr><td colspan=6>
  <form method='GET'>
   <?php
    if (isset($_GET['order'])) echo "<input type=hidden name='order' value='$order'>";
    if (isset($_GET['dir'])) echo "<input type=hidden name='dir' value='$dir'>";
    if ($page) echo "<button style='float:left;' name='page' value='".($page-1)."'> Prev </button>";
    if ($page < $totpages) echo "<button style='float:right;' name='page' value='".($page+1)."'> Next </button>";
    echo "<span style='float: right;'> Displaying page $page of $totpages <input type='number' name='jump' size=20></span>";
   ?>
 </form>
 </tfoot>
 </table>
 </div>

 <div id="Departments" class="content">
  <table>
  <thead>
  <tr>
  <th>
   <?php
   $headers = array("Dept. ID", "Dept. Name", "Domain prefix", "Dept. HeadID");
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
  $res = safe_query("depts", "SELECT count(*) FROM depts", "READ");
  $row = $res->fetch_row();
  $total = (int)$row[0];
  $res->free();

  $totpages = (int)(($total+29)/30)-1;
  $page = max(0, min($page, $totpages));
  $offset = $page * 30;

  $idx = $offset;
  $res = safe_query("depts", "SELECT * FROM depts ORDER BY {$cols2[$order]} {$dirs[$dir]} LIMIT $offset,30", "READ");
  while ($row = $res->fetch_assoc()) {
    echo "<tr><td> $idx </td>";
    foreach($row as $k => $v) {
      if ($k == " ") {
      $f = explode(" ", $v);
      $v = $f[0];
      }
      echo "<td> $v </td>";
    }
    echo "</tr>\n";
    $idx++;
  }
?>
 </tbody>
 <tfoot>
 <tr><td colspan=5>
  <form method='GET'>
   <?php
    if (isset($_GET['order'])) echo "<input type=hidden name='order' value='$order'>";
    if (isset($_GET['dir'])) echo "<input type=hidden name='dir' value='$dir'>";
    if ($page) echo "<button style='float:left;' name='page' value='".($page-1)."'> Prev </button>";
    if ($page < $totpages) echo "<button style='float:right;' name='page' value='".($page+1)."'> Next </button>";
    echo "<span style='float: right;'> Displaying page $page of $totpages <input type='number' name='jump' size=20></span>";
   ?>
 </form>
 </tfoot>
 </table>
 </div>

  <script>
  function table(tableName) {
   var i, content, link;
     content = document.getElementsByClassName("content");
       for (i = 0; i < content.length; i++) {
               content[i].style.display = "none";
                }
     link = document.getElementsByClassName("link");
       for (i = 0; i < link.length; i++) {
               link[i].className = link[i].className.replace(" active", "");
                }
     document.getElementById(tableName).style.display = "block";
        tableName.currentTarget.className += " active";
         }
     document.getElementById("defaultOpen").click();
  </script>
 </body>
 </html>
