<?php
/* User login
 * 
 *
 **/
//Check that correct post data is passed
//return get_user() if all POST is set
if($_SERVER['REQUEST_METHOD'] == 'POST')
	echo json_encode(get_user($_POST['email'], $_POST['password']));

function get_user($email, $pass)
{	
	include('../confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
	if (!$con)	die('Could not connect: ' . mysql_error());
	mysql_select_db($data_name, $con);
	mysql_query("SET NAMES 'utf8'");
	mysql_query('SET CHARACTER SET utf8');
	mysql_set_charset('utf8');
	$result = mysql_query("SELECT * FROM $users_table WHERE email='$email' AND pass='$pass'");
	if(mysql_num_rows($result) != 1) // user & email does exist
	{
		mysql_close($con);
		return array("success" => FALSE, "data" => array("email" => $email, "password" => $pass));
		// return values as an object (email/pass)
	}
	$row = mysql_fetch_array($result);
	$user_id=$row['uid'];
	$user = user_from_row($row);
	mysql_close($con);
	return array("success" => TRUE, "user"=>$user); 
}
function get_user_byid($uid)
{
	include('./confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
	if (!$con)
		die('Could not connect: ' . mysql_error());
	mysql_select_db($data_name, $con);
	mysql_query("SET NAMES 'utf8'");
	mysql_query('SET CHARACTER SET utf8');
	mysql_set_charset('utf8');
	$result = mysql_query("SELECT * FROM $users_table WHERE uid='$uid'");
	return $result;
	if(mysql_num_rows($result) != 1)
	{	
		mysql_close($con);
		return array("success" => FALSE);
	}
	$row = mysql_fetch_array($result);
	$user_id=$row['uid'];
	$user = user_from_row($row);
	mysql_close($con);
	return array("success" => TRUE, "user"=>$user);
}
function user_from_row($row)
{	
	include('./listteams.php');
	return array(
		"uid" => $row['uid'],
		"username" => "hboylan",
		"firstname" => $row['firstname'],
		"lastname" => $row['lastname']
	);
}

?>
