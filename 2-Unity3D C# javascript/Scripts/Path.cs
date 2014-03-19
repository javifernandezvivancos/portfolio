using UnityEngine;
using System.Collections.Generic;

public class Path : MonoBehaviour {
	//Atributes
	private LinkedList<Ball> balls;								//list of lineBalls
	private int numberOfBalls;									//iterator
	private float distance;										//distance against each ball
	private Vector3 firstPosition;								//first position ball
	private Scene scene;										//scene
		
	//Get
	public bool containsRigidBody(Rigidbody rigidBodyBall){
		foreach (Ball item in balls)
		{
	    	if(item!=null && item.rigidbody.Equals(rigidBodyBall)){
				return true;
			}
		}
		return false;		
	}	
	public Ball getLast(){
		return balls.Last.Value;
	}
	public Ball getFirst(){
		return balls.First.Value;
	}
	public Ball getBall(Rigidbody rigidBodyBall){
		foreach (Ball item in balls)
		{
			if(item!=null){
	    		if(item.rigidbody.Equals(rigidBodyBall)){
					return item;
				}
			}
		}
		return null;
	}
	public bool isEmpty(){
		if(balls.Count==0){
			return true;
		}
		else{
			return false;
		}
	}
	public int getNumberOfBalls(){
		return numberOfBalls;
	}
	
	//Functions
	public void shiftBalls(Ball indexBall){
		LinkedListNode<Ball> ball= balls.Find (indexBall);
		while(ball.Next!=null){	//moves all the balls an exception of the last one
			ball.Value.setPercent(ball.Next.Value.getPercent());
			ball= ball.Next;
		}
		ball.Value.setPercent(ball.Value.getPercent()+distance);
		
	}
	private void recoverPositions(LinkedListNode<Ball> pivot){
		while(pivot!=null && pivot.Next!=null){
			pivot.Next.Value.setPercent(pivot.Value.getPercent()+distance);
			pivot= pivot.Next;
		}
	}
	public void createBall(){
		if((balls.First.Value.getPercent()>distance||balls.Count==0) && numberOfBalls<scene.MaxNumberOfBalls){//if we have to create a new ball
			Ball ball;
			if(numberOfBalls==scene.MaxNumberOfBalls/2 && scene.BallDeath){
				ball= scene.getShooter().createBall(firstPosition,true,true);
			}
			else{
				ball= scene.getShooter().createBall(firstPosition, true, false);				
			}
			balls.AddFirst(ball);	
			numberOfBalls++;
		}
	}
	private void exploteBalls(LinkedListNode<Ball> firstNodeToExplote, int numberOfBallsToExplote){
		LinkedListNode<Ball> explotedNode= firstNodeToExplote;
		LinkedListNode<Ball> pivot= firstNodeToExplote.Previous;
		if(numberOfBallsToExplote>2){
			for(int i= 0; i<numberOfBallsToExplote; i++){
				explotedNode= firstNodeToExplote;
				firstNodeToExplote= firstNodeToExplote.Next;	
				balls.Remove(explotedNode);		
				Destroy(explotedNode.Value.gameObject);
				scene.setShootedBall(null);
			}
			recoverPositions(pivot);
		}
	}
	public void addBefore(LinkedListNode<Ball> node, Ball shootedBall){
		balls.AddBefore(node,shootedBall);	//first we add the ball to the list
		
		LinkedListNode<Ball> firstNodeToExplote= balls.Find(shootedBall);
		LinkedListNode<Ball> lastNodeToExplote= balls.Find(shootedBall);
		
		int numberOfBallsToExplote= 1;	
		while((firstNodeToExplote.Previous!=null) && (firstNodeToExplote.Previous.Value.sameColor(shootedBall))){ //we check the right side
			firstNodeToExplote= firstNodeToExplote.Previous;
			numberOfBallsToExplote++;
		}
		while((lastNodeToExplote.Next!=null)&&(lastNodeToExplote.Next.Value.sameColor(shootedBall))){
			lastNodeToExplote= lastNodeToExplote.Next;
			numberOfBallsToExplote++;
		}		
		exploteBalls(firstNodeToExplote, numberOfBallsToExplote);
		
	}
	public void introduceBall(Ball victimBall){
		if(victimBall!=null && scene.getShootedBall()!=null){
			if(victimBall.getColor()==4){					//if the ball hited is the deathBall
				scene.punishment();
			}
			else{										//if not..
				scene.getShootedBall().setPercent(victimBall.getPercent());
				shiftBalls(victimBall);
				addBefore(balls.Find(victimBall),scene.getShootedBall());
			}
		}
	}
	public void move(){		
		foreach (Ball item in balls)
		{
			if(item!=null){
				item.setPercent(item.getPercent()+scene.speed);
				iTween.PutOnPath(item.gameObject, iTweenPath.GetPath("path1"), item.getPercent());
			}
		}
	}
	public void keepStatic(){
		foreach (Ball item in balls)
		{
			if(item!=null){
				item.setPercent(item.getPercent());
				iTween.PutOnPath(item.gameObject, iTweenPath.GetPath("path1"), item.getPercent());
			}
		}
	}
	
	// Use this for initialization
	void Start () {
		float number= iTween.PathLength(iTweenPath.GetPath("path1"));
		
		scene = (Scene)FindObjectOfType(typeof(Scene));		
		distance= (1f/number);	
		balls = new LinkedList<Ball>();
		balls.AddFirst(scene.getShooter().createBall(firstPosition,true,false));	//Add first ball to the path
		firstPosition= iTween.PointOnPath(iTweenPath.GetPath("path1"), 0.0f);
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}