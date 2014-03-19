package muelles.escenario;

import muelles.elementos.Elemento;

/**
 * Representa una casilla de tipo hueco: este tipo de casilla tiene las mismas
 * particularidades que una casilla normal, sin embargo, si se intenta
 * insertar un elemento, este se bajara a la casilla de la planta inferior.
 * @author Guadalupe Garcia Fernandez, Javier Fernandez Vivancos.
 *
 */
public class Hueco extends Casilla {

	/**
	 * Constructor de la casilla de tipo Hueco
	 * --precondiciones:
	 * - x e y deben ser mayores que 0.
	 * @param x coordenada x de la casilla
	 * @param y coordenada y de la casilla
	 */
	public Hueco (int x, int y){
		super(x, y, true);
	}
	public Hueco (int x, int y, Planta p){
		super(x, y, true, p);
	}
	
	/**
	 * Inserta un elemento en una casilla Hueco.
	 * @param elem parámetro de tipo elemento, que sera el elemento a insertar.
	 * @see muelles.escenario.Casilla#setElemento(Elemento)
	 * @see muelles.escenario.Planta#bajarElemento(int, int)
	 * @see muelles.escenario.Casilla#getPlanta().
	 */
	public void setElemento (Elemento elem){
		if(getPlanta()!=null)
			super.setElemento(elem);
			if (elem!=null){
				getPlanta().bajarElemento(getX(), getY());
			}
		
	}
	
	/**
	 * Redefinicion del metodo clone, las particularidades de este método
	 * son idénticas a las del clone de la casilla, con la diferencia de
	 * que nos devuelve un hueco.
	 */
	public Hueco clone(){
		Hueco copia;
		Object obj = super.clone();
		copia = (Hueco)obj;
		return copia;
	}
	/**
	 * Implementacion del metodo getImagen() de la interfaz Dibujable.
	 */
	public String getImagen(){
		return "hueco"; 
	}
}
