<?php
/*
* Events functions
*
*/
$event_test = function($params)
{
	return $params;
};

$add_event=function($params){
	/** This function create a new events
	* 	it needs many fields
	**/
	include('confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
	
 	//Required parameters
	$required = array("title","sport","dategame","start","end","minage","maxage","gender","address","zip","type","minplayer","maxplayer","range","regtype","ownerid");
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	
	$title=$params['title'];
	$sport=$params['sport'];
	$dategame=$params['dategame'];
	$start=$params['start'];
	$end=$params['end'];
	$minage=$params['minage'];
	$maxage=$params['maxage'];
	$gender=$params['gender'];
	$address=$params['address'];
	$zip=$params['zip'];
	$type=$params['type'];
	$minPlayer=$params['minplayer'];
	$maxPlayer=$params['maxplayer'];
	$range=$params['range'];
	$regType=$params['regtype'];
	$ownerID=$params['ownerid'];
	$date=date("Y/m/d"); 
	$uid=md5(uniqid(rand(), true)); 
	
	//we check if it's possible to create the event with this player	
	if($ownerID==NULL){
		return array("err" => "The owner can't be null");		
	}
	$exist = mysql_num_rows(mysql_query("SELECT * FROM $users_table WHERE '$ownerID'=uid"));
	if(!$exist)		//we check if the event exists
		return array("err" => "The player ".$ownerID." doesn't exists ");
	
	
	$sql="INSERT INTO $events_table (uid,Title,Sport,Date,Startingtime,Endingtime,
	Agemin,Agemax,Gender,Address,Zipcode,Gametype,Playersmin,Playersmax,Locationrange
	,Registrationtype,Ownerid,Dateofcreation) VALUES ('$uid','$title','$sport','$dategame','$start','$end','$minage','$maxage','$gender','$address','$zip','$type','$minPlayer','$maxPlayer','$range','$regType','$ownerID','$date')";
	if (!mysql_query($sql,$con))
	{
		//failing here
		return array("success" => false);
	}
	else 
	{
		// if the event created then add the owner to the event
		if(join_event($uid,$ownerID)){
			return get_event($uid); 
			//return array("success"=>true);
		}
		else
			return array("success" => false);	
	}
};

$get_events=function($params){
	/** This function returns all events + the members who are attempting these event
	*	For no we are not testing if the event is in the future
	*	For the demo will will just check all the events 
	*	it requires no entry
	**/
	
	include('confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
	$results = mysql_query("SELECT * FROM $events_table");
	$events = array();
	
	while($row = mysql_fetch_array($results))
 	{
		$eventID=$row['uid'];
		$event_members = mysql_query("SELECT * FROM $event_player_table WHERE uid='$eventID'");
		$allplayersID="";
		while($players = mysql_fetch_array($event_members))
		{
			if($allplayersID=="")
				$allplayersID=$players['uid'];
			else
				$allplayersID=$allplayersID.",".$players['uid'];
		}
	 	$event = array(
			"title" => $row['Title'],
			"sport" => $row['uid'],
			"date" => $row['Date'],
			"start" => $row['Startingtime'],
			"end" => $row['Endingtime'],
			"agemin" => $row['Agemin'],
			"agemax" => $row['Agemax'],
			"gender" => $row['Gender'],
			"address" => $row['Address'],
			"zipcode" => $row['Zipcode'],
			"type" => $row['Gametype'],
			"playermin" => $row['Playersmin'],
			"playermax" => $row['Playersmax'],
			"range" => $row['Locationrange'],
			"regdate" => $row['Registrationtype'],
			"founder" => $row['Ownerid'],
			"players" => $allplayersID,
			"date_founded" => $row['Dateofcreation'],
		);
		array_push($events, $event);
 	}	 
	return $events;
};

function join_event($eventID,$playerID){
//$join_event=function($params){	
	/** This function to add a player to a given event 
	* 	it requires the event unique ID + the player ID
	**/
	include('confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);

	$date=date("Y/m/d"); 
	$sql="INSERT INTO $event_player_table(uid,Playerid,Playertype,Date)VALUES('$eventID','$playerID','0','$date')";
	if (!mysql_query($sql,$con))
	{
		return array("success" => FALSE);
	}
	else return array("success" => TRUE);
};

$cancel_event=function($params){
	/**	This function cancel an event
	*	it requires the owner id
	*	only owner can cancel their events
	*	when the owner cancels the event all joined players to that event will be

	* 	deleted from table players.
	*	this can be done by looping with leave event(each member ID, the event ID)
	**/
	include('confi/confi_info.php');
	
	$required = array("eventid"); 		//Required parameters
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
		
	//variables
	$eventID=$params['eventid'];
	$con = mysql_connect($host_name,$user_name,$user_pass);
	$error = array("err" => "Couldn't remove event ".$eventID);	
	$error2 = array("err" => "Couldn't remove event ".$eventID." but the event is empty.");
	
	//code
	if(!mysql_query("DELETE FROM $event_player_table WHERE uid='$eventID'"))
		return $error;
	
	if(!mysql_query("DELETE FROM $events_table WHERE uid='$eventID'"))
		return $error2;
	else
		return true;	
};

$leave_event=function($params){
	/**	This function allows the joined player to leave an event
	*	it requires the event ID + player ID
	*   
	**/		
	include('confi/confi_info.php');
	$required = array("eventid","playerid");	
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	$eventID=$params['eventid'];
	$playerID=$params['playerid'];
	
	$con = mysql_connect($host_name,$user_name,$user_pass);
	//cehck if player and Event Exist
	$results = mysql_query("SELECT * FROM $event_player_table WHERE uid='$eventID' AND Playerid='$playerID'");
	if(!$row = mysql_fetch_array($results))
 	{
		return $event = array("success" => false);
	}
	else
	{
		//delete the player from the event
	  	$results = mysql_query("DELETE FROM $event_player_table WHERE UID='$eventID' AND Playerid='$playerID'");
		return $event = array("success" => true);
	}
};

$remove_player=function($params){
	/**
	*	remove player from an event
	*	requires $eventID,$playerID
	*   This function is similar to leave_event but this is used by
	*  the owner of the event only
	**/
	include('confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
	$required = array("eventid","playerid");
	 //Required parameters
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	$eventID=$params['eventid'];
	$playerID=$params['playerid'];
	$sql="DELETE FROM $event_player_table WHERE uid='$eventID' AND Playerid='$playerID'";
	if (!mysql_query($sql,$con))
	{
		return array("success" => FALSE);
	}
	else return array("success" => TRUE);
};

$add_player=function($params){
	/**
	*	add player to an event
	*	$eventID,$playerID
	*
	**/
	include('confi/confi_info.php');
	//$con = mysql_connect($host_name,$user_name,$user_pass);		
	$required = array("eventid","playerid");
	
	 //Required parameters
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	$eventID=$params['eventid'];
	$playerID=$params['playerid'];
	$error2 = array("err" => "The player ".$playerID." is already into the event ".$eventID);
	$error3 = array("err" => "The event ".$eventID." does not exists.");
	$error4 = array("err" => "The player ".$playerID." does not exists.");
	$date=date("Y/m/d");

	//check if it's possible to add the player into the event	
	$exist = mysql_num_rows(mysql_query("SELECT * FROM $event_player_table WHERE '$eventID'=uid AND '$playerID'=Playerid"));
	if($exist)		//we check if the player is already into the event
		return $error2;	
	$exist = mysql_num_rows(mysql_query("SELECT * FROM $events_table WHERE '$eventID'=uid"));
	if(!$exist)		//we check if the event exists
		return $error3;	
	$exist = mysql_num_rows(mysql_query("SELECT * FROM $users_table WHERE '$playerID'=uid"));
	if(!$exist)		//we check if the event exists
		return $error4;	 
		
	//UID in event_player_table is UNIQUE AND IT DOESN'T HAVE TO BE.
	if (!mysql_query("INSERT INTO $event_player_table(uid,Playerid,Playertype,Date)VALUES('$eventID','$playerID','0','$date')"))
	{
		return array("success" => FALSE);
	}
	else return array("success" => TRUE);
};

/**
*	update_event
*	receive: id of the event to be updated
*	date, location.. every fields can be changed
*	true if everything was ok
**/
$update_event=function($params){
	//set-up and exeptions
	include('confi/confi_info.php');
	$required = array("uid"); //Required parameters
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	
	//variables
	$uid = $params['uid'];
	$error2 = array("err" => "The event ".$uid." does not exists ");
	$columnNames = array();
	
	//check if the id passed exists in the database
	$exist = mysql_num_rows(mysql_query("SELECT * FROM $events_table WHERE '$uid'=uid"));
	if(!$exist)		//we check first if the event exists
		return $error2;
	
	//store the columnNames in an array called columnNames
	$query = mysql_query("SELECT column_name FROM information_schema.columns WHERE table_name = 'events'");
	while($row = mysql_fetch_array($query))
		array_push($columnNames, $row);
	$query = mysql_query("SELECT * FROM $events_table WHERE uid = '$uid'");	
	$values = mysql_fetch_array($query);
	
	//update all the values which have been given.
	$i= 0;
	foreach ($columnNames as $columnName){			//check each given param
		$required= array($columnNames[$i][0]);
		if($has_params($params, $required)){		//if we recieve a param
			$value= $params[$columnNames[$i][0]];	//we take the value of the param
			$query= mysql_query("UPDATE $events_table SET $columnName[0]='$value' WHERE uid='$uid'");
		}
		$i++;
	}
	return true;	
};

function get_event($eventID){
//$get_event=function($params){
	/** This function retuns the information of a required event 
	* 	it requires the event unique ID
	*	from table events we get the event info
	*	from playes table we get joined players
	**/
	include('confi/confi_info.php');
	$results = mysql_query("SELECT * FROM $events_table WHERE uid='$eventID'");
	$event = array("success" => false);
	if($row = mysql_fetch_array($results))
 	{
		$event_members = mysql_query("SELECT * FROM $event_player_table WHERE uid='$eventID'");
		$allplayersID="";
		while($players = mysql_fetch_array($event_members))
		{
			if($allplayersID=="")
				$allplayersID=$players['uid'];
			else
				$allplayersID=$allplayersID.",".$players['uid'];
		}
		$event = array(
			"title" => $row['Title'],
			"sport" => $row['uid'],
			"date" => $row['Date'],
			"start" => $row['Startingtime'],
			"end" => $row['Endingtime'],
			"agemin" => $row['Agemin'],
			"agemax" => $row['Agemax'],
			"gender" => $row['Gender'],
			"address" => $row['Address'],
			"zipcode" => $row['Zipcode'],
			"type" => $row['Gametype'],
			"playermin" => $row['Playersmin'],
			"playermax" => $row['Playersmax'],
			"range" => $row['Locationrange'],
			"regdate" => $row['Registrationtype'],
			"founder" => $row['Ownerid'],
			"players" => $allplayersID,
			"date_founded" => $row['Dateofcreation'],
		);
		$event = array("success" => true, "event" => $event);
 	}
	return $event;
}

$search_event=function($params){
	/*
	* to search upcoming events
	* 1- search [by name] requires a [name] ============> for now
	* 2- search [by location] requires a [zipcode] ==========> for now
	* 3- search [by sport] requires a [sport name] ==========> for now
	* 4- search [by range location] requires [zipcode]+[miles range] 
	* 5- search [by future date] requires [date]
	* 6- also, allowing filtering the results [advanced search]
	**/
};

?>
