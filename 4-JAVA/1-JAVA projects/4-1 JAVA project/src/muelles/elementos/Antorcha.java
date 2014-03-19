package muelles.elementos;

import muelles.escenario.Direccion;
import muelles.escenario.Casilla;
import java.util.LinkedList;
import java.util.Random;
import java.lang.System;

/**
 * Representa al elemento Antorcha, arma que lanza elementos
 * de tipo proyectil. Antorcha es un tipo de Arma, por lo que hereda
 * de la misma e implementa la interfaz Autonomo.
 * @author Javier Fernandez Vivancos y Guadalupe Garcia Fernandez.
 *
 */
public class Antorcha extends Arma implements Autonomo{
	
	private Direccion direccion;
	private double tiempo;
	private final int nsegs=3;
	
	/**
	 * Constructor de Antorcha. Establece por defecto que la
	 * casilla es nula y no tiene propietario.
	 * @param direccion Direccion en la que va a lanzar los proyectiles
	 */
	public Antorcha (Direccion direccion){
		this(null, null, direccion);		
	}
	
	/**
	 * Constructor de Antorcha. Establece por defecto que la
	 * que no tiene propietario. Se le pasan como parametros la
	 * casilla en la que se encuentra y la direccion de la antorcha.
	 * @param casilla Casilla en la que se va a encontrar la Antorcha.
	 * @param direccion Direccion en la que va a lanzar los proyectiles
	 */
	public Antorcha (Casilla casilla, Direccion direccion){
		this(casilla, null, direccion);
	}
	
	/**
	 * Constructor de Antorcha. Llama al constructor de arma
	 * y establece el valor del parametro tiempo.
	 * @param casilla Casilla en la que se va a encontrar la Antorcha.
	 * @param propietario Propietario de la Antorcha.
	 * @param direccion Direccion en la que va a lanzar los proyectiles.
	 */
	public Antorcha (Casilla casilla, Personaje propietario, Direccion direccion){
		super(casilla, propietario);
		this.direccion= direccion;
		tiempo=System.currentTimeMillis()/1000;
	}
	
	
	/**
	 * Implementacion del metodo activar() de la clase Arma.
	 * Un arma de tipo Antorcha, al activarse lanza elementos de
	 * tipo proyectil en una dirección fija.
	 */
	public void activar(){		
		Proyectil proyectil;
		Casilla casillaProyectil= this.getCasilla();
		if (direccion==Direccion.ABAJO){
			casillaProyectil= getPlanta().getCasilla(getPosicionX(), getPosicionY()-1);
		}
		else if (direccion==Direccion.ARRIBA){
			casillaProyectil= getPlanta().getCasilla(getPosicionX(), getPosicionY()+1);
		}
		else if (direccion==Direccion.DERECHA){
			casillaProyectil= getPlanta().getCasilla(getPosicionX()+1, getPosicionY());
		}
		else if (direccion==Direccion.IZQUIERDA){
			casillaProyectil= getPlanta().getCasilla(getPosicionX()-1, getPosicionY());
		}
		
		if(casillaProyectil!=null){
			proyectil= new Proyectil(casillaProyectil, direccion);
			proyectil.getPosicionX();//Esto es simplemente para que no d el warning
		}
	}
	
	/**
	 * Implementacion del metodo accion() de la interfaz Autonomo.
	 * Se comprueba si han transcurrido al menos 3 segundos desde el ultimo
	 * movimiento, y si es asi se mueve a una casilla aleatoria.
	 */
	public void accion(){
		if ((System.currentTimeMillis()/1000)-tiempo>=nsegs){
			//Obtenemos las casillas adyacentes...
			LinkedList<Casilla> casillasAdyacentes= getPlanta().getCasillasAdyacentes(this.getPosicionX(), this.getPosicionY());
			LinkedList<Casilla> casillasAdyacentesVacias=new LinkedList<Casilla>();
			Random rnd = new Random();
			int posicionAleatoria;
			//y nos quedamos con las que estn vacas
			for(Casilla casilla :casillasAdyacentes){
				if(!casilla.isLlena()){
					casillasAdyacentesVacias.add(casilla);
				}
			}
			//nos movemos a una casilla aleatoria vaca de las adyacentes
			if(!casillasAdyacentesVacias.isEmpty()){
				posicionAleatoria= (int)(rnd.nextDouble()*casillasAdyacentesVacias.size());
				mover(casillasAdyacentesVacias.get(posicionAleatoria));						
			}
			tiempo=System.currentTimeMillis()/1000;		
		}		
	}
	
	/**
	 *  Implementacion del metodo getImagen de la interfaz Dibujable.
	 *  Si la casilla en la que se encuentra la antorcha no es visible
	 *  no se mostrara nada.
	 */
	public String obtenerImagen() {
			if (direccion==Direccion.ABAJO) {
				return "antorcha-abajo";
			}
			else if (direccion==Direccion.ARRIBA){
				return "antorcha-arriba";
			}
			else if (direccion==Direccion.DERECHA){
				return "antorcha-derecha";
			}
			else {
				return "antorcha-izquierda";
			}
	}
}
