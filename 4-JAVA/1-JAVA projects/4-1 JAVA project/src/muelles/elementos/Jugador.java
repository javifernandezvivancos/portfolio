package muelles.elementos;

import muelles.escenario.Direccion;
import muelles.escenario.Casilla;

/**
 * Representa al tipo de Personaje Jugador del juego.
 * @author Guadalupe Garca Fernandez y Javier Fernandez Vivancos.
 *
 */
public class Jugador extends Personaje{
	private TipoAccion tipoAccion;
	
	//Constructores:
	/**
	 * Constructor de Jugador. Se llama al constructor de personaje, no se 
	 * le asigna ninguna casilla y se inicializa la accion a realizar a nulo.
	 */
	public Jugador(){
		super();
		tipoAccion=null;
	}
	
	/**
	 * Constructor de Jugador. Se llama al constructor de personaje,
	 * asignandole la casilla dada, y se inicializa la accion a 
	 * realizar a nulo.
	 */
	public Jugador(Casilla casilla){
		super(casilla);
		tipoAccion=null;
	}
	
	//Acciones:
	/**
	 * Implementacion del metodo accion() de la clase abstracta jugador.
	 * Segun la accion a realizar, el atributo tipoaccion tendra un valor
	 * u otro.
	 */
	public void accion(){
		if(tipoAccion==TipoAccion.ARRIBA)
			this.mover(Direccion.ARRIBA);
		else if(tipoAccion==TipoAccion.DERECHA)
			this.mover(Direccion.DERECHA);
		else if(tipoAccion==TipoAccion.ABAJO)
			this.mover(Direccion.ABAJO);
		else if(tipoAccion==TipoAccion.IZQUIERDA)
			this.mover(Direccion.IZQUIERDA);
		else if(tipoAccion==TipoAccion.ACTIVAR_ARMA)
			this.activarArma();
		tipoAccion=null;
	}
	
	/**
	 * Metodo que actualiza el atributo tipoAccion con el fin de
	 * mover el Jugador a la derecha.
	 */
	public void solicitudMueveDerecha(){
		tipoAccion=TipoAccion.DERECHA;
	}
	
	/**
	 * Metodo que actualiza el atributo tipoAccion con el fin de
	 * mover el Jugador a la izquierda.
	 */
	public void solicitudMueveIzquierda(){
		tipoAccion=TipoAccion.IZQUIERDA;
	}
	
	/**
	 * Metodo que actualiza el atributo tipoAccion con el fin de
	 * mover el Jugador hacia arriba.
	 */
	public void solicitudMueveArriba(){
		tipoAccion=TipoAccion.ARRIBA;
	}
	
	/**
	 * Metodo que actualiza el atributo tipoAccion con el fin de
	 * mover el Jugador hacia abajo.
	 */
	public void solicitudMueveAbajo(){
		tipoAccion=TipoAccion.ABAJO;
	}
	
	/**
	 * Metodo que actualiza el atributo tipoAccion con el fin de
	 * activar el arma del jugador.
	 */
	public void solicitudActivarArma(){
		tipoAccion=TipoAccion.ACTIVAR_ARMA;
	}
	/**
	 * Implementacion del metodo getImagen() de la interfaz Dibujable.
	 */
	public String getImagen(){
		if (this.getArma()!=null){
			return "jugador-armado";
		}
		else {
			return "jugador";
		}
	}
}
