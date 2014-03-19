package muelles.elementos;
import muelles.escenario.Casilla;
import muelles.escenario.Planta;

/**
 * Representa a las diferentes armas que puede haber en
 * el juego. Puede ser: Antorcha, Compuesta o Visor.
 * @author Javier Fernandez Vivancos y Guadalupe Garcia Fernandez.
 *
 */
public abstract class Arma extends Elemento{
	private Personaje propietario;
	private boolean activa;
	
	//Constructores:
	/**
	 * Constructor por defecto de Arma. El arma no estara
	 * en ninguna casilla y no tendra propietario. 
	 * 
	 */
	public Arma(){
		this(null, null);
	}
	
	/**
	 * Constructor de Arma. El arma no tendra propietario
	 * @param casilla Casilla en la que se encontrara el arma.
	 */
	public Arma(Casilla casilla){
		this(casilla, null);
	}
	
	/**
	 * Constructor de Arma. Llama al constructor de elemento y establece
	 * como propietario el introducido como parametro, y el estado de la
	 * misma como inactivo. 
	 * @param casilla Casilla en la que se encontrara el arma.
	 * @param propietario Propietario del arma.
	 */
	public Arma(Casilla casilla, Personaje propietario){
		super(casilla);
		this.propietario= propietario;
		activa= false;
	}
	
	//Consultas:
	/**
	 * Metodo que devuelve el propietario del arma.
	 * @return Propietario del arma. 
	 */
	public Personaje getPropietario(){
		return propietario;
	}
	
	/**
	 * Metodo que devuelve true si el arma esta activa y
	 * false en caso contrario.
	 * @return Estado del arma.
	 */
	public boolean estaActiva(){
		return activa;
	}
	
	/**
	 * Metodo que devuelve un valor booleano dependiendo
	 * de si el arma tiene dueÃ±o o no.
	 * @return true si el arma tiene dueño y false en
	 * caso contrario.
	 */
	public boolean tieneDueno(){
		if(propietario==null)
			return false;
		return true;
	}
	
	//redefiniciones de los mtodos del elemento:
	/**
	 * Metodo que devuelve la casilla del arma.
	 * Si el arma tiene propietario, la casilla en la que
	 * se encontrara sera la del propietario. 
	 * @return Casilla en la que se encuentra el arma.
	 */
	public Casilla getCasilla(){
		if(propietario==null)
			return super.getCasilla();
		return propietario.getCasilla();
	}
	
	/**
	 * Metodo que devuelve la planta del arma.
	 * Si el arma tiene propietario, la planta en la
	 * que se encontrara sera la del propietario.
	 * @return Planta en la que se encuentra el arma.
	 */
	public Planta getPlanta(){
		if(propietario==null)
			return super.getPlanta();
		return propietario.getPlanta();
	}
	
	/**
	 * Metodo que devuelve la posicion en el eje x
	 * del arma. Si el arma tiene propietario, la posicion
	 * en la que se encontrara sera la del propietario.
	 * @return Entero posicion x.
	 */
	public int getPosicionX(){
		if(propietario==null)
			return super.getPosicionX();
		return propietario.getPosicionX();
	}
	
	/**
	 * Metodo que devuelve la posicion en el eje y
	 * del arma. Si el arma tiene propietario, la posicion
	 * en la que se encontrara sera la del propietario.
	 * @return Entero posicion y
	 */
	public int getPosicionY(){
		if(propietario==null)
			return super.getPosicionY();
		return propietario.getPosicionY();
	}
	
	//Modificadores:
	/**
	 * Metodo abstracto activar(). Dependiendo del tipo de arma  
	 * tendra una funcionalidad u otra al activarse.
	 */
	public abstract void activar();
	
	/**
	 * Metodo que desactiva el arma dando el valor falso
	 * a activa.
	 */
	public void desactivar(){
		activa= false;
	}
	
	/**
	 * Metodo que establece el propietario de un arma.
	 * @param propietario Propietario del arma.
	 */
	public void setPropietario(Personaje propietario){
		this.propietario= propietario;
		if(propietario.getArma()!=this)
			propietario.setArma(this);
	}
	
	public String getImagen(){
		if (this.getCasilla().isVisible()){
			return obtenerImagen();
		}
		return "";
	}
	
	protected abstract String obtenerImagen();
}
