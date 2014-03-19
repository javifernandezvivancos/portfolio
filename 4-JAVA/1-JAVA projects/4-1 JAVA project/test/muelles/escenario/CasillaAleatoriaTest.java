package muelles.escenario;

import muelles.elementos.*;
import junit.framework.TestCase;

public class CasillaAleatoriaTest extends TestCase {

	protected Planta planta1;
	protected CasillaAleatoria casilla1, casilla2;
	protected Elemento elemento1, elemento2;
	
	protected void setUp() {
		planta1= new Planta(10,10);
		casilla1= new CasillaAleatoria (1,2, planta1);
		casilla2= new CasillaAleatoria (2,1);
		elemento1= new Loco();					//le asignamos un valor a elemento1
		elemento2= new Vidente();					//"		"	"	"	"	" elemento2
	
		
	}
	
	public void testCasillaAleatoriaIntIntPlanta() {
		assertEquals (true, casilla1.isVisible());
		assertEquals (true, casilla2.isVisible());
	}

	public void testOcultar() {
		casilla1.ocultar();
		assertEquals (true, casilla1.isVisible());
	}
	
	public void testElemento() {
		assertEquals (true, planta1.getElementos().isEmpty());
		assertEquals (false, casilla1.isLlena());
		
		casilla1.setElemento(elemento1);
		assertEquals (false, planta1.getElementos().isEmpty());
		assertSame (planta1, casilla1.getPlanta());
		assertSame (null, casilla1.getElemento());
		
		casilla2.setElemento(elemento2);
		assertEquals (true, casilla2.isLlena());
	}
	
	public void testEquals () {
		
		assertEquals(false, casilla1.equals(casilla2));
		CasillaAleatoria casilla3=new CasillaAleatoria(1,2);
		assertEquals(true, casilla3.equals(casilla1));
		assertEquals(false, casilla3.equals(casilla2));
		
	}
	
	public void testClone(){
		
		casilla1.setElemento(elemento1);
		casilla2 = casilla1.clone();

		assertEquals(true, casilla1.getX()==casilla2.getX());
		assertEquals(true, casilla1.getY()==casilla2.getY());
		assertEquals(false, casilla1.getPlanta()==casilla2.getPlanta());
		assertEquals(true, casilla1.getElemento()==casilla2.getElemento());
		assertEquals(true, casilla1.isVisible()==casilla2.isVisible());
		assertEquals(true, casilla2.equals(casilla1));
	}

}
