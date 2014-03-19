package pollos.elementos;

import java.util.List;
import pollos.geometria.Orientacion;

/**
 * Clase para el manejo de bombas.
 * Las bombas caen del cielo y, pasado cierto tiempo, destruyen todo lo que hay a su alrededor. 
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 */
public class Bomba extends Elemento implements Empujable{
	//Atributos
	private boolean activada, explotada;
	private long horaInicioActivacion;
	private int tiempoDetonacion;
	
	//Constructores
	/**
	 * Constructor a partir de una determinada masa.
	 * @param masa Masa que tendra el elemento
	 * @param tiempoDetonacion tiempo que tarda en explotar una bomba.
	 */
	public Bomba(int masa, int tiempoDetonacion){
		super(masa);
		this.tiempoDetonacion= tiempoDetonacion;
		activada= false;
	}
	
	/**
	 * Constructor por defecto, establece la masa a 1.
	 * @param tiempoDetonacion tiempo que tarda en explotar una bomba.
	 */
	public Bomba(int tiempoDetonacion){
		this(1, tiempoDetonacion);
	}
	
	//Modificadores
	/**
	 * Implementacion del metodo empujarse de la interfaz empujable, recibe la 
	 * orientacion hacia la que se empujara el elemento.
	 * @param orientacion es la direccion en la cual se empuja al objeto. 
	 */
	public void empujarse(Orientacion orientacion) {
		Elemento vecino= this.getVecino(orientacion);
		
		if(!this.mover(orientacion)){
			if(vecino!=null){
				if(vecino instanceof Empujable){
					((Empujable) vecino).empujarse(orientacion);
				}
			}
		}
	}

	/**
	 * Accion propia de la bomba, que consiste en hacer desaparecer a todos los
	 * elementos vecinos si ha transcurrido su tiempo de activacion.
	 */
	public void accionPropia() {
		long horaActual= System.currentTimeMillis();
		List<Elemento> vecinos;
		
		if(activada){
			if((horaActual-horaInicioActivacion)>(tiempoDetonacion*1000)){
				vecinos= this.getVecinos();
				for (Elemento elemento : vecinos) {
					elemento.desaparecer();
				}
				explotada= true;
			}			
		}
	}
	
	/**
	 * Evaluacion del estado de la bomba, si no esta activada y debe activarse se hace,
	 * y si esta activada y explotada desaparece.
	 */
	public void evaluarEstado() {
		if(!activada){
			if(this.getPosicionY()==0 || this.getVecino(Orientacion.ABAJO)!=null){
				horaInicioActivacion= System.currentTimeMillis();
				activada= true;
			}
		}	
		else if(activada && explotada){
			this.desaparecer();
		}	
	}

	/**
	 * Implementacion de getImagen
	 * @return cadena con el nombre del fichero, sin extension.
	 */
	public String getImagen() {
		return "bomba";
	}
	
}