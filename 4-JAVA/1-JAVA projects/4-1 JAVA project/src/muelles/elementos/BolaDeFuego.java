package muelles.elementos;

import muelles.escenario.Casilla;
import muelles.escenario.Direccion;

public class BolaDeFuego extends Proyectil {
	
	private int numMovimientos;
	
	/**
	 * Constructor de BolaDeFuego. La BolaDeFuego no se encontrara en ninguna
	 * casilla y tendra una direccion fija pasada como parametro.
	 * @param direccion Direccion en la que se va a desplazar el proyectil.
	 */
	public BolaDeFuego(Direccion direccion){
		this(null, direccion);
	}
	
	/**
	 * Constructor de BolaDeFuego. La BolaDeFuego se encontrara en una casilla
	 * y una direccion fija, ambas pasadas como parametro.
	 * @param casilla Casilla en la que se va a encontrar el proyectil.
	 * @param direccion Direccion en la que se va a desplazar el proyectil.
	 */
	public BolaDeFuego (Casilla casilla, Direccion direccion){
		super(casilla,direccion);
		if (direccion==Direccion.DERECHA || direccion==Direccion.IZQUIERDA){
			numMovimientos=(getPlanta().getTamX())/2;
		}
		else if (direccion==Direccion.ARRIBA || direccion==Direccion.ABAJO){
			numMovimientos=(getPlanta().getTamY())/2;
		}
		
	}
	
	/**
	 * Metodo sobrecargado accion(), que implementa la interfaz autonomo.
	 * Se encarga de implementar la funcionalidad de la BolaDeFuego.
	 */
	public void accion (){
		super.accion();
		if (numMovimientos>0)
			numMovimientos--;
	}
	
	/**
	 * Metodo auxiliar para comprobar si se puede mover o no el elemento,
	 * es decir, si se ha agotado el numero maximo de movimientos
	 * @return boolean que indica si se puede mover o no el elemento. 
	 */
	protected boolean seMueve(){
		if (numMovimientos>0)
			return true;
		return false;
	}

}
