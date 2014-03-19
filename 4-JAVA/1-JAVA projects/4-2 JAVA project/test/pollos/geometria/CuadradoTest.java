package pollos.geometria;

import java.util.List;

import junit.framework.TestCase;

public class CuadradoTest extends TestCase {
	protected int lado;
	protected int p1X, p1Y;
	protected Posicion p1;
	protected Cuadrado c1;
	protected List<Posicion> verts;
	
	protected void setUp() throws Exception {
		p1X= 1;
		p1Y= -2;
		lado= 100;
		p1= new Posicion(p1X, p1Y);
		c1 = new Cuadrado(p1, lado);
		verts = c1.getVertices();
		
	}
	
	public void testCuadrado() {
		// Comprobamos el perímetro
		assertEquals(lado*4, c1.getPerimetro());
		
		// Comprobamos el centro
		assertEquals(p1X + lado/2, c1.getCentro().getX());
		assertEquals(p1Y - lado/2, c1.getCentro().getY());
		
		//Comprobamos los vértices
		assertEquals(p1X, verts.get(0).getX());		 // vertInfIzq
		assertEquals(p1Y, verts.get(0).getY());
		assertEquals(p1X, verts.get(1).getX());		 // vertSupIzq
		assertEquals(p1Y-lado, verts.get(1).getY());
		assertEquals(p1X+lado, verts.get(2).getX()); // vertSupDer
		assertEquals(p1Y-lado, verts.get(2).getY());
		assertEquals(p1X+lado, verts.get(3).getX()); // vertInfDer
		assertEquals(p1Y, verts.get(3).getY());
	}

	public void testEscalarEnX() {
		// Probamos escalando al 50%
		c1.escalarEnX(50); // Deberia escalar a la mitad ambos lados
		assertEquals(50, c1.getLado());
		assertEquals(50, c1.getLadoEnX());
		assertEquals(50, c1.getLadoEnY());
		
		// Probamos escalando al 200%
		c1.escalarEnX(200); // Deberia volver al tamaño original
		assertEquals(100, c1.getLado());
		assertEquals(100, c1.getLadoEnX());
		assertEquals(100, c1.getLadoEnY());
		
	}

	public void testEscalarEnY() {
		// Probamos escalando al 50%
		c1.escalarEnX(50); // Deberia escalar a la mitad ambos lados
		assertEquals(50, c1.getLado());
		assertEquals(50, c1.getLadoEnX());
		assertEquals(50, c1.getLadoEnY());
		
		// Probamos escalando al 200%
		c1.escalarEnX(200); // Deberia volver al tamaño original
		assertEquals(100, c1.getLado());
		assertEquals(100, c1.getLadoEnX());
		assertEquals(100, c1.getLadoEnY());
	}

	public void testGetLado() {
		// Comprobamos que ambos lados sean, efectivamente, iguales.
		assertEquals(c1.getLado(), c1.getLadoEnX());
		assertEquals(c1.getLado(), c1.getLadoEnY());
		
		// Y que correspondan con el valor que le hemos dado
		assertEquals(lado, c1.getLado());
		
	}

	public void testEquals(){
		Cuadrado c2 = new Cuadrado(p1, lado);
		Cuadrado c3 = new Cuadrado(p1, lado+1);
		
		assertTrue(c1.equals(c2));
		assertTrue(c2.equals(c1));
		assertFalse(c1.equals(c3));
		assertFalse(c2.equals(c3));
	}

	public void testClone() throws CloneNotSupportedException{
		Cuadrado c2 = null;
		c2 = c1.clone();
		
		assertTrue(c1.getVertices().get(0).equals(c2.getVertices().get(0)));	// Comprobamos que la posicion se ha copiado bien
		assertEquals(c1.getLado(), c2.getLado());								// Lo mismo con el lado
		assertTrue(c1.equals(c2));												// Y que los objetos son equivalentes.
		
	}
	
}
