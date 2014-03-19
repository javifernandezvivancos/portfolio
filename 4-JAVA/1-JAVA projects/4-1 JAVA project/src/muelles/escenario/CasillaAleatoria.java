package muelles.escenario;

import muelles.elementos.Elemento;

/**
 * Representa una casilla aleatoria: este tipo de casilla tiene las mismas
 * particularidades que una casilla normal, sin embargo, si se intenta
 * insertar un elemento, este se insertara en una casilla aleatoria de 
 * la misma planta.
 * @author Guadalupe Garcia Fernandez, Javier Fernandez Vivancos.
 *
 */
public class CasillaAleatoria extends Casilla {


	/**
	 * Constructor de la casilla de tipo CasillaAleatoria
	 * --precondiciones:
	 * - x e y deben ser mayores que 0.
	 * @param x coordenada x de la casilla
	 * @param y coordenada y de la casilla.
	 * @see muelles.escenario.Casilla#Casilla(int, int, boolean).
	 */
	public CasillaAleatoria (int x, int y){
		super(x, y, true);
	}
	
	/**
	 * Constructor de la casilla de tipo CasillaAleatoria
	 * --precondiciones:
	 * - x e y deben ser mayores que 0.
	 * @param x coordenada x de la casilla
	 * @param y coordenada y de la casilla
	 * @param p planta en la que se va a situar la casilla. 
	 * @see muelles.escenario.Casilla#Casilla(int, int, boolean, Planta).
	 */
	public CasillaAleatoria (int x, int y, Planta p){
		super(x, y, true, p);
	}
	
	/**
	 * Inserta un elemento en una casilla de tipo CasillaAleatoria.
	 * Si la casilla no esta situada en ninguna planta se tratar como
	 * si fuese una casilla normal. En caso contrario, el elemento se
	 * insertara en una casilla aleatoria de la misma planta.
	 * @param elem parametro de tipo elemento, que ser el elemento a insertar.
	 * @see muelles.escenario.Casilla#setElemento(Elemento)
	 * @see muelles.escenario.Casilla#getPlanta()
	 * @see muelles.escenario.Planta#getCasillaAleatoria().
	 */
	public void setElemento(Elemento elem){
		
		if (getPlanta()==null) {
			super.setElemento(elem);
		} else {
			getPlanta().getCasillaAleatoria().setElemento(elem);
		}
	}
	
	/**
	 * Metodo sobrecargado con el fin de que una casilla de tipo
	 * CasillaAleatoria nunca se pueda ocultar.
	 * @see muelles.escenario.Casilla#ocultar().
	 */
	public void ocultar (){
	}
	
	/**
	 * Redefinicion del metodo clone, las particularidades de este método
	 * son idénticas a las del clone de la casilla, con la diferencia de
	 * que nos devuelve una casillaAleatoria.
	 */
	public CasillaAleatoria clone(){
		CasillaAleatoria copia;
		Object obj = super.clone();		
		copia = (CasillaAleatoria)obj;
		return copia;		
	}
	/**
	 * Implementacion del metodo getImagen() de la interfaz Dibujable.
	 */
	public String getImagen(){
		return "casilla-aleatoria";
	}
}
