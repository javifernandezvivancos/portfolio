package pollos.juego;
import pollos.vista.*;
/**
 * Clase Principal del programa, se encarga de lanzar la aplicación.
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 *
 */

public class Principal {

	/**
	 * Metodo principal del programa.
	 */
	public static void main(String[] args) {
		IControlador controlador = new Partida();

		Pantalla pantalla = new Pantalla(controlador);
		
		controlador.setPantalla(pantalla);
	}

}
