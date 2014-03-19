package pollos.elementos;

import pollos.geometria.Orientacion;

/**
 * Clase para el manejo de nubes.
 * Es un elemento que viaja horizontalmente, transportando lo que tenga encima. 
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 */
public class Nube extends Arrastre implements Empujable{
	//Atributos
	Orientacion orientacion;
	
	//Constructores
	/**
	 * Constructor a partir de una determinada masa y orientacion.
	 * <p><strong>Precondiciones:</strong></p>
	 * <ul>
	 * <li>La orientacion debe ser horizontal.</li>
	 * </ul>
	 * @param masa Masa que tendra la nube.
	 */
	public Nube(int masa, Orientacion orientacion){
		super(masa);
		if(orientacion.equals(Orientacion.ARRIBA) || orientacion.equals(Orientacion.ABAJO)){
			throw new IllegalArgumentException("La orientacion debe ser horizontal"); 
		}
		this.orientacion= orientacion;
	}
	
	/**
	 * Constructor a partir de una determinada orientacion.
	 * <p><strong>Precondiciones:</strong></p>
	 * <ul>
	 * <li>La orientacion debe ser horizontal.</li>
	 * </ul>
	 * @param orientacion Orientacion que tendr� la nube.
	 */
	public Nube(Orientacion orientacion){
		this(1, orientacion);
	}
		
	//Modificadores	
	/**
	 * Redefinicion del metodo aplicarGravedad de Elemento, a la nube no le afecta.
	*/
	public void aplicarGravedad(){
	}
	
	/**
	 * Accion propia de la nube, consiste en moverse y arrastrar a su vecino de arriba.
	*/
	public void accionPropia(){
		mover(orientacion);
	}
	
	/**
	 * Evaluacion del estado de la nube, cambia de direccion si no pede seguir.
	*/
	public void evaluarEstado(){
		if(!this.getEscenario().movimientoValido(this, orientacion)){
			orientacion= orientacion.opuesta();
		}
	}
	
	/**
	 * Implementacion del metodo empujarse de la interfaz empujable, recibe la 
	 * orientacion hacia la que se empujara el elemento.
	 */
	public void empujarse(Orientacion orientacion){
		Elemento vecino= this.getVecino(orientacion);
		
		if(!this.mover(orientacion)){
			if(vecino!=null){
				if(vecino instanceof Empujable){
					((Empujable) vecino).empujarse(orientacion);
				}
			}
		}
	}
	
	//Consultas
	/**
	 * Implementacion del metodo getImagen() de la interfaz Dibujable.
	 * @return cadena con el nombre del fichero, sin extension
	 */
	public String getImagen(){
		return "nube";
	}
}
