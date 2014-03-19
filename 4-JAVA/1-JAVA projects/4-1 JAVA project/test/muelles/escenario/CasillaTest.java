package muelles.escenario;

import muelles.elementos.*;
import junit.framework.TestCase;

public class CasillaTest extends TestCase {
	protected int x1,y1, x2,y2, x3,y3;
	protected Elemento elemento1, elemento2;
	protected Casilla casilla1, casilla2, casilla3, casilla4;
	protected Planta planta1, planta2;
	
	protected void setUp() {
		x1=1; y1=2; x2=3; y2=4; x3=5; y3=6;			//coordenadas de las casillas
		planta1 = new Planta(10,10);
		planta2 = new Planta(7,7);
		casilla1 = new Casilla(x1,y1,true);			//casilla1 creada con el primer constructor
		casilla2 = new Casilla(x2,y2);				//casilla2 creada con el segundo constructor
		casilla3 = new Casilla(x3,y3,true,planta1);	//casilla3 creada con el tercer constructor
		casilla4 = new Casilla(x3,y3,true);
		elemento1= new Vidente();					//le asignamos un valor a elemento1
		elemento2= new Loco();					//"		"	"	"	"	" elemento2
	}
	public void testCasilla() {
		//Comprobacion de casilla1:
		assertSame(null, casilla1.getElemento());
		assertEquals(x1, casilla1.getX());
		assertEquals(y1, casilla1.getY());
		assertEquals(true, casilla1.isVisible());		
		assertSame(null, casilla1.getPlanta());
		//comprobacion de casilla2:
		assertSame(null, casilla2.getElemento());
		assertEquals(x2, casilla2.getX());
		assertEquals(y2, casilla2.getY());
		assertEquals(false, casilla2.isVisible());
		assertSame(null, casilla2.getPlanta());
		//comprobacion de casilla3:
		assertSame(null, casilla3.getElemento());
		assertEquals(x3, casilla3.getX());
		assertEquals(y3, casilla3.getY());
		assertEquals(true, casilla3.isVisible());
		assertEquals(planta1, casilla3.getPlanta());
	}
	
	public void testVisible() {
		casilla1.mostrar();
		assertEquals(true, casilla1.isVisible());
		casilla1.ocultar();
		assertEquals(false, casilla1.isVisible());
	}
	
	public void testElemento() {
		casilla1.setElemento(elemento1);
		assertEquals(true, casilla1.isLlena());
		assertEquals(elemento1, casilla1.getElemento());
		casilla1.setElemento(elemento2);
		assertEquals(true, casilla1.isLlena());
		assertEquals(elemento2, casilla1.getElemento());
		casilla1.removeElemento();
		assertEquals(false, casilla1.isLlena());
		assertSame(null, casilla1.getElemento());
		
		//comprobamos los movimientos:
		//casilla 1: x=1 Y=2
		elemento1.setCasilla(casilla1);
		casilla1.setPlanta(planta1);
		
		elemento1.mover(Direccion.ARRIBA);
		assertSame(elemento1, casilla1.getPlanta().getCasilla(1, 1).getElemento());
		assertSame(null, casilla1.getPlanta().getCasilla(1, 2).getElemento());
		elemento1.mover(Direccion.ABAJO);
		assertSame(elemento1, casilla1.getPlanta().getCasilla(1, 2).getElemento());
		assertSame(null, casilla1.getPlanta().getCasilla(1, 3).getElemento());
		elemento1.mover(Direccion.DERECHA);
		assertSame(elemento1, casilla1.getPlanta().getCasilla(2, 2).getElemento());
		assertSame(null, casilla1.getPlanta().getCasilla(1, 3).getElemento());
		elemento1.mover(Direccion.IZQUIERDA);
		assertSame(elemento1, casilla1.getPlanta().getCasilla(1, 2).getElemento());
		assertSame(null, casilla1.getPlanta().getCasilla(2, 3).getElemento());
		
	}
	public void testPlanta(){
		//la casilla3 está inicialmente en la planta1.
		casilla3.removePlanta();
		assertSame(null, casilla3.getPlanta());
		assertNotSame(casilla3,planta1.getCasilla(casilla3.getX(),casilla3.getY()));
		casilla3.setPlanta(planta2);
		assertSame(planta2, casilla3.getPlanta());
		assertSame(casilla3, planta2.getCasilla(casilla3.getX(), casilla3.getY()));		
	}
	
	public void testToString() {
		assertEquals("muelles.escenario.Casilla[x=1][y=2][visible=true][contenido=null][planta=null]", casilla1.toString());
	}
	
	public void testEquals(){

		casilla1 = casilla2;
		assertEquals(true, casilla2.equals(casilla1));
		assertEquals(true, casilla1.equals(casilla2));
		assertEquals(false, casilla2.equals(casilla3));
		assertEquals(false, casilla3.equals(casilla2));
		assertEquals (false, casilla3.equals(casilla1));
		
		
	}
	public void testClone(){
		
		casilla3.setElemento(elemento1);
		casilla2 = casilla3.clone();
		
		assertEquals(true, casilla2.getX()==casilla3.getX());
		assertEquals(true, casilla2.getY()==casilla3.getY());
		assertEquals(false, casilla2.getPlanta()==casilla3.getPlanta());
		assertEquals(false, casilla2.getElemento()==casilla3.getElemento());
		assertEquals(true, casilla2.isVisible()==casilla3.isVisible());
		assertEquals(true, casilla2.equals(casilla3));
	}
}
