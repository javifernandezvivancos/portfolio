package pollos.elementos;

import pollos.geometria.Orientacion;

/**
 * Bloque deslizante.
 * Bloque que transporta lo que hay sobre él, en una dirección dada. 
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 */
public class BloqueDeslizante extends BloqueBasico{
	
	// Atributos
	private final Orientacion miOrientacion;

	//Constructores
	/**
	 * Constructor a partir de una determinada masa.
	 * <p><strong>Precondiciones:</strong></p>
	 * <ul>
	 * <li>La direccion debe ser horizontal.</li>
	 * </ul>
	 * @param masa Masa que tendra el bloque.
	 * @param direccion dirección hacia la que transporta los elementos.
	 */
	public BloqueDeslizante(int masa, String direccion){
		super(masa);
		Orientacion orientacion = Orientacion.fromString(direccion);
		if(orientacion.equals(Orientacion.ARRIBA) || orientacion.equals(Orientacion.ABAJO)){
			throw new IllegalArgumentException("La direccion debe ser horizontal"); 
		}
		this.miOrientacion = orientacion;
	}
	
	/**
	 * Constructor suponiendo masa 1.
	 * <p><strong>Precondiciones:</strong></p>
	 * <ul>
	 * <li>La direccion debe ser horizontal.</li>
	 * </ul>
	 * @param direccion dirección hacia la que transporta los elementos.
	 */
	public BloqueDeslizante(String direccion){
		this(1, direccion);
	}	
	
	/**
	 * Implementacion de accion propia.
	 * Mueve al vecino de arriba en la orientacion propia.
	 */
	@Override
	public void accionPropia() {
		Elemento ele = this.getVecino(Orientacion.ARRIBA);
		if(ele!=null){
			ele.mover(this.miOrientacion);
		}
		
	}
	
	/**
	 * Implementacion de getImagen de la interfaz Dibujable.
	 * @return cadena con el nombre del fichero sin extension.
	 */
	public String getImagen() {
		if(this.miOrientacion.equals(Orientacion.DERECHA)){
			return "bloque-deslizante-derecha";
		}
		return "bloque-deslizante-izquierda";
	}

}
