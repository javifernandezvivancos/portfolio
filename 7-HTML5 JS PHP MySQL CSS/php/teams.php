<?php

/* Functions List:
 * add_team - 
 * delete_team - uid
 */

$team_test = function($params)
{
	return $params;
};


$get_teams=function($params)
{	
	 /** This function returns all teams + all players per team
	 *	it requires nothing
	 *	it first get the name id of the a team 
	 *	search for its member table
	 *  get all members and team information
	 *	return the result back
	 **/
	include('confi/confi_info.php');
	$result = mysql_query("SELECT * FROM $teams_table");
	$teams = array();
	while($row = mysql_fetch_array($result)){
		array_push($teams, $row);
	}
	return $teams;
};

$add_team = function($params)
{
	/** This function create a new team
	* 	it requires, the name of the team + the id of the the current user
	*	a unique ID will be generated fo the the new team
	*	the new team's info will be insrted into teams table
	*	the function also create a member table for the team
	*	This function returns what get_team (current function) returns...
	**/
	//set-up and exeptions
	include('confi/confi_info.php');	
	$required = array("name", "owner"); //Required parameters
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));

	//variables
	$name=$params['name'];
	$owner=$params['owner'];
	$uid=md5(uniqid(rand(), true));
	$date=date("y/d/m");
	$error= array("err" => "The team has been created but the user couldn't be added.");
	$error2= array("err" => "The team ".$name." already exist.");
	$error3= array("err" => "SQL INSERT Failed.");
	
	//code
	$exist = mysql_num_rows(mysql_query("SELECT * FROM $teams_table WHERE '$name'=teamname"));
	if($exist)		//we check first if the player is already into the team
		return $error2;	
	
	$query=mysql_query("INSERT INTO $teams_table (uid,Teamname,sports,Ownerid,Creationdate) VALUES ('$uid','$name','','$owner','$date')");
	if(!$query)
	{
		return $error3;
	}
	else
	{
		$id = mysql_insert_id();	
		if(add_player2($id, $owner))
			return $GLOBALS['get_team'](array("teamid" => $id));
		else 
			return $error;
	}
};
function add_player2($teamID,$playerID){
	/** This function to add a player to a given team 
	* 	it requires the team unique ID + the player ID
	*	JUST TO BE USED INSIDE OF TEAMS.PHP
	**/
	//set-up	
	include('confi/confi_info.php');	
	
	//variables used
	$date=date("y/d/m");
	$error1 = array("err" => "Couldn't add player: ".$playerID." to team: ".$teamID);
	$error2 = array("err" => "The player ".$playerID." is already into the team ".$teamID);

	//code
	$exist = mysql_num_rows(mysql_query("SELECT * FROM $team_player_table WHERE '$playerID'=playerid AND '$teamID'=teamid"));
	if($exist)		//we check first if the player is already into the team
		return true;
		
	$insert= mysql_query("INSERT INTO $team_player_table (teamid,playerid,Joineddate,Membertype) VALUES ('$teamID','$playerID','$date','0')");
	if(!$insert)	//we insert the user into the team
		return false;
	else
		return true;
}



$add_player = function($params){
	/** This function to add a player to a given team 
	* 	it requires the team unique ID + the player ID
	**/
	
	//set-up and exception control
	include('confi/confi_info.php');	
	$required = array("teamid", "playerid"); //Required parameters	
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
		
	//variables used
	$teamID=$params['teamid'];
	$playerID=$params['playerid'];
	$date=date("y/d/m");
	$error1 = array("err" => "Couldn't add player: ".$playerID." to team: ".$teamID);
	$error2 = array("err" => "The player ".$playerID." is already into the team ".$teamID);

	//code
	$exist = mysql_num_rows(mysql_query("SELECT * FROM $team_player_table WHERE $playerID=playerid AND $teamID=teamid"));
	if($exist)		//we check first if the player is already into the team
		return $error2;
		
	$insert= mysql_query("INSERT INTO $team_player_table (teamid,playerid,Joineddate,Membertype) VALUES ('$teamID','$playerID','$date','0')");
	if(!$insert)	//we insert the user into the team
		return $error1;
		else
			return true;
			
};

$remove_player=function($params){
	/** This function to remove a player to a given team 
	* 	it requires the team unique ID + the player ID
	**/
	
	//set-up
	include('confi/confi_info.php');	
	$required = array("teamid", "playerid"); //Required parameters
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
		
	//variables
	$teamID=$params['teamid'];
	$playerID=$params['playerid'];	
	$error = array("err" => "Couldn't remove: ".$playerID." to team: ".$teamID);	
	$error2 = array("err" => "The player ".$playerID." is not into the team ".$teamID);
	
	//code
	$exist = mysql_num_rows(mysql_query("SELECT * FROM $team_player_table WHERE $playerID=playerid AND $teamID=teamid"));
	if(!$exist)		//we check first if the player is into the team
		return $error2;
		
	if(!mysql_query("DELETE FROM $team_player_table WHERE playerid='$playerID' AND teamid='$teamID'"))
		return $error;
		else
			return true;	
};

$delete_team=function($params){
	/*
	*	remove all players from team
	*	delete the team from teams
	*	it recieves the teamid
	*/
	//set-up
	include('confi/confi_info.php');	
	$required = array("teamid"); //Required parameters
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
		
	//variables
	$teamID=$params['teamid'];	
	$error = array("err" => "Couldn't remove team ".$teamID);	
	$error2 = array("err" => "Couldn't remove team ".$teamID." but the team is empty.");
	
	//code
	if(!mysql_query("DELETE FROM $team_player_table WHERE teamid='$teamID'"))
		return $error;
	
	if(!mysql_query("DELETE FROM $teams_table WHERE id='$teamID'"))
		return $error2;
		else
			return true;	
};

$find_teams=function($params)
{
	/**
	* search teams based on name (for now)
	*
	**/
	//set-up
	include('confi/confi_info.php');	
	$required = array("teamname"); //Required parameters
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
		
	//variables
	$teamName=$params['teamname'];
	$error = array("err" => "Impossible to find the team ".$teamName);	//error to be shown
	$teams = array();	//array of teams found
	
	//code
	$result = mysql_query("SELECT * FROM $teams_table WHERE '$teamName'=teamname");
	if(!$result)		//we check first if everything was all right
		return $error;		
	
	while($row = mysql_fetch_array($result)){
		array_push($teams, $row);
	}
	return $teams;
};

$get_team = function($params)
{ 
	/** This function retuns the information of a required team 
	* 	it requires the team unique ID
	*	from table members we get the team info
	*	from team table we get the players 
	**/
	//set-up
	include('confi/confi_info.php');
	$required = array("teamid"); //Required parameters
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	
	//variables
	$id = $params['teamid'];
	$t_query = mysql_query("SELECT * FROM $teams_table WHERE id=$id");
	$p_query = mysql_query("SELECT DISTINCT * FROM $users_table, (SELECT DISTINCT playerid FROM $team_player_table WHERE teamid=$id) tp WHERE tp.playerid=id");	
	//$p_query = mysql_query("SELECT * FROM $users_table, (SELECT DISTINCT * FROM $team_player_table) tp WHERE tp.teamid=$id");
	//Parse p_query results
	$players = array();
	while($row = mysql_fetch_array($p_query))
		array_push($players, $row);
	return array(
		"team" => mysql_fetch_array($t_query),
		"players" => $players,
	);
};


$update_team=function($params)
{
	/**
	* updaste team information
	*/
};

$search_teams=function($params)
{
	/**
	* Advanced searching
	*/
	include('confi/confi_info.php');	
	$required = array("fields", "values"); //Required parameters
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	//variables
	$fields=$params['fields']; // example playerid,teamid
	$values=$params['values']; // example the user ID value, the team ID
	
	//fields are sepreate by comma, we can turn it to an array 
	//values are sperated by comma, we can turn it to an array
	//Then what to search double loops we print '+the field[#]+' plus = then values[#] plust AND
	// But if the loop is about to end we ignore addint AND
	
	$what_to_search="'$playerID'=playerid AND '$teamID'=teamid";
	$search = mysql_num_rows(mysql_query("SELECT * FROM $team_player_table WHERE $what_to_search"));
	if($search){
		echo "Show results";
		return array("success" => true);
	}
	else
	{
		echo "Sorry No results";
		return array("success" => false);
	}
};

?>