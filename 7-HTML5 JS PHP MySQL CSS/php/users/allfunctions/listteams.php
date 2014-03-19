<?php
if($_SERVER['REQUEST_METHOD'] == 'POST'){
	
}

function get_teams()
{
	include('./confi/confi_info.php');
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
		$allplayersID=$allplayersID.",".$players['uid'];
			}
			$allplayersID=explod(",",$allplayersID);

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


?>
