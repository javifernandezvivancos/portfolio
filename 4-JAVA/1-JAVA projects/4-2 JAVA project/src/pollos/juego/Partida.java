package pollos.juego;

//import java.awt.List;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Map;
import java.util.List;
import pollos.configuracion.ConfiguracionIncorrecta;
import pollos.configuracion.ProcesadorConfiguracion;
import pollos.vista.*;
import pollos.escenario.Escenario;
import pollos.escenario.EstadoEscenario;
import pollos.elementos.BloqueBasico;
import pollos.elementos.BloqueDeslizante;
import pollos.elementos.BloqueEstatico;
import pollos.elementos.Bomba;
import pollos.elementos.Elemento;
import pollos.elementos.Huevo;
import pollos.elementos.Nube;
import pollos.geometria.Orientacion;
/**
 * Clase Partida, encargada de controlar el transcurso de la misma.
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 *
 */
public class Partida implements IControlador{
	//Atributos:
	private IPantalla pantalla;
	private Map<String, List<List<String>>> config;
	private Escenario escenario;	
	private enum estadoResultados{SINMOSTRAR, MOSTRADOS};
	private estadoResultados misResultados;
	
	//Modificadores:
	/**
	 * Metodo encargado de abrir el fichero de configuracion con la informacion
	 * sobre el escenario del juego.
	 * @param fichero ruta del fichero a cargar.
	 */
	public void abrir(String fichero){
		try{
			config= ProcesadorConfiguracion.procesar(fichero);
		}
		catch(ConfiguracionIncorrecta ci){
			pantalla.abrirDialogo("Incorrecto","El fichero de configuracion no es valido");
			throw new IllegalArgumentException("No se puede cargar el fichero de configuracion. "+
			"Configuracion Incorrecta");

		}
		catch(IOException io){
			throw new IllegalArgumentException("No se puede cargar el fichero de configuracion. "+
			"IOException");
		}		
		cargarConfiguracion();
		pantalla.abrirDialogo("Correcto", "fichero de configuracion abierto correctamente");
	}
	
	/**
	 * Metodo encargado de interpretar la informacion del fichero de configuracion
	 * y cargarlo.
	 * <p><strong>Precondiciones</p></strong>
	 * <ul>
	 * <li>Se debe suministrar un fichero de configuracion siguiendo el formato adecuado.</li>
	 * </ul>
	 */
	public void cargarConfiguracion(){
		if(config==null){
			throw new IllegalArgumentException("No se puede cargar el fichero de configuracion. "+
												"Primero debe abrirse");
		}
		
		String valor1;
		int valor2, valor3;
		
		//leemos las propiedades del escenario
		List<List<String>> datosEscenario = (List<List<String>>) config.get("escenario");
		
		int tiempo=101, temporizador=0, ancho=0, alto=0, lanzamiento=0;
				
		for (List<String> datoEscenario : datosEscenario) {
			valor1= datoEscenario.get(0);
			valor2= Integer.parseInt(datoEscenario.get(1));
			if(valor1.equals("lanzamiento")){
				lanzamiento= valor2;
			}
			else if(valor1.equals("ancho")){
				ancho= valor2;
			}
			else if(valor1.equals("alto")){
				alto= valor2;
			}
			else if(valor1.equals("temporizador")){
				temporizador= valor2;
			}
			else if(valor1.equals("tiempo")){
				tiempo= valor2;
			}
		}
		//Controlamos las precondiciones del constructor del escenario
		if(tiempo==0 || temporizador==0 || ancho==0 || alto==0 || lanzamiento==0)
			throw new IllegalArgumentException("No se puede crear el escenario. "+
			"faltan propiedades del escenario en el fichero de entrada");
		//si las propiedades son correctas, creamos el escenario
		escenario= new Escenario(ancho, alto, temporizador, tiempo, lanzamiento);
		
		//leemos los elementos:		
		List<List<String>> elementos = (List<List<String>>) config.get("elementos");
		Elemento e;
		
		for (List<String> elemento : elementos) {
			e= null;
			valor1= elemento.get(0);
			valor2= Integer.parseInt(elemento.get(1));
			valor3= Integer.parseInt(elemento.get(2));
			if(valor1.equals("basico")){
				e = new BloqueBasico();
			}
			else if(valor1.equals("estatico")){
				e = new BloqueEstatico();
			}
			else if(valor1.equals("deslizante")){
				String direccion= elemento.get(3);
				e= new BloqueDeslizante(direccion);
			}
			else if(valor1.equals("nube")){
				String direccion= elemento.get(3);
				e= new Nube(Orientacion.fromString(direccion));
			}
			else if(valor1.equals("huevo")){
				e= new Huevo();
			}
			else if(valor1.equals("bomba")){
				int segundos= Integer.parseInt(elemento.get(3));
				e= new Bomba(segundos);
			}
			if(e==null  || valor2>=escenario.getTamanoX() || valor3>=escenario.getTamanoY())
				throw new IllegalArgumentException("No se crear el elemento. "+
				"las propiedades del elemento "+e+" no son correctas");
			//si el elemento es correcto, lo insertamos en el escenario
			escenario.setElemento(e, valor2, valor3);
		}
		
		misResultados = estadoResultados.SINMOSTRAR;
		 
		//ponemos el escenario en modo completo
		//escenario.setCompleto();
		//Establecemos el jugador en la posici�n 0,0
		//Jugador jugador= new Jugador();
		//escenario.setJugador(0, 0, 0, jugador);		
	}
	
	/**
	 * Metodo que informa si el escenario puede ser dibujado o no.
	 * @return true si el escenario puede dibujarse y false en caso contrario.
	 */
	public boolean dibujarEscenario(){
		if(escenario==null){return false;}
		if(escenario.getEstado()==EstadoEscenario.FINALIZADO){
			if(misResultados == estadoResultados.SINMOSTRAR){
				misResultados = estadoResultados.MOSTRADOS;
				pantalla.abrirDialogo("Fin de la partida!", "Has salvado " + escenario.getNumPollos() + " pollos");
			}
			pantalla.setBarraEstado("JUEGO TERMINADO!");
		}
		else if(escenario.getEstado()==EstadoEscenario.ARRANCADO){
			pantalla.setBarraEstado("Tiempo restante: " + escenario.tiempoRestante() + " segundo(s)");
		}
		
		if (escenario.getEstado()==EstadoEscenario.ARRANCADO){
			return true;
		}
		else {
			return false;
		}
	}
	
	/**
	 * Metodo que establece la pantalla pasada como parametro.
	 * @param pantalla identificador de la pantalla a la que pertenecerá la ventana.
	 */
	public void setPantalla (IPantalla pantalla){
		this.pantalla=pantalla;
	}
	
	/**
	 * Metodo que devuelve la posicion en el eje Y del escenario.
	 * @return Tama&ntilde;o del eje Y del escenario.
	 */
	public int getAltoEscenario(){
		return escenario.getTamanoY();
	}
	
	/**
	 * Metodo que devuelve la posicion en el eje X del escenario.
	 * @return Tama&ntilde;o del eje X del escenario.
	 */
	public int getAnchoEscenario(){
		return escenario.getTamanoX();
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
	 * Metodo para mover hacia abajo el jugador.
	 */
	public void mueveAbajo(){
		escenario.getJugador().solicitudMueveAbajo();
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
	public void empujar(){
		escenario.getJugador().solicitudEmpujar();
	}

	/**
	 * Metodo que devuelve la coleccion de objetos dibujables del escenario.
	 * @return Coleccion de objetos de tipo Dibujable.
	 */
	
	public Collection<Dibujable> getDibujables() {
		Collection<Dibujable> elementos= new ArrayList<Dibujable>();
		
		elementos.addAll(escenario.getElementos());
		for (Dibujable e:elementos){
			if (!((Elemento)e).tieneEscenario())elementos.remove(e);
		}
		return elementos;
	}	

	/**
	 * Metodo para crear una nueva partida a partir del escenario cargado
	 * con el fichero de configuracion.
	 */
	public void nueva(){
		if (escenario==null){
			pantalla.abrirDialogo("Error: ", "debe introducir un fichero de configuraci�n");
		}
		else if(escenario.getEstado()!=EstadoEscenario.CONFIGURACION){
			pantalla.abrirDialogo("Aviso: ", "para empezar otra partida, debe cargar un fichero.");			
		}
		else {
			escenario.arrancar();
			pantalla.setBarraEstado("Juego arrancado");
		}
	}
}
