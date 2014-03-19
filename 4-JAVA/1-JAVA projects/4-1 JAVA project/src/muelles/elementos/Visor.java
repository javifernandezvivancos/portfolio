package muelles.elementos;

import java.util.*;
import muelles.escenario.Casilla;

/**
 * Representa el tipo de arma Visor. Esta arma se encarga de mostrar
 * las casillas adyacentes al Personaje.
 * @author Javier Fernandez Vivancos y Guadalupe Garcia Fernandez.
 *
 */
public class Visor extends Arma{
	
	/**
	 * Constructor por defecto de Visor. Llama al constructor
	 * de Arma, no asignandole ninguna casilla ni ningun 
	 * propietario.
	 */
	public Visor (){
		this(null,null);
	}
	
	/**
	 * Constructor de Visor. Llama al constructor de Arma, 
	 * asignandole una casilla pasada como parametro, pero
	 * ningun propietario.
	 * @param casilla Casilla en la que se va a encontrar el visor.
	 */
	public Visor (Casilla casilla){
		this(casilla, null);
	}
	
	/**
	 * Constructor de Visor. Llama al constructor de Arma, 
	 * asignandole una casilla y el propietario
	 * pasados como parametro.
	 * @param casilla Casilla en la que se va a encontrar el visor.
	 * @param propietario Propietario del visor.
	 */
	public Visor (Casilla casilla, Personaje propietario){
		super(casilla, propietario);
	}
	
	/**
	 * Implementacion del metodo accion() de la clase abstracta Arma.
	 * Este metodo se encargara de implementar la funcionalidad del
	 * visor.
	 */
	public void activar(){
		
		LinkedList <Casilla> lista=getPlanta().getCasillasAdyacentes(getPosicionX(), getPosicionY());
		
		for (Casilla casillaLista : lista) {
			if (casillaLista.isVisible()==false){
				casillaLista.mostrar();
			}
		}
	}
	
	/**
	 * Implementacion del metodo getImagen() de la interfaz Dibujable.
	 * Si la casilla en la que se encuentra la antorcha no es visible
	 * no se mostrara nada.
	 */
	public String obtenerImagen(){
			return "visor";	
	}
}