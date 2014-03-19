<?php
/*
* members profile update/edit/profile image
*
*/
$member_test = function($params)
{
	return $params;
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
	$user = mysql_fetch_array($result);
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

$user_teams = function($params)
{
	include('confi/confi_info.php');
	$id = $params['id'];
// select * from teams, (select teamid from team_player where playerid=1) t where id=t.teamid
	$sql = "SELECT * FROM $teams_table, (SELECT teamid FROM $team_player_table WHERE playerid=$id) tp WHERE id=tp.teamid";
	$query = mysql_query($sql);
	$teams = array();
	while($row = mysql_fetch_array($query))
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
};

$get_user=function($params){
	/**
	*	This function to get specefic user
	*	
	*
	**/
};

$new_user=function($params){
	/**
	*	This function for creating new user with simple (informatuon)
	*	escap/encryption for privacy and security
	*
	**/	
	
	include('confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
 	//Required parameters
	$required = array("firstname","lastname","email","pass","day","month","year","gender");
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	// user full name
	$firstname=$params['firstname'];
	$lastname=$params['lastname'];
	//personal info
	$day=$params['day'];
	$month=$params['month'];
	$year=$params['year'];
		// set up user date of birth
		$newdate=$year.'-'.$month.'-'.$day;
		$birthdate=date("Y-m-d H:i:s", strtotime($newdate));
	$gender=$params['gender'];
	// account setting
	$email=$params['email'];
	$password=$params['pass'];
	//secure inputs 
	$firstname=mysql_real_escape_string($firstname);
	$lastname=mysql_real_escape_string($lastname);
	$pass=mysql_real_escape_string($password);
	//user account
	$UIC=uniqid(member);
	$salt=$UIC; // user account is unique and it used for crypt the user password
	$hashpw=crypt($password,$salt);
	$pass=$hashpw;
	$dateofregistration=date("Y/m/d"); // today's date
	$sql="INSERT INTO $users_table (uid,firstname,lastname,email,pass,birthdate,dateofregistration,gender,activation)VALUES ('$UIC','$firstname','$lastname','$email','$pass','$birthdate','$dateofregistration','$gender','0')";
if (!mysql_query($sql,$con))
	{
		//failing here
		return array("success" => false);
	}
  else
  {
	 // send a welcome message to the user
	 $message = "Hello! congratulation you have successfully created you account \n please
	 click on the link below to activate your account.";
	 sendMessage($emailaddress,$message);
	return array("success" => true);
  }
};

function sendMessage($to,$message){
	/**
	* sending a message to the user Email
	*	$to , $message
	*
	**/
$subject = "Test mail";
$from = "EMAIL_SENT_FROM@gmail.com";
$headers = "From:" . $from;
if(mail($to,$subject,$message,$headers))
	return array("success" => true);
	else
	return array("success" => false);
}

$uploadProfileImage=function($params){	
	/**
	* This function is to let the user Upload a profile image
	*
	**/
	include('confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
 	//Required parameters
	$required = array("userid","file");
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	// user ID
	$id=$params['userid'];
   // Simple PHP Upload Script:  http://coursesweb.net/php-mysql/
$uploadpath = 'profileimg/';      // directory to store the uploaded files
$max_size = 20000;          // maximum file size, in KiloBytes
$alwidth = 1200;            // maximum allowed width, in pixels
$alheight = 1200;           // maximum allowed height, in pixels
$allowtype = array('bmp', 'gif', 'jpg', 'jpe', 'png');        // allowed extensions

if(isset($_FILES['fileup']) && strlen($_FILES['fileup']['name']) > 1) {
  $uploadpath = $uploadpath.$id;       // gets the file name
  $sepext = explode('.', strtolower($_FILES['fileup']['name']));
  $type = end($sepext);       // gets extension
  $uploadpath=$uploadpath.".".$type;
  list($width, $height) = getimagesize($_FILES['fileup']['tmp_name']);     // gets image width and height
  $err = '';         // to store the errors
  // Checks if the file has allowed type, size, width and height (for images)
  if(!in_array($type, $allowtype)) $err .= 'The file: <b>'. $_FILES['fileup']['name']. '</b> not has the allowed extension type.';
  if($_FILES['fileup']['size'] > $max_size*1000) $err .= '<br/>Maximum file size must be: '. $max_size. ' KB.';
  if(isset($width) && isset($height) && ($width >= $alwidth || $height >= $alheight)) $err .= '<br/>The maximum Width x Height must be: '. $alwidth. ' x '. $alheight;
  // If no errors, upload the image, else, output the errors
  if($err == '') {
    if(move_uploaded_file($_FILES['fileup']['tmp_name'], $uploadpath)) { 
   	return array("success" => true);
    }
     return array("success" => false);
  }
  else echo $err;
}
};


$updateUserPassword=function($params){
	/**
	* This function update the user's Password
	**/
		include('confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
 	//Required parameters
	$required = array("userid","email","oldpass","newpass");
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	// parms
	$userID=$params['userid'];
	$OLD_PASSWORD=$params['oldpass'];
	$em=$params['email'];
	$newem=$params['newpass'];
	//secure
	$NEW_PASSWORD=mysql_real_escape_string($newem); ///new pass
	$OLD_PASSWORD=mysql_real_escape_string($newem); ///new pass
	$em=mysql_real_escape_string($em); ///email
	// salt
	$salt=$userID;
	$NEW_PASSWORD=crypt($NEW_PASSWORD,$salt); //new pass encrypted
	$OLD_PASSWORD=crypt($NEW_PASSWORD,$salt); //new pass encrypted
	//boolean success 0 is no 1 is yes
	$isActivat=0;
//check if userId+email+oldpass exist
$result = mysql_query("SELECT * FROM $users_table WHERE uid='$userID' AND emailaddress='$em' AND password='$OLD_PASSWORD'");
if($row = mysql_fetch_array($result)) 
  {
		$isActivat=1; // id exist and the user exist 
  }
  if($isActivat==1)
  {
	  	 //update the new pass
		$qry="UPDATE $users_table SET password='$NEW_PASSWORD' where uid='$userID'";
  		if(mysql_query($qry)){
			return array("success" => true);
		}
  }
  else{
			return array("success" => false); //account does not exist (pass or email) not correct
  }	
};
$updateUserEmail=function($params){
	/**
	* This function update the user's Email
	* It first check if the email already exist 
	* Also if the new one is not already registred
	* if both condition are correct then the user's email will be updated
	* This is not the complete code (need to convert it for API use)
	**/

		include('confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
 	//Required parameters
	$required = array("userid","email","pass","newemail");
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	// parms
	$userID=$params['userid'];
	$password=$params['pass'];
	$oldemail=$params['email'];
	$newemail=$params['newemail'];
	//secure
	$OLD_EMAIL=mysql_real_escape_string($oldemail); ///old email
	$NEW_EMAIL=mysql_real_escape_string($newemail); ///new email
	// salt
	$salt=$userID;
	$password=crypt($NEW_PASSWORD,$salt); //pass encrypted based on user ID
	//boolean success 0 is no 1 is yes
	$isActivat=0;
//check if userId+email+oldpass exist
$result = mysql_query("SELECT * FROM $users_table WHERE uid='$userID' AND emailaddress='$oldemail' AND password='$password'");
if($row = mysql_fetch_array($result)) 
  {
		$isActivat=1; // id exist and the user exist 
  }
  if($isActivat==1)
  {
	  	 //update the new pass
		$qry="UPDATE $users_table SET emailaddress='$NEW_EMAIL' where uid='$userID'";
  		if(mysql_query($qry)){
			return array("success" => true);
		}
  }
  else{
			return array("success" => false); //account does not exist (pass or email) not correct
  }	
};
$updateUserInfo=function($params){
	/**
	*	This function let the user update his information
	*   update public infor only not the account seetings
	*	remove any other personal info
	**/	
	include('confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
 	//Required parameters
	$required = array("userid","firstname","lastname","gender","dateofbirth","country","city","zipcode");
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	// parms
	$userid=$params['userid'];
	$firstname=$params['firstname'];
	$lastname=$params['lastname'];
	$gedner=$params['gedner'];
	$day=$params['day'];
	$month=$params['month'];
	$year=$params['year'];
	$country=$params['country'];
	$city=$params['city'];
	$zipcode=$params['zipcode'];	
	//secure
	$firstname=mysql_real_escape_string($firstname);
	$lastname=mysql_real_escape_string($lastname);
	$zipcode=mysql_real_escape_string($zipcode);
	//date
	$newdate=$year.'-'.$month.'-'.$day;
	$datebirth=date("Y-m-d H:i:s", strtotime($newdate));

	 $qry="UPDATE $users_table SET firstname='$firstname' AND lastname='$lastname' AND gender='$gender' AND dateofbirth='$dateofbirth' AND country='$country' AND city='$city'  AND zipcode='$zipcode' where emailaddress='$em' AND uid='$userid'";
        if(mysql_query($qry))
		{
			echo "information was updated";
					return array("success" => true);
		}
		else
		{
			echo "couldn't update your information";
					return array("success" => false);
		}
};

$deActivateuserAccount=function($params){	
	/**
	*	This function De-activate user account
	*   it turns his name into --> user last name --> empty
	*	remove any other personal info
	**/
	include('confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
 	//Required parameters
	$required = array("userid","email","pass");
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	// parms
	$userid=$params['email'];
	$em=$params['email'];
	$pass=$params['pass'];
//boolean success 0 is no 1 is yes
$isActivat=0;
//check if user id and email exist + the is activated
$result = mysql_query("SELECT * FROM $users_table WHERE userid='$userid' activation=1 AND emailaddress='$em'");

if($row = mysql_fetch_array($result))
  {
	  //deactivate the account change the user name
	  	$qry="UPDATE $users_table SET activation = 0 AND firstname='user' AND lastname='-removed' where emailaddress='$em'";
        if(mysql_query($qry))
		$isDeActivat=1; // Deactivation was done correctly
		else
		$isDeActivat=-1;		
  }
  
  if($isDeActivate==1)
  {
		echo "Your account is deactivated now";
					return array("success" => true);
  }
  else
   if($isDeActivat==-1)
  {
		echo "Sorry, for some reason we couldn't deactivate your account";
					return array("success" => false);
  }
  else
  		echo "Your account infor is not correct"; //we assume it is activated
			return array("success" => false);
};


$activate_account=function($params){
	/**
	*	This function recieves email+user ID 
	*	it check if the user exist
	*   then check if the link was reached in (speceific time) 24 hours
	*   This iss a draft :: the function will be converted later today
	**/
	//get email and user id
	
	include('confi/confi_info.php');
	$con = mysql_connect($host_name,$user_name,$user_pass);
 	//Required parameters
	$required = array("userid","email");
	if(!$has_params($params, $required)) //Ensures $params contains requirements
		return array("err" => "Invalid parameters passed. Expected ".json_encode($required));
	// parms
	$em=$params['userid'];
	$id=$params['pass'];
//boolean success 0 is no 1 is yes
$isActivat=0;
//check if user id and email exist + the activation is not equal to 1
$result = mysql_query("SELECT * FROM $users_table WHERE uid='$id' AND email='$em'");
while($row = mysql_fetch_array($result))
  {
	  return $params;
  $sign_date=$row['dateofregistration'];
  $todays_date=date("Y-m-d");
  $today = strtotime($todays_date);
  $old_date = strtotime($sign_date);
  if($today-($old_date+10)<(60*60*48)){
	 
	  	//if within 48 hours activate account
		$qry="UPDATE $users_table SET activation = 1 where emailaddress='$em'";
		
        if(mysql_query($qry))
		$isActivat=1; // activation was done correctly
		}
		else
		{
		//if 48 hours is passed remove account
		$qry="DELETE FROM $table_members WHERE activation = 0 AND emailaddress='$em'";
        mysql_query($qry) ;
		$isActivat=-1; // activation was NOT done correctly
		}
  }
  if($isActivat==1)
  {
		echo "Your account is activated now";
					return array("success" => true);
  }
  else
   if($isActivat==-1)
  {
		echo "Sorry, You have to signup again";
					return array("success" => false);
  }
  else
  		echo "Your account is already activated"; //we assume it is activated
			return array("success" => false);
};

$member_in_events=function($params){
	/**
	* this function returns all events the user went to
	* from table players ((get all rows  where the required user exist)) get it in order (new to old)
	* 
	**/
};
$member_events=function($params){
	/**
	* This function returns all events the user have created
	* from table events ((get all rows  where the required user exist)) get it in order (new to old)
	* 
	**/
};
$member_teams=function($params){
	/**
	* This function returns all temas that is owned by the user
	* from table teams ((get all rows  where the required user exist)) get it in order (new to old)
	* 
	**/
};

$member_teammember=function($params){
	/**
	* This function returns all temas that user is a member of it
	* from table events ((get all rows  where the required user exist)) get it in order (new to old)
	* 
	**/
};
?>
