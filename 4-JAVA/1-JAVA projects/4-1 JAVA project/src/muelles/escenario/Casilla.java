package muelles.escenario;
import muelles.elementos.Elemento;
import muelles.vista.*;

/**
 * Representa una casilla: esta debe tener unas coordenadas
 * bidimensionales ("x" e "y"),puede estar dentro de una determinada planta,
 * ser visible o no serlo y tambien puede contener algun elemento en su interior.
 * @author Guadalupe Garcia Fernandez, Javier Fernandez Vivancos.
 *
 */
public class Casilla implements Cloneable,  Dibujable{
	//Atributos
	private boolean visible;
	private final int x, y;
	private Elemento contenido;
	private Planta planta;

	//Constructores:
	/**
	 * Constructor basico de una casilla, establece por defecto 
	 * que no es visible y que su contenido y su planta son nulos
	 * --precondiciones:
	 * x e y deben ser mayores que 0.
	 * @param x coordenada x de la casilla.
	 * @param y coordenada y de la casilla.
	 */
	public Casilla(int x, int y){
		this(x,y,false,null);		
	}
	/**
	 * Constructor sobrecargado de una casilla, establece por defecto que
	 * su contenido y su planta son nulos
	 * --precondiciones:
	 * - x e y deben ser mayores que 0.
	 * @param x coordenada x de la casilla
	 * @param y coordenada y de la casilla
	 * @param visible establece si la casilla va a ser visible (true) o no (false)
	 */
	public Casilla(int x, int y, boolean visible){
		this(x,y,visible,null);
	}
	/**
	 * Constructor sobrecargado de una casilla, establece por defecto que su
	 * contenido es nulo
	 * --precondiciones:
	 * - x e y deben ser mayores o iguales que 0.
	 * @param x coordenada x de la casilla.
	 * @param y coordenada y de la casilla.
	 * @param visible establece si la casilla va a ser visible (true) o no (false).
	 * @param p planta a la que va a pertenecer la casilla creada.
	 */
	public Casilla(int x, int y, boolean visible, Planta p){
		if(x<0){
			throw new IllegalArgumentException("No se puede crear la casilla. "+
												"La coordenada x es menor que cero");
		}
		if(y<0){
			throw new IllegalArgumentException("No se puede crear la casilla. "+
												"La coordenada y es menor que cero");
		}
		
		this.x = x;
		this.y = y;
		this.visible = visible;
		contenido=null;
		planta = p;
		if(p!=null)
			if(p.getCasilla(x, y)!=null && p.getCasilla(x, y)!=this)	//Si este constructor no ha sido llamado desde el constructor de la planta (pues en ese caso esta casilla ya estara dentro de la planta)...
				p.setCasilla(this);											//...metemos en la planta la casilla que estamos creando
	}
	
	//Consultas:
	/**
	 * Matodo para obtener el valor de la coordenada x de una casilla.
	 * @return coordenada x de la casilla. 
	 * @see muelles.escenario.Casilla#getY().
	 */
	public int getX(){
		return x;
	}
	/**
	 * Matodo para obtener el valor de la coordenada y de una casilla.
	 * @return coordenada y de la planta.
	 * @see muelles.escenario.Casilla#getX().
	 */
	public int getY(){
		return y;
	}
	/**
	 * Obtiene el elemento que contiene la casilla.
	 * @return elemento de la casilla.
	 */
	public Elemento getElemento(){
		return contenido;
	}
	/**
	 * Obtiene la planta en la que se encuentra la casilla actualmente.
	 * @return la planta en la que se encuentra
	 */
	public Planta getPlanta(){
		return planta;
	}
	/**
	 * Permite saber si la casilla es visible o no.
	 * @return true si es visible, false si no lo es.
	 */
	public boolean isVisible(){
		return visible;
	}
	/**
	 * Permite saber si la casilla contiene algn elemento dentro o no.
	 * @return true si contiene algun elemento y false si no contiene ninguno.
	 */
	public boolean isLlena(){
		if(null==contenido)
			return false;
		else
			return true;
	}
	
	
	//Modificadores
	/**
	 * Establece que la casilla es visible.
	 * @see muelles.escenario.Casilla#ocultar().
	 */
	public void mostrar(){
		visible=true;
	}
	/**
	 * Establece que la casilla no es visible.
	 * @see muelles.escenario.Casilla#mostrar().
	 */
	public void ocultar(){
		visible=false;
	}
	/**
	 * Asigna un elemento a la casilla, cualquier elemento que hubiera 
	 * anteriormente en dicha casilla deja de estar en ella.
	 * @param elem el elemento que contendr la casilla.
	 * @see muelles.escenario.Casilla#setElemento(Elemento, boolean).
	 * @see muelles.escenario.Casilla#removeElemento().
	 */
	public void setElemento(Elemento elem){
		if(elem==null)
			throw new IllegalArgumentException("No se puede establecer una elemento nulo. "+
			"Utilice removeElemento");
		//Desaparecemos el elemento que hubiera anteriormente en la casilla
		if(contenido!=null){
			contenido.desaparecer();
		}
		//el nuevo contenido de la casilla será el del elemento que nos pasan
		contenido = elem;
		if(elem.getCasilla()!=this)
			elem.setCasilla(this);
	}
	/**
	 * metodo sobrecargado.
	 * @see muelles.escenario.Casilla#setElemento(Elemento)
	 * ademas de modificar el elemento que contiene la casilla, modifica su 
	 * visibilidad.
	 * @param elem elemento que contendra la casilla.
	 * @param v visibilidad que tendra la casilla: si le pasamos true 
	 * pasar a ser visible, dejar de serlo si le pasamos false.
	 * @see muelles.escenario.Casilla#removeElemento().
	 */
	public void setElemento(Elemento elem, boolean v){
		this.setElemento(elem);
		visible = v;
	}
	/**
	 * Quita cualquier elemento que haya en la casilla. 
	 * @see muelles.escenario.Casilla#setElemento(Elemento, boolean).
	 * @see muelles.escenario.Casilla#setElemento(Elemento).
	 */
	public void removeElemento(){
		if(contenido!=null){
			Elemento aux= contenido;
			contenido = null;
			if(aux.getCasilla()!=null)
				aux.removeCasilla();
		}
	}
	/**
	 * Introduce la casilla en una determinada planta, este metodo sustituye
	 * la antigua casilla que habia en la planta por la casilla actual;
	 * la antigua casilla dejar de pertenecer a cualquier planta.
	 * @param p planta en donde se introducir la casilla.
	 * @see muelles.escenario.Casilla#removePlanta().
	 */
	public void setPlanta(Planta p){
		if(p==null)
			throw new IllegalArgumentException("No se puede establecer una planta nula. "+
			"Utilice removePlanta");
		
		planta= p;					//referenciamos la casilla actual hacia la planta
		if(p.getCasilla(x, y)!=this)//si la casilla que hay en la posicin x e y de la planta no es la actual
			p.setCasilla(this);		//introducimos en la planta la casilla actual
	}
	/**
	 * Saca la casilla de la planta a la que pertenece introduciendo una nueva
	 * en el lugar en donde se encontraba esta.
	 * @see muelles.escenario.Casilla#setPlanta(Planta).
	 */
	public void removePlanta(){
		if(planta!=null){	//si el atributo planta no está vacío ya, procedemos a vaciarlo:
			Planta aux = planta;
			planta= null;
			if(aux.getCasilla(this.x, this.y)==this)
				aux.removeCasilla(this.x, this.y);
		}
	}
	
	/**
	 * Redefinicion del metodo toString 
	 */
	public String toString () {
		return getClass().getName() + "[" + "x=" + x + "]" +
		"[" + "y=" + y + "]" + "[" + "visible=" + visible + "]" +
		"[" + "contenido=" + contenido + "]" + "[" + "planta=" + planta + "]";	
	}

	
	/**
	 * Redefinicion del metodo equals, dos casillas serán iguales si
	 * son el mismo tipo de casilla y sus coordenadas y visibilidad son
	 * iguales.
	 */
	public boolean equals (Object obj) {
		
		// Si es nulo, entonces no son iguales
		if (obj == null) return false;
		
		// Si son el mismo objeto, entonces son iguales
		if (this == obj) return true;
		
		// Si no son del mismo tipo, no son iguales
		if (this.getClass() != obj.getClass()) return false;
		
		// Se hace un casting al tipo actual
		Casilla casilla = (Casilla)obj;
		
		return this.x == casilla.x && this.y == casilla.y &&
				this.visible == casilla.visible;
	}
	
	/**
	 * Redefinicion del metodo clone, el método clone nos devuelve
	 * una casilla idéntica a la actual salvo con la diferencia de que su
	 * planta y su contenido estarán vacíos.
	 */
	public Casilla clone(){
		
		Object obj = null;
		Casilla copia;		
		try{			
			obj = super.clone();

		}catch (CloneNotSupportedException e){
			assert false: "El objeto no puede ser clonado";
		}
		copia = (Casilla)obj;
		copia.planta = null;
		copia.contenido=null;
		return copia;
	}
	
	/**
	 * Implementacion del metodo getPosicionX() de la interfaz Dibujable.
	 */
	public int getPosicionX() {
		return x;
	}

	/**
	 * Implementacion del metodo getPosicionY() de la interfaz Dibujable.
	 */
	public int getPosicionY() {
		return y;
	}
	
	/**
	 * Implementacion del metodo getImagen() de la interfaz Dibujable.
	 */
	public String getImagen(){
		if (visible==false){
			return "casilla-oculta";
		}
		else {
			return "casilla";
		}
	}
}
