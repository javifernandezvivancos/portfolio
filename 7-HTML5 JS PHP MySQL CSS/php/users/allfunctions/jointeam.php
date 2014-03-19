<?php
session_start();
if(isset($_SESSION['user']))
{
$user=$_SESSION['user'];
}
include('../../confi/confi_info.php');
$con = mysql_connect($host_name,$user_name,$user_pass);
//Today's date
$date=date("y/d/m");
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
$sql="INSERT INTO $team_member_tablename (uid,Joineddate,Membertype)
VALUES('$user','$date','player')";
if (!mysql_query($sql,$con))
  {
  echo "<div class='alert alert-warining'>";
  die('Error: ' . mysql_error());
  echo "</div'>";
  }
  else
  {
  echo "<div class='alert alert-success'>";
echo "<strong>Congratulation! </strong>You have successfully joined a team";
}
mysql_close($con)
?>