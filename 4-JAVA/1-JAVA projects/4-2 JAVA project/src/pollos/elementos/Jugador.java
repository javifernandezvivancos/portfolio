package pollos.elementos;

import pollos.geometria.Orientacion;
/**
 * Clase para el manejo del jugador.
 * Recibe ordenes por teclado e interactua con el resto de elementos.
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 *
 */
public class Jugador extends Arrastre{
	private TipoAccion tipoAccion;
	private Orientacion ultimaOrientacion;
	private boolean descender;
	//Constructores
	/**
	 * Constructor a partir de una determinada masa.
	 * @param masa Masa que tendra la nube.
	 */
	public Jugador(int masa){
		super(masa);
	}
	
	/**
	 * Constructor suponiendo masa 1.
	 */
	public Jugador(){
		this(1);
	}
	
	//Acciones:
	/**
	 * Metodo que actualiza el atributo tipoAccion con el fin de
	 * mover el Jugador a la derecha.
	 */
	public void solicitudMueveDerecha(){
		tipoAccion= TipoAccion.MOVER_DERECHA;
	}
	
	/**
	 * Metodo que actualiza el atributo tipoAccion con el fin de
	 * mover el Jugador a la izquierda.
	 */
	public void solicitudMueveIzquierda(){
		tipoAccion= TipoAccion.MOVER_IZQUIERDA;
	}
	
	/**
	 * Metodo que actualiza el atributo tipoAccion con el fin de
	 * mover el Jugador hacia arriba.
	 */
	public void solicitudMueveArriba(){
		tipoAccion= TipoAccion.MOVER_ARRIBA;
	}
	
	/**
	 * Metodo que actualiza el atributo tipoAccion con el fin de
	 * mover el Jugador hacia abajo.
	 */
	public void solicitudMueveAbajo(){
		tipoAccion= TipoAccion.MOVER_ABAJO;
	}
	
	/**
	 * Metodo que actualiza el atributo tipoAccion con el fin de
	 * empujar algo
	 */
	public void solicitudEmpujar(){
		tipoAccion= TipoAccion.EMPUJAR;
	}
	
	/**
	 * Implementacion del metodo accionPropia() de la clase jugador.
	 * Segun la accion a realizar, el atributo tipoAccion tendra un valor
	 * u otro.
	 */
	public void accionPropia() {
		if(tipoAccion==TipoAccion.MOVER_ARRIBA){
			mover(Orientacion.ARRIBA);
			ultimaOrientacion= Orientacion.ARRIBA;
		}
		else if(tipoAccion==TipoAccion.MOVER_DERECHA){
			mover(Orientacion.DERECHA);
			ultimaOrientacion= Orientacion.DERECHA;
		}
		else if(tipoAccion==TipoAccion.MOVER_ABAJO){
			mover(Orientacion.ABAJO);
			ultimaOrientacion= Orientacion.ABAJO;
		}
		else if(tipoAccion==TipoAccion.MOVER_IZQUIERDA){
			mover(Orientacion.IZQUIERDA);
			ultimaOrientacion= Orientacion.IZQUIERDA;
		}
		else if(tipoAccion==TipoAccion.EMPUJAR){
			empujar();
		}
		tipoAccion= null;
	}
	
	/**
	 * Redefinicion del metodo aplicarGravedad de Elemento, el jugador desciende menos.
	*/
	public void aplicarGravedad(){
		if(descender){
			super.aplicarGravedad();
		}
		descender= !descender;
	}
	
	/**
	 * El jugador no evalua nada.
	 */
	public void evaluarEstado() {		
	}
	
	/**
	 * El jugador no puede desaparecer.
	 */
	public void desaparecer(){
	}
	
	
	/**
	 * Empuja a otro elemento, siempre que este permitido, en la direccion del ultimo movimiento.
	 */
	public void empujar(){
		if(this.getVecino(ultimaOrientacion) instanceof Empujable){
			((Empujable)this.getVecino(ultimaOrientacion)).empujarse(ultimaOrientacion);
		}
	}
	
	//Consultas
	/**
	 * Implementacion del metodo getImagen() de la interfaz Dibujable.
	 * @return Cadena con el nombre de archivo, sin extension.
	 */
	public String getImagen(){
		return "jugador1";
	}
}
