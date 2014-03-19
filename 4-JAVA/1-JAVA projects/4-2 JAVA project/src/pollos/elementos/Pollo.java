package pollos.elementos;

import pollos.geometria.Orientacion;
/**
 * Clase para el manejo de pollos.
 * El pollo es el elemento que aparece cuando el jugador incuba un huevo, y que deberá protegerse para conseguir una mejor puntuacion en la partida. 
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 */
public class Pollo extends Elemento{

	//Constructores
	/**
	 * Constructor a partir de una determinada masa.
	 * @param masa Masa que tendra el pollo.
	 */
	public Pollo(int masa){
		super(masa);
	}
	
	/**
	 * Constructor suponiendo masa 1.
	 */
	public Pollo(){
		this(1);
	}
	
	/**
	 * Un pollo no tiene accion propia.
	 */
	@Override
	public void accionPropia() {
	}

	/**
	 * Un pollo desaparece al ser chafado.
	 */
	@Override
	public void evaluarEstado() {
		if(getVecino(Orientacion.ARRIBA)!=null){
			this.desaparecer();
		}		
	}

	/**
	 * Devuelve la imagen correspondiente.
	 * @return string con el nombre, sin extension, de la imagen.
	 */
	public String getImagen() {
		return "pollo";
	}
}
