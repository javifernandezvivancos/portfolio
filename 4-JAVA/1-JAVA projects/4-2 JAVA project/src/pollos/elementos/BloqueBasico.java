package pollos.elementos;
/**
 * Bloque Basico.
 * Bloque a partir del cual se crean los demas. 
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 */
public class BloqueBasico extends Elemento{

	//Constructores
	/**
	 * Constructor a partir de una determinada masa.
	 * @param masa Masa que tendra el bloque.
	 */
	public BloqueBasico(int masa){
		super(masa);
	}
	
	/**
	 * Constructor suponiendo masa 1.
	 */
	public BloqueBasico(){
		this(1);
	}

	/**
	 * Un bloque basico no tiene accion propia.
	 */
	public void accionPropia() {
	}

	/**
	 * Un bloque desaparece si soporta el triple de su peso.
	 */
	@Override
	public void evaluarEstado() {
		if(this.getMasaTotal() > this.getMasa()*3){
			this.desaparecer();
		}
	}

	/**
	 * Implementacion de getImagen de la interfaz Dibujable.
	 * @return cadena con el nombre del fichero sin extension.
	 */
	public String getImagen() {
		return "bloque-basico";
	}

}