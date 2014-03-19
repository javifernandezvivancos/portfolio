package muelles.juego;
import muelles.vista.*;

public class Principal {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Ap�ndice de m�todo generado autom�ticamente
		IControlador controlador = new Partida();

		// Se toman como valores por defecto la tasa de refresco y los p�xeles por unidad

		Pantalla pantalla = new Pantalla(controlador);

		controlador.setPantalla(pantalla);
	}

}
