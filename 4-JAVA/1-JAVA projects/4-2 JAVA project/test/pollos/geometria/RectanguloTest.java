package pollos.geometria;

import junit.framework.TestCase;

public class RectanguloTest extends TestCase {
	protected int tamX1,tamY1;
	protected int p1X, p1Y;
	protected Posicion p1;
	protected Rectangulo r1;
	
	protected void setUp(){
		p1X= 1;
		p1Y= -2;
		tamX1= 100;
		tamY1= 200;
		p1= new Posicion(p1X, p1Y);
		r1 = new Rectangulo(p1, tamX1, tamY1);
	}
	
	public void testRectangulo() {
		//Variables
		Posicion vertice;
			
		//Acciones																			
		vertice= r1.getVertices().get(0);						//comprobamos los valores de los v�rtices:	
		assertEquals(p1X, vertice.getX());						//comprobamos el valor del primer v�rtice
		assertEquals(p1Y, vertice.getY());
		vertice= r1.getVertices().get(1);					
		assertEquals(p1X, vertice.getX());						//comprobamos el valor del segundo v�rtice
		assertEquals(p1Y-tamY1, vertice.getY());
		vertice= r1.getVertices().get(2);					
		assertEquals(p1X+tamX1, vertice.getX());				//comprobamos el valor del segundo v�rtice
		assertEquals(p1Y-tamY1, vertice.getY());
		vertice= r1.getVertices().get(3);					
		assertEquals(p1X+tamX1, vertice.getX()); 				//comprobamos el valor del segundo v�rtice
		assertEquals(p1Y, vertice.getY());
		assertEquals(p1X+tamX1/2, r1.getCentro().getX());		//comprobamos el centro
		assertEquals(p1Y-tamY1/2, r1.getCentro().getY());
		assertEquals(tamX1, r1.getLadoEnX());					//comprobamos la anchura
		assertEquals(tamY1, r1.getLadoEnY());					//comprobamos la altura
		assertEquals(tamX1*2+tamY1*2, r1.getPerimetro());		//comprobamos el per�metro						
	}

	public void testTrasladar() {
		//Variables
		int desplazamientoX=0; 
		int desplazamientoY=0;
		Posicion vertice;
		
		//Acciones
		for(int i=0;i<4;i++){
			//vamos a probar desplazamientos en distintas direcciones:
			switch(i){												
			case 0:													//desplazamiento hacia la derecha-arriba
				desplazamientoX= 3;
				desplazamientoY= -5;
			case 1:													//desplazamiento hacia la derecha-abajo
				desplazamientoX= 3;
				desplazamientoY= 5;	
			case 2:													//desplazamiento hacia la izquierda-arriba
				desplazamientoX= -3;
				desplazamientoY= -5;
			case 3:													//desplazamiento hacia la izquierda-abajo
				desplazamientoX= -3;
				desplazamientoY= 5;
			}
			//trasladamos el rect�ngulo con el primer m�todo:
			r1.trasladar(desplazamientoX, desplazamientoY);			
			
			//comprobamos que los valores son correctos:
			assertEquals(p1X+tamX1/2+desplazamientoX, r1.getCentro().getX());	//comprobamos el centro
			assertEquals(p1Y-tamY1/2+desplazamientoY, r1.getCentro().getY());
			vertice= r1.getVertices().get(0);									//comprobamos los valores de los v�rtices:	
			assertEquals(p1X+desplazamientoX, vertice.getX());					//comprobamos el valor del primer v�rtice
			assertEquals(p1Y+desplazamientoY, vertice.getY());
			vertice= r1.getVertices().get(1);					
			assertEquals(p1X+desplazamientoX, vertice.getX());					//comprobamos el valor del segundo v�rtice
			assertEquals(p1Y-tamY1+desplazamientoY, vertice.getY());
			vertice= r1.getVertices().get(2);					
			assertEquals(p1X+tamX1+desplazamientoX, vertice.getX());			//comprobamos el valor del segundo v�rtice
			assertEquals(p1Y-tamY1+desplazamientoY, vertice.getY());
			vertice= r1.getVertices().get(3);					
			assertEquals(p1X+tamX1+desplazamientoX, vertice.getX());			//comprobamos el valor del segundo v�rtice
			assertEquals(p1Y+desplazamientoY, vertice.getY());
			assertEquals(tamX1, r1.getLadoEnX());								//comprobamos la anchura
			assertEquals(tamY1, r1.getLadoEnY());								//comprobamos la altura
			assertEquals(tamX1*2+tamY1*2, r1.getPerimetro());					//comprobamos el per�metro			
			
			//trasladamos el rect�ngulo con el m�todo sobrecargado:
			r1.trasladar(new Posicion(desplazamientoX, desplazamientoY));			
			
			//comprobamos que los valores son correctos:
			assertEquals(desplazamientoX, r1.getCentro().getX());	//comprobamos el centro
			assertEquals(desplazamientoY, r1.getCentro().getY());
			vertice= r1.getVertices().get(0);						//comprobamos los valores de los v�rtices:	
			assertEquals(desplazamientoX-tamX1/2, vertice.getX());	//comprobamos el valor del primer v�rtice
			assertEquals(desplazamientoY+tamY1/2, vertice.getY());
			vertice= r1.getVertices().get(1);					
			assertEquals(desplazamientoX-tamX1/2, vertice.getX());	//comprobamos el valor del segundo v�rtice
			assertEquals(desplazamientoY-tamY1/2, vertice.getY());
			vertice= r1.getVertices().get(2);					
			assertEquals(desplazamientoX+tamX1/2, vertice.getX());	//comprobamos el valor del segundo v�rtice
			assertEquals(desplazamientoY-tamY1/2, vertice.getY());
			vertice= r1.getVertices().get(3);					
			assertEquals(desplazamientoX+tamX1/2, vertice.getX());	//comprobamos el valor del segundo v�rtice
			assertEquals(desplazamientoY+tamY1/2, vertice.getY());
			assertEquals(tamX1, r1.getLadoEnX());					//comprobamos la anchura
			assertEquals(tamY1, r1.getLadoEnY());					//comprobamos la altura
			assertEquals(tamX1*2+tamY1*2, r1.getPerimetro());		//comprobamos el per�metro			
			
			//volvemos a dejar el rect�ngulo en su posici�n original para probar con otros valores:
			setUp();
		}
	}

	public void testPermutar() {
		//Variables
		Rectangulo r2 = new Rectangulo(new Posicion(p1X,p1Y), tamX1, tamY1);	//creamos un rect�ngulo igual que el original
		Posicion vertice, vertice2;
		
		//Acciones
		r1.permutar();												//permutamos el rect�ngulo		
		vertice= r1.getVertices().get(0);							//comprobamos los valores de los v�rtices:	
		assertEquals(p1X, vertice.getX());							//comprobamos el valor del primer v�rtice
		assertEquals(p1Y, vertice.getY());
		vertice= r1.getVertices().get(1);					
		assertEquals(p1X, vertice.getX());							//comprobamos el valor del segundo v�rtice
		assertEquals(p1Y-tamX1, vertice.getY());
		vertice= r1.getVertices().get(2);					
		assertEquals(p1X+tamY1, vertice.getX());					//comprobamos el valor del tercer v�rtice
		assertEquals(p1Y-tamX1, vertice.getY());
		vertice= r1.getVertices().get(3);					
		assertEquals(p1X+tamY1, vertice.getX()); 					//comprobamos el valor del cuarto v�rtice
		assertEquals(p1Y, vertice.getY());
		assertEquals(p1X+tamY1/2, r1.getCentro().getX());			//comprobamos el centro
		assertEquals(p1Y-tamX1/2, r1.getCentro().getY());
		assertEquals(tamY1, r1.getLadoEnX());						//comprobamos la anchura
		assertEquals(tamX1, r1.getLadoEnY());						//comprobamos la altura
		assertEquals(tamX1*2+tamY1*2, r1.getPerimetro());			//comprobamos el per�metro						

		r1.permutar();
		vertice= r1.getVertices().get(0);							//comprobamos los valores de los v�rtices:	
		vertice2= r2.getVertices().get(0);
		assertEquals(vertice.getX(), vertice2.getX());				//comprobamos el valor del primer v�rtice
		assertEquals(vertice.getY(), vertice2.getY());
		vertice= r1.getVertices().get(1);					
		vertice2= r2.getVertices().get(1);
		assertEquals(vertice.getX(), vertice2.getX());				//comprobamos el valor del segundo v�rtice
		assertEquals(vertice.getY(), vertice2.getY());
		vertice= r1.getVertices().get(2);					
		vertice2= r2.getVertices().get(2);
		assertEquals(vertice.getX(), vertice2.getX());				//comprobamos el valor del tercer v�rtice
		assertEquals(vertice.getY(), vertice2.getY());
		vertice= r1.getVertices().get(3);					
		vertice2= r1.getVertices().get(3);
		assertEquals(vertice.getX(), vertice2.getX()); 				//comprobamos el valor del cuarto v�rtice
		assertEquals(vertice.getY(), vertice2.getY());
		assertEquals(r1.getCentro().getX(), r2.getCentro().getX());	//comprobamos el centro
		assertEquals(r1.getCentro().getY(), r2.getCentro().getY());
		assertEquals(r1.getLadoEnX(), r2.getLadoEnX());				//comprobamos la anchura
		assertEquals(r1.getLadoEnY(), r2.getLadoEnY());				//comprobamos la altura
		assertEquals(r1.getPerimetro(), r2.getPerimetro());			//comprobamos el per�metro			
	}

	public void testEscalar(){
		//Variables
		int porcentajeX= 50;
		int porcentajeY= 20;
		int nuevoTamX1= 50;//100*tamX1/porcentajeX;
		int nuevoTamY1= 40;//100*tamY1/porcentajeY;
		Posicion vertice;
		
		//Acciones
		r1.escalarEnX(porcentajeX);									//escalamos el rect�ngulo
		r1.escalarEnY(porcentajeY);
		vertice= r1.getVertices().get(0);							//comprobamos los valores de los v�rtices:	
		assertEquals(p1X, vertice.getX());							//comprobamos el valor del primer v�rtice
		assertEquals(p1Y, vertice.getY());
		vertice= r1.getVertices().get(1);					
		assertEquals(p1X, vertice.getX());							//comprobamos el valor del segundo v�rtice
		assertEquals(p1Y-nuevoTamY1, vertice.getY());
		vertice= r1.getVertices().get(2);					
		assertEquals(p1X+nuevoTamX1, vertice.getX());				//comprobamos el valor del segundo v�rtice
		assertEquals(p1Y-nuevoTamY1, vertice.getY());
		vertice= r1.getVertices().get(3);					
		assertEquals(p1X+nuevoTamX1, vertice.getX()); 				//comprobamos el valor del segundo v�rtice
		assertEquals(p1Y, vertice.getY());
		assertEquals(p1X+nuevoTamX1/2, r1.getCentro().getX());		//comprobamos el centro
		assertEquals(p1Y-nuevoTamY1/2, r1.getCentro().getY());
		assertEquals(nuevoTamX1, r1.getLadoEnX());					//comprobamos la anchura
		assertEquals(nuevoTamY1, r1.getLadoEnY());					//comprobamos la altura
		assertEquals(nuevoTamX1*2+nuevoTamY1*2, r1.getPerimetro());	//comprobamos el per�metro		
	}
	
	
	public void testEquals(){
		Rectangulo r2 = new Rectangulo(p1, tamX1, tamY1);
		assertTrue(r1.equals(r2));
		assertTrue(r2.equals(r1));
	}

	public void testClone() throws CloneNotSupportedException{
		Rectangulo r2;
		r2 = (Rectangulo) r1.clone();
		
		assertTrue(r1.getVertices().get(0).equals(r2.getVertices().get(0)));	// Comprobamos que la posicion se ha copiado bien
		assertEquals(r1.getLadoEnX(), r2.getLadoEnX());							// Lo mismo con los lados
		assertEquals(r1.getLadoEnY(), r2.getLadoEnY());
		assertTrue(r1.equals(r2));												// Y que los objetos son equivalentes.
		
	}


}
