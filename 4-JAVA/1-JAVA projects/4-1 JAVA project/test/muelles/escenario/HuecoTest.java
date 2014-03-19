package muelles.escenario;

import muelles.elementos.*;

import junit.framework.TestCase;

public class HuecoTest extends TestCase {
	
	protected Planta planta0, planta1;
	protected Hueco huecoPlanta0, huecoPlanta1;
	protected Elemento elementoPlanta0, elementoPlanta1;
	protected Casilla casilla;
	
	protected void setUp() {
		
		planta0= new Planta(10,10);
		planta1= new Planta(10,10);
		huecoPlanta0= new Hueco(1,1,planta0);
		huecoPlanta1= new Hueco(2,2,planta1);
		
		elementoPlanta0= new Vidente();					//"		"	"	"	"	" elemento2
		elementoPlanta1= new Loco();					//le asignamos un valor a elemento1
	}
	

	public void testSetElemento() {
		assertEquals (true, planta0.getElementos().isEmpty());
		assertEquals (true, planta1.getElementos().isEmpty());
		assertEquals (false, huecoPlanta0.isLlena());
		assertEquals (false, huecoPlanta1.isLlena());

		planta0.setPlantaSuperior(planta1);

		huecoPlanta1.setElemento(elementoPlanta1);
		assertEquals (false, planta0.getElementos().isEmpty());
		assertEquals (true, planta1.getElementos().isEmpty());
		assertEquals (false, huecoPlanta1.isLlena());

		setUp();

		huecoPlanta0.setElemento(elementoPlanta0);
		assertEquals (null, planta0.getPlantaInferior());
		assertEquals (true, planta0.getElementos().isEmpty());
		assertEquals (false, huecoPlanta0.isLlena());	

	}
	
	public void testEquals (){

		assertEquals (false, huecoPlanta0.equals(huecoPlanta1));
		Hueco huecoPlanta2 = new Hueco(1,1,planta1);
		assertEquals (true, huecoPlanta2.equals(huecoPlanta0));
		assertEquals (true, huecoPlanta0.equals(huecoPlanta2));
		assertEquals (false, huecoPlanta2.equals(huecoPlanta1));
	}
	
	public void testClone(){
		
		huecoPlanta0.setElemento(elementoPlanta1);
		huecoPlanta1 = huecoPlanta0.clone();

		assertEquals(true, huecoPlanta0.getX()==huecoPlanta1.getX());
		assertEquals(true, huecoPlanta0.getY()==huecoPlanta1.getY());
		assertEquals(false, huecoPlanta0.getPlanta()==huecoPlanta1.getPlanta());
		assertEquals(true, huecoPlanta0.getElemento()==huecoPlanta1.getElemento());
		assertEquals(true, huecoPlanta0.isVisible()==huecoPlanta1.isVisible());
		assertEquals(true, huecoPlanta1.equals(huecoPlanta0));
	}
}
