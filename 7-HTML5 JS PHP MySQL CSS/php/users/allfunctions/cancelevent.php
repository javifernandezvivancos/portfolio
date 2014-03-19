<?php
session_start();
/* CREATING FIRST TIME ADMIN ACCOUNT
 * FOR THE WEBSITE
 *
 **/
$uid=$_GET['uid'];
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

if (!mysql_query("DELETE FROM $events_table WHERE uid='$uid'"))
  {
  echo "<div class='alert alert-warining'>";
  die('Error: ' . mysql_error());
  echo "</div'>";
  }
  else
  {
  echo "<div class='alert alert-success'>";
echo "<strong>Event </strong> was successfully removed";
echo "</div>";
}
mysql_close($con)
?>
