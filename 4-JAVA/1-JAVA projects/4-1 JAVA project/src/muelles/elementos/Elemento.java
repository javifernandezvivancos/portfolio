package muelles.elementos;

import java.util.LinkedList;
import java.lang.Math;
import muelles.vista.*;
import muelles.escenario.Casilla;
import muelles.escenario.Direccion;
import muelles.escenario.Planta;
/**
 * Representa los diferentes elementos que puede contener una casilla, que 
 * por el momento son: JUGADOR, ARMA o MONSTRUO.
 * @author Guadalupe Garca Fernandez y Javier Fernandez Vivancos.
 *
 */
public abstract class Elemento implements Dibujable{
	//Atributos:
	private EstadoElemento estado;
	private Casilla casilla;
	
	//Constructores:
	/**
	 * Constructor por defecto de Elemento. El elemento no
	 * se situa en ninguna casilla y se actualiza su estado a NO_ACTIVO con
	 * la llamada a this.
	 */
	public Elemento(){
		this(null);
	}
	
	/**
	 * Constructor de casilla de Elemento. El elemento se situara en
	 * una casilla dada y si la casilla tiene un se actualizara su 
	 * estado a ACTIVO.
	 * @param casilla
	 */
	public Elemento(Casilla casilla){
		
		this.casilla= casilla;
		estado= EstadoElemento.NO_ACTIVO;
		if(casilla!=null){
			casilla.setElemento(this);
			estado= EstadoElemento.ACTIVO;
		}
	}
	
	//Consultas:
	/**
	 * Metodo que devuelve la casilla en la que se situa el 
	 * elemento.
	 */
	public Casilla getCasilla(){
		return casilla;
	}
	
	/**
	 * Metodo que devuelve el estado en el que se encuentra el
	 * elemento.
	 * @return NO_ACTIVO o ACTIVO segun corresponda.
	 */
	public EstadoElemento getEstado(){
		return estado;
	}
	
	/**
	 * Metodo que devuelve la planta en la que se encuentra el elemento, saltando
	 * una excepcion en el caso de que no tenga.
	 * @return Planta del elemento.
	 */
	public Planta getPlanta(){
		if(casilla==null)
			throw new IllegalStateException("No se puede obtener la planta. "+
			"El elemento no tiene asociada ninguna casilla");
		return casilla.getPlanta();
	}
	
	/**
	 * Metodo que devuelve la posicion de la coordenada x de la casilla 
	 * en la que se encuentra el elemento. En el caso de que no tenga casilla
	 * asociada, saltara una excepcion.
	 * @return Entero posicion x.
	 */
	public int getPosicionX(){
		if(casilla==null)
		/*	throw new IllegalStateException("No se puede obtener la coordenada. "+
			"El elemento no tiene asociada ninguna casilla");*/
			return -1;
		return casilla.getX();
	}
	
	/**
	 * Metodo que devuelve la posicion de la coordenada y de la casilla 
	 * en la que se encuentra el elemento. En el caso de que no tenga casilla
	 * asociada, saltara una excepcion.
	 * @return Entero posicion y.
	 */
	public int getPosicionY(){
		if(casilla==null)
		/*	throw new IllegalStateException("No se puede obtener la coordenada. "+
			"El elemento no tiene asociada ninguna casilla");*/
			return -1;
		return casilla.getY();
	}
	
	/** Metodo que devuelve el elemento mas cercano.
	 * precondiciones:
	 * la lista no puede ser nula
	 * los elementos de la lista deben pertenecer todos a la misma planta.
	 * @return Elemento mas cercano.
	 */
	protected Elemento masCercano(LinkedList<Elemento> elementos){
		if(elementos==null || elementos.isEmpty())
			return null;
		
		int i=0;
		double aux1, aux2, dist, distMenor=Double.MAX_VALUE;
		Elemento elemAux= elementos.get(0);
		Elemento elementoCercano= null;
		
		while(i<elementos.size()){
			aux1= Math.pow(this.getPosicionX()-elemAux.getPosicionX(), 2);
			aux2= Math.pow(this.getPosicionY()-elemAux.getPosicionY(), 2);
			dist= Math.sqrt(aux1+aux2);
			if(distMenor>dist){
				distMenor= dist;
				elementoCercano= elemAux;
			}	
			i++;
		}
		return elementoCercano;		
	}	
	/** Metodo que calcula la casilla adyacente mas cercana.
	* precondiciones:
	* la posicion pasada debe estar dentro del tamaño de la planta, sino
	* lanzara una excepcion.
	* @param x Coordenada x de la casilla.
	* @param y Coordenada y de la casilla.
	* @return Casilla mas cercana.
	*/
	protected Casilla casillaCercana(int x, int y){
		if(x<this.getPosicionX())
			return this.getPlanta().getCasilla(this.getPosicionX()-1, this.getPosicionY());
		else if(x>this.getPosicionX())
			return this.getPlanta().getCasilla(this.getPosicionX()+1, this.getPosicionY());
		else if(y<this.getPosicionY())
			return this.getPlanta().getCasilla(this.getPosicionX(), this.getPosicionY()-1);
		else if(y>this.getPosicionY())
			return this.getPlanta().getCasilla(this.getPosicionX(), this.getPosicionY()+1);
		else 
			throw new IllegalArgumentException("La posicion pasada como argumento no es valida." + 
					"Introduzca una posicion que este dentro de la planta.");
	}
	
	//modificadores:
	/**
	 * Metodo que asigna una casilla pasada como
	 * parametro al elemento.
	 * @param casilla Casilla en la que se va a introducir el elemento.
	 */
	public void setCasilla(Casilla casilla){
		if(casilla==null)
			throw new IllegalArgumentException("No se puede establecer una casilla nula. "+
			"Utilice removeCasilla");
		if(this.casilla!=null)
			this.casilla.removeElemento();
		
		this.casilla=casilla;
		estado= EstadoElemento.ACTIVO;
		
		if(casilla.getElemento()!=this)
			casilla.setElemento(this);
	}
	
	/**
	 * Metodo que elimina la casilla del elemento.
	 */
	public void removeCasilla(){
		if(casilla!=null){
			Casilla aux= casilla;
			casilla= null;
			estado= EstadoElemento.NO_ACTIVO;
			
			if(aux.getElemento()!=null)
				aux.removeElemento();
		}
	}
	
	/**
	 * Metodo encargado de mover el elemento a una posicion adyacente de
	 * la planta en la direccion pasada como parametro.
	 * @param direccion Direccion en la que se va a mover el elemento
	 * @return true si se ha podido mover y false en caso contrario.
	 */
	public boolean mover(Direccion direccion){	
	//	if(this instanceof Antorcha || this instanceof Personaje || this instanceof Proyectil){
			Planta planta = getPlanta();
			if(planta!=null){
				if(direccion==Direccion.ARRIBA && getPosicionY()<planta.getTamY()-1){
					planta.getCasilla(getPosicionX(), getPosicionY()+1).setElemento(this);
					return true;
				}
				else if(direccion==Direccion.ABAJO && getPosicionY()>0){
					planta.getCasilla(getPosicionX(), getPosicionY()-1).setElemento(this);
					return true;
				}	
				else if(direccion==Direccion.DERECHA && getPosicionX()<planta.getTamX()-1){
					planta.getCasilla(getPosicionX()+1, getPosicionY()).setElemento(this);
					return true;
				}
				else if(direccion==Direccion.IZQUIERDA && getPosicionX()>0){
					planta.getCasilla(getPosicionX()-1, getPosicionY()).setElemento(this);
					return true;
				}
				else{
					throw new IllegalArgumentException ("No se ha podido mover el elemento." +
							"Los parametros pasados no son correctos");
				}
			}
			
		//}
		return false;
	}
	/**
	 * Metodo encargado de mover el elemento a una casilla (adyacente).
	 * Precondiciones: la casilla que se pasa debe ser adyacente, en
	 * caso contrario se lanzara una excepcion.
	 * 
	 */
	/*public void mover(Casilla casilla){
		boolean permitido= false;
		LinkedList<Casilla> casillasAdyacentes= this.getPlanta().getCasillasAdyacentes(this.getPosicionX(), this.getPosicionY());
		//slo lo movemos si es una antorcha, un personaje o un proyectil (esto se podra haber resuelto creando una interfaz movible)
		if(this instanceof Antorcha || this instanceof Personaje || this instanceof Proyectil){
			while(!casillasAdyacentes.isEmpty()){
				if(casillasAdyacentes.removeFirst()==casilla)
					permitido= true;
			}
			if(permitido==false){
				throw new IllegalArgumentException("No se puede mover el elemento ("+
				this.getClass()+"). La casilla hacia la que se quiere mover no es adyacente");
			}
			//si lo que vamos a mover es un personaje cogemos el arma de la casilla hacia la que nos dirigimos
			if(this instanceof Personaje){
				if(casilla.getElemento() instanceof Arma && !(casilla.getElemento() instanceof Proyectil)){//Si la casilla tiene un arma...
					Personaje p= (Personaje)this;
					p.setArma((Arma)casilla.getElemento());
				}
			}
			getPlanta().getCasilla(casilla.getX(), casilla.getY()).setElemento(this);
		}
	}*/
	
	
	/*public void mover(Casilla casilla){
		boolean permitido= false;
		LinkedList<Casilla> casillasAdyacentes= this.getPlanta().getCasillasAdyacentes(this.getPosicionX(), this.getPosicionY());
		
		while(!casillasAdyacentes.isEmpty()){
			if(casillasAdyacentes.removeFirst()==casilla)
				permitido= true;
		}
		
		if(permitido==false){
			throw new IllegalArgumentException("No se puede mover el elemento ("+
			this.getClass()+"). La casilla hacia la que se quiere mover no es adyacente");
		}
		
		getPlanta().getCasilla(casilla.getX(), casilla.getY()).setElemento(this);
	}*/
	
	public void mover(Casilla casilla){
		if (this.casilla.getX()==casilla.getX() && (this.casilla.getY()+1)==casilla.getY())
			this.mover(Direccion.ARRIBA);	
		else if (this.casilla.getX()==casilla.getX() && (this.casilla.getY()-1)==casilla.getY())
			this.mover(Direccion.ABAJO);
		else if ((this.casilla.getX()+1)==casilla.getX() && this.casilla.getY()==casilla.getY())
			this.mover(Direccion.DERECHA);
		else if ((this.casilla.getX()-1)==casilla.getX() && this.casilla.getY()==casilla.getY())
			this.mover(Direccion.IZQUIERDA);
		else
			throw new IllegalArgumentException("No se puede mover el elemento ("+
					this.getClass()+"). La casilla hacia la que se quiere mover no es adyacente");
	}
	
	
	/**
	 * Metodo encargado de indicar que el elemento a ganado. Para
	 * ello se cambia su estado a EXITO.
	 */
	public void escapar(){
		removeCasilla();
		estado= EstadoElemento.EXITO;		
	}
	
	/**
	 * Metodo encargado de indicar que el elemento ha fracasado. Para
	 * ello cambia su estado a FRACASO.
	 */
	public void fracasar(){
		removeCasilla();
		estado= EstadoElemento.FRACASO;
	}
	
	/** 
	 * Metodo encargado de indicar que un elemento ha desaparecido.
	 * Para ello se cambia su estado a DESAPARECIDO.
	 */
	public void desaparecer(){
		removeCasilla();
		estado= EstadoElemento.DESAPARECIDO;		
	}
	
}
