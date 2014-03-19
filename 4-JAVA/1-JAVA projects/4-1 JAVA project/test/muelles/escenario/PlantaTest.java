package muelles.escenario;

import junit.framework.TestCase;
import muelles.elementos.*;
import java.util.LinkedList;

public class PlantaTest extends TestCase {
	protected int tamX0,tamY0, tamX1,tamY1, tamX2,tamY2;
	protected Planta planta0, planta1, planta2;
	protected Elemento elemento1, elemento2, elemento3;
	
	protected void setUp(){
		tamX0=3;tamY0=3; tamX1=3;tamY1=3; tamX2=3;tamY2=3;
		planta0 = new Planta(tamX0,tamY0);
		planta1 = new Planta(tamX1,tamY1);
		planta2 = new Planta(tamX2,tamY2);
		
		planta1.setPlantaInferior(planta0);
		planta1.setPlantaSuperior(planta2);
		elemento1= new Vidente();					//"		"	"	"	"	" elemento2
		elemento2= new Loco();					//"		"	"	"	"	" elemento2
		elemento3= new Jugador();
	}
	
	public void testPlanta() {
		LinkedList lista;
		//comprobacin tamaos
		assertEquals(tamX0,planta0.getTamX());
		assertEquals(tamY0,planta0.getTamY());
		assertEquals(tamX1,planta1.getTamX());
		assertEquals(tamY1,planta1.getTamY());
		assertEquals(tamX2,planta2.getTamX());
		assertEquals(tamY2,planta2.getTamY());
		//comprobacin de referencias a plantas superiores e inferiores
		assertSame(null,planta0.getPlantaInferior());
		assertSame(planta0,planta1.getPlantaInferior());
		assertSame(planta1,planta2.getPlantaInferior());
		assertSame(planta1,planta0.getPlantaSuperior());
		assertSame(planta2,planta1.getPlantaSuperior());
		assertSame(null,planta2.getPlantaSuperior());
		
		//Comprobamos que todas las casillas de cada una de las listas son correctas
		lista =  planta0.getCasillas();											//creamos una lista con las casillas que hay en la planta
		for(int j=0;j<planta0.getTamY();j++){
			for(int i=0;i<planta0.getTamX();i++){
				assertEquals(i, planta0.getCasilla(i, j).getX());				//comprobamos que el las coordenadas de las casillas son correctas
				assertEquals(j, planta0.getCasilla(i, j).getY());				
				assertSame(planta0, planta0.getCasilla(i, j).getPlanta());	//comprobamos que el atributo planta de las casillas es correcto
				assertSame(planta0.getCasilla(i, j), lista.removeFirst());	//comprobamos que la lista est ordenada correctamente (la funcin remove devuelve la primera casilla de la lista adems de eliminarla)
			}
		}
		lista =  planta1.getCasillas();											//creamos una lista con las casillas que hay en la planta
		for(int j=0;j<planta1.getTamY();j++){
			for(int i=0;i<planta1.getTamX();i++){
				assertEquals(i, planta1.getCasilla(i, j).getX());				//comprobamos que el las coordenadas de las casillas son correctas
				assertEquals(j, planta1.getCasilla(i, j).getY());				
				assertSame(planta1, planta1.getCasilla(i, j).getPlanta());	//comprobamos que el atributo planta de las casillas es correcto
				assertSame(planta1.getCasilla(i, j), lista.removeFirst());	//comprobamos que la lista est ordenada correctamente (la funcin remove devuelve la primera casilla de la lista adems de eliminarla)
			}
		}
		lista =  planta2.getCasillas();											//creamos una lista con las casillas que hay en la planta
		for(int j=0;j<planta2.getTamY();j++){
			for(int i=0;i<planta2.getTamX();i++){
				assertEquals(i, planta2.getCasilla(i, j).getX());				//comprobamos que el las coordenadas de las casillas son correctas
				assertEquals(j, planta2.getCasilla(i, j).getY());				
				assertSame(planta2, planta2.getCasilla(i, j).getPlanta());	//comprobamos que el atributo planta de las casillas es correcto
				assertSame(planta2.getCasilla(i, j), lista.removeFirst());	//comprobamos que la lista est ordenada correctamente (la funcin remove devuelve la primera casilla de la lista adems de eliminarla)
			}
		}
	}
	
	public void testCasilla(){
		int x, y;
		x=1; y=2;
		Casilla c1 = planta1.getCasilla(x, y);
		Casilla c2 = new Casilla(x, y);
		
		c2.setPlanta(planta1);
		assertSame(null,c1.getPlanta());
		assertSame(planta1,c2.getPlanta());
		assertEquals(x,c2.getX());
		assertEquals(y,c2.getY());
	}
	
	public void testSubirElemento(){
		int x, y;
		x=1; y=2;
		
		planta0.getCasilla(x, y).setElemento(elemento1);		//metemos un elemento en una casilla de la planta 0
		planta0.subirElemento(x, y);							//subimos el elemento
		//assertEquals(false, planta0.getCasilla(x, y).isLlena());//comprobamos que el elemento ya no est en la casilla...
		//assertEquals(true, planta1.getCasilla(x, y).isLlena());	//...sino que est en la casilla de la planta superior
		
		//planta1.subirElemento(x, y);
		//assertEquals(false, planta1.getCasilla(x, y).isLlena());//comprobamos que el elemento ya no est en la casilla...
		//assertEquals(true, planta2.getCasilla(x, y).isLlena());	//...sino que est en la casilla de la planta superior
		
		//planta2.subirElemento(x, y);
		//assertEquals(false, planta2.getCasilla(x, y).isLlena());//comprobamos que el elemento ya no est en la casilla...
		
		//assertEquals(false, planta0.getCasilla(x, y).isLlena());//comprobamos que no hay ningn elemento en la posicin...
		//planta0.subirElemento(x, y);							//...y que si intentamos subirlo la casilla permanece vaca
		//assertEquals(false, planta0.getCasilla(x, y).isLlena());
	}
	
	/*public void testElementoSetCasilla(){
		Casilla c1= new Casilla(1,1,true);
		Casilla c2= new Casilla(2,2,false);
		Elemento e = new Elemento('d');
		e.setCasilla(c1);
		assertSame(e, c1.getElemento());
		e.setCasilla(c2);
		assertSame(e, c2.getElemento());
		assertSame(null, c1.getElemento());
	}*/
	
	public void testBajarElemento(){
		int x, y;
		x=1; y=2;
		
		planta2.getCasilla(x, y).setElemento(elemento1);		//metemos un elemento en una casilla de la planta 2
		planta2.bajarElemento(x, y);							//bajamos el elemento
		assertEquals(false, planta2.getCasilla(x, y).isLlena());//comprobamos que el elemento ya no est en la casilla...
		assertEquals(true, planta1.getCasilla(x, y).isLlena());	//...sino que est en la casilla de la planta inferior
		
		planta1.bajarElemento(x, y);
		assertEquals(false, planta1.getCasilla(x, y).isLlena());//comprobamos que el elemento ya no est en la casilla...
		assertEquals(true, planta0.getCasilla(x, y).isLlena());	//...sino que est en la casilla de la planta inferior
		
		planta0.bajarElemento(x, y);
		assertEquals(false, planta0.getCasilla(x, y).isLlena());//comprobamos que el elemento ya no est en la casilla...
		
		assertEquals(false, planta1.getCasilla(x, y).isLlena());//comprobamos que no hay ningn elemento en la posicin...
		planta1.bajarElemento(x, y);							//...y que si intentamos subirlo la casilla permanece vaca
		assertEquals(false, planta1.getCasilla(x, y).isLlena());
	}
	public void testElementos(){
		int x1,y1, x2,y2, x3,y3;
		x1=0;y1=0; x2=1;y2=1; x3=1;y3=2;
		
		planta1.getCasilla(x1, y1).setElemento(elemento1);	//metemos los tres elementos en distintas posiciones de la planta
		planta1.getCasilla(x2, y2).setElemento(elemento2);
		planta1.getCasilla(x3, y3).setElemento(elemento3);
		
		assertSame(elemento1, planta1.getCasilla(x1, y1).getElemento());	//comprobamos que en las casillas estn los elementos esperados
		assertSame(elemento2, planta1.getCasilla(x2, y2).getElemento());
		assertSame(elemento3, planta1.getCasilla(x3, y3).getElemento());
	}
	public void testCasillasAdyacentes(){
		int x, y;
		LinkedList lista;		
		x=1; y=1;
		
		lista = planta1.getCasillasAdyacentes(x, y);	//obtenemos las casillas adyacentes a la posicin x,y
		assertSame(planta1.getCasilla(x-1, y),lista.removeFirst()); //comprobamos que son las esperadas
		assertSame(planta1.getCasilla(x, y-1),lista.removeFirst());
		assertSame(planta1.getCasilla(x+1, y),lista.removeFirst());
		assertSame(planta1.getCasilla(x, y+1),lista.removeFirst());
	}
	
	public void testToString(){
		
		System.out.println(planta1.toString());
	}
	
	public void testEquals () {
		
		assertEquals(true, planta0.equals(planta1));
		assertEquals(true, planta0.equals(planta2));
		
		Planta planta3 = new Planta (2,2);
	
		assertEquals(false, planta0.equals(planta3));
		
		Casilla casilla1 = new Casilla (1,2, true, planta0);
		Casilla casilla2 = new Casilla (2,1, true, planta0);
		casilla1.setElemento(elemento1);
		casilla2.setElemento(elemento2);
		
		assertEquals(false, planta0.equals(planta1));
		assertEquals(false, planta0.equals(planta2));
		
		Casilla casilla3 = new Casilla (1,2, true, planta1);	
		casilla3.setElemento(elemento1);
		
		assertEquals(false, planta0.equals(planta1));
		
		Casilla casilla4 = new Casilla (2,1, true, planta1);
		casilla4.setElemento(elemento2);
		
		assertEquals(true, planta0.equals(planta1));		
	}
	public void testGetElementos(){
		int x1,y1, x2,y2, x3,y3;
		LinkedList lista;
		x1=0;y1=0; x2=1;y2=1; x3=1;y3=2;
		
		planta1.getCasilla(x1, y1).setElemento(elemento1);	//metemos los tres elementos en distintas posiciones de la planta
		planta1.getCasilla(x2, y2).setElemento(elemento2);
		planta1.getCasilla(x3, y3).setElemento(elemento3);
		lista=planta1.getElementos();
		
		assertSame(lista.removeFirst(),elemento1);
		assertSame(lista.removeFirst(),elemento2);
		assertSame(lista.removeFirst(),elemento3);
		
	}
	
	public void testClone(){
		planta1.setPlantaInferior(planta0);
		Planta copia = planta1.clone();
		
		//comproabación de que las plantas son iguales:
		assertEquals(true, planta1.equals(copia));
		
		//comprobación de que tienen las mismas dimensiones:
		assertEquals(true, copia.getTamX()==planta1.getTamX());
		assertEquals(true, copia.getTamY()==planta1.getTamY());
		
		//comprobación de que la copia no tiene planta superior ni inferior:
		assertSame(planta1.getPlantaInferior(), planta0);
		assertSame(copia.getPlantaInferior(), null);
		assertSame(copia.getPlantaSuperior(), null);
		
		//comprobación de que todas las casillas son iguales y de que cada una de ellas apunta a su respectiva planta:
		for(int i=0;i<copia.getTamX();i++){
			for(int j=0;j<copia.getTamY();j++){
				assertEquals(true,copia.getCasilla(i, j).equals(planta1.getCasilla(i, j)));
				assertSame(copia.getCasilla(i, j).getPlanta(), copia);
				assertSame(planta1.getCasilla(i, j).getPlanta(), planta1);
			}
		}
		//comprobación de que las plantas a las que apuntan son distintas:
		assertNotSame(planta1.getCasilla(1, 1).getPlanta(), copia.getCasilla(1, 1).getPlanta());
	}	
}
