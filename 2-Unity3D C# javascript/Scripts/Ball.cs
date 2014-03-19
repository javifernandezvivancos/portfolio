using UnityEngine;
using System.Collections;

public class Ball : MonoBehaviour {
	//--Attributes
	private float percent;
	private int color;
	private bool hidden;
	private Scene scene;
	
	//--Get
	public int getColor(){
		return color;
	}	
	public float getPercent(){
		return percent;
	}
	public bool sameColor(Ball ball){
		if(this.getColor()== ball.getColor()){
			return true;
		}
		return false;
	}
	public bool isVisible(){
		return !hidden;
	}
	
	//-Set
	public void hide(){
		hidden= true;
		renderer.enabled= false;
	}
	public void unHide(){
		hidden= false;
		renderer.enabled= true;
	}
	public void setPercent(float percent){
		this.percent= percent;
	}
	public void setColor(int color){
		this.color= color;
	}
	
	//--Unity
	// Use this for initialization
	void Start () {
		percent= 0.0f;
		scene= (Scene)FindObjectOfType(typeof(Scene));
	}
	
	// Update is called once per frame
	void Update () {
	}
	void OnCollisionStay(Collision collision) {
		bool collisionWithLineBall= scene.getPath().containsRigidBody(collision.rigidbody);
		
		if(collision!=null && collision.rigidbody!=null && this.rigidbody!=null){	//there is a collision..		
			scene = (Scene)FindObjectOfType(typeof(Scene));
			//if there is a collision between the shooted ball and a lineball..
			if((!collisionWithLineBall)&&(collision.gameObject!=scene.gameObject)){
				scene.shootCollision(collision.rigidbody, this.rigidbody);	//we send the shooted ball and the victim ball
			}
		}
    }
}
