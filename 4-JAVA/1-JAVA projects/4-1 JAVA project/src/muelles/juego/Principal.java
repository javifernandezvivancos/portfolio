package muelles.juego;
import muelles.vista.*;

public class Principal {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Apéndice de método generado automáticamente
		IControlador controlador = new Partida();

		// Se toman como valores por defecto la tasa de refresco y los píxeles por unidad

		Pantalla pantalla = new Pantalla(controlador);

		controlador.setPantalla(pantalla);
	}

}
