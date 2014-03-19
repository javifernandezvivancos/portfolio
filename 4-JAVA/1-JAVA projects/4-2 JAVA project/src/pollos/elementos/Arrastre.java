package pollos.elementos;

import pollos.geometria.Orientacion;

/**
 * Clase abstracta Arrastre.
 * Define elementos de arrastre, que son aquellos que transportan al que tengan encima.
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 */
public abstract class Arrastre extends Elemento{
	//Constructores
	/**
	 * Constructor a partir de una determinada masa.
	 * @param masa Masa que tendra el elemento
	 */
	public Arrastre(int masa){
		super(masa);
	}
	
	/**
	 * Constructor por defecto, establece la masa a 1.
	 */
	public Arrastre(){
		this(1);
	}
	
	//Modificadores
	/**
	 * Metodo redefinido para que al moverse arrastre al elemento superior.
	 * @return booleano indicando si el movimiento es correcto.
	 */
	public boolean mover(Orientacion o){
		//Variables
		Elemento elemSuperior= getVecino(Orientacion.ARRIBA);
		
		//Acciones
		if(elemSuperior!=null){
			elemSuperior.mover(o);
		}
		return super.mover(o);
	}
}
