package muelles.escenario;

import muelles.elementos.*;
import java.util.LinkedList;
import java.awt.event.*;
import javax.swing.Timer;
import java.util.Random;

/**
 * Representa al escenario del juego.
 * @author Javier Fernandez Vivancos y Guadalupe Garcia Fernandez.
 *
 */

public class Escenario implements ActionListener{
	
	//Atributos:
	private int dimensionX, dimensionY, nPlantas;
	private Planta plantaBaja;
	private Jugador jugador;
	private EstadoEscenario estado;
	private int visibilidad;			//porcentaje de visibilidad
	private Timer crono;
	private int delay;
	
	
	//Constructores:
	/** Constructor del Escenario. Se le asigna el numero de plantas,
	 * la dimension de las mismas, el atributo delay y la visibilidad.
	 * --precondiciones:
	 * - el número de plantas, x, y deben ser mayores que cero.
	 */
	public Escenario(int nPlantas, int dimensionX, int dimensionY, int delay, int visibilidad){
		
		if (nPlantas<=0 | dimensionX<=0 | dimensionY<=0 | visibilidad<=0){
			throw new IllegalArgumentException("Error:"+
					"Los parametros introducidos en el escenario tienen que ser mayor de cero");
		}
		
		Planta pAux;
		
		this.nPlantas= nPlantas;
		this.dimensionX= dimensionX;
		this.dimensionY= dimensionY;	
		
		plantaBaja= new Planta(dimensionX, dimensionY);
		pAux= plantaBaja;
		for(int i=1;i<nPlantas;i++){
			pAux.setPlantaSuperior(new Planta(dimensionX, dimensionY));
			pAux = pAux.getPlantaSuperior();
		}
		estado= EstadoEscenario.CONFIGURACION;
		this.delay = delay;
		this.visibilidad= visibilidad;
	}
	
	//Consultas:
	/**
	 * Metodo que devuelve el numero de plantas del escenario.
	 * @return Entero numero de plantas.
	 */
	public int getNPlantas(){
		return nPlantas;
	}
	
	/**
	 * Metodo que devuelve la dimension del eje X del escenario.
	 * @return Entero dimension x.
	 */
	public int getX(){
		return dimensionX;
	}
	
	/**
	 * Metodo que devuelve la dimension del eje Y del escenario.
	 * @return Entero dimension y.
	 */
	public int getY(){
		return dimensionY;
	}
	
	/**
	 * Metodo que devuelve el jugador del escenario.
	 * @return Jugador del escenario.
	 */
	public Jugador getJugador(){
		if(estado!=EstadoEscenario.PREPARADO && estado!=EstadoEscenario.ARRANCADO && estado!=EstadoEscenario.FINALIZADO){
			throw new IllegalStateException("No se puede consultar el jugador. "+
			"el escenario no está preparado");
		}
		return jugador;
	}
	
	/**
	 * Metodo que devuelve la planta activa actual del escenario.
	 * @return Planta activa del escenario.
	 */
	public Planta getPlantaActiva(){
		if(estado!=EstadoEscenario.ARRANCADO){
			throw new IllegalStateException("No se puede consultar el jugador. "+
			"el escenario no está preparado");
		}
		
		return jugador.getPlanta();
	}
	
	/**
	 * Metodo que devuelve el indice de la planta activa actual del escenario.
	 * @return Entero indice de la planta activa.
	 */
	public int getIndicePlantaActiva(){
		if(estado!=EstadoEscenario.ARRANCADO){
			throw new IllegalStateException("No se puede consultar la planta activa. "+
			"el escenario no está preparado");
		}
		
		Planta plantaJugador= jugador.getPlanta();
		
		for(int i=0;i<nPlantas;i++){
			if(obtenerPlanta(i)==plantaJugador)
				return i;
		}
		
		throw new IllegalStateException("No se puede consultar la planta activa. "+
				"No hay ninguna planta activa. "+"No hay ningun jugador en el escenario");
	}
	
	/**
	 * Metodo que devuelve el estado del escenario.
	 * @return Estado del escenario.
	 */
	public EstadoEscenario getEstado(){
		return estado;
	}
	
	/**
	 * Metodo que devuelve una planta del escenario pasandole como
	 * parametro el indice de la misma. 
	 * @param piso Indice de la planta.
	 * @return Planta correspondiente al indice pasado como parametro.
	 */
	public Planta obtenerPlanta(int piso){
		Planta planta= plantaBaja;
		for(int i=0;i<piso;i++){
			planta= planta.getPlantaSuperior();
		}
		return planta;
	}
	
	//Modificadores:
	/**
	 * Metodo que crea una nueva casilla en la planta,
	 * posicion x y posicion y pasados como parametro.
	 * @param nPlanta Indice de la planta.
	 * @param x Posicion en el eje X.
	 * @param y Posicion en el eje Y.
	 */
	public void nuevaCasilla(int nPlanta, int x, int y){
		if ((this.nPlantas<nPlanta) || (x>=dimensionX) || (y>=dimensionY))
			throw new IllegalArgumentException ("No se ha podido crear la casilla." +
					"Los parametros pasados no son correctos.");
		obtenerPlanta(nPlanta).removeCasilla(x, y);
	}
	
	/**
	 * Metodo que inserta una casilla en una planta determinada,
	 * ambas pasadas como parametro.
	 * @param nPlanta Indice de la planta en la que se va a insertar la casilla.
	 * @param cn Casilla a insertar.
	 */
	public void setCasilla(int nPlanta, Casilla cn){
		if ((this.nPlantas<nPlanta) || (cn==null) || (cn.getX()>=dimensionX) || (cn.getY()>=dimensionY))
			throw new IllegalArgumentException ("No se ha podido insertar la casilla." +
					"Los parametros pasados no son correctos.");
		obtenerPlanta(nPlanta).setCasilla(cn);
	}
	/**
	 * Metodo encargado de establecer un elemento en una planta,
	 * posicion x y posicion y pasados como parametro.
	 */
	public void setElemento(int nPlanta, int x, int y, Elemento elem){
	/*	if ((this.nPlantas>nPlanta) || (elem==null) || (x>=dimensionX) || (y>=dimensionY))
			throw new IllegalArgumentException ("No se ha podido establecer el elemento." +
					"Los parametros pasados no son correctos.");*/
		obtenerPlanta(nPlanta).getCasilla(x, y).setElemento(elem);
	}
	
	/**
	 * Metodo que inserta un jugador en la casilla una planta,
	 * pasados como parametros.
	 * @param nPlanta Planta en la que se va a insertar el jugador
	 * @param x Posicion en el eje x de la casilla en la que se va a insertar el jugador.
	 * @param y Posicion en el eje y de la casilla en la que se va a insertar el jugador.
	 * @param jugador Jugador a insertar.
	 */
	public void setJugador(int nPlanta, int x, int y, Jugador jugador){	
		if ((this.nPlantas<nPlanta) || (jugador==null) || (x>=dimensionX) || (y>=dimensionY))
			throw new IllegalArgumentException ("No se ha podido insertar el jugador." +
					"Los parametros pasados no son correctos.");
		
		if(estado!=EstadoEscenario.COMPLETO){
			throw new IllegalStateException("No se puede establecer el jugador. "+
			"el escenario no está completo");
		}
		
		obtenerPlanta(nPlanta).getCasilla(x, y).setElemento(jugador);
		this.jugador= jugador;
		estado= EstadoEscenario.PREPARADO;
	}
	
	/**
	 * Metodo que actualiza el estado del escenario a COMPLETO.
	 */
	public void setCompleto(){
		if(estado!=EstadoEscenario.CONFIGURACION)
			throw new IllegalStateException("No se puede actualizar el estado del escenario. "+
					"El escenario no esta configurado");
		estado= EstadoEscenario.COMPLETO;
	}
	
	/**
	 * Metodo que actualiza el estado del escenario a ARRANCADO.
	 */
	public void arrancar(){
		if(estado!=EstadoEscenario.PREPARADO)
			throw new IllegalStateException("No se puede actualizar el estado del escenario. "+
					"El escenario no esta preparado");
		estado= EstadoEscenario.ARRANCADO;
		animar();
	}
	
	/**
	 * Metodo que actualiza el estado del escenario a FINALIZADO.
	 */
	public void finalizar(){
		if(estado!=EstadoEscenario.ARRANCADO)
			throw new IllegalStateException("No se puede actualizar el estado del escenario. "+
					"El escenario no esta arrancado");
		estado= EstadoEscenario.FINALIZADO;
	}
	
	/**
	 * Metodo que activa el temporizador, es decir, se inicia la animacion
	 * del juego.
	 */
	private void animar(){		
		crono= new Timer(delay,this);
		crono.start();
	}
	
	/**
	 * Metodo que va a actualizando el escenario.
	 */
	public void actionPerformed(ActionEvent e){
		LinkedList<Elemento> elementos;
		LinkedList<Casilla> casillasPlantaActiva;
		LinkedList<Casilla> casillasVisibles= new LinkedList<Casilla>();
		Random rnd= new Random();
		int nAleatorio;
		int nCasillasVisibles;
		Elemento eAux;
		Autonomo aAux;		

		if(jugador.getEstado()==EstadoElemento.EXITO){
			finalizar();
		}
		else if(jugador.getEstado()==EstadoElemento.FRACASO){
			finalizar();
		}
		else if(jugador.getEstado()==EstadoElemento.DESAPARECIDO){
			finalizar();
		}
		//si el escenario está finalizado, paramos el reloj
		if(estado==EstadoEscenario.FINALIZADO){
			crono.stop();
		}
		//si no, continuamos con el juego
		else{
			elementos= getPlantaActiva().getElementos();
			nCasillasVisibles= (this.getX()*this.getY()*visibilidad)/100;
			//ocultamos todas las casillas de la planta activa:
			for(int i=0;i<this.getPlantaActiva().getTamX();i++){
/*				for(int j=0;j<this.getPlantaActiva().getTamY();j++){
					this.getPlantaActiva().getCasilla(i, j).ocultar();
				}*/
				for (Casilla casilla:this.getPlantaActiva().getCasillas()){
					casilla.ocultar();
				}
			}
			//mostramos casillas de forma aleatoria sin repetir ninguna de las casillas ya mostradas
			casillasPlantaActiva= this.getPlantaActiva().getCasillas(); //primero obtenemos todas las casillas de la planta activa
			for(int i=0;i<nCasillasVisibles;i++){						//hacemos una iteración por cada casilla que queremos mostrar
				nAleatorio= (int)(rnd.nextDouble()*casillasPlantaActiva.size());
				casillasVisibles.add(casillasPlantaActiva.remove(nAleatorio));//vamos sacando casillas de la lista total y las vamos metiendo en la lista de casillas visibles
			}
			for(int i=0;i<nCasillasVisibles;i++){		//mostramos la lista de casillas visibles
				casillasVisibles.removeFirst().mostrar();
			}
									
			
			while (!elementos.isEmpty()){	//recorremos los elementos de la planta activa...
				eAux= elementos.removeFirst();
				if(eAux instanceof Autonomo){//...nos quedamos con los autónomos...
					aAux= (Autonomo)eAux;
					if(eAux.getEstado()==EstadoElemento.ACTIVO)
						aAux.accion();//...y los accionamos.
				}
			}
		}
	}
}