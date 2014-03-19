package pollos.geometria;
/**
 * Enumerado Orientaci�n, con los cuatro posibles valores ARRIBA, ABAJO, IZQUIERDA y DERECHA.
 * @author Oscar Berrocal Frahija / Javier Fernandez Vivancos
 *
 */
public enum Orientacion {
	ARRIBA, ABAJO, DERECHA, IZQUIERDA;
	/**
	 * Dada una orientaci�n, devuelve la orientaci�n en sentido opuesto.
	 * @return Enumerado Orientaci�n opuesto al actual
	 */
	public Orientacion opuesta(){
		switch(this){
		case ARRIBA:
			return ABAJO;
		case ABAJO:
			return ARRIBA;
		case DERECHA:
			return IZQUIERDA;
		case IZQUIERDA:
			return DERECHA;
		}
		return null;
	}
	/**
	 * Devuelve un enumerado Orientaci�n a partir de una cadena.
	 * @param ori Orientaci�n original en formato de cadena de texto en min�sculas.
	 * @return Enumerado correspondiente al string de entrada, o null si es incorrecto. 
	 */
	public static Orientacion fromString(String ori){
		if(ori.equals("arriba"))	{return ARRIBA; }
		if(ori.equals("abajo"))		{return ABAJO; }
		if(ori.equals("izquierda"))	{return IZQUIERDA; }
		if(ori.equals("derecha"))	{return DERECHA; }
		return null;	
	}
}