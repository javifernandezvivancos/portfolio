package muelles.escenario;

import junit.framework.TestCase;

public class DireccionTest extends TestCase {	

	protected Direccion direccion1;
	
	protected void setUp() {
		direccion1 = Direccion.ARRIBA;
	}
	
	public void testFromString() {
		assertEquals(Direccion.ARRIBA, Direccion.fromString("arriba"));
		assertEquals(Direccion.DERECHA, Direccion.fromString("derecha"));
		assertEquals(Direccion.ABAJO, Direccion.fromString("abajo"));
		assertEquals(Direccion.IZQUIERDA, Direccion.fromString("izquierda"));
		//assertEquals(null, Direccion.fromString("noVale"));
	}

	public void testGirarSentidoReloj() {
		direccion1 = direccion1.girarSentidoReloj();
		assertEquals(Direccion.DERECHA,direccion1);
		
		direccion1 = direccion1.girarSentidoReloj();
		assertEquals(Direccion.ABAJO,direccion1);
		
		direccion1 = direccion1.girarSentidoReloj();
		assertEquals(Direccion.IZQUIERDA,direccion1);
		
		direccion1 = direccion1.girarSentidoReloj();
		assertEquals(Direccion.ARRIBA,direccion1);
	}
}
