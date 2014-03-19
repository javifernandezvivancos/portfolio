package practica;

import java.sql.Connection;

import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import javax.swing.JFrame;


public class ControlBomba {
	private static final int gasMin= 0;
	private static final int gasMax= 100;
	private static final int aguaMin= 50;
	private static final int aguaMax= 100;
	private static boolean bombaEncendida;
	private static boolean manual;
	private static boolean gasCorrecto= false;
	private static boolean aguaCorrecta= false;
	private static JFrame frame;
	
	//obtener valores de seguridad
	public static boolean gasSeguro(int valor){
		if(valor>gasMin && valor<gasMax){
			return true;
		}
		return false;
	}
	public static boolean aguaSuperiorAMax(int valor){
		if(valor>aguaMax){
			return true;
		}
		return false;
	}
	public static boolean aguaInferiorAMin(int valor){
		if(valor<aguaMin){
			return true;
		}
		return false;
	}
	
	//manejo de la bomba
	public static void pararBomba(){
		bombaEncendida= false;
		PantallaControl.valorBomba("Parada");
		
		PantallaControl pc= (PantallaControl)frame;
		pc.introducirBBDD(new Lectura("BombaParada",""));
		System.out.println("Bomba parada");
	}
	public static void encenderBomba(){
		bombaEncendida= true;
		PantallaControl.valorBomba("Encendida");
		
		PantallaControl pc= (PantallaControl)frame;
		pc.introducirBBDD(new Lectura("BombaEncendida",""));
		System.out.println("Bomba encendida");
	}/*
	public static boolean estaEncendida(){
		return bombaEncendida;
	}*/
	/*public static boolean valoresCorrectos(){
		
	}*/
	
	/**
	 * Metodo para que el lectorSensorAgua informe sobre su lectura, a partir de ésta
	 * el método tendrá total libertad para encender/parar la bomba.
	 */
	public static void informarAgua(int valor){
		if(valor==-1)				{pararBomba();}			//si ninguno de los sensores de agua envía información paramos la bomba
		if(aguaSuperiorAMax(valor))	{aguaCorrecta= true;}	//la variable aguaCorrecta indica si puede encenderse la bomba...
		else						{aguaCorrecta= false;}	//...en caso de que esté apagada.
		
		if(bombaEncendida && aguaInferiorAMin(valor)){		//comprobamos si debemos parar la bomba
			pararBomba();
		}
		else if(!bombaEncendida && aguaCorrecta && gasCorrecto){//si se puede encender la bomba se hace
				encenderBomba();
		}
	}
	
	/**
	 * Metodo para que el lectorSensorGas informe sobre su lectura, a partir de ésta 
	 * el método tendrá total libertad para encender/parar la bomba.
	 */
	public static void informarGas(int valor){
		if(valor==-1)			{pararBomba();}			//si ninguno de los sensores de gas envía información paramos la bomba
		if(gasSeguro(valor))	{gasCorrecto= true;}		//actualizamos la variable gasCorrecto
		else					{gasCorrecto= false;}
				
		if(bombaEncendida && !gasCorrecto){				//si la bomba está encendida y el gas no es correcto la paramos.
			pararBomba();
		}
		
		else if(!bombaEncendida && gasCorrecto && aguaCorrecta){//si la bomba está apagada y el gas y el agua son correctos la encendemos
				encenderBomba();
		}
	}
	
	//manejo del modo de funcionamiento
	public static void ponerManual(){
		ControlBomba.manual= true;
	}
	public static void ponerAuto(){
		ControlBomba.manual= false;
	}
	public static boolean estaAuto(){
		return !ControlBomba.manual;
	}
	public static boolean estaManual(){
		return ControlBomba.manual;
	}
	
	public static void main(String[] args) {
		try {
	        Class.forName("org.hsqldb.jdbcDriver" );
	    } catch (Exception e) {
	        System.out.println("ERROR: failed to load HSQLDB JDBC driver.");
	        e.printStackTrace();	       
	    }
	    Connection conn=null;
	    try {
			conn = DriverManager.getConnection("jdbc:hsqldb:mem://localhost/burn", "sa", "");
		} catch (SQLException e) {			
			e.printStackTrace();
		}
		frame=new PantallaControl(conn);
		frame.show();
		SensorAgua.main(args);
		SensorGas.main(args);
	}
}