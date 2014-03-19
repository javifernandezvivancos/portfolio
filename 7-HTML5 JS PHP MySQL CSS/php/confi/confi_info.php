<?php
/* THIS FILE INCLUDE THE DATABASE INFORMATION
 * 
 *
 **/
$data_name='MyDemoSport';
$host_name='localhost';
$user_name="root";
$user_pass="root";
$teams_table="teams";
$event_player_table="event_player";
$team_player_table="team_player";
$users_table="users";
$events_table="events";

$user_id="";

$has_params = function($params, $req)
{
	for($i = 0; $i < count($req); $i++)
		if(!isset($params[$req[$i]]))
			return FALSE;
	return TRUE;
}

?>