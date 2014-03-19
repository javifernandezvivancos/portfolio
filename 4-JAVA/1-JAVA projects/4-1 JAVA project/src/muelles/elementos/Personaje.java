package muelles.elementos;
import muelles.escenario.Casilla;
import muelles.escenario.Direccion;

/**
 * Representa a los tipos Personaje que va a haber en el juego,
 * Estos pueden ser: Jugador, Vidente o Loco.
 * @author Guadalupe Garca Fernandez y Javier Fernandez Vivancos.
 *
 */

public abstract class Personaje extends Elemento implements Autonomo{
	private Arma arma;
	
	//Constructores:
	/**
	 * Constructor por defecto de Personaje. Llama al constructor por
	 * defecto de elemento, no asignandole ninguna casilla al mismo.
	 */
	public Personaje(){
		super();
	}
	
	/**
	 * Constructor de personaje. Llama al constructor de elemento, asignandole
	 * la casilla pasada como parametro.
	 * @param casilla Casilla en la que se va a encontrar el Personaje.
	 */
	public Personaje(Casilla casilla){
		super(casilla);
	}
	
	//Consultas:
	/**
	 * Metodo que devuelve verdadero si el Personaje tiene
	 * arma y falso en caso contrario.
	 * @return true o false.
	 */
	public boolean tieneArma(){
		if(arma==null)
			return false;
		return true;
			
	}
	
	/**
	 * Metodo que devuelve el arma que tiene el Personaje.
	 * @return Arma del personaje.
	 */
	public Arma getArma(){
		return arma;
	}
	
	/**
	 * Metodo abstracto accion() que implementaran los distintos
	 * tipos de personajes dependiendo de la funcionalidad de los
	 * mismos.
	 */
	public abstract void accion();
	
	/**
	 * Metodo encargado de mover el Personaje a una
	 * casilla adyacente en la direccion pasada
	 * como parametro.
	 * @param direccion Direccion en la que se va a mover.
	 * @return true si se ha podido mover y false en caso contrario.
	 */
	public boolean mover(Direccion direccion){
		Elemento aux= null;
		//Arma a= null;
		if(direccion==Direccion.ARRIBA && getCasilla().getY()<getPlanta().getTamY()-1){//Si la casilla a la que nos vamos a mover existe...
			aux= getPlanta().getCasilla(getPosicionX(), getPosicionY()+1).getElemento();//guardamos el elemento que contiene en aux
		}
		else if(direccion==Direccion.ABAJO && getCasilla().getY()>0){
			aux= getPlanta().getCasilla(getPosicionX(), getPosicionY()-1).getElemento();
		}
		else if(direccion==Direccion.DERECHA && getCasilla().getX()<getPlanta().getTamX()-1){
			aux= getPlanta().getCasilla(getPosicionX()+1, getPosicionY()).getElemento();
		}
		else if(direccion==Direccion.IZQUIERDA && getCasilla().getX()>0){
			aux= getPlanta().getCasilla(getPosicionX()-1, getPosicionY()).getElemento();
		}

		//aux contiene la casilla hacia la que nos vamos a mover
		if(aux instanceof Arma){//Si la casilla tiene un arma...
			aux.removeCasilla();//lo sacamos de la casilla y
			setArma((Arma)aux);//el personaje pasa a ser propietario de ella
		}
		return super.mover(direccion);//movemos el elemento
	}
	
	/**
	 * Metodo que establece al Personaje un arma pasada 
	 * como parametro. Si el personaje posee un arma compuesta,
	 * añade la nueva arma a la misma.
	 * @param arma Arma que va a poseer el Personaje.
	 */
	public void setArma(Arma arma){
		Compuesta c= null;
		
		if(this.arma==null){//Si no tenemos arma...
			this.arma= arma; //...nos quedamos con la que llega
		}
		else{//Si si que tenemos arma
			if(this.arma instanceof Compuesta){	//Si lo que tenemos es un arma compuesta...
				if(!(arma instanceof Compuesta)){	//...y lo que nos llega es un arma normal...
					c= (Compuesta)this.arma;		//...la insertamos.
					c.insertarArma(arma);
				}
			}
			else{//Si lo que tenemos no es un arma compuesta...
				if(arma instanceof Compuesta){//...y nos llega un arma compuesta
					c= (Compuesta)arma;			//la insertamos
					c.insertarArma(this.arma);
					this.arma= c;
				}
				else{//...y nos llega un arma normal
					this.arma= arma;	//nos quedamos con la que llega
				}
			}
		}
		
		if(arma.getPropietario()!=this){
			arma.setPropietario(this);
		}
		arma.removeCasilla();
	}
	
	/**
	 * Metodo encargado de activar el arma pasada como parametro.
	 */
	public void activarArma(){
		if(arma!=null)
			arma.activar();
	}
}
