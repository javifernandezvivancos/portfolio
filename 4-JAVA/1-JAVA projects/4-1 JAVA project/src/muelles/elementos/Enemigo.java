package muelles.elementos;

import java.util.LinkedList;
import java.util.Random;

import muelles.escenario.Casilla;
import muelles.escenario.Direccion;

/**
 * Clase abstracta que implementaran representa los diferentes enemigos que va a contener 
 * el juego. Los enemigos seran: LOCO y VIDENTE. 
 * @author Guadalupe Garca Fernandez y Javier Fernandez Vivancos.
 */
public abstract class Enemigo extends Personaje{
	//Constructores:
	/**
	 * Constructor de enemigo que llama al constructor por defecto
	 * de personaje, es decir, de elemento, no asignando ninguna casilla
	 * al enemigo. 
	 */
	public Enemigo(){
		super();
	}
	
	/**
	 * Constructor de enemigo que llama al constructo de personaje, asignando
	 * la casilla pasada como parametro al enemigo.
	 */
	public Enemigo(Casilla casilla){
		super(casilla);
	}
	
	/**
	 * Metodo asbtracto accion() que representa la funcion que tiene
	 * cada uno de los distintos tipos de enemigos. 
	 */
	public void accion() {
		Elemento e1= this.masCercano(this.obtenerArmas());
		if ((e1!=null) && (this.persigueArma()==true)) {
			mover(casillaCercana(e1.getCasilla().getX(), e1.getCasilla().getY()));
		}
		else if ((e1!=null) && (this.persigueArma()==false)) {
			Random rnd = new Random();
			int aleatorio = (int)(rnd.nextDouble()*4); //generamos un numero aleatorio entre 0 y 4
			mover(Direccion.direccionAleatoria());
			if(aleatorio==0 || aleatorio==2)
				this.activarArma();
		}
		
	}
	
	protected abstract LinkedList<Elemento> obtenerArmas();
	protected abstract boolean persigueArma();
	
}
