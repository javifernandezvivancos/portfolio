package muelles.escenario;

import java.util.Random;		//para generar nmeros aleatorios
import java.util.LinkedList;	//para la utilizacin de listas
import muelles.elementos.*;
/**
 * Representa una planta bidimensional de casillas, su tamaño viene determinado
 * por el numero de casillas que tiene de anchura y de altura, ademas puede 
 * tener asociada otra planta superior e inferior.
 * @author Guadalupe Garcia Fernandez y Javier Fernandez Vivancos.
 *
 */
public class Planta implements Cloneable{
	private Casilla[][] casillas;
	private Planta plantaSuperior,plantaInferior;
	private int anchura, altura;
	
	//Constructores:
	/**
	 * Constructor de una planta, por defecto se llena de casillas nuevas y vacias.
	 * --precondiciones:
	 * - la anchura y la altura deben ser mayores que 0.
	 * @param x anchura (en numero de casillas) que tendra la planta.
	 * @param y altura (en numero de casillas) que tendra la planta.
	 */
	public Planta(int x, int y){
		if(x<0){
			throw new IllegalArgumentException("No se puede crear la planta. "+
												"La anchura es menor que cero");
		}
		if(y<0){
			throw new IllegalArgumentException("No se puede crear la planta. "+
												"La anchura es menor que cero");
		}
		
		casillas = new Casilla[x][y];
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				casillas[i][j]=new Casilla(i,j,false,this);
			}
		}
		anchura = x;
		altura = y;
	}
	
	
	//Consultas:
	/**
	 * obtiene la anchura de la planta.
	 * @return anchura de la planta (en numero de casillas).
	 * @see muelles.escenario.Planta#getTamY().
	 */
	public int getTamX(){
		return anchura;
	}
	
	/**
	 * obtiene la altura de la planta.
	 * @return altura de la planta (en numero de casillas).
	 * @see muelles.escenario.Planta#getTamX().
	 */
	public int getTamY(){
		return altura;
	}
	
	/**
	 * Obtiene la casilla que hay en una determinada posicion de la planta.
	 * @param x coordenada x de la casilla que queremos obtener.
	 * @param y coordenada y de la casilla que queremos obtener.
	 * @return casilla que hay en la posicin (x, y).
	 * @see muelles.escenario.Planta#getCasillaAleatoria().
	 */
	public Casilla getCasilla(int x, int y){
		if(x>=0 && y>=0 && x<anchura && y<altura)
			return casillas[x][y];
		return null;
	}
	
	/**
	 * Obtiene una casilla de la planta con posicion aleatoria.
	 * @return casilla aleatoria.
	 * @see muelles.escenario.Planta#getCasilla(int, int).
	 */
	public Casilla getCasillaAleatoria(){
		Random rnd = new Random();
		int xAleatoria = (int)(rnd.nextDouble()*anchura); //generamos un numero aleatorio entre 0 y anchura
		int yAleatoria = (int)(rnd.nextDouble()*altura);  // "	"	"	"	"	"	"	"	"	0 y altura
		return casillas[xAleatoria][yAleatoria];
	}
	
	/**
	 * obtiene todas las casillas de la planta.
	 * @return lista que contiene las casillas de la planta.
	 * @see muelles.escenario.Planta#getElementos().
	 */
	public LinkedList<Casilla> getCasillas(){
		LinkedList<Casilla> listaCasillas = new LinkedList<Casilla>();
		for(int j=0;j<altura;j++)
			for(int i=0;i<anchura;i++)
				listaCasillas.add(casillas[i][j]);
		return listaCasillas;
	}
	
	/**
	 * obtiene las casillas adyacentes a la posicion 
	 * que nos pasen como parametro.
	 * @param x coordenada x de la planta.
	 * @param y coordenada y de la planta.
	 * @return lista con las casillas adyacentes a la posicion (x, y), el orden
	 * en que aparecen las casillas en la lista es:
	 * casillaDerecha-casillaInferior-casillaIzquierda-casillaSuperior.
	 */
	public LinkedList<Casilla> getCasillasAdyacentes(int x, int y){
		if ((x<0) || (x>=anchura) || (y<0) || (y>=altura))
				throw new IllegalArgumentException("No se pueden obtener las casillas adyacentes." +
						"Las coordenadas de la casilla pasada como parametro son erroneas.");
		
		
		LinkedList<Casilla> listaCasillas = new LinkedList<Casilla>();
		if(x>0)	listaCasillas.add(casillas[x-1][y]);
		if(y>0) listaCasillas.add(casillas[x][y-1]);
		if(x<anchura-1) listaCasillas.add(casillas[x+1][y]);
		if(y<altura-1) listaCasillas.add(casillas[x][y+1]);

		return listaCasillas;
	}
	
	/**
	 * Obtiene la planta superior de la planta.
	 * @return planta superior.
	 * @see muelles.escenario.Planta#getPlantaInferior().
	 */
	public Planta getPlantaSuperior(){
		return plantaSuperior;
	}
	
	/**
	 * Obtiene la planta inferior de la planta.
	 * @return planta inferior.
	 * @see muelles.escenario.Planta#getPlantaSuperior().
	 */
	public Planta getPlantaInferior(){
		return plantaInferior;
	}
	
	/**
	 * Obtiene todos los elementos que hay en la planta
	 * @return lista con los elementos de la planta.
	 * @see muelles.escenario.Planta#getCasillas().
	 */
/*	public LinkedList<Elemento> getElementos(){
		LinkedList<Elemento> listaElementos = new LinkedList<Elemento>();
		for(int j=0;j<altura;j++)
			for(int i=0;i<anchura;i++)
				if(casillas[i][j].isLlena())
					listaElementos.add(casillas[i][j].getElemento());
		return listaElementos;
	}*/
	
	/**
	 * Metodo que devuelve una lista de todos los elementos visibles
	 * que hay en la planta.
	 * @return Lista de elementos visibles.
	 */
/*	public LinkedList<Elemento> getElementosVisibles(){
		LinkedList<Elemento> listaElementos = new LinkedList<Elemento>();
		for(int j=0;j<altura;j++)
			for(int i=0;i<anchura;i++)
				if(casillas[i][j].isLlena() && casillas[i][j].isVisible())
					listaElementos.add(casillas[i][j].getElemento());
		return listaElementos;
	}*/
	
	/**
	 * Metodo que devuelve una lista de las armas que hay en la planta.
	 * @return Lista de armas.
	 */
	/*public LinkedList<Elemento> getArmas(){
		LinkedList<Elemento> listaElementos = new LinkedList<Elemento>();
		for(int j=0;j<altura;j++)
			for(int i=0;i<anchura;i++)
				if(casillas[i][j].isLlena())
					if(casillas[i][j].getElemento() instanceof Arma)
						listaElementos.add(casillas[i][j].getElemento());
		return listaElementos;		
	}*/
	
	/**
	 * Metodo que devuelve una lista de las armas visibles que hay en la planta.
	 * @return Lista de armas visibles.
	 */
	/*public LinkedList<Elemento> getArmasVisibles(){
		LinkedList<Elemento> listaElementos = new LinkedList<Elemento>();
		for(int j=0;j<altura;j++)
			for(int i=0;i<anchura;i++)
				if(casillas[i][j].isLlena() && casillas[i][j].isVisible())
					if(casillas[i][j].getElemento() instanceof Arma)
						listaElementos.add(casillas[i][j].getElemento());
		return listaElementos;
	}*/
	
	public LinkedList<Elemento> filtrar(Criterio criterio){
		LinkedList<Elemento> listaElementos = new LinkedList<Elemento>();
		for(int j=0;j<altura;j++)
			for(int i=0;i<anchura;i++)
				if(casillas[i][j].isLlena() && criterio.test(casilla[i][j]))
						listaElementos.add(casillas[i][j].getElemento());
		return listaElementos;
	}
	
	//Modificadores:
	/**
	 * Este procedimiento sirve para introducir una determinada casilla en
	 * la planta, la casilla que habia anteriormente en esa posicion deja de
	 * pertenecer a cualquier planta.
	 * --precondiciones:
	 * - la casilla que pasemos como parámetro no podrá ser nula.
	 * @param cn casilla que queremos introducir en la planta.
	 */
	public void setCasilla(Casilla cn){
		if(cn==null){
			throw new IllegalArgumentException("No se puede introducir la casilla. "+
												"la casilla es nula");
		}
		
		Casilla casillaAntigua = casillas[cn.getX()][cn.getY()]; //casilla que se va a sobreescribir				
		casillas[cn.getX()][cn.getY()]= cn;				//metemos la nueva casilla en el array plantas
		cn.setPlanta(this);								//establecemos la referencia de la nueva casilla hacia la planta actual
		casillaAntigua.removePlanta();					//eliminamos la referencia de la casilla antigua hacia la planta actual
	}
	
	/**
	 * Establece la planta superior de la planta.
	 * --Precondiciones:
	 * - las dimensiones de la planta que se pasa como parámetro
	 * deben ser iguales a las de la planta actual 
	 * @param p planta que pasar a ser la planta superior.
	 * @see muelles.escenario.Planta#setPlantaInferior(Planta).
	 */
	public void setPlantaSuperior(Planta p){
		if(p.anchura!=anchura || p.altura!=altura){
			throw new IllegalArgumentException("No se puede establecer la planta superior. "+
			"las dimensiones de las plantas no son iguales");
		}
		plantaSuperior = p;			//establecemos p como la planta superior a la actual
		p.plantaInferior = this;	//Establecemos la planta actual como planta inferior de p
	}
	
	/**
	 * Establece la planta inferior de la planta.
	 * @param p planta que pasar a ser la planta inferior.
	 * @see muelles.escenario.Planta#setPlantaSuperior(Planta).
	 */
	public void setPlantaInferior(Planta p){
		if(p.anchura!=anchura || p.altura!=altura){
			throw new IllegalArgumentException("No se puede establecer la planta inferior. "+
			"las dimensiones de las plantas no son iguales");
		}
		plantaInferior = p;			//establecemos p como la planta inferior a la actual
		p.plantaSuperior = this;	//Establecemos la planta actual como planta superior de p
	}
	
	/**
	 * Sube el elemento que hay en la posicion (x,y) a la planta superior,
	 * si hay algun elemento en la planta superior ste desaparece;
	 * si no hay ningun elemento en la posicion (x,y) la operacion no hace nada.
	 * --precondiciones:
	 * - las posiciones x e y deberán estar dentro de las dimensiones de
	 * la planta.
	 * @param x posicion x de la casilla que contiene el elemento que queremos subir.
	 * @param y posicion y de la casilla que contiene el elemento que queremos subir.
	 * @see muelles.escenario.Planta#bajarElemento(int, int).
	 */
	public void subirElemento(int x, int y){
		if(x<0 || x>=anchura){
			throw new IllegalArgumentException("No se subir el elemento. "+
												"La coordenada x no es correcta");
		}
		if(y<0 || y>=altura){
			throw new IllegalArgumentException("No se subir el elemento. "+
			"La coordenada y no es correcta");
		}
		if(plantaSuperior==null){//si la planta superior es nula eliminamos el elemento directamente
			casillas[x][y].getElemento().escapar();
		}
		
		else if(casillas[x][y].getElemento()!=null){//comprobamos que existe planta superior y elemento en la casilla solicitada
			if(plantaSuperior.casillas[x][y].isLlena())
				plantaSuperior.casillas[x][y].getElemento().desaparecer();
			
			plantaSuperior.casillas[x][y].setElemento(casillas[x][y].getElemento());	//copiamos el elemento de la planta actual a la planta superior
		}
	}
	
	/**
	 * Baja el elemento que hay en la posicion (x,y) a la planta inferior,
	 * si hay algun elemento en la planta inferior este desaparece;
	 * si no hay ningun elemento en la posicion (x,y) la operacion no hace nada.
	 * --precondiciones:
	 * - las posiciones x e y deberán estar dentro de las dimensiones de
	 * la planta.
	 * @param x posicion x de la casilla que contiene el elemento que queremos bajar.
	 * @param y posicion y de la casilla que contiene el elemento que queremos bajar.
	 * @see muelles.escenario.Planta#subirElemento(int, int).
	 */
	public void bajarElemento(int x, int y){
		if(x<0 || x>=anchura){
			throw new IllegalArgumentException("No se bajar el elemento. "+
												"La coordenada x no es correcta");
		}
		if(y<0 || y>=altura){
			throw new IllegalArgumentException("No se bajar el elemento. "+
			"La coordenada y no es correcta");
		}
		if(plantaInferior==null){
			casillas[x][y].getElemento().fracasar();
		}		
		else if(casillas[x][y].getElemento()!=null){
			if(plantaInferior.casillas[x][y].isLlena()){
				plantaInferior.casillas[x][y].getElemento().desaparecer();
			}			
			plantaInferior.casillas[x][y].setElemento(casillas[x][y].getElemento());
		}
	}
	
	/**
	 * Metodo que elimina una casilla de una planta dadas sus coordenadas x e y.
	 * @param x Posicion de la casilla en el eje X.
	 * @param y Posicion de la casilla en el eje Y.
	 */
	public void removeCasilla(int x, int y)
	{
		Casilla aux= casillas[x][y];
		casillas[x][y]= new Casilla(x,y,false,this);
		if(aux.getPlanta()==this)
			aux.removePlanta();
	}
	
	/**
	 * Redefinicion del metodo toString.
	 */
	public String toString(){
		String cadena = getClass().getName() + "[" + "plantaSuperior=";
		if(getPlantaSuperior()==null)
			cadena+= "null";
		else
			cadena+= getPlantaSuperior().hashCode();
		
		cadena+= "]" + "[" + "plantaInferior=";
		if(getPlantaInferior()==null)
			cadena+= "null";
		else
			cadena+= getPlantaInferior().hashCode();
		
		cadena+="]" + "[" + "anchura=" + anchura + "]" +
		"[" + "altura=" + altura + "]";
		
		return cadena;
		
	}
	
	/**
	 * Redefinicion del metodo equals.
	 */
	public boolean equals (Object obj) {
		
		// Si es nulo, entonces no son iguales
		if (obj == null) return false;
		
		// Si son el mismo objeto, entonces son iguales
		if (this == obj) return true;
		
		// Si no son del mismo tipo, no son iguales
		if (this.getClass() != obj.getClass()) return false;
		
		// Se hace un casting al tipo actual
		Planta planta = (Planta)obj;
		
		if (this.anchura == planta.anchura && this.altura == planta.altura) {
			for (int j=0;j<altura;j++) {
				for (int i=0; i<anchura;i++) {
					if (! this.casillas[i][j].equals(planta.casillas[i][j])) return false;
				}
			}
			return true;
		}
		else return false;		
	}
	
	/**
	 * Redefinicion del metodo clone.
	 */
	public Planta clone(){

		Planta copia;
		Object obj = null;
		Casilla[][] casillasCopiadas = new Casilla[anchura][altura];
		
		try{			
			obj = super.clone();

		}catch (CloneNotSupportedException e){
			assert false: "El objeto no puede ser clonado";
		}
		copia = (Planta)obj;
		
		//Cambiamos los atributos de la planta copiada para ajustarnos a la especificación
		copia.plantaInferior = null;
		copia.plantaSuperior = null;
		copia.casillas = casillasCopiadas;
		for(int i=0;i<anchura;i++){
			for(int j=0;j<altura;j++){
				copia.casillas[i][j]=casillas[i][j].clone();
				copia.casillas[i][j].setPlanta(copia);
			}
		}
		return copia;
	}
}
