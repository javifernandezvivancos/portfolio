package muelles.elementos;

import java.util.LinkedList;
//import java.util.Random;

import muelles.escenario.Casilla;
//import muelles.escenario.Direccion;

/**
 * Representa al tipo enemigo Loco, encargado de conseguir todas las armas
 * que se encuentren en casillas visibles. Cuando consiga un arma se movera
 * a casillas aleatorias y activara su arma tambien de forma aleatoria.
 * @author Guadalupe Garca Fernandez y Javier Fernandez Vivancos.
 *
 */

public class Loco extends Enemigo{
	
	//Constructores:
	/**
	 * Constructor por defecto de loco. Llama al constructor por defecto
	 * de enemigo, no asignando ninguna casilla al mismo.
	 */
	public Loco(){
		super();
	}
	
	/**
	 * Constructor de loco. Llama al constructor de enemigo
	 * asignando la casilla introducida como parametro al mismo.
	 * @param casilla Casilla en la que se va a situar Loco.
	 */
	public Loco(Casilla casilla){
		super(casilla);
	}
	
	//modificadores:
	/**
	 * Implementacion del metodo accion() de la clase abstracta enemigo.
	 * El enemigo Loco avanza hasta la casilla visible mas cercana
	 * que contenga un arma. En el momento que la consiga, se movera a posiciones
	 * aleatorias de la planta y activara su arma de forma tambien aleatoria.  
	 */
/*	public void accion(){
		Random rnd = new Random();
		Elemento e1;
		
		int aleatorio = (int)(rnd.nextDouble()*4); //generamos un numero aleatorio entre 0 y 4

		if(!this.tieneArma()){
			e1=null;
			e1= this.masCercano(this.getPlanta().getArmasVisibles());
			if(e1!=null && e1 instanceof Arma){
				mover(casillaCercana(e1.getCasilla().getX(), e1.getCasilla().getY()));
			}
		}
		else{
			mover(Direccion.direccionAleatoria());
			if(aleatorio==0 || aleatorio==2)
				this.activarArma();
		}
	}*/
	
	/**
	 * Implementacion de los metodos abstractos de la clase enemigo para el
	 * metodo plantilla accion().
	 * @see muelles.elementos.Enemigo#accion().
	 */
	public LinkedList<Elemento> obtenerArmas(){
		return this.getPlanta().getArmasVisibles();
	}
	public boolean persigueArma() {
		if (!this.tieneArma())
			return true;
		return false;
	}
	
	
	/**
	 * Implementacion del metodo getImagen() de la interfaz Dibujable.
	 */
	public String getImagen(){
		return "loco";
	}
}
