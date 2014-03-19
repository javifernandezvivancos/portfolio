package pollos.elementos;

import java.util.List;

import pollos.escenario.Escenario;
import pollos.geometria.Orientacion;
import pollos.geometria.Posicion;
import junit.framework.TestCase;

public class ElementoTest extends TestCase {
	private Escenario esc;
	private Elemento ele1, ele2; 
	int m1, m2;
	
	protected void setUp() throws Exception {
		// Variables
		esc = new Escenario(32, 32, 500, 60, 1);
		ele1 = new Jugador(5);
		ele2 = new Jugador(15);
		
		// Valores iniciales de las masas
		m1 = 5;
		m2 = 15;
		
		// Establecemos algunas relaciones iniciales
		ele1.setEscenario(esc);
		ele2.setEscenario(esc);
		esc.setElemento(ele1, 10, 31);
		esc.setElemento(ele2, 10, 30);
	}


	public void testElemento() {
		// Comprobamos las propiedades del primer elemento
		assertEquals(10, ele1.getPosicionX());
		assertEquals(31, ele1.getPosicionY());
		assertEquals(esc, ele1.getEscenario());
		assertTrue(ele1.tieneEscenario());
		assertEquals(m1, ele1.getMasa());
		assertEquals(m1, ele1.getMasaTotal());
		
		// Y del segundo
		assertEquals(10, ele2.getPosicionX());
		assertEquals(30, ele2.getPosicionY());
		assertEquals(esc, ele2.getEscenario());
		assertTrue(ele2.tieneEscenario());
		assertEquals(m2, ele2.getMasa());
		assertEquals(m1 + m2, ele2.getMasaTotal());
		
		// Comprobamos las relaciones de vecindad
		assertEquals(ele2, ele1.getVecino(Orientacion.ABAJO));
		assertEquals(ele1, ele2.getVecino(Orientacion.ARRIBA));
		assertEquals(null, ele1.getVecino(Orientacion.ARRIBA));

		// Vecinos del primer elemento
		List<Elemento> vecinos;
		vecinos = ele1.getVecinos();										// Comprobamos que solo hay un vecino en la lista
		assertEquals(1, vecinos.size());		
		assertEquals(ele2, vecinos.remove(0));
		assertEquals(0, vecinos.size());		

		// Vecinos del segundo elemento
		vecinos = ele2.getVecinos();										// Comprobamos que solo hay un vecino en la lista
		assertEquals(1, vecinos.size());		
		assertEquals(ele1, vecinos.remove(0));
		assertEquals(0, vecinos.size());		

	}

	public void testSetEscenario() {
		Escenario esc2 = new Escenario(32, 32, 500, 60, 1);
		esc2.setElemento(ele2, 3, 3);
		
		// El elemento ya no esta en el escenario 1
		assertFalse(esc2.estaElemento(ele1));
		assertEquals(null, esc.getPosicionElemento(ele2));
		
		// Se ha movido al escenario 2, con nuevas coordenadas
		assertTrue(esc2.estaElemento(ele2));
		assertEquals(new Posicion(3, 3), esc2.getPosicionElemento(ele2));
		
	}

	
	public void testMover() {
		int coordAux;
		
		// Movimiento no valido
		coordAux = ele1.getPosicionY();
		ele1.mover(Orientacion.ABAJO);
		assertEquals(coordAux, ele1.getPosicionY()); // no ha podido moverse
		ele1.mover(Orientacion.ARRIBA);
		assertEquals(coordAux, ele1.getPosicionY()); // no ha podido moverse
		
		// Movimiento valido
		coordAux = ele1.getPosicionX();
		ele1.mover(Orientacion.DERECHA);
		assertNotSame(coordAux, ele1.getPosicionX()); // no ha podido moverse
	}

	public void testDesaparecer() {
		int tX, tY;
		
		tX = ele1.getPosicionX();
		tY = ele1.getPosicionY();
		
		// quitamos el elemento
		ele1.desaparecer();
		
		// ya no tiene escenario
		assertFalse(ele1.tieneEscenario());
		assertEquals(null, ele1.getEscenario());
		
		// y el escenario ya no lo tiene
		assertFalse(esc.estaElemento(ele1));
		assertEquals(null, esc.getElemento(tX, tY));
	}
	
}
