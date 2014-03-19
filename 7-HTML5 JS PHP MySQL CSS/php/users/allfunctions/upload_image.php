<?php

/**
to upload the profile picture of the user
just get the current user ID
and let $id ==> the current use ID

to get the profile picture of the user
just get the current user ID
it would look like this

upload/userID.jpg  for now we are just alloweing jpg 
//////////////////////
session_start();
if(isset($_SESSION['userid']))  
	$id=$_SESSION['userid']; // we need the user ID to rename the uploaded image to his ID
	else // we can use JSON object to replace this
		die();
		
		**/
$id="mypicture"; // this can change to get the value of the currect user ID
	
// Simple PHP Upload Script:  http://coursesweb.net/php-mysql/ 
$uploadpath = 'upload/';      // directory to store the uploaded files
$max_size = 2000;          // maximum file size, in KiloBytes
$alwidth = 900;            // maximum allowed width, in pixels
$alheight = 800;           // maximum allowed height, in pixels
//$allowtype = array('bmp', 'gif', 'jpg', 'jpe', 'png');        // allowed extensions
$allowtype = array('jpg'); //for now we will only allow jpg 
/**
we can allow gif,png but we will need to create another field on the user (table)
that includes the type of image he have uploaded
**/

if(isset($_FILES['fileup']) && strlen($_FILES['fileup']['name']) > 1) {
  $uploadpath = $uploadpath.$id;       // gets the file name and append the user ID
  $sepext = explode('.', strtolower($_FILES['fileup']['name']));
  $type = end($sepext);       // gets extension
  $uploadpath=$uploadpath.".".$type; //then append the type 
 
  list($width, $height) = getimagesize($_FILES['fileup']['tmp_name']);     // gets image width and height
  $err = '';         // to store the errors

  // Checks if the file has allowed type, size, width and height (for images)
  if(!in_array($type, $allowtype)) $err .= 'The file: <b>'. $_FILES['fileup']['name']. '</b> not has the allowed extension type.';
  if($_FILES['fileup']['size'] > $max_size*1000) $err .= '<br/>Maximum file size must be: '. $max_size. ' KB.';
  if(isset($width) && isset($height) && ($width >= $alwidth || $height >= $alheight)) $err .= '<br/>The maximum Width x Height must be: '. $alwidth. ' x '. $alheight;

  // If no errors, upload the image, else, output the errors
  if($err == '') {
    if(move_uploaded_file($_FILES['fileup']['tmp_name'], $uploadpath)) { 
	/**
      echo 'File: <b>'. basename( $_FILES['fileup']['name']). '</b> successfully uploaded:';
      echo '<br/>File type: <b>'. $_FILES['fileup']['type'] .'</b>';
      echo '<br />Size: <b>'. number_format($_FILES['fileup']['size']/1024, 3, '.', '') .'</b> KB';
      if(isset($width) && isset($height)) echo '<br/>Image Width x Height: '. $width. ' x '. $height;
      echo '<br/><br/>Image address: <b>http://'.$_SERVER['HTTP_HOST'].rtrim(dirname($_SERVER['REQUEST_URI']), '\\/').'/'.$uploadpath.'</b>';
	  **/
   echo "<button class='btn btn-success btn-large' type='button' style='margin:50px; 50px;'
   onClick='goBack()'>back to profile</button>";

    }
    else echo '<b>Unable to upload the file.</b>';
  }
  else echo $err;
}
?> 
<div style="margin:1em auto; width:333px; text-align:center;">
 <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST" enctype="multipart/form-data"> 
  Upload File: <input type="file" name="fileup" /><br/>
  <input type="submit" name='submit' value="Upload" /> 
 </form>
</div>
