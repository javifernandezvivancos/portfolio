<?php
session_start();
include('../../confi/confi_info.php');
$con = mysql_connect($host_name,$user_name,$user_pass);
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
mysql_select_db($data_name, $con);
mysql_query("SET NAMES 'utf8'"); 
mysql_query('SET CHARACTER SET utf8');
mysql_set_charset('utf8'); 
$result = mysql_query("SELECT * FROM $events_table");
while($row = mysql_fetch_array($result))
  {
echo $row['Title'];
echo " "."<a href='cancelevent.php?uid=".$row['uid']."'>[X]</a>";
echo " | ";
echo "<a href='joinevent.php?uid=".$row['uid']."'>[JOIN]</a>";
  }
  mysql_close($con);
?>
