package muelles.escenario;

import muelles.elementos.Elemento;

/**
 * Representa una casilla de tipo muelle: este tipo de casilla tiene las mismas
 * particularidades que una casilla normal, sin embargo, si se intenta
 * insertar un elemento, este se subirá a la casilla de la planta superior,
 * esto ocurrirá hasta diez veces, la siguiente vez que se intente insertar
 * un elemento en el muelle, éste se comportará como una casilla normal.
 * @author Guadalupe Garcia Fernandez, Javier Fernandez Vivancos.
 *
 */
public class Muelle extends Casilla {

	private int nelem;
	private static final int MAX_ELEM = 10;
	
	/**
	 * Constructor de la casilla de tipo Muelle
	 * --precondiciones:
	 * - x e y deben ser mayores que 0.
	 * @param x coordenada x de la casilla
	 * @param y coordenada y de la casilla.
	 * @see muelles.escenario.Casilla#Casilla(int, int, boolean).
	 */
	public Muelle (int x, int y) {
		super(x,y,true);
		nelem=0;
	}
	
	/**
	 * Constructor de la casilla de tipo muelle 
	 * --precondiciones:
	 * - x e y deben ser mayores que 0.
	 * @param x coordenada x de la casilla
	 * @param y coordenada y de la casilla
	 * @param p planta en la que se va a situar la casilla.
	 * @see muelles.escenario.Casilla#Casilla(int, int, boolean, Planta).
	 */
	public Muelle (int x, int y, Planta p) {
		super(x,y,true,p);
		nelem=0;
	}
	
	/**
	 * Inserta un elemento en una casilla muelle.
	 * Lleva un contador de el numero de veces que ha impulsado elementos, 
	 * no permitiendo que eso lo haga mas de 10 veces. En caso de que haya 
	 * completado todas las oportunidades, se comportar como una casilla normal.
	 * @param elem parametro de tipo elemento, que ser el elemento a insertar.
	 * @see muelles.escenario.Casilla#setElemento(Elemento)
	 * @see muelles.escenario.Planta#subirElemento(int, int).
	 */
	public void setElemento (Elemento elem){
	
		if (nelem>MAX_ELEM){
			super.setElemento(elem);
		}
		else {
			if(getPlanta()!=null){
				super.setElemento(elem);
				nelem++;
				getPlanta().subirElemento(getX(), getY());
			}
			else{
				super.setElemento(elem);
			}
		}
	}
	
	/**
	 * Este metodo ser utilizado para saber si una casilla muelle
	 * puede seguir impulsando elementos, o por el contrario ya ha 
	 * impulsado elementos el numero maximo de veces 10.
	 * @return valor booleana que ser verdadero cuando 
	 * la casilla muelle no haya sobrepasado el numero maximo para 
	 * impulsar elementos.
	 */
	public boolean estaOperativo (){
		if (nelem<=10) {
			return true;
		}
		else {
			return false;
		}
	}

	/**
	 * Redefinicion del metodo toString.
	 * @see muelles.escenario.Casilla#toString().
	 */
	public String toString (){
		return super.toString() + "[" + "nelem" + this.nelem + "]";
	}

	/**
	 * Redefinicion del metodo equals.`
	 * @see muelles.escenario.Casilla#equals(Object).
	 */
	public boolean equals (Object obj){
		
		if (super.equals(obj) == false) return false;
		
		Muelle muelle = (Muelle)obj;
		
		return this.nelem == muelle.nelem;
	}
	
	/**
	 * Redefinicion del metodo clone, las particularidades de este método
	 * son idénticas a las del clone de la casilla, con la diferencia de
	 * que nos devuelve un muelle.
	 */
	public Muelle clone(){
		Muelle copia;			
		Object obj = super.clone();		
		copia = (Muelle)obj;
		return copia;		
	}
	/**
	 * Implementacion del metodo getImagen() de la interfaz Dibujable.
	 */
	public String getImagen(){
		return "muelle"; 
	}
}
