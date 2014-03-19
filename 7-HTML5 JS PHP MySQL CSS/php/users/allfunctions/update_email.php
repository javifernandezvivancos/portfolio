<?php
$em=$_POST['email']; //old email
$newem=$_POST['newemail']; // new email
//boolean success 0 is no 1 is yes
$isActivat=1;
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
//check if the new email is not used before
$result = mysql_query("SELECT * FROM $users_table WHERE  email='$newem'");
if($row = mysql_fetch_array($result)) 
  {
		$isActivat=0; // the new email does exist	
  }
  if($isActivat==1)
  {
	  	 //update the new email/ if the new email does not exist
		$qry="UPDATE $users_table SET emailaddress='$newem' where email='$em'";
        mysql_query($qry) ;
		
		/// I will need to change this to JSON
echo "<div class='alert alert-success'>
 Your Email was succesfully updated 
</div>";
  }
  else{
  echo "<div class='alert alert-error'>
 Sorry! Your Email was NOT! updated 
</div>";
  }
  
  mysql_close($con);
?>

