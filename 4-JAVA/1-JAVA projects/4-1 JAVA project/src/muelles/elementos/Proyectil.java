package muelles.elementos;

import muelles.escenario.Casilla;
import muelles.escenario.Direccion;

/**
 * Representa al tipo de elemento proyectil. Este elemento tiene una direccion
 * fija y un numero de elementos. Este tipo de elementos son lanzados
 * por una antorcha.
 * @author Javier Fernandez Vivancos y Guadalupe Garcia Fernandez.
 *
 */

public class Proyectil extends Elemento implements Autonomo{
	
	private Direccion direccion;
	
	/**
	 * Constructor de Proyectil. El proyectil no se encontrara en ninguna
	 * casilla y tendra una direccion fija pasada como parametro.
	 * @param direccion Direccion en la que se va a desplazar el proyectil.
	 */
	public Proyectil (Direccion direccion){
		this(null, direccion);
	}
	
	/**
	 * Constructor de Proyectil. El proyectil se encontrara en una casilla
	 * y una direccion fija, ambas pasadas como parametro.
	 * @param casilla Casilla en la que se va a encontrar el proyectil.
	 * @param direccion Direccion en la que se va a desplazar el proyectil.
	 */
	public Proyectil (Casilla casilla, Direccion direccion){
		super(casilla);
		this.direccion=direccion;
	}
	
	/**
	 * Implementacion del metodo accion() de la interfaz Autonomo.
	 * Este metodo se encargara de implementar la funcionalidad del
	 * proyectil.
	 */
	public void accion(){
		boolean sePuedeMover= false;
		
		if (direccion==Direccion.ABAJO && getPlanta().getCasilla(getPosicionX(),getPosicionY()-1)!=null){
			sePuedeMover= true;
		}
		else if(direccion==Direccion.ARRIBA && getPlanta().getCasilla(getPosicionX(), getPosicionY()+1)!=null){
			sePuedeMover= true;
		}
		else if(direccion==Direccion.DERECHA && getPlanta().getCasilla(getPosicionX()+1, getPosicionY())!=null){
			sePuedeMover= true;
		}
		else if(direccion==Direccion.IZQUIERDA && getPlanta().getCasilla(getPosicionX()-1, getPosicionY())!=null){
			sePuedeMover= true;
		}
		
		if(sePuedeMover && seMueve())
			mover(direccion);
		else{
			this.desaparecer();
		}
	}
	
	/**
	 * Método auxiliar utilizado en el metodo accion() para comprobar que si se trata de una bola de fuego,
	 * no se han agotado aun todos los movimientos.
	 * @return valor boolean que indica si se puede mover o no el elemento.
	 */
	protected boolean seMueve(){
		return true;
	}
	
	/**
	 * Implementacion del metodo getImagen() de la interfaz Dibujable.
	 */
	public String getImagen(){
		return "bola";
	}
}
