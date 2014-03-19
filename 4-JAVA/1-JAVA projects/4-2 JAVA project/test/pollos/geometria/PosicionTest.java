package pollos.geometria;

import junit.framework.TestCase;
/**
 * Pruebas JUNIT para la clase Posicion
 * @author Oscar Berrocal Frahija - Javier Fernandez Vivancos
 *
 */
public class PosicionTest extends TestCase {
	protected Posicion pos1, pos2, pos3;
	
	protected void setUp() throws Exception {
		pos1 = new Posicion(5, 5);
		pos2 = new Posicion();
		pos3 = new Posicion(pos1);
	}
	/**
	 * Pruebas para los constructores
	 */
	public void testPosicion(){
		assertEquals(5, pos1.getX());
		assertEquals(5, pos1.getY());
		
		assertEquals(0, pos2.getX());
		assertEquals(0, pos2.getY());
		
		assertEquals(5, pos3.getX());
		assertEquals(5, pos3.getY());
	}
	/**
	 * Pruebas para las posiciones adyacentes
	 */
	public void testAdyacente(){
		pos2 = pos1.adyacente(Orientacion.DERECHA);
		assertEquals(6, pos2.getX());
		assertEquals(5, pos2.getY());
		
		pos2 = pos1.adyacente(Orientacion.IZQUIERDA);
		assertEquals(4, pos2.getX());
		assertEquals(5, pos2.getY());
		
		pos2 = pos1.adyacente(Orientacion.ARRIBA);
		assertEquals(5, pos2.getX());
		assertEquals(6, pos2.getY());
		
		pos2 = pos1.adyacente(Orientacion.ABAJO);
		assertEquals(5, pos2.getX());
		assertEquals(4, pos2.getY());
		
	}

	/**
	 * Pruebas para los setters de X e Y
	 */
	public void testModificacion(){
		// Probamos con valores positivos
		pos1.setX(15);
		pos1.setY(12);
		assertEquals(15, pos1.getX());
		assertEquals(12, pos1.getY());
		
		// As� como con valores negativos
		pos1.setX(-7);
		pos1.setY(-20);
		assertEquals(-7, pos1.getX());
		assertEquals(-20, pos1.getY());
	}

	/**
	 * Pruebas para el metodo Equals
	 */
	public void testEquals(){
		assertTrue(pos1.equals(pos1)); // pos1 es equivalente a si misma
		assertTrue(pos1.equals(pos3)); // y tambien a pos3
		assertFalse(pos1.equals(null)); // no equivale a null
		assertFalse(pos1.equals(this)); // ni a objetos de otra clase
		assertFalse(pos1.equals(pos2)); // ni a posiciones de distintas coordenadas
	}

	/**
	 * Pruebas para el metodo Clone
	 * @throws CloneNotSupportedException 
	 */
	public void testClone() throws CloneNotSupportedException{
		Posicion pos4;
		pos4 = (Posicion) pos1.clone(); 		// clonamos una posicion
		
		assertEquals(pos1.getX(), pos4.getX());	// y comprobamos que las coordenadas
		assertEquals(pos1.getY(), pos4.getY()); // se han copiado correctamente
		assertTrue(pos1.equals(pos4));			// y que un clon es equivalente al original	
	}
	
}
