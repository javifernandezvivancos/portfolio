<?php
	

if($_SERVER['REQUEST_METHOD'] == 'POST'){
	if($_POST['action']=="create"){
		$result = '';
		if(!isset($_POST['name']) || !isset($_POST['uid']))
			$result = array("success" => FALSE);
		else
			$result = create_team($_POST['name'],$_POST['uid']);
		echo json_encode($result);
	}	
}

function get_teams()
{
	 /** This function returns all teams + all players per team
	 *	it requires nothing
	 *	it first get the name id of the a team 
	 *	search for its member table
	 *  get all members and team information
	 *	return the result back
	 **/
	include('../confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	mysql_select_db($data_name, $con);
	mysql_query("SET NAMES 'utf8'"); 
	mysql_query('SET CHARACTER SET utf8');
	mysql_set_charset('utf8');
	
	$result = mysql_query("SELECT * FROM $teams_table");
	$teams = array();
	while($row = mysql_fetch_array($result)){
		$myteam_table="members_".$row['uid'];
		$team_members = mysql_query("SELECT * FROM $myteam_table");
		$allplayersID="";
		while($players = mysql_fetch_array($team_members))
				{
		if($allplayersID=="")
		$allplayersID=$players['uid'];
		else
		$allplayersID=$allplayersID.",".$players['uid'];
			}
			$allplayersID=explode(",",$allplayersID);
		$team = array(
			"name" => $row['teamname'],
			"uid" => $row['uid'],
			"players" => $allplayersID,
			"founder" => $row['Ownerid'],
			"date_founded" => $row['Creationdate'],
		);
		array_push($teams, $team);
	}
	mysql_close($con);
	return $teams;
}

function create_team($name,$owner)
{
	/** This function create a new team
	* 	it requires, the name of the team + the id of the the current user
	*	a unique ID will be generated fo the the new team
	*	the new team's info will be insrted into teams table
	*	the function also create a member table for the team
	*	This function returns what get_team (current function) returns...
	**/
	
	include('../confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	mysql_select_db($data_name, $con);
	mysql_query("SET NAMES 'utf8'"); 
	mysql_query('SET CHARACTER SET utf8');
	mysql_set_charset('utf8');
	
	$uid=md5(uniqid(rand(), true)); 
	$date=date("y/d/m"); 
	$sql="INSERT INTO teams (uid,teamname,Sportslist,Ownerid,Creationdate) VALUES ('$uid','$name','','$owner','$date')";
	if (!mysql_query($sql,$con))
	{
		return array("success" => false);
	}
	else 
	{
		if(build_membertable("members_".$uid)){
		add_player($uid,$owner); // add the owner to be a member of a team 
		return get_team($uid); 
		}
		else
		return array("success" => false);
		
	}
}

function build_membertable($member_table)
{
		/** This function to build a team table
		*	it requres the team ID
		**/
	
	include('../confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	mysql_select_db($data_name, $con);
	mysql_query("SET NAMES 'utf8'"); 
	mysql_query('SET CHARACTER SET utf8');
	mysql_set_charset('utf8');
	
$sql = "CREATE TABLE $member_table
(
ID int NOT NULL AUTO_INCREMENT,
PRIMARY KEY (ID),
uid varchar(125),
Joineddate date,
Membertype int,
UNIQUE(uid)
)";
if(!mysql_query($sql,$con)){
	return false;
}
else
	return true;


	
}

function drop_player($teamID,$playerID)
{
		/** This function to drop a player from a given team
		*	it requires the team unique ID + the player ID
		*
		*
		**/
		include('../confi/confi_info.php');
		$con = mysql_connect($host_name,$user_name,$user_pass);
		if (!$con)
		{
		die('Could not connect: ' . mysql_error());
		}
		mysql_select_db($data_name, $con);
		mysql_query("SET NAMES 'utf8'"); 
		mysql_query('SET CHARACTER SET utf8');
		mysql_set_charset('utf8');
		
		$myteam_table="members_".$teamID;
		$team_members = mysql_query("DELETE FROM $myteam_table WHERE uid='$playerID'");
		if(!mysql_query($team_members,$con))
				{
				return array("success" => FALSE);
				}
				else return array("success" => TRUE);
}

function add_player($teamID,$playerID){
	
	/** This function to add a player to a given team 
	* 	it requires the team unique ID + the player ID
	**/
	
	include('../confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	mysql_select_db($data_name, $con);
	mysql_query("SET NAMES 'utf8'"); 
	mysql_query('SET CHARACTER SET utf8');
	mysql_set_charset('utf8');
	

		$date=date("y/d/m"); 
		$myteam_table="members_".$teamID;
		$sql="INSERT INTO $myteam_table(uid,Joineddate,Membertype)VALUES('$playerID','$date','0')";
	if (!mysql_query($sql,$con))
	{
			return array("success" => FALSE);
		}
		else return array("success" => TRUE);
}


function get_team($teamID)
{ 
	/** This function retuns the information of a required team 
	* 	it requires the team unique ID
	*	from table members we get the team info
	*	from team table we get the players 
	**/
	
	include('../confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	mysql_select_db($data_name, $con);
	mysql_query("SET NAMES 'utf8'"); 
	mysql_query('SET CHARACTER SET utf8');
	mysql_set_charset('utf8');
	
	$result = mysql_query("SELECT * FROM $teams_table WHERE uid='$teamID'");
	$team = array("success" => FALSE);
	if($row = mysql_fetch_array($result)){
		$myteam_table="members_".$teamID;
		$team_members = mysql_query("SELECT * FROM $myteam_table");
		$allplayersID="";
		while($players = mysql_fetch_array($team_members))
				{
		if($allplayersID=="")
		$allplayersID=$players['uid'];
		else
		$allplayersID=$allplayersID.",".$players['uid'];
			}
			$allplayersID=explode(",",$allplayersID);
		$team = array(
			"name" => $row['teamname'],
			"uid" => $row['uid'],
			"players" => $allplayersID,
			"founder" => $row['Ownerid'],
			"date_founded" => $row['Creationdate'],
		);
		$team = array("success" => TRUE, "team" => $team);
	}
	return $team;
}



?>
