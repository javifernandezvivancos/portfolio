<?php
session_start();
if(isset($_SESSION['user']))
{
$user=$_SESSION['user'];
}
/* CREATING FIRST TIME ADMIN ACCOUNT
 * FOR THE WEBSITE
 *
 **/
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
$result = mysql_query("SELECT * FROM $players_table WHERE Playerid='$user'");
while($row = mysql_fetch_array($result))
  {
$result2 = mysql_query("SELECT * FROM $events_table WHERE uid='$row[uid]'");
while($row2 = mysql_fetch_array($result2))
  {
  echo $row2['Title'];
  }
echo " <a href='leaveevent.php?uid=".$row['uid']."'>[LEAVE]</a>";
echo "<br/>";
  }
  mysql_close($con);
?>
