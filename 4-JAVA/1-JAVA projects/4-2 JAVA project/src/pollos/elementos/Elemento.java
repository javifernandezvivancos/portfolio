package pollos.elementos;
import java.util.LinkedList;
import java.util.List;
import pollos.escenario.Escenario;
import pollos.geometria.Orientacion;
import pollos.vista.*;

/**
 * Clase Elemento, que puede pertenecer a un escenario y posee una masa propia y total
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 *
 */
public abstract class Elemento implements Dibujable{
	private final int masa;
	private Escenario escenario;
	
	//Constructores
	/**
	 * Constructor a partir de una determinada masa.
	 * @param masa Masa que tendra el elemento
	 */
	public Elemento(int masa){
		this.masa= masa;
	}
	
	/**
	 * Constructor por defecto, establece la masa a 1.
	 */
	public Elemento(){
		this(1);
	}
	
	//Modificadores
	/**
	 * Metodo para sacar un elemento del elemento en el que estuviera.
	 */
	public void desaparecer(){		
		//Variables
		Escenario aux= escenario;
		
		//Acciones		
		if(escenario==null)	{return;}			//si no tiene asociado ning�n escenario salimos directamente
		
		if(aux.estaElemento(this)){			//si este elemento todav�a se encuentra en su antiguo escenario...
			aux.removeElemento(this);		//...lo sacamos de �l
		}
		escenario= null;					//establecemos el escenario a null

	}
	
	/**
	 * Metodo que realiza la aplicacion del turno del elemento si este tiene escenario.
	 */
	public void aplicarTurno(){
		if(tieneEscenario()){
			aplicarGravedad();
			accionPropia();
			evaluarEstado();
		}
	}
	
	/**
	 * Metodo que aplica la gravedad sobre el objeto.
	 */
	public void aplicarGravedad(){
		mover(Orientacion.ABAJO);
	}
	
	/**
	 * Metodo para que el elemento realice su accion propia.
	 */
	public abstract void accionPropia();
	
	/**
	 * Metodo para evaluar el estado del elemento.
	 */
	public abstract void evaluarEstado();
	
	/**
	 * Metodo para mover un elemento en una determinada orientacion.
	 * @param o orientacion hacia la que se desea mover el elemento.
	 * @return devuelve un booleano indicando si ha podido realizar el movimiento.
	 */
	public boolean mover(Orientacion o){
		return escenario.trasladar(this, o);
	}
	
	/**
	 * Establece el escenario del elemento, se supone que este elemento ya esta dentro del escenario.
	 * @param escenario en donde se metera el elemento.
	 */
	public void setEscenario(Escenario escenario){		
		if(escenario!=null){					//si el elemento tiene escenario tomamos sus antiguas coordenadas para trasladarlo
			desaparecer();
		}
		this.escenario= escenario;
	}	
	
	//Consultas
	/**
	 * Devuelve la masa del elemento.
	 * @return masa valor con la masa del elemento.
	 */
	public int getMasa(){
		return masa;
	}
	
	/**
	 * Devuelve la masa total del elemento.
	 * @return masa total del elemento (la suya mas la total del elemento superior).
	 */
	public int getMasaTotal(){
		if (getPosicionY()==escenario.getTamanoY() || getVecino(Orientacion.ARRIBA)==null){	//Si el elemento es el superior o no tiene ning�n otro elemento por encima...
			return masa;																//...devolvemos la masa
		}
		return masa + getVecino(Orientacion.ARRIBA).getMasaTotal();						//En otro caso devolvemos la masa m�s la masa del superior.
	}
	
	/**
	 * Permite consultar si el elemento tiene asociado un escenario.
	 * @return true si el elemento esta en un escenario, false en caso contrario.
	 */
	public boolean tieneEscenario(){
		if(escenario==null){
			return false;
		}
		return true;
	}
	
	/**
	 * Obtiene el elemento vecino a una orientacion dada.
	 * @param o Orientacion hacia la que se quiere obtener el elemento vecino.
	 * @return el elemento vecino.
	 */
	public Elemento getVecino(Orientacion o){
		return escenario.getVecino(this, o);
	}
	
	/**
	 * Obtiene todos los vecinos del elemento ARRIBA,ABAJO,DERECHA,IZQUIERDA.
	 * @return Una nueva lista con cada uno de ellos.
	 */
	public List<Elemento> getVecinos(){
		//Variables
		List<Elemento> vecinos= new LinkedList<Elemento>();

		//Acciones
		if(getVecino(Orientacion.ABAJO)!=null){
			vecinos.add(getVecino(Orientacion.ABAJO));
		}
		if(getVecino(Orientacion.ARRIBA)!=null){
			vecinos.add(getVecino(Orientacion.ARRIBA));
		}
		if(getVecino(Orientacion.DERECHA)!=null){
			vecinos.add(getVecino(Orientacion.DERECHA));
		}
		if(getVecino(Orientacion.IZQUIERDA)!=null){
			vecinos.add(getVecino(Orientacion.IZQUIERDA));
		}
		return vecinos;
	}
	
	/**
	 * Devuelve la coordenada X del elemento.
	 * @return Coordenada X del elemento.
	 */
	public int getPosicionX(){	
		if(escenario==null)return -1;
		return escenario.getPosicionElemento(this).getX();
	}
	
	/**
	 * Devuelve la coordenada Y del elemento.
	 * @return Coordenada Y del elemento.
	 */
	public int getPosicionY(){		
		if(escenario==null)return -1;
		return escenario.getPosicionElemento(this).getY();
	}
	
	/**
	 * Devuelve el escenario en el que esta situado el elemento (null si no tiene asociado ninguno).
	 * @return Escenario en el que se encuentra el elemento, o null si no lo hay.
	 */
	public Escenario getEscenario() {
		return escenario;
	}
}
