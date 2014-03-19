package pollos.geometria;
/**
 * Clase Cuadrado, caracterizada por tener todos sus lados iguales. 
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 *
 */
public class Cuadrado extends Rectangulo{

	//Constructores
	/**
	 * Constructor de un cuadrado.
	 * @param inferiorIzquierda posicion inferior izquierda del cuadrado.
	 * @param lado Magnitud del lado del cuadrado.
	 */
	public Cuadrado(Posicion inferiorIzquierda, int lado) {
		super(inferiorIzquierda, lado, lado);
	}
	
	//Modificadores
	/**
	 * La permutacion no tiene sentido en el caso del cuadrado, el metodo no hace nada.
	 */	
	public void permutar(){
	}
	
	/**
	 * Metodo para escalar un cuadrado en el eje X.
	 * Al ser un cuadrado, en realidad se escalan ambos ejes.
	 * - precondiciones: El porcentaje debe estar entre 1 y 100.
	 * @param porcentaje porcentaje a escalar.
	 */
	public void escalarEnX(int porcentaje){
		super.escalarEnX(porcentaje);
		super.escalarEnY(porcentaje);
	}
	
	/**
	 * Metodo para escalar un cuadrado en el eje Y.
	 * Al ser un cuadrado, en realidad de escalan ambos ejes.
	 * @param porcentaje porcentaje a escalar.
	 */
	public void escalarEnY(int porcentaje){
		super.escalarEnX(porcentaje);
		super.escalarEnY(porcentaje);
	}

	// Consultas
	/**
	 * Lado del cuadrado, identico en X e Y.
	 * @return Lado del cuadrado, en formato entero.
	 * @see pollos.geometria.Rectangulo#getLadoEnX()
	 */	
	public int getLado(){		
		return getLadoEnX();
	}

	
	
	/**
	 * Metodo toString del cuadrado.
	 * Devuelve una cadena con informacion relevante.
	 * @return cadena de texto con informacion sobre el cuadrado
	 */
	@Override
	public String toString() {
		return  getClass().getName() + "[Posicion=" 
				+ inferiorIzquierda.getX() + "," + inferiorIzquierda.getY()
				+ ", lado=" + getLado() + "]";
	}	

	/**
	 * Metodo clone del cuadrado.
	 * Devuelve un cuadrado en la misma posicion y con el mismo lado.
	 * @return copia del cuadrado
	 */
	@Override
	public Cuadrado clone() throws CloneNotSupportedException{
		Cuadrado cuad = new Cuadrado(inferiorIzquierda.clone(), getLado());
		return cuad;
	}
}
