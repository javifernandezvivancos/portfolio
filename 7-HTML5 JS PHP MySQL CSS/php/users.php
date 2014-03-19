<?php

/* Functions List:
 * get_user - email, pass
 * add_user - first, last, email, pass
 * delete_user - uid, pass?
 */

$test = function($params)
{
	return array();
};

$get_user = function($params)
{
/**
*	receive email, pass
*	returns user	
**/
	//setup
	include('./confi/confi_info.php');
	$resp = array("success" => FALSE);	
	$required = array("email", "pass"); //Required parameters
	if(!$has_params($params, $required)){ //Ensures $params contains requirements
		$resp['err'] = "Invalid parameters passed. Expected ".json_encode($required);
		return $resp;
	}
	
	//variables	
	$email = $params['email'];
	$pass = $params['pass'];
	$error= array("err" => "The player ".$email." does not exist or password is wrong");
	
	//code
	$result = mysql_query("SELECT * FROM $users_table WHERE email='$email' AND pass='$pass'");
	if(!$result){ //Request failed
		return "failed";
	}
	if(!mysql_num_rows($result)){
		return $error;
	}	
	
	//get actual age value
	$user = mysql_fetch_array($result, MYSQL_ASSOC);
	$bday = new DateTime($user['birthdate']);
	$user['age'] = $bday->diff(new DateTime)->y;
	return $user;
};

$user_by_id = function($params)
{
	include('confi/confi_info.php');
	$id = $params['id'];
	
	$sql = "SELECT * FROM $users_table WHERE id='$id'";
	$query = mysql_query($sql);
	if(!$query)
		return $sql;
	return array(
		"user" => mysql_fetch_array($query),
		"teams" => $GLOBALS['user_teams'](array("id" => $id))
	);
};

$add_user = function($params)
{
	include('./confi/confi_info.php');
	$resp = array("success" => FALSE);
	
	$required = array("first", "last", "email", "pass");
	if(!$has_params($params, $required)){
		$resp['err'] = "Invalid parameters passed. Expected ".json_encode($required);
		return $resp;
	}
	
	$uid = $uid=md5(uniqid(rand(), true));
	$first = $params['first'];
	$last = $params['last'];
	$email = $params['email'];
	$pass = $params['pass'];
	$query = "INSERT INTO $users_table (uid,firstname,lastname,email,pass,city,state,sports) VALUES('$uid','$first','$last','$email','$pass','Morgantown','WV','')";
	if(!mysql_query($query)){
		$resp['err'] = $query;
		return $resp;
	}
	
	return $GLOBALS['get_user']($params);
};

$user_teams = function($params)
{
	include('confi/confi_info.php');
	$id = $params['id'];
// select * from teams, (select teamid from team_player where playerid=1) t where id=t.teamid
	$sql = "SELECT * FROM $teams_table, (SELECT teamid FROM $team_player_table WHERE playerid=$id) tp WHERE id=tp.teamid";
	$query = mysql_query($sql);
	$teams = array();
	while($row = mysql_fetch_array($query, MYSQL_ASSOC))
		array_push($teams, $row);
	return $teams;
};

/**
*	Edit an user, it needs the ID
*	and field(s) to change the value.
*	
**/
$edit_user = function($params){
	//set-up and exeptions
	include('confi/confi_info.php');
	$required = array("id"); //Required parameters
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	
	//variables
	$id = $params['id'];
	$error2 = array("err" => "The player ".$id." does not exists ");
	$columnNames = array();
	
	//check if the id passed exists in the database
	$exist = mysql_num_rows(mysql_query("SELECT * FROM $users_table WHERE $id=id"));
	if(!$exist)		//we check first if the player is already into the team
		return $error2;
	
	//store the columnNames in an array called columnNames
	$query = mysql_query("SELECT column_name FROM information_schema.columns WHERE table_name = 'users'");
	while($row = mysql_fetch_array($query))
		array_push($columnNames, $row);	
	$query = mysql_query("SELECT * FROM users WHERE id = '$id'");	
	$values = mysql_fetch_array($query);
	
	//update all the values which have been given.
	$i= 0;
	foreach ($columnNames as $columnName){				//check each given param
		$required= array($columnNames[$i][0]);
		if($has_params($params, $required)){		//if we recieve a param
			$value= $params[$columnNames[$i][0]];	//we take the value of the param
			$query= mysql_query("UPDATE $users_table SET $columnName[0]='$value' WHERE id=$id");
		}
		$i++;
	}
	return true;	
}

?>