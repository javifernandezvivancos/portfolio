package practica;

import java.io.BufferedReader;


import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.*;//LinkedList;

public class LectorSensorGas extends Thread {

	PantallaControl p;
	ServerSocket servidor;
	public static final int numSensores= 2;
	
	public LectorSensorGas(PantallaControl control) {
		p=control;
		try {
			servidor=new ServerSocket(5000);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	private void controlarBomba(int lecturaMedia){
		if(ControlBomba.estaAuto()){
			ControlBomba.informarGas(lecturaMedia);
		}
	}
	public int calcularMedia(ArrayList<Integer> lecturas){
		int resultado= 0;
		int numLecturasCorrectas= lecturas.size();
		
		if(numLecturasCorrectas==0){
			return -1;
		}
		
		for(int i=0; i<numLecturasCorrectas; i++){
			resultado+= lecturas.remove(0);
		}
		return resultado/numLecturasCorrectas;
	}
	public void run(){		
		System.out.println("Lectura sensor gas online");
		
		//Variables
		Socket socket;																											//socket de escucha
		BufferedReader in;																										//buffer de entrada
		int numLecturasCorrectas= 0;																							//acumulador con el número de lecturas correctas por cada sensor que se van haciendo
		ArrayList<Integer> lecturas= new ArrayList<Integer>();																//lista con las lecturas
		int lecturaMedia;
		
		//Acciones
		while(true){
			try {
				for (numLecturasCorrectas=0; numLecturasCorrectas<numSensores; numLecturasCorrectas++) {						//leemos del socket tantas veces como sensores haya
					servidor.setSoTimeout(2500);																				//establecemos un tiempo límite de espera
					socket= servidor.accept();																					//aceptamos la conexión
					in= new BufferedReader(new InputStreamReader(socket.getInputStream()));										//le asociamos el buffer
					lecturas.add(Integer.parseInt(in.readLine()));																//almacenamos una lectura de un sensor
					//System.out.println("Lectura gas sensor"+numLecturasCorrectas+":"+lecturas.get(numLecturasCorrectas));//.getLast());						//la mostramos por pantalla
					in.close();																									//cerramos el socket y el buffer
					socket.close();
				}
				lecturaMedia= calcularMedia(lecturas);
				p.lecturaGas(Integer.toString(lecturaMedia));
				controlarBomba(lecturaMedia);
				
				try {
					Thread.sleep(1000);									//nos dormimos
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}catch(SocketTimeoutException ste){																					//si sobrepasamos el timeout... 
				System.out.println("Hay "+(numSensores-numLecturasCorrectas)+" sensores de gas que no envían información");		//mostramos un error
				p.lecturaGas(Integer.toString(calcularMedia(lecturas)));									//y mostramos la media de los valores que hayamos podido obtener

			}catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}














/*
package practica;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;



public class LectorSensorGas extends Thread {

	PantallaControl p;
	
	public LectorSensorGas(PantallaControl p){
		this.p=p;
	}
	
	public void run(){
		while(true){
			try{
				String s;
				Socket socket=new Socket("localhost",5000);
				BufferedReader in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
				s=in.readLine();
				System.out.println("Lectura gas:"+s);
				p.lecturaGas(s);
				in.close();
				socket.close();
				try {
					sleep(3000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			catch(UnknownHostException une){
				System.out.println("No se encuentra el servidor, esperamos 3 segundos");
				try {
					sleep(3000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			catch(IOException une){
				System.out.println("Error en la comunicación");
				try {
					sleep(3000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}
}
*/