package muelles.juego;
import java.util.*;
import muelles.configuracion.ConfiguracionIncorrecta;
import muelles.configuracion.ProcesadorConfiguracion;
import muelles.vista.*;
import muelles.elementos.*;
import muelles.escenario.Casilla;
import muelles.escenario.CasillaAleatoria;
import muelles.escenario.Direccion;
import muelles.escenario.Escenario;
import muelles.escenario.EstadoEscenario;
import muelles.escenario.Hueco;
import muelles.escenario.Muelle;

import java.io.IOException;

/**
 * Clase Partida encargada de proporcionar informacion a la pantalla y de recibir
 * mensajes por parte de la pantalla para notificar la pulsacion de las teclas.
 * @author Javier Fernandez Vivancos y Guadalupe Garcia Fernandez.
 *
 */
public class Partida implements IControlador {
	//Atributos:
	private IPantalla pantalla;
	private Map<String, List<List<String>>> config;
	private Escenario escenario;	
	
	//Modificadores:
	/**
	 * Metodo encargado de abrir el fichero de configuracion con la informacion
	 * sobre el escenario del juego.
	 */
	public void abrir(String fichero){
		try{
		config= ProcesadorConfiguracion.procesar(fichero);
		}
		catch(ConfiguracionIncorrecta ci){
			pantalla.abrirDialogo("Incorrecto","El fichero de configuracion no es valido");
		}
		catch(IOException io){
			pantalla.abrirDialogo("Incorrecto","No se puede cargar el fichero de configuracion. "+
			"IOException");
		}		
		cargarConfiguracion();
		pantalla.abrirDialogo("Correcto", "fichero de configuracion abierto correctamente");
	}
	
	/**
	 * Metodo encargado de interpretar la informacion del fichero de configuracion
	 * y cargarlo.
	 */
	private void cargarConfiguracion(){
		if(config==null){
			throw new IllegalArgumentException("No se puede cargar el fichero de configuracion. "+
												"Primero debe abrirse");
		}
		
		String valor1;
		int valor2, valor3, valor4;
		
		//leemos las propiedades del escenario
		List<List<String>> datosEscenario = (List<List<String>>) config.get("escenario");
		
		int visibilidad=101, temporizador=0, x=0, y=0, plantas=0;
				
		for (List<String> datoEscenario : datosEscenario) {
			valor1= datoEscenario.get(0);
			valor2= Integer.parseInt(datoEscenario.get(1));
			if(valor1.equals("plantas")){
				plantas= valor2;
			}
			else if(valor1.equals("x")){
				x= valor2;
			}
			else if(valor1.equals("y")){
				y= valor2;
			}
			else if(valor1.equals("temporizador")){
				temporizador= valor2;
			}
			else if(valor1.equals("visibilidad")){
				visibilidad= valor2;
			}
		}
		
		
		//#################################################
		// Esta comprobacione es necesaria??????? Se comprueba en escenario.java
		if(visibilidad>100 || temporizador==0 || x==0 || y==0 || plantas==0)
			throw new IllegalArgumentException("No se puede crear el escenario. "+
			"faltan propiedades del escenario en el fichero de entrada");
		//si las propiedades son correctas, creamos el escenario
			escenario= new Escenario(plantas,x,y,temporizador,visibilidad);
		
		//leemos las casillas:		
		List<List<String>> casillas = (List<List<String>>) config.get("casillas");
		Casilla c;
		
		for (List<String> casilla : casillas) {
			c= null;
			valor1= casilla.get(0);
			valor2= Integer.parseInt(casilla.get(1));
			valor3= Integer.parseInt(casilla.get(2));
			valor4= Integer.parseInt(casilla.get(3));
			if(valor1.equals("aleatoria")){
				c = new CasillaAleatoria(valor3,valor4);
			}
			else if(valor1.equals("muelle")){
				c = new Muelle(valor3, valor4);
			}
			else if(valor1.equals("hueco")){
				c= new Hueco(valor3, valor4);
			}
			/*if(c==null || valor2>=escenario.getNPlantas() || valor3>=escenario.getX() || valor4>=escenario.getY())
				throw new IllegalArgumentException("No se crear la casilla. "+
				"las propiedades de la casilla "+c+" no son correctas");*/

			try {
				//si la casilla es correcta, la insertamos
				escenario.setCasilla(valor2, c);
			}
			catch (Exception io){
				pantalla.abrirDialogo("Incorrecto", "No se ha podido crear el escenario, las propiedades del fichero" +
						"de configuración no son correctas");
			}

		}
		
		//leemos los elementos:		
		List<List<String>> elementos = (List<List<String>>) config.get("elementos");
		Elemento e;
		
		for (List<String> elemento : elementos) {
			e= null;
			valor1= elemento.get(0);
			valor2= Integer.parseInt(elemento.get(1));
			valor3= Integer.parseInt(elemento.get(2));
			valor4= Integer.parseInt(elemento.get(3));
			if(valor1.equals("compuesta")){
				e = new Compuesta();				
			}
			else if(valor1.equals("loco")){
				e = new Loco();
			}
			else if(valor1.equals("vidente")){
				e= new Vidente();
			}
			else if(valor1.equals("visor")){
				e= new Visor();
			}
			else if(valor1.equals("antorcha_abajo")){
				e= new Antorcha(Direccion.ABAJO);
			}
			else if(valor1.equals("antorcha_derecha")){
				e= new Antorcha(Direccion.DERECHA);
			}
			else if(valor1.equals("antorcha_izquierda")){
				e= new Antorcha(Direccion.IZQUIERDA);
			}
			else if(valor1.equals("antorcha_arriba")){
				e= new Antorcha(Direccion.ARRIBA);
			}
		/*	if(e==null || valor2>=escenario.getNPlantas() || valor3>=escenario.getX() || valor4>=escenario.getY())
				throw new IllegalArgumentException("No se crear el elemento. "+
				"las propiedades del elemento "+e+" no son correctas");*/
			//si el elemento es correcto, lo insertamos en el escenario
			escenario.setElemento(valor2, valor3, valor4, e);
		}
		
		//ponemos el escenario en modo completo
		escenario.setCompleto();
		//Establecemos el jugador en la posición 0,0
		Jugador jugador= new Jugador();
		escenario.setJugador(0, 0, 0, jugador);
		
	}
	
	/**
	 * Metodo que informa si el escenario puede ser dibujado o no.
	 * @return true si el escenario puede dibujarse y false en caso contrario.
	 */
	public boolean dibujarEscenario(){
		
		if (escenario.getEstado()==EstadoEscenario.ARRANCADO){
			return true;
		}
		else {
			return false;
		}
	}
	
	/**
	 * Metodo que devuelve una coleccion con las casillas de la planta activa
	 * si el juego esta en curso, las de la ultima planta si el jugador ha ganado,
	 * y las de la planta baja en caso contrario.
	 * @return Coleccion de casillas.
	 */
	public Collection<Dibujable> getCasillas() {
		Collection<Dibujable> casillas= new ArrayList<Dibujable>();
		//Si el jugador sigue activo mostramos la planta activa
		if(escenario.getJugador().getEstado()==EstadoElemento.ACTIVO){
			casillas.addAll(escenario.getPlantaActiva().getCasillas());			
		}
		//si ha ganado, mostramos las casillas de la última planta.
		else if(escenario.getJugador().getEstado()==EstadoElemento.EXITO){
			casillas.addAll(escenario.obtenerPlanta(escenario.getNPlantas()-1).getCasillas());
		}
		//si ha perdido, mostramos las casillas de la planta baja.
		else{
			casillas.addAll(escenario.obtenerPlanta(0).getCasillas());
		}
		return casillas;
	}
	
	/**
	 * Metodo que devuelve una coleccion con los elementos de la planta activa
	 * si el juego esta en curso, los de la ultima planta si el jugador ha ganado,
	 * y los de la planta baja en caso contrario.
	 * @return Coleccion de elementos.
	 */
	public Collection<Dibujable> getElementos() {
		Collection<Dibujable> elementos= new ArrayList<Dibujable>();
		//Si el jugador sigue activo mostramos la planta activa
		if(escenario.getJugador().getEstado()==EstadoElemento.ACTIVO){
			elementos.addAll(escenario.getPlantaActiva().getElementos());			
		}
		//si ha ganado, mostramos los elementos de la última planta.
		else if(escenario.getJugador().getEstado()==EstadoElemento.EXITO){
			elementos.addAll(escenario.obtenerPlanta(escenario.getNPlantas()-1).getElementos());
			pantalla.setBarraEstado("¡¡¡HAS GANADO!!!");
		}
		//si ha perdido, mostramos los elementos de la planta baja.
		else{
			elementos.addAll(escenario.obtenerPlanta(0).getElementos());
			pantalla.setBarraEstado("HAS PERDIDO... ¡inténtalo de nuevo!");
		}
		return elementos;
	}
	
	/**
	 * Metodo que devuelve la posicion en el eje Y del escenario.
	 * @return Tamaño del eje Y del escenario.
	 */
	public int getAltoEscenario(){
		return escenario.getY();
	}
	
	/**
	 * Metodo que devuelve la posicion en el eje X del escenario.
	 * @return Tamaño del eje X del escenario.
	 */
	public int getAnchoEscenario(){
		return escenario.getX();
	}
	
	/**
	 * Metodo para mover hacia abajo el jugador.
	 */
	public void mueveAbajo(){
		escenario.getJugador().solicitudMueveAbajo();
	}
	
	/**
	 * Metodo para mover hacia arriba el jugador.
	 */
	public void mueveArriba(){
		escenario.getJugador().solicitudMueveArriba();
	}
	
	/**
	 * Metodo para mover hacia la derecha el jugador.
	 */
	public void mueveDerecha(){
		escenario.getJugador().solicitudMueveDerecha();
	}
	
	/**
	 * Metodo para mover hacia la izquierda el jugador.
	 */
	public void mueveIzquierda(){
		escenario.getJugador().solicitudMueveIzquierda();
	}	
	
	/**
	 * Metodo para activar el arma del jugador. 
	 */
	public void accion (){
		escenario.getJugador().solicitudActivarArma();
	}
	
	/**
	 * Metodo para crear una nueva partida a partir del escenario cargado
	 * con el fichero de configuracion.
	 */
	public void nueva(){
		if (escenario==null){
			pantalla.abrirDialogo("Error: ", "debe introducir un fichero de configuración");
		}
		else {
			escenario.arrancar();
			pantalla.setBarraEstado("Juego arrancado");
		}
	}
	
	/**
	 * Metodo que establece la pantalla pasada como parametro.
	 */
	public void setPantalla (IPantalla pantalla){
		this.pantalla=pantalla;
	}
}


