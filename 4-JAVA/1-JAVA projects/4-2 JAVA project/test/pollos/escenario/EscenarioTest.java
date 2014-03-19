package pollos.escenario;

import java.util.List;

import junit.framework.TestCase;
import pollos.elementos.Elemento;
import pollos.elementos.Jugador;
import pollos.geometria.Orientacion;
/**
 * Pruebas JUNIT para la clase Escenario
 * @author Oscar Berrocal Frahija - Javier Fernandez Vivancos
 *
 */
public class EscenarioTest extends TestCase {
	protected Escenario escenario;
	protected Elemento elemento1, elemento2, elemento3;
	
	protected void setUp() throws Exception {		
		escenario= new Escenario(100, 50, 500, 60, 1);
		elemento1= new Jugador(5);
		elemento2= new Jugador(10);
		elemento3= new Jugador(20);
	}

	public void testPosicion(){
		assertEquals(100, escenario.getTamanoX());
		assertEquals(50, escenario.getTamanoY());
		assertTrue(escenario.estaVacio());
	}

	public void testElemento(){
		//Variables
		int posX= 10;int posY= 20;
		int posX2= 99;int posY2= 49;
		List<Elemento> elementos;
		
		//Acciones
		escenario.setElemento(elemento1, posX, posY);							//metemos el elemento1 en el escenario
		assertEquals(elemento1, escenario.getElemento(posX, posY));				//comprobamos que est� dentro
		assertEquals(posX, escenario.getPosicionElemento(elemento1).getX());	//en la posici�n indicada
		assertEquals(posY, escenario.getPosicionElemento(elemento1).getY());
		assertFalse(escenario.setElemento(elemento2, posX, posY));				//intentamos meter el elemento2 en la misma posici�n, pero nos devuelve false
		escenario.setElemento(elemento3, posX2, posY2);							//situamos el elemento3 en una nueva posici�n
		elementos= escenario.getElementos();									//obtenemos todos los elementos del escenario
		assertTrue(elementos.remove(elemento1));								//y vemos que tenemos el primero...
		assertTrue(elementos.remove(elemento3));								//...y el tercero
		assertTrue(elementos.isEmpty());										//y que no quedan m�s
		escenario.removeElemento(elemento3);									//eliminamos el elemento3
		elementos= escenario.getElementos();									//y obtenemos todos los elementos del escenario de nuevo
		assertEquals(elemento1, elementos.remove(0));						//comprobamos que est� el elemento1
		assertTrue(elementos.isEmpty());										//y ya est�
	}
	
	public void testVecino(){
		List<Elemento> vecinos;
		escenario.setElemento(elemento1, 20, 10);								//situamos los 2 elementos para que sean vecinos
		escenario.setElemento(elemento2, 20, 11);
		
		assertEquals(elemento2,elemento1.getVecino(Orientacion.ARRIBA));		//comprobamos que realmente lo son
		
		vecinos = elemento1.getVecinos();										// Comprobamos que solo hay un vecino en la lista
		assertEquals(elemento2, vecinos.remove(0));
		assertEquals(0, vecinos.size());
	}
	
	public void testMovimiento(){
		escenario.setElemento(elemento1, 20, 49);								//establecemos el elemento1 en una posici�n del borde
		assertFalse(escenario.movimientoValido(elemento1, Orientacion.ARRIBA));	//comprobamos c�ales son sus movimientos v�lidos
		assertTrue(escenario.movimientoValido(elemento1, Orientacion.ABAJO));
		assertFalse(escenario.movimientoValido(0, 10, Orientacion.IZQUIERDA));	//hacemos lo mismo con el otro m�todo que no recibe ning�n elemento
		assertTrue(escenario.movimientoValido(0, 10, Orientacion.DERECHA));		

	}
	
	public void testTrasladar(){
		escenario.setElemento(elemento1, 0, 20);
		escenario.setElemento(elemento2, 1, 20);
		assertFalse(escenario.trasladar(elemento1, Orientacion.DERECHA));		//trasladar el elemento1 hacia la posici�n en la que se encuentra el elemento2 no se realiza
		assertTrue(escenario.trasladar(elemento1, Orientacion.ARRIBA));			//s� se realiza si el movimiento es v�lido
		assertFalse(escenario.trasladar(elemento1, Orientacion.IZQUIERDA));		//y no se realiza si intentamos sacarlo del tablero
	}
}
