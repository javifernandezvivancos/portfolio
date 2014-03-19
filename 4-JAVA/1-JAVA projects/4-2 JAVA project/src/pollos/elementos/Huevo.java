package pollos.elementos;

import pollos.escenario.Escenario;
import pollos.geometria.Orientacion;
/**
 * Clase Huevo.
 * Los huevos caen en el escenario, y el jugador debe incubarlos, evitando que sean destruidos.
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 *
 */
public class Huevo extends Elemento{

	// Atributos
	private boolean incubado;
	private boolean chafado;
	
	//Constructores
	/**
	 * Constructor a partir de una determinada masa.
	 * @param masa Masa que tendra el huevo.
	 */
	public Huevo(int masa){
		super(masa);
		incubado = false;
		chafado = false;
	}
	
	/**
	 * Constructor suponiendo masa 1.
	 */
	public Huevo(){
		this(1);
	}

	// Acciones
	@Override
	/**
	 * Un huevo no realiza ninguna accion propia en su turno.
	 */
	public void accionPropia() {		
	}

	/**
	 * Evalua el estado del huevo: si ha sido incubado, y si debe generar un pollo, o si ha sido chafado.
	 */
	@Override
	public void evaluarEstado() {
		Elemento ele = getVecino(Orientacion.ARRIBA);

		//Si la posicion esta libre y esta incubado, colocamos un pollo
		if(ele==null && incubado){
			Pollo miPollo = new Pollo();
			Escenario esc = getEscenario();
			miPollo.setEscenario(esc);
			esc.setElemento(miPollo, getPosicionX(), getPosicionY()+1);
			this.desaparecer();
			return;
		}
		
		// Si ha sido chafado, desaparece
		if(chafado){
			this.desaparecer();
			return;
		}
		
		if(ele==null){ return; }
		
		else if(ele.getClass() == Jugador.class){
			incubado = true;
		}
		
		else{
			chafado = true;
		}
	}

	/**
	 * Devuelve la imagen correspondiente.
	 * @return string con el nombre, sin extension, de la imagen.
	 */
	public String getImagen() {
		return "huevo";
	}

}
