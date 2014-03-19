#pragma strict

function OnGUI(){
	if(GUI.Button(Rect(0,0,200,100),"BASIC LEVEL \n (hit 3 balls in a row)")){
		Application.LoadLevel ("level1");
	}
	if(GUI.Button(Rect(210,0,200,100),"SHORT TERM MEMORY \n (remember the bullets \n you have)")){
		Application.LoadLevel ("level2");
	}	
	if(GUI.Button(Rect(420,0,200,100),"WORKING MEMORY \n (remember the bullets \n in reverse)")){
		Application.LoadLevel ("level3");
	}
	if(GUI.Button(Rect(210,110,200,100),"INHIBITION \n (don't hit the yellow  \n spotted ball)")){
		Application.LoadLevel ("level4");
	}
	if(GUI.Button(Rect(420,110,200,100),"COG. FLEX. \n (click 'S' if you see the \n 3 same special balls")){
		Application.LoadLevel ("level5");
	}
	if(GUI.Button(Rect(620,110,200,100),"CREDITS!!")){
		Application.LoadLevel ("credits");
	}
}