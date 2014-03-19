<?php
include('confi_info.php');
$con = mysql_connect($host_name,$user_name,$user_pass);
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
   mysql_set_charset('utf8',$con); 
if (mysql_query("CREATE DATABASE"." ".$data_name,$con))
  { 
  echo "<div class='alert alert-success'>";
  echo "Database was successfully created<br/>";
  echo "</div>";
  }
else
  {
  echo "<div class='alert alert-error'>";
  echo "Error creating database: " . mysql_error();
  echo "</div>";
  die();
  }
mysql_select_db($data_name, $con);
mysql_query("ALTER DATABASE $data_name CHARACTER SET utf8 COLLATE utf8_general_ci;");
/*
* Table: users
* This table to hold the user basic info/account info
* 
**/
$sql = "CREATE TABLE $users_table
(
id int NOT NULL AUTO_INCREMENT,
PRIMARY KEY (id),
uid varchar(125),
firstname varchar(45),
lastname varchar(45),
email varchar(45),
pass varchar(45),
sports varchar(45),
birthdate date,
dateofregistration varchar(45),
state varchar(45),
city varchar(45),
gender varchar(25),
activation int,
UNIQUE(uid),
UNIQUE(email)
)";
// Execute query
/*
* Creation of users Table
*
**/
mysql_query($sql,$con);
$sql="SELECT* FROM $users_table";
$result=@mysql_query($sql);
if($result)
{
echo "<div class='alert alert-success'>";
echo "Table $users_table was successfully built<br/>";
echo "</div>";
}
else{
echo "<div class='alert alert-error'>";
echo "ERROR Table $table_members<br/>";
echo "</div>";
}
/*
* Table: events
* This table to hold the eents basic info
* 
**/
$sql2 = "CREATE TABLE $events_table
(
id int NOT NULL AUTO_INCREMENT,
PRIMARY KEY (id),
uid varchar(125),
title varchar(45),
sport varchar(45),
date date,
startingtime date,
endingtime date,
agemin int,
agemax int,
gender varchar(45),
address varchar(145),
zipcode varchar(15),
gametype varchar(45),
playersmin varchar(45),
playersmax varchar(45),
locationrange varchar(45),
registrationtype varchar(45),
ownerid varchar(125),
dateofcreation date,
isdelete int,
cancel date,
UNIQUE(uid)
)";
// Execute query
/*
* Creation of events Table
*
**/
mysql_query($sql2,$con);
$sql2="SELECT* FROM $events_table";
$result=@mysql_query($sql2);
if($result)
{
echo "<div class='alert alert-success'>";
echo "Table $events_table was successfully built<br/>";
echo "</div>";
}
else{
echo "<div class='alert alert-error'>";
echo "ERROR Table $events_table<br/>";
echo "</div>";
}

/*
* Table: events player
* This table to hold the users who joined an event
* 
**/
$sql3 = "CREATE TABLE $event_player_table
(
id int NOT NULL AUTO_INCREMENT,
PRIMARY KEY (id),
playerid varchar(125),
eventid varchar(125),
playertype varchar(45),
datejoined date,
isdelete int,
cancel date
)";
// Execute query
/*
* Creation of events player Table
*
**/
mysql_query($sql3,$con);
$sql3="SELECT* FROM $event_player_table";
$result=@mysql_query($sql3);
if($result)
{
echo "<div class='alert alert-success'>";
echo "Table $event_player_table was successfully built<br/>";
echo "</div>";
}
else{
echo "<div class='alert alert-error'>";
echo "ERROR Table $event_player_table<br/>";
echo "</div>";
}

/*
* Table: teams
* This table to hold the teams that were created by users
* 
**/
$sql4 = "CREATE TABLE $teams_table
(
id int NOT NULL AUTO_INCREMENT,
PRIMARY KEY (id),
uid varchar(125),
teamname varchar(45),
sports varchar(225),
ownerid varchar(125),
dateofcreation date,
isdelete int,
cancel date,
UNIQUE(uid)
)";
// Execute query
/*
* Creation of teams Table
*
**/
mysql_query($sql4,$con);
$sql4="SELECT* FROM $teams_table";
$result=@mysql_query($sql4);
if($result)
{
echo "<div class='alert alert-success'>";
echo "Table $teams_table was successfully built<br/>";
echo "</div>";
}
else{
echo "<div class='alert alert-error'>";
echo "ERROR Table $teams_table<br/>";
echo "</div>";
}
/*
* Table: team players
* This table to hold the members of a team
* 
**/
	$sql5 = "CREATE TABLE $team_player_table (
		id int NOT NULL AUTO_INCREMENT,
		PRIMARY KEY (id),
		playerid varchar(125),
		teamid varchar(125),
		joineddate date,
		isdelete int,
		cancel date,
		membertype int  
	)";
// Execute query
/*
* Creation of team player Table
*
**/
mysql_query($sql5,$con);
$sql4="SELECT* FROM $team_player_table";
$result=@mysql_query($sql4);
if($result)
{
echo "<div class='alert alert-success'>";
echo "Table $team_player_table was successfully built<br/>";
echo "</div>";
}
else{
echo "<div class='alert alert-error'>";
echo "ERROR Table $team_player_tables<br/>";
echo "</div>";
}
mysql_close($con);
?>