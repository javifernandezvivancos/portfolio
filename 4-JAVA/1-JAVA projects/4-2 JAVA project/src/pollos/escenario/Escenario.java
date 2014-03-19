package pollos.escenario;
import pollos.elementos.Bomba;
import pollos.elementos.Elemento;
import pollos.elementos.Huevo;
import pollos.elementos.Jugador;
import pollos.elementos.Pollo;
import pollos.geometria.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Collection;
import java.util.LinkedList;
import java.util.HashMap;
import java.util.List;
import java.util.Random;

import javax.swing.Timer;
/**
 * clase Escenario, la cual tendr� unas dimensiones y una serie de elementos en su interior.
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 *
 */
public class Escenario implements ActionListener{
	private Elemento[][] elementos;					//array de elementos que hay en el escenario
	private HashMap<Elemento, Posicion> posiciones;	//hasmap para obtener las posiciones de los elementos
	private final int ancho, alto;					//dimensiones del escenario
	private EstadoEscenario estado;					//estado en el que se encuentra el escenario
	private Timer crono;							//timer que avisara a los elementos
	private Jugador jugador;						//jugador controlado por teclado
	private long horaInicio;						//hora de inicio del juego
	private int tiempo;								//tiempo en segundos que dura el juego
	private long horaUltimoLanzamiento;				//hora de la ultima vez que se lanzo un elemento
	private int periodoLanzamiento;					//periodo de lanzamiento de un elemento en segundos
	private int posLanzamiento;
	
	//Constructores
	/**
	 * Construye un escenario vacio a partir de sus dimensiones.
	 * <p><strong>Precondiciones:</strong></p>
	 * <ul>
	 * <li>Las coordenadas deben ser positivas y mayores que cero.</li>
	 * <li>Todos los tiempos deben ser positivos y mayores que cero.</li>
	 * </ul>
	 * @param ancho tama�o horizontal del escenario
	 * @param alto tama�o vertical del escenario
	 * @param temporizador milisegundos que transcurren entre actualizaciones del escenario.
	 * @param tiempo duracion en segundos de la partida.
	 * @param periodoLanzamiento tiempo que se tarda en lanzar elementos desde el aire.
	 */
	public Escenario(int ancho, int alto, int temporizador, int tiempo, int periodoLanzamiento){
		// precondiciones
		if(alto<1 || ancho<1 ){
			throw new IllegalArgumentException("Las coordenadas deben ser positivas y mayores que cero.");
		}
		if(temporizador<1 || tiempo<1 || periodoLanzamiento<1){
			throw new IllegalArgumentException("Todos los tiempos deben ser positivos y matores que cero.");
		}
		elementos= new Elemento[ancho][alto];
		posiciones= new HashMap<Elemento, Posicion>();
		this.alto= alto;
		this.ancho= ancho;
		crono= new Timer(temporizador,this);
		jugador= new Jugador();
		setElemento(jugador, 0, 0);
		this.tiempo= tiempo;
		horaInicio= System.currentTimeMillis();
		this.estado= EstadoEscenario.CONFIGURACION;
		this.periodoLanzamiento= periodoLanzamiento;
	}
	
	//Modificadores
	/**
	 * traslada el elemento recibido como parametro hacia la orientacion deseada.
	 * @param e Elemento que vamos a trasladar
	 * @param o Orientacion hacia la cual queremos trasladar el elemento
	 * @return true si ha sido posible mover el elemento, false en caso contrario.
	 */
	public boolean trasladar(Elemento e, Orientacion o){
		//Variables
		Posicion posDestino= posiciones.get(e).adyacente(o);
		
		//Acciones
		if(movimientoValido(e, o)){
			elementos[posDestino.getX()][posDestino.getY()]= elementos[e.getPosicionX()][e.getPosicionY()];	//copiamos el elemento a la posici�n de destino
			elementos[e.getPosicionX()][e.getPosicionY()]= null;											//elminamos el elemento de la posici�n origen
			posiciones.put(e, posDestino);													//actualizamos su posici�n a la de destino
			return true;
		}
		return false;
	}
	
	/**
	 * Elimina el elemento recibido como parametro del escenario.
	 * @param e Elemento que queremos eliminar del escenario.
	 */
	public void removeElemento(Elemento e){	
		if(estaElemento(e)){								//Si el elemento est� en el escenario...
			elementos[e.getPosicionX()][e.getPosicionY()]= null;			//...lo sacamos
			posiciones.remove(e);
			if(e.tieneEscenario()){							//y si tiene asociado un escenario...
				e.desaparecer();							//...se lo quitamos
			}
		}		
	}
	
	/**
	 * Introduce un elemento en las coordenadas que se indican.
	 * @param e Elemento que queremos colocar en el escenario
	 * @param x Coordenada X en la que queremos situar el elemento
	 * @param y Coordenada Y en la que queremos situar el elemento
	 * @return booleano indicando si ha sido posible la insercion.
	 */
	public boolean setElemento(Elemento e, int x, int y){
		if(getElemento(x, y)==null){						//Si no hay ning�n elemento en la posici�n continuamos
			e.desaparecer();								//lo sacamos del escenario en el que est�
			elementos[x][y]= e;								//lo metemos en este escenario
			posiciones.put(e, new Posicion(x, y));
			if(e.getEscenario()!=this){
				e.setEscenario(this);
			}
			return true;
		}
		return false;										//si ya hab�a un elemento en esa posici�n devolvemos false
	}
	 
	/**
	 * Metodo que actualiza el estado del escenario a COMPLETO.
	 */
	public void arrancar(){
		horaInicio= System.currentTimeMillis();
		if(estado!=EstadoEscenario.CONFIGURACION){
			throw new IllegalArgumentException("No se puede actualizar el estado del escenario. "+
					"El escenario no esta configurado");
		}
		crono.start();
		estado= EstadoEscenario.ARRANCADO;
	}
		
	/**
	 * Metodo que actualiza el estado del escenario a FINALIZADO.
	 */
	public void finalizar(){
		if(estado!=EstadoEscenario.ARRANCADO)
			throw new IllegalArgumentException("No se puede actualizar el estado del escenario. "+
					"El escenario no esta arrancado");
		crono.stop();
		estado= EstadoEscenario.FINALIZADO;
	}

	/**
	 * Metodo privado que lanza un elemento de forma ciclica en el escenario si la casilla esta libre.
	 */
	private void lanzarElemento(){
		//Variables
		Elemento lanzado;
		
		//Acciones
		posLanzamiento = (posLanzamiento + 1) % ancho;
		if(elementos[posLanzamiento][alto-1]!=null) return;
		
		if((System.currentTimeMillis()-horaUltimoLanzamiento)>=periodoLanzamiento){ //comprobamos si debe lanzar el elemento
			if(new Random().nextBoolean()){										//lanzamos una bomba o un huevo
				lanzado= new Bomba(5);
			}
			else{
				lanzado= new Huevo();
			}
			//coordenadaX= (segundosTranscurridos()/periodoLanzamiento)%ancho;	//calculamos la coordenadaX en la que caera
			setElemento(lanzado, posLanzamiento, alto-1);
			//lanzado.setEscenario(this);
			horaUltimoLanzamiento= System.currentTimeMillis();
		}
	}
	
	/**
	 * Metodo privado que recorre los elementos del escenario y les aplica el turno.
	 */
	private void aplicarTurnos(){
		List<Elemento> elementos= getElementos();
		
		for (Elemento elemento : elementos) {
			elemento.aplicarTurno();
		}
	}
	
	/**
	 * Metodo accion que sera invocado en cada tic del timer.
	 */
	public void actionPerformed(ActionEvent arg0) {
		lanzarElemento();
		aplicarTurnos();
		if(tiempoRestante()<=0){
			finalizar();
		}
	}
	
	//Consultas
	/**
	 * Devuelve true si las coordenadas recibidas son validas.
	 * @param x Coordenada X a comprobar
	 * @param y Coordenada Y a comprobar
	 * @return true en caso de encontrarse dentro de las dimensiones del escenario.
	 */
	private boolean coordenadasValidas(int x, int y){
		if(x>=ancho || x<0){										//si la posicion destino se sale del tablero...
			return false;														
		}
		if(y>=alto || y<0){
			return false;														//...devolvemos false
		}
		return true;
	}
	
	/**
	 * Devuelve el elemento que se encuentra en las coordenadas recibidas.
	 * <p><strong>Precondiciones:</strong></p>
	 * <ul>
	 * <li>Las coordenadas deben estar dentro del escenario</li>
	 * </ul>
	 * @param x Coordenada X a comprobar
	 * @param y Coordenada Y a comprobar
	 * @return elemento en la posicion x,y pasadas como parametros
	 */
	public Elemento getElemento(int x, int y){
		if(!coordenadasValidas(x, y)){
			throw new IllegalArgumentException("Las coordenadas se salen del escenario.");
		}
		return elementos[x][y];		
	}
	
	/**
	 * Devuelve el vecino al elemento que se pasa como parametro en una determinada orientacion.
	 * @param e Elemento cuyo vecino queremos conocer
	 * @param o Orientacion hacia la cual se encuentra el vecino.
	 * @return vecino en la orientacion dada, o null si no existe.
	 */
	public Elemento getVecino(Elemento e, Orientacion o){
		//Variables
		Posicion posVecino= posiciones.get(e).adyacente(o);				//calculamos la posici�n del elemento a devolver
		
		//Acciones
		if(coordenadasValidas(posVecino.getX(), posVecino.getY())){
			return elementos[posVecino.getX()][posVecino.getY()];		//devolvemos el elemento de la posici�n adyacente si lo hubiera
		}
		return null;
	}
	
	/**
	 * Obtiene la posicion del elemento que se recibe como parametro.
	 * @param e Elemento cuya posicion queremos conocer.
	 * @return posicion del elemento buscado
	 */
	public Posicion getPosicionElemento(Elemento e){
		return posiciones.get(e);
	}
	
	/**
	 * Permite conocer si dadas coordenadas y una orientacion, el movimiento seria valido.
	 * @param x nuestra X actual
	 * @param y nuestra Y actual
	 * @param o Orientacion hacia la que nos queremos mover
	 * @return booleano indicando true o false en cada caso.
	 */
	public boolean movimientoValido(int x, int y, Orientacion o){
		//Variables
		Posicion posicionDestino= new Posicion(x, y).adyacente(o);
		
		//Acciones
		if(!coordenadasValidas(posicionDestino.getX(), posicionDestino.getY())){
			return false;
		}
		if(elementos[posicionDestino.getX()][posicionDestino.getY()]!=null){	//Si hay otro elemento en la posici�n destino...
			return false;														//...devolvemos false
		}		
		return true;
	}
	
	/**
	 * Permite saber si el elemento recibido se puede mover hacia la orientacion recibida.
	 * @param e Elemento cuyo posible movimiento queremos comprobar
	 * @param o Orientacion hacia la cual queremos movernos
	 * @return booleando indicando si el movimiento es posible.
	 */
	public boolean movimientoValido(Elemento e, Orientacion o){
		return movimientoValido(e.getPosicionX(), e.getPosicionY(), o);
	}
	/**
	 * Permite consultar si un elemento se encuentra en el escenario en este momento.
	 * @param e Elemento buscado
	 * @return booleano indicando si el elemento esta en el escenario
	 */
	public boolean estaElemento(Elemento e){
		if(getPosicionElemento(e)!=null){
			return true;
		}
		return false;
	}
	
	/**
	 * Obtiene todos los elementos que se encuentran en el escenario.
	 * @return lista con cada uno de los elementos.
	 */
	public LinkedList<Elemento> getElementos(){
		//Variables
		Collection<Posicion> listaPosiciones= posiciones.values();
		LinkedList<Elemento> listaElementos= new LinkedList<Elemento>();
		
		//Acciones
		for(Posicion p : listaPosiciones){
			listaElementos.add(elementos[p.getX()][p.getY()]);
		}
		
		return listaElementos;
	}
	/**
	 * Obtiene la anchura del escenario.
	 * @return Anchura del escenario en formato entero
	 */
	public int getTamanoX(){
		return ancho;
	}
	/**
	 * Obtiene la altura del escenario.
	 * @return Altura del escenario en formato entero
	 */
	public int getTamanoY(){
		return alto;
	}
	/**
	 * Metodo de consulta para saber si el escenario posee algun elemento.
	 * @return true si el escenario esta vacio, false si tiene alguno.
	 */
	public boolean estaVacio(){
		return getElementos().isEmpty();
	}
	
	/**
	 * Metodo que devuelve el estado del escenario.
	 * @return Estado del escenario.
	 */
	public EstadoEscenario getEstado(){
		return estado;
	}
	
	/**
	 * Metodo que devuelve el numero de pollos que hay en el escenario.
	 * @return Estado del escenario.
	 */
	public int getNumPollos(){
		int numPollos= 0;
		List<Elemento> elementos= getElementos();
		for (Elemento elemento : elementos) {
			if(elemento instanceof Pollo){
				numPollos++;
			}
		}
		return numPollos;
	}
	
	/**
	 * Metodo que devuelve el jugador del escenario.
	 * @return jugador que hay en el escenario
	 */
	public Jugador getJugador(){
		return jugador;
	}
	
	/**
	 * Devuelve el tiempo total que dura el juego en segundos.
	 * @return tiempo de juego.
	 */
	public int tiempoDeJuego(){
		return tiempo;
	}
	
	/**
	 * Metodo para calcular el numero de segundos que han transcurrido de juego.
	 * @return segundos que han transcurrido desde el inicio de la partida.
	 */
	private int segundosTranscurridos(){
		return (int)((System.currentTimeMillis()-horaInicio)/1000);
	}
	
	/**
	 * Devuelve el tiempo restante que queda de juego en segundos.
	 * @return tiempo restante de juego.
	 */
	public int tiempoRestante(){
		return tiempo-segundosTranscurridos();
	}
}
