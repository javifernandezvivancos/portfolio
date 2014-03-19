<?php

include('confi_info.php');
$con = mysql_connect($host_name,$user_name,$user_pass);
if(!$con)
{
	die('Could not connect: ' . mysql_error());
}
mysql_select_db($data_name);
mysql_set_charset('utf8');


function insert_users($users)
{
	include('../users.php');
	for($i = 0; $i < count($users); $i++){
		$next = $users[$i];
		$params = array("first" => $next[0], "last" => $next[1], "email" => $next[2], "pass" => $next[3]);
		// $GLOBALS['add_user']($params);
		echo "Added User: ".json_encode($params)."<br>";
	}
}

insert_users(array(
	array("Dan", "Sweeney", "email@email.com", "password"),
	array("Dan", "Sweeney", "email@email.com", "password")
));


echo "Finished";

mysql_close($con);
?>