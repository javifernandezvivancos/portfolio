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
//UNIQUE ID
$uid=md5(uniqid(rand(), true));
//Today's date
$date=date("y/d/m");
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
$sql="INSERT INTO $events_table (uid,Title,Sport,Date,
Startingtime,Endingtime,Agemin,Agemax,Gender,Address,Zipcode,Gametype,
Playersmin,Playersmax,Locationrange,Registrationtype,Ownerid
,Dateofcreation)
VALUES('$uid','$_POST[title]',
'$_POST[sport]','$_POST[date]'
,'$_POST[startingtime]','$_POST[endingtime]'
,'$_POST[agemin]','$_POST[agemax]','$_POST[gender]',
'$_POST[address]','$_POST[zipcode]',
'$_POST[gametype]','$_POST[playersmin]','$_POST[playersmax]',
'$_POST[locationrange]','$_POST[registrationtype]',
'$user','$date')";
if (!mysql_query($sql,$con))
  {
  echo "<div class='alert alert-warining'>";
  die('Error: ' . mysql_error());
  echo "</div'>";
  }
  else
  {
  echo "<div class='alert alert-success'>";
echo "<strong>Congratulation! </strong>You have successfully created a new event";
}
mysql_close($con)
?>