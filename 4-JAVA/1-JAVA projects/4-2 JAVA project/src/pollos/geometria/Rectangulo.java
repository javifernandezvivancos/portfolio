package pollos.geometria;

import java.util.LinkedList;
import java.util.List;
/**
 * Representa un rectangulo, que estara formado por 4 posiciones y un centro
 * @author Oscar Berrocal Frahija, Javier Fernandez Vivancos.
 *
 */
public class Rectangulo implements Cloneable{
	
	Posicion inferiorIzquierda, superiorDerecha;
	
	//Constructores
	/**
	 * Constructor de un rectangulo.
	 * @param inferiorIzquierda posicion inferior izquierda del rectangulo.
	 * @param ladoEnX anchura del rectangulo.
	 * @param ladoEnY altura del rectangulo.
	 */
	public Rectangulo(Posicion inferiorIzquierda, int ladoEnX, int ladoEnY){		
		this.inferiorIzquierda= inferiorIzquierda;
		superiorDerecha= new Posicion(inferiorIzquierda.getX()+ladoEnX, inferiorIzquierda.getY()-ladoEnY);
	}
	
	//Modificadores
	/**
	 * Metodo para trasladar un rectangulo dados 2 desplazamientos, los desplazamientos
	 * podran ser negativos si se desea.
	 * @param desplazamientoX numero de posiciones a desplazar en el ejeX.
	 * @param desplazamientoY numero de posiciones a desplazar en el ejeY.
	 */
	public void trasladar(int desplazamientoX, int desplazamientoY){		
		inferiorIzquierda= new Posicion(inferiorIzquierda.getX()+desplazamientoX, inferiorIzquierda.getY()+desplazamientoY);
		superiorDerecha= new Posicion(superiorDerecha.getX()+desplazamientoX, superiorDerecha.getY()+desplazamientoY);
	}
	
	/**
	 * Metodo para trasladar un rectangulo dada la posicion del centro hacia
	 * la que se desea mover.
	 * @param centro posicion que pasara a ser el centro del rectangulo.
	 */
	public void trasladar(Posicion centro){
		//Variables
		int desplazamientoX, desplazamientoY;
		
		//Acciones
		desplazamientoX= centro.getX()- (getCentro().getX());	//obtenemos el desplazamiento como nuevoCentro-viejoCentro.
		desplazamientoY= centro.getY()- (getCentro().getY());
		trasladar(desplazamientoX, desplazamientoY);			//trasladamos el rectangulo a partir de los desplazamientos.
	}
	
	/**
	 * Metodo para permutar un rectangulo manteniendo la posicion inferior izquierda.
	 * 
	 */
	public void permutar(){
		//Variables
		int aux;
		Posicion posOriginal= new Posicion(inferiorIzquierda.getX(), inferiorIzquierda.getY());
		
		//Acciones
		trasladar(-posOriginal.getX(), -posOriginal.getY());	//trasladamos el rect�ngulo al origen			
		aux= superiorDerecha.getX();							//lo permutamos
		superiorDerecha.setX(-superiorDerecha.getY());
		superiorDerecha.setY(-aux);
		trasladar(posOriginal.getX(), posOriginal.getY());		//trasladamos el rect�ngulo a su posici�n original
	}
	
	/**
	 * Metodo para escalar un rectangulo en el ejeX
	 * - precondiciones: El porcentaje debera ser mayor de 1.
	 * @param porcentaje porcentaje a escalar.
	 */
	public void escalarEnX(int porcentaje){
		//Variables
		Posicion posOriginal= new Posicion(inferiorIzquierda.getX(), inferiorIzquierda.getY());
		
		//Acciones
		trasladar(-posOriginal.getX(), -posOriginal.getY());			//trasladamos el rectangulo al origen
		superiorDerecha.setX(superiorDerecha.getX()*porcentaje/100);	//escalamos el rectangulo
		trasladar(posOriginal.getX(), posOriginal.getY());				//trasladamos el rectangulo a su posicion original
	}
	
	/**
	 * Metodo para escalar un rectangulo en el ejeY.
	 * @param porcentaje porcentaje a escalar.
	 */
	public void escalarEnY(int porcentaje){
		//Variables
		Posicion posOriginal= new Posicion(inferiorIzquierda.getX(), inferiorIzquierda.getY());
		
		//Acciones
		trasladar(-posOriginal.getX(), -posOriginal.getY());			//trasladamos el rectangulo al origen
		superiorDerecha.setY(superiorDerecha.getY()*porcentaje/100);	//escalamos el rectangulo		
		trasladar(posOriginal.getX(), posOriginal.getY());				//trasladamos el rectangulo a su posicion original
	}
	
	//Consultas
	/**
	 * Obtiene la longitud del lado X.
	 * @return lado del rectangulo
	 */
	public int getLadoEnX(){		
		return superiorDerecha.getX()-inferiorIzquierda.getX();
	}
	
	/**
	 * Obtiene la longitud del lado Y.
	 * @return altura del rectangulo
	 */
	public int getLadoEnY(){
		return inferiorIzquierda.getY()-superiorDerecha.getY();
	}
	
	/**
	 * Obtiene el perimetro.
	 * @return perimetreo del rectangulo
	 */
	public int getPerimetro(){
		return getLadoEnX()*2 + getLadoEnY()*2;
	}
	
	/**
	 * Obtiene la posicion central del rectangulo.
	 * @return objeto de tipo Posicion con las coordenadas del centro del rectangulo
	 */
	public Posicion getCentro(){
		return new Posicion(inferiorIzquierda.getX()+getLadoEnX()/2, inferiorIzquierda.getY()-getLadoEnY()/2);
	}
	
	/**
	 * Obtiene los vertices del rectangulo.
	 * @return nueva lista con los vertices del rectangulo.
	 */
	public List<Posicion> getVertices(){
		//Variables
		LinkedList<Posicion> copia= new LinkedList<Posicion>();
		
		//Acciones
		copia.add(new Posicion(inferiorIzquierda.getX(), inferiorIzquierda.getY()));
		copia.add(new Posicion(inferiorIzquierda.getX(), superiorDerecha.getY()));
		copia.add(new Posicion(superiorDerecha.getX(), superiorDerecha.getY()));
		copia.add(new Posicion(superiorDerecha.getX(), inferiorIzquierda.getY()));

		return copia;
	}

	
	/**
	 * Metodo toString para la clase Rectangulo.
	 * @return Cadena con informacion relevante acerca de un rectangulo
	 */
	@Override
	public String toString() {
		return getClass().getName() + "[Posicion=" 
				+ inferiorIzquierda.getX() + "," + inferiorIzquierda.getY()
				+ ", ancho=" + getLadoEnX() + ", alto="
				+ getLadoEnY() + "]";
	}

	/**
	 *  Metodo clone para la clase rectangulo.
	 *  @return Rectangulo con la misma posicion y tama�o que el original.
	 */
	@Override
	public Rectangulo clone() throws CloneNotSupportedException {
		Rectangulo obj = null;
		obj = new Rectangulo(inferiorIzquierda.clone(), getLadoEnX(), getLadoEnY());
		return (Rectangulo)obj;
		
		
	}

	
	/**
	 * Metodo equals para el rectangulo.
	 * Consideramos que dos rectangulos son equivalentes si estan en el mismo punto
	 * y tienen las mismas dimensiones.
	 * @return true en caso de que ambos objetos sean equivalentes.
	 */
	@Override
	public boolean equals(Object obj) {
		if (obj == null) {return false; }
		if (obj == this) {return true; }
		if (obj.getClass() != this.getClass()) {return false; }
		
		Rectangulo rect = (Rectangulo)obj;
		return (this.getVertices().get(0).equals(rect.getVertices().get(0))
				&& this.getLadoEnX() == rect.getLadoEnX()
				&& this.getLadoEnY() == rect.getLadoEnY()
				);
	}
}
