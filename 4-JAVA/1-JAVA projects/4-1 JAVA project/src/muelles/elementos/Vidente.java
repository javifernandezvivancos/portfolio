package muelles.elementos;
import java.util.LinkedList;
import muelles.escenario.Casilla;

/**
 * Representa al tipo de enemigo Vidente. Este enemigo detecta todas
 * las armas de la planta, esten en una casilla visible o no, y avanza
 * hasta conseguirlas.
 * @author Javier Fernandez Vivancos y Guadalupe Garcia Fernandez.
 *
 */
public class Vidente extends Enemigo implements Criterio{
	
	Criterio criterio;
	
	//Constructores:
	/**
	 * Constructor por defecto de Vidente. Se llama al constructor por
	 * defecto de Enemigo, no asignando ninguna casilla al mismo.
	 */
	public Vidente(){
		this(null);
	}
	
	/**
	 * Constructor de Vidente. Se llama al constructor de enemigo,
	 * asignandole la casilla pasada como parametro.
	 * @param casilla Casilla en la que se va a encontrar el Vidente.
	 */
	public Vidente(Casilla casilla){
		super(casilla);
		criterio = new Casilla();
		
	}
	
	/**
	 * Implementacion del metodo accion() de la clase abstracta enemigo.
	 * Este metodo se encargara de implementar la funcionalidad del
	 * Vidente.
	 */
/*	public void accion(){
		Elemento e1= this.masCercano(this.getPlanta().getArmas());
		if(e1!=null)
			mover(casillaCercana(e1.getCasilla().getX(), e1.getCasilla().getY()));
	}*/
	
	/**
	 * Implementacion de los metodos abstractos de la clase enemigo para el
	 * metodo plantilla accion().
	 * @see muelles.elementos.Enemigo#accion().
	 */
	public LinkedList<Elemento> obtenerArmas(){
		return this.getPlanta().filtrar(Criterio criterio);
	}
	public boolean persigueArma(){
		return true;
	}
	
	/**
	 * Implementacion del metodo getImagen() de la interfaz Dibujable.
	 */
	public String getImagen(){
		return "vidente";
	}
	
	/**
	 * Implementacion del metodo test de la interfaz Criterio.
	 */
	public boolean test (Casilla casilla){
		if (casilla.getElemento() instanceof Arma)
			return true;
		return false;
	}
}
