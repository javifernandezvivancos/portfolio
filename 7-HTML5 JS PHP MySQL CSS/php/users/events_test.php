<?php
if($_SERVER['REQUEST_METHOD'] == 'POST'){
	if($_POST['action']=="create"){
		$result = '';
		if(!isset($_POST['name']))
			$result = array("success" => false);
		else
			$result = new_event($_POST['name'],
			'n','n','n','n','n','n','n','n','n','n','n','n','n',
			'n',$_POST['uid']);
		echo json_encode($result);
	}	
}


function new_event($title,$sport,$dategame,$start,$end,$minage,$maxage,$gender,$address
,$zip,$type,$minPlayer,$maxPlayer,$range,$regType,$ownerID){
	
	/** This function create a new events
	* 	it needs many fields
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
	$date=date("Y/m/d"); 
	$sql="INSERT INTO $events_table (uid,Title,Sport,Date,Startingtime,Endingtime,
	Agemin,Agemax,Gender,Address,Zipcode,Gametype,Playersmin,Playersmax,Locationrange
	,Registrationtype,Ownerid,Dateofcreation) VALUES ('$uid','$title','$sport','$dategame','$start','$end','$minage','$maxage','$gender','$address','$zip',
	'$type','$minPlayer','$maxPlayer','$range','$regType','$ownerID','$date')";
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
		}
		else
			return array("success" => false);	
	}
}

function get_events(){
	/** This function returns all events + the members who are attempting these event
	*	For no we are not testing if the event is in the future
	*	For the demo will will just check all the events 
	*	it requires no entry
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
	
	$results = mysql_query("SELECT * FROM $events_table");
	$events = array();
	while($row = mysql_fetch_array($results))
 	 {
		$eventID=$row['uid'];
		$event_members = mysql_query("SELECT * FROM $players_table WHERE uid='$eventID'");
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
			"start" => $row['Startintime'],
			"end" => $row['endingtime'],
			"agemin" => $row['Agemin'],
			"agemax" => $row['Agemax'],
			"gender" => $row['Gender'],
			"address" => $row['Address'],
			"zipcode" => $row['Zipcode'],
			"type" => $row['Gametype'],
			"playermin" => $row['Playermin'],
			"playermax" => $row['Playermax'],
			"range" => $row['Locationrange'],
			"regdate" => $row['Registrationtype'],
			"founder" => $row['Ownerid'],
			"players" => $allplayersID,
			"date_founded" => $row['Dateofcreation'],
		);
		array_push($events, $event);
 	 }


}

function join_event($eventID,$playerID){
	
	/** This function to add a player to a given event 
	* 	it requires the event unique ID + the player ID
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
		$date=date("Y/m/d"); 
		$sql="INSERT INTO $players_table(uid,Playerid,Playertype,Date)VALUES('$eventID','$playerID','0','$date')";
	if (!mysql_query($sql,$con))
	{
			return array("success" => FALSE);
		}
		else return array("success" => TRUE);
}

function cancel_event($onwer){
	/**	This function cancel an event
	*	it requires the owner id
	*	only owner can cancel their events
	*	when the owner cancels the event all joined players to that event will be
	* 	deleted from table players.
	*	this can be done by looping with leave event(each member ID, the event ID)
	**/
}

function leave_event($eventID,$playerID){
	/**	This function allows the joined player to leave an event
	*	it requires the event ID + player ID
	*
	**/
	
	
}

function get_event($eventID){
	/** This function retuns the information of a required event 
	* 	it requires the event unique ID
	*	from table events we get the event info
	*	from playes table we get joined players
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
	
	$results = mysql_query("SELECT * FROM $events_table WHERE uid='$eventID'");
	$event = array("success" => false);
	if($row = mysql_fetch_array($results))
 	{
		$event_members = mysql_query("SELECT * FROM $players_table WHERE uid='$eventID'");
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
			"start" => $row['Startintime'],
			"end" => $row['endingtime'],
			"agemin" => $row['Agemin'],
			"agemax" => $row['Agemax'],
			"gender" => $row['Gender'],
			"address" => $row['Address'],
			"zipcode" => $row['Zipcode'],
			"type" => $row['Gametype'],
			"playermin" => $row['Playermin'],
			"playermax" => $row['Playermax'],
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
?>
