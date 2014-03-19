<?php
/* CREATING A NEW USER
 *
 *
 **/
include('../confi/confi_info.php');	
include('./login.php');
if($_SERVER['REQUEST_METHOD'] == 'POST')
	echo json_encode(new_user($_POST[firstname], $_POST[lastname], $_POST[email], $_POST[password]));

function new_user($first, $last, $email, $pass)
{
	$con = mysql_connect($host_name,$user_name,$user_pass);
	//UNIQUE ID
	$uid=md5(uniqid(rand(), true));
	//UNIQUE CODE
	$UAC=md5(uniqid(rand(), true));
	//Today's date
	$date=date("y/d/m");
	$con = mysql_connect($host_name,$user_name,$user_pass);
	if (!$con)
	  {
	  echo "<div class='alert alert-error'>";
	  die('Could not connect: ' . mysql_error());
	  echo "</div>";
	  }
	mysql_select_db($data_name, $con);
	mysql_query("SET NAMES 'utf8'"); 
	mysql_query('SET CHARACTER SET utf8');
	mysql_set_charset('utf8');
	
	$sql="INSERT INTO $users_table (uid,firstname,lastname,email,pass) VALUES('$uid','$first','$last','$email','$pass')";
	if (!mysql_query($sql,$con))
	{
		mysql_close($con);
		return array("success" => FALSE);
	}
	$user_id = $uid;

	mysql_close($con);
	return array("id" => $user_id);
}

?>