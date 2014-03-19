package practica;

import java.io.*;

import java.util.LinkedList;
import java.net.Socket;
import java.net.UnknownHostException;

public class SensorGas extends Thread{
	private String ruta;
	private boolean encendido;
	private Socket socket;
	private int puerto;

	public SensorGas(String ruta, int puerto){
		this.ruta= ruta;
		this.puerto= puerto;
		encendido= false;
	}
	
	public static void main(String[] args) {
		SensorGas sgas= new SensorGas("D:\\Mis documentos\\Mis proyectos\\SITR\\mina\\valorSensores\\gas1", 5000);
		SensorGas sgas2= new SensorGas("D:\\Mis documentos\\Mis proyectos\\SITR\\mina\\valorSensores\\gas2", 5000);
		sgas.start();
		sgas2.start();
	}
	
	/**
	 * método para obtener los valores del sensor a partir del fichero
	 * que se le indica en el constructor.
	 * @return LinkedList con cada uno de los valores.
	 */
	private LinkedList<Integer> obtenerValores(){
		File archivo = null;
	    FileReader fr = null;
	    BufferedReader br = null;
	    //String linea= "";
	    LinkedList<Integer> listaValores= new LinkedList<Integer>();
	    try {
	         archivo = new File (ruta);
	         fr = new FileReader (archivo);
	         br = new BufferedReader(fr);

	         for(String linea= br.readLine();!linea.equals("end");linea= br.readLine()){
	        	 listaValores.add(Integer.parseInt(linea));
	         }/*
	         while((linea=br.readLine())!=null)
	            listaValores.add(Integer.parseInt(linea));
				*/
	      }
	      catch(Exception e){
	         e.printStackTrace();
	      }finally{
	         try{                    
	            if( null != fr ){   
	               fr.close();     
	            }                  
	         }catch (Exception e2){ 
	            e2.printStackTrace();
	         }
	      }	      
	      return listaValores;
	}
	
	/**
	 * Metodo para enviar la lectura del sensor al puerto indicado
	 */
	public void run() {
		//precondiciones
		if(encendido){														//si ya está encendido el sensor no hacemos nada
			return;
		}		
		encendido= true;													//si no lo marcamos como encendido
		
		//Variables
		LinkedList<Integer> lecturas= obtenerValores();
		PrintWriter out;
		
		//Acciones
		for (Integer lectura : lecturas) {									//mientras haya lecturas pendientes...			
			try {
				if(lectura>-1){												//si sale -1 significa que el sensor ha muerto
					socket= new Socket("localhost",puerto);					//conectamos el sensor al puerto
					out= new PrintWriter(socket.getOutputStream(),true);	//asociamos el socket al printwriter				
					out.print(""+lectura);									//enviamos una lectura
					out.close();											//cerramos la salida
					socket.close();											//y el socket
				}
				try {
					Thread.sleep(3000);										//nos dormimos
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			} catch (UnknownHostException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}


/*
package practica;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class SensorGas {

	public static void main(String[] args) {
		SensorGas sgas= new SensorGas();
		sgas.encendido();
	}

	private void encendido() {
		System.out.println("Sensor Gas online OID: " + this.toString());
		try {
			ServerSocket servidor=new ServerSocket(5000);
			while(true){
				Socket socket= servidor.accept();
				System.out.println("Sensor gas conectado");
				PrintWriter out=new PrintWriter(socket.getOutputStream(),true);
				int i=(int)(1+Math.round(Math.random()*60));
				out.print(""+i);
				System.out.println("lectura gas enviada:"+i);
				out.close();
				socket.close();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}			
	}
}
*/