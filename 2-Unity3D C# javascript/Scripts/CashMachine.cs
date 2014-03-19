using UnityEngine;
using System.Collections;

public class CashMachine : MonoBehaviour {
	
	private Shooter shooter;
	private Scene scene;
	private Vector3[] positions;
	private Ball[] balls;
	private int numberOfBalls;	
	private float updateTime;
	private float nextUpdate;
	
	
	private void award(){
	}
	// Use this for initialization
	void Start () {
		numberOfBalls= 3;
		updateTime= 3;
		nextUpdate= Time.time+updateTime;
		shooter = (Shooter)FindObjectOfType(typeof(Shooter));	
		scene= (Scene)FindObjectOfType(typeof(Scene));	
		positions= new Vector3 [numberOfBalls];
		positions[0]= new Vector3(-16,2,-12);
		positions[1]= new Vector3(-15,2,-12);
		positions[2]= new Vector3(-14,2,-12);
		balls= new Ball[numberOfBalls];
		regenerateBalls();
	}
	private bool sameColorBalls(){
		if((balls[0].getColor()==balls[1].getColor()) && (balls[1].getColor()==balls[2].getColor())){
			return true;
		}
		return false;
	}
	private void regenerateBalls(){
		for(int i=0;i<numberOfBalls;i++){
			if(balls[i]!=null){
				Destroy(balls[i].gameObject);
			}
			balls[i]= shooter.createBall(positions[i],false,false);
		}
	}
	
	// Update is called once per framek
	public void Update () {		
		if(Input.GetKeyDown(KeyCode.S)){
			if(sameColorBalls()){
				award();
			}
			else{
				scene.punishment();
			}
			regenerateBalls();
     		nextUpdate= Time.time+updateTime;
		}
		else if(Time.time>nextUpdate){
			if(sameColorBalls()){
				scene.punishment();				
			}
			regenerateBalls();
     		nextUpdate= Time.time+updateTime;
		}
	}
}
