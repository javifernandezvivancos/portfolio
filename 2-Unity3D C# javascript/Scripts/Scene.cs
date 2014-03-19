using UnityEngine;
using System.Collections.Generic;

public class Scene : MonoBehaviour {
	
	//--Atributes
	public bool BallDeath;										//BallDeath mode?
	public bool reverse;										//the balls are generated in reverse mode
	public bool cashMachine;
	public float rememberTime;									//how many seconds the user has to remember (0 to non-memoryTime mode)
	public float speed;											//speed of the line
	public int MaxNumberOfBalls;								//number of balls which are going to appear
		
	private CashMachine cashmachine;
	private int numShotedBalls;									//number of balls shoted after the last stop
	private Ball shootedBall;									//shooterBall (the only one which can be added to the line)
	private Path path;											
	private Shooter shooter;	
	private float nextFireTime;									//when will be the next time when the user will shoot.
	private bool frozen;										//shows when the scene is frozen
	
	//--get functions
	public Shooter getShooter(){
		return shooter;
	}
	public Ball getShootedBall(){
		return shootedBall;
	}
	public Path getPath(){
		return path;
	}
	public float getRememberTime(){
		return rememberTime;
	}
	public bool isFrozen(){
		return frozen;
	}
	//--Set functions
	public void setShootedBall(Ball ball){
		shootedBall= ball;
	}	
	public void addShoot(){		
		numShotedBalls++;
	}
	public void resetNumOfShootedBalls(){
		numShotedBalls= 0;	
	}
	
	//--Functionality	
	void win(){
		Application.LoadLevel ("menu");
	}
	void loose(){
		Application.LoadLevel ("menu");
	}
	bool move(){	
		bool noBallsAnymore= path.isEmpty()&&path.getNumberOfBalls()==MaxNumberOfBalls;
		bool justDeathBall= (path.getNumberOfBalls()==1&&path.getFirst().getColor()==4);
		bool finalBallFinished= (path.getLast().getPercent()>1f);
		
		if(noBallsAnymore||justDeathBall){							//winning conditions
			win ();
			return false;
		}
		if(finalBallFinished){										//if the balls finished the line
			loose();
			return false;
		}
		path.createBall();
		path.move();
		return true;
	}
	public void punishment(){
		speed= speed*2;
	}
	public void shootCollision(Rigidbody shootedBall, Rigidbody victimBall){	//we send the shooted ball and the victim ball
		path.introduceBall(path.getBall(victimBall));
	}
	public void moveAndHide(){
		frozen= false;
		shooter.hideBalls();
		move();	
		if(numShotedBalls>=shooter.getNumberOfBullets()){
			nextFireTime= Time.time+rememberTime;
			resetNumOfShootedBalls();
		}
	}
	public void stopAndShow(){
		frozen= true;
		shooter.showBalls();
		path.keepStatic();
	}
	
	//--Unity
	void Start () {
		//reverse= false;
		//speed = 0.0003f;										//speed of the line
		//MaxNumberOfBalls= 20;									//number of balls which are going to appear
		//BallDeath= true;										//Balldeath mode?
		shooter = (Shooter)FindObjectOfType(typeof(Shooter));	//find the shooter
		path = (Path)gameObject.AddComponent ("Path");			//add the path
		numShotedBalls= 0;		
		nextFireTime= Time.time+rememberTime;
		if(cashMachine==true){
			cashmachine = (CashMachine)gameObject.AddComponent ("CashMachine");			//add the path
		}	
	}
	void Update () {
		if(rememberTime==0){
			move ();
		}
		else{
			if(Time.time>nextFireTime){
				moveAndHide();
			}
			else{
				stopAndShow();
			}	
		}
	}
}