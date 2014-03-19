package muelles.escenario;


import muelles.elementos.*;
import muelles.escenario.Casilla;
import muelles.escenario.Muelle;
import muelles.escenario.Planta;
import junit.framework.TestCase;

public class MuelleTest extends TestCase {
	
	protected Planta planta0, planta1;
	protected Muelle muellePlanta0, muellePlanta1;
	protected Elemento elementoPlanta0, elementoPlanta1;
	protected Casilla casilla;
	
	
	protected void setUp() {
		
		planta0= new Planta(10,10);
		planta1= new Planta(10,10);
		muellePlanta0= new Muelle(1,1,planta0);
		muellePlanta1= new Muelle(2,2,planta1);
		
		elementoPlanta0= new Vidente();					//"		"	"	"	"	" elemento2
		elementoPlanta1= new Loco();					//"		"	"	"	"	" elemento2
		
	}

	public void testSetElementoElemento() {
		
		assertEquals (true, planta0.getElementos().isEmpty());
		assertEquals (true, planta1.getElementos().isEmpty());
		assertEquals (false, muellePlanta0.isLlena());
		assertEquals (false, muellePlanta1.isLlena());
		
		planta0.setPlantaSuperior(planta1);
		muellePlanta0.setElemento(elementoPlanta0);
		
		assertEquals (true, planta0.getElementos().isEmpty());
		assertEquals (false, planta1.getElementos().isEmpty());
		assertEquals (false, muellePlanta0.isLlena());
		
		setUp();
		
		muellePlanta1.setElemento(elementoPlanta1);
		assertSame (null, planta1.getPlantaSuperior());
		assertEquals (true, planta1.getElementos().isEmpty());
		assertEquals (false, muellePlanta1.isLlena());
		
		
	}
	
	public void testImpulsos() {
		
		planta0.setPlantaSuperior(planta1);
		
		assertEquals (true, muellePlanta0.estaOperativo());
		for(int i=0;i<=9;i++){
			muellePlanta0.setElemento(elementoPlanta0);
			assertEquals (true, muellePlanta0.estaOperativo());		
		}
		
		muellePlanta0.setElemento(elementoPlanta0);
		assertEquals (false, muellePlanta0.estaOperativo());
		
	}
	
	public void testToString (){
		
		assertEquals("muelles.escenario.Muelle[x=1][y=1]" +
				"[visible=true][contenido=null]" +
				"[planta=muelles.escenario.Planta[plantaSuperior=null]" +
				"[plantaInferior=null][anchura=10][altura=10]][nelem0]",
				muellePlanta0.toString());
	}
	
	public void testEquals () {
		
		Muelle muellePlanta2 = new Muelle(1,1);
		
		assertEquals (true, muellePlanta2.equals(muellePlanta0));
		assertEquals (true, muellePlanta0.equals(muellePlanta2));		
		assertEquals (false, muellePlanta2.equals(muellePlanta1));
		assertEquals (false, muellePlanta0.equals(muellePlanta1));
	}
	public void testMuelle(){
		
		planta0.setPlantaSuperior(planta1);

		muellePlanta0.setElemento(elementoPlanta0);

		Muelle copia = muellePlanta0.clone();

		assertEquals(true, muellePlanta0.getX()==copia.getX());
		assertEquals(true, muellePlanta0.getY()==copia.getY());
		assertEquals(false, muellePlanta0.getPlanta()==copia.getPlanta());
		assertEquals(true, muellePlanta0.getElemento()==copia.getElemento());
		assertEquals(true, muellePlanta0.isVisible()==copia.isVisible());		
		assertEquals(true, muellePlanta0.estaOperativo()==copia.estaOperativo());
		assertEquals(true, copia.equals(muellePlanta0));
		
	}

}
