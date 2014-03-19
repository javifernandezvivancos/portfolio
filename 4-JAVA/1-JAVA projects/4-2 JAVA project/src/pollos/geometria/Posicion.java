package pollos.geometria;
/**
 * Clase Posicion, que cuenta con unas coordenadas enteras X e Y que pueden cambiar.
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 *
 */
public class Posicion implements Cloneable{
	private int x, y;
	
	// Constructores
	/**
	 * Constructor a partir de unas coordeanadas X e Y, de valores enteros.
	 * @param x Coordenada X de la nueva posici�n.
	 * @param y Coordenada Y de la nueva posici�n.
	 */
	public Posicion(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	/**
	 * Constructor sin parametros, establece la posicion en el origen de coordenadas.
	 */
	public Posicion(){
		this(0,0);
	}
	
	/**
	 * Constructor a partir de otra posicion, copia sus coordenadas.
	 * @param pos Posicion de referencia.
	 */
	public Posicion(Posicion pos){
		this(pos.getX(), pos.getY());
	}

	
	// Modificadores
	/**
	 * Establece la coordenada X de la posici�n.
	 * @param x Coordenada X deseada.
	 */
	public void setX(int x) {
		this.x = x;
	}
	
	/**
	 * Establece la coordenada Y de la posici�n.
	 * @param y Coordenada Y deseada.
	 */
	public void setY(int y) {
		this.y = y;
	}
	
	
	// Consultas
	/**
	 * Devuelve la coordenada horizontal de la posici�n.
	 * @return Coordenada X de la posici�n.
	 */
	public int getX() {
		return x;
	}

	/**
	 * Devuelve la coordenada vertical de la posici�n
	 * @return Coordenada Y de la posici�n.
	 */
	public int getY() {
		return y;
	}

	/**
	 * Calcula la posicion adyacente dada una orientacion. Por ejemplo, para DERECHA devolveria una posicion en (x+1, y).
	 * @param ori Orientacion en direccion a la posicion adyacente buscada.
	 * @return Nuevo objeto de la clase Posicion adyacente a la original en la orientacion dada.
	 */
	public Posicion adyacente(Orientacion ori){
		switch (ori){
		case ARRIBA:
			return new Posicion(x, y+1);
		case ABAJO:
			return new Posicion(x, y-1);
		case IZQUIERDA:
			return new Posicion(x-1, y);
		case DERECHA:
			return new Posicion(x+1, y);
		}	
		return null;
	}
	
	/**
	 * Metodo toString para la clase Posicion.
	 * Crea una cadena de texto con informacion relevante del objeto Posicion.
	 * @return Cadena con la informacion del objeto Posicion.
	 */
	@Override
	public String toString(){
		return getClass().getName() +
		"[X = " + this.x + ", Y = " + this.y +	"]";
	}
	/**
	 * Metodo equals para la clase Posicion. Comprueba si dos posiciones son equivalentes.
	 * @param obj Posicion a comparar.
	 * @return true si ambas posiciones tienen las mismas coordenadas, false en caso contrario.
	 */
	@Override
	public boolean equals(Object obj){
		if (obj == null) {return false; }
		if (obj == this) {return true; }
		if (obj.getClass() != this.getClass()) {return false; }
		
		Posicion pos = (Posicion)obj;
		return (this.x==pos.x && this.y==pos.y);
	}
	
	/**
	 * Metodo clone para la clase Posicion. Al no contener datos enlazados,
	 * es suficiente con hacer una copia superficial.
	 * @return Copia del objeto Posicion original.
	 */
	@Override
	public Posicion clone() {
		Object obj = null;
		try {
			obj = super.clone();
		} catch (CloneNotSupportedException e) {
		}
		return (Posicion)obj;
	}
	  
	
	
}