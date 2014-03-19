package muelles.escenario;

import java.util.Random;

/**
 * Representa una direcci�n bidimensional
 * sus posibles valores son arriba, abajo, derecha o izquierda. 
 * @author Guadalupe Garcia Fernandez, Javier Fernandez Vivancos.
 *
 */
public enum Direccion {
	ARRIBA, ABAJO, DERECHA, IZQUIERDA;
	/**
	 * Devuelve la direcci�n que le solicitemos.
	 * --precondiciones:
	 * - la cadena que se pase como par�metro deber� ser una de las que 
	 * se muestran a continuaci�n y no podr� ser ni null ni vac�a.
	 * @param cadena string de entrada, que puede ser:
	 * arriba-abajo-derecha-izquierda.
	 * @return direcci�n correspondiente al string que le pasamos como par�metro.
	 */
	public static Direccion fromString(String cadena){
		if(cadena==null || cadena.equals("")){
			throw new IllegalArgumentException("No se puede devolver la direcci�n. "+
												"la cadena introducida es null o vac�a");
		}
		if(!(cadena.equals("arriba") || cadena.equals("abajo") || 
			cadena.equals("derecha") || cadena.equals("izquierda"))){
			throw new IllegalArgumentException("No se puede devolver la direcci�n. "+
												"la cadena introducida no es v�lida");
		}
		
		if(cadena.equals("arriba"))
			return ARRIBA;
		else if(cadena.equals("abajo"))
			return ABAJO;
		else if(cadena.equals("derecha"))
			return DERECHA;
		else if(cadena.equals("izquierda"))
			return IZQUIERDA;
		else return null;		
	}
	/**
	 * M�todo que nos sirve para obtener la direcci�n girada en el sentido 
	 * de las agujas del reloj,
	 * porEj: si la direcci�n es arriba, el m�todo devolver� derecha.
	 * @return direcci�n girada en el sentido de las agujas del reloj.
	 */
	public Direccion girarSentidoReloj(){
		if(this == ARRIBA)
			return DERECHA;
		else if(this==DERECHA)
			return ABAJO;
		else if(this==ABAJO)
			return IZQUIERDA;
		else if(this==IZQUIERDA)
			return ARRIBA;
		else
			return null;
	}
	
	/**
	 * Metodo que devuelve el tipo de Direccion respecto
	 * a un entero que se le pasa como parametro.
	 * @param numero Numero que se corresponde con una direccion.
	 * @return Direccion resultante.
	 */
	public static Direccion fromNumber(int numero){
		if(numero==0)
			return ARRIBA;
		if(numero==1)
			return DERECHA;
		if(numero==2)
			return ABAJO;
		if(numero==3)
			return IZQUIERDA;
		else return null;
	}
	
	/**
	 * Metodo que obtiene una direccion aleatoria.
	 * @return Direccion aleatoria resultante.
	 */
	public static Direccion direccionAleatoria(){
		Random rnd = new Random();
		int numeroAleatorio = (int)(rnd.nextDouble()*4);
		return fromNumber(numeroAleatorio);
	}
}
