<?php
/* CREATING A NEW TEAM
 * 
 *
 **/
session_start();
if(isset($_SESSION['user']))
{
$user=$_SESSION['user'];
}
include('../../confi/confi_info.php');
$con = mysql_connect($host_name,$user_name,$user_pass);
//UNIQUE ID for the team
$uid=md5(uniqid(rand(), true));
//Today's date
$date=date("y/d/m");
// Check connection
$team_member_tablename="member_".$uid;
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
$sql="INSERT INTO $teams_table (uid,teamname,sports,Ownerid
,Creationdate)
VALUES('$uid','$_POST[teamname]',
'$_POST[sportslist]','$user','$date')";
if (!mysql_query($sql,$con))
{
  	echo "<div class='alert alert-warining'>";
  	die('Error: ' . mysql_error());
  	echo "</div'>";
}
else
{
  	echo "<div class='alert alert-success'>";
	echo "<strong>Congratulation! </strong>You have successfully created a new team";
}
//////////////////////////////////////////// BUILDING TABLE MEMBER FOR THE TEAM
$sql = "CREATE TABLE $team_member_tablename
(
ID int NOT NULL AUTO_INCREMENT,
PRIMARY KEY (ID),
uid varchar(125),
Joineddate date,
Membertype int,
UNIQUE(uid)
)";
// Execute query
mysql_query($sql,$con);
$sql="SELECT* FROM $team_member_tablename";
$result=@mysql_query($sql);
if($result)
{
echo "<div class='alert alert-success'>";
echo "Table $team_member_tablename was successfully built<br/>";
echo "</div>";
}
else{
echo "<div class='alert alert-error'>";
echo "ERROR Table $team_member_tablename<br/>";
echo "</div>";
}
mysql_close($con)
?>