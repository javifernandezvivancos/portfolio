<?php
include('confi/confi_info.php');

$request = '';
$resp = '';

$type = $_SERVER['REQUEST_METHOD'];
if($type == 'POST') // POST Request
{
	$request = $_POST;
}
else if($type == 'GET') // GET Request
{
	$request = $_GET;
}
else if($type == 'DELETE')
{
	$request = $_DELETE;
}

if(isset($request['script']) && isset($request['action']))
{
	$script = $request['script']; // Declares which php script to call from
	$action = $request['action']; // Declares which function to call within the script
	
	include($script . '.php'); // Include requested script
	if(isset($action)) // Requested function exists
	{
		// Init DB connection
		$con = mysql_connect($host_name,$user_name,$user_pass);
		if(!$con)
		{
			die('Could not connect: ' . mysql_error());
		}
		mysql_select_db($data_name);
		mysql_set_charset('utf8');

		// Call user-requested function
		$function = $GLOBALS[$action];
		if(!isset($function))
			$resp['err'] = "Function: ".$action." does not exist";
		else
			$resp = $function($request);
		
		// End DB connection
		mysql_close($con);
	}
	else
		$resp['err'] = "Function not found";
}
else
	$resp['err'] = "Check script/action variables";

echo json_encode($resp);

?>