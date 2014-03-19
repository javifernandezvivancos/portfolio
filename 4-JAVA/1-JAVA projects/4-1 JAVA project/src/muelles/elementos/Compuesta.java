package muelles.elementos;

import java.util.LinkedList;

import muelles.escenario.Casilla;

/**
 * Representa al Arma compuesta. Este arma tiene la caracteristica
 * de que el personaje que la consiga podra ir acumulando armas que se
 * vaya encontrando.
 * @author Javier Fernandez Vivancos y Guadalupe Garcia Fernandez.
 *
 */
public class Compuesta extends Arma{
	
	private LinkedList<Arma> armas;
	
	//Constructores:
	/**
	 * Constructor por defecto de Compuesta. El arma no
	 * se situa en ninguna casilla y no tendra propietario.
	 */
	public Compuesta(){
		this(null, null);
	}
	
	/**
	 * Constructor de Compuesta. El arma no tendra propietario
	 * pero se encontrara en una casilla pasada como parametro.
	 * @param casilla Casilla en la que se encontrara el arma.
	 */
	public Compuesta(Casilla casilla){
		this(casilla, null);
	}
	
	/**
	 * Constructor de Compuesta. Se llama al constructor de Arma
	 * y se crea una lista armas en la que se iran almacenando
	 * las armas que el jugador vaya consiguiendo. El arma tendra
	 * un propietario y se encontrara en una casilla determinada.
	 * @param casilla
	 * @param propietario
	 */
	public Compuesta(Casilla casilla, Personaje propietario){
		super(casilla, propietario);
		armas=new LinkedList<Arma>();
	}
	
	//Consultas:
	/**
	 * Metodo que devuelve una lista con todas las armas que contiene
	 * el arma compuesta.
	 * @return Lista de las armas que contiene.
	 */
	public LinkedList<Arma> getContenido(){
		return armas;
	}	
	
	/**
	 *  Metodo que activa cada una de las armas que contiene el arma
	 *  compuesta.
	 *  @see muelles.elementos.Arma#activar().
	 */
	public void activar(){
		for(Arma arma:armas){
			arma.activar();
		}
	}
	
	//Modificadores:
	/**
	 * Metodo que inserta una nueva arma conseguida en la lista de
	 * armas del arma compuesta.
	 */
	public void insertarArma(Arma arma){
		armas.add(arma);
	}
	
	/**
	 * Implementacion del metodo getImagen de la interfaz Dibujable.
	 * Si la casilla en la que se encuentra el arma compuesta no es visible
	 * no se mostrara nada.
	 */
	public String obtenerImagen(){
		return "arma-compuesta";	
	}
}
