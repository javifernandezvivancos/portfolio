<?php
session_start();
include('../../confi/confi_info.php');
$con = mysql_connect($host_name,$user_name,$user_pass);
$uid=$_GET['uid'];
$team_member_tablename="member_".$uid;
// Check connection
$con = mysql_connect($host_name,$user_name,$user_pass);
if (!$con)
  {
  echo "<div class='alert alert-error'>";
  die('Could not connect: ' . mysql_error());
  echo "</div>";
  }
mysql_select_db($data_name, $con);
mysql_query("SET NAMES 'utf8'"); 
mysql_query('SET CHARACTER SET utf8');
mysql_set_charset('utf8'); 
$result = mysql_query("SELECT * FROM $team_member_tablename");
$num=1;
while($row = mysql_fetch_array($result))
  {
$temperory_ID=$row['uid'];
echo $num;
echo "- ";
$resultID = mysql_query("SELECT * FROM $users_table WHERE uid='$temperory_ID'");
while($rowID = mysql_fetch_array($resultID))
  {
  echo $rowID['firstname']." ".$rowID['lastname'];
  }
$num++;
  }
  mysql_close($con);
?>