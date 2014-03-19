package pollos.elementos;

import pollos.geometria.Orientacion;
/**
 * Bloque Estatico.
 * Bloque que permanece inmovil siempre. 
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 */
public class BloqueEstatico extends BloqueBasico{

	//Constructores
	/**
	 * Constructor a partir de una determinada masa.
	 * @param masa Masa que tendra el bloque.
	 */
	public BloqueEstatico(int masa){
		super(masa);
	}
	
	/**
	 * Constructor suponiendo masa 1.
	 */
	public BloqueEstatico(){
		this(1);
	}

	/**
	 * La gravedad no le afecta.
	 */
	public void aplicarGravedad(){
	}

	/**
	 * No puede ser movido.
	 */
	public boolean mover(Orientacion o){
		return false;
	}

	/**
	 * Implementacion de getImagen de la interfaz Dibujable.
	 * @return cadena con el nombre del fichero sin extension.
	 */
	public String getImagen() {
		return "bloque-estatico";
	}
}
