<?php session_start();
$userID=$_SESSION['userid']; // we can use JSON to get the current user ID
$oldpass=$_POST['oldpass'];
$newpass=$_POST['newpass'];
$NEW_PASSWORD=mysql_real_escape_string($newpass); ///new pass
$oldpass=mysql_real_escape_string($oldpass); //old pass
$salt=$userID; // we user user ID as salt for password encrypt
$oldpass=crypt($oldpas,$salt); //encrypt the old password based on the user ID
$NEW_PASSWORD=crypt($NEW_PASSWORD,$salt); //encrypt the new password based on the user ID
//boolean success 0 is no 1 is yes
$isActivat=0;
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
//double check if the user do exist
$result = mysql_query("SELECT * FROM $users_table WHERE  uid='$userID' AND pass='$oldpass'");
if($row = mysql_fetch_array($result)) 
  {
		$isActivat=1; // id exist and old password exist
  }
  if($isActivat==1)
  {
	  	 //update the current password if and only if the old password does exist
		$qry="UPDATE $users_table SET pass='$NEW_PASSWORD' where uid='$userID'";
  		mysql_query($qry) ;
echo "<div class='alert alert-success'>
 Your Password was succesfully updated 
</div>";
  }
  else{
  echo "<div class='alert alert-error'>
 Sorry! Your password was NOT! updated 
</div>";
  }
  mysql_close($con);
?>

