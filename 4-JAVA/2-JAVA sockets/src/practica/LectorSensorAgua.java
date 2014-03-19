package practica;

import java.io.BufferedReader;

import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.LinkedList;

public class LectorSensorAgua extends Thread {

	PantallaControl p;
	ServerSocket servidor;
	public static final int numSensores= 4;
	
	public LectorSensorAgua(PantallaControl control) {
		p=control;
		try {
			servidor=new ServerSocket(6000);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public int calcularMedia(LinkedList<Integer> lecturas, int numLecturasCorrectas){
		int resultado= 0;
		
		if(numLecturasCorrectas==0){
			return -1;
		}
		
		for(int i=0; i<numLecturasCorrectas; i++){
			resultado+= lecturas.removeFirst();
		}
		return resultado/numLecturasCorrectas;
	}
	
	private void controlarBomba(int lecturaMedia){
		if(ControlBomba.estaAuto()){
			ControlBomba.informarAgua(lecturaMedia);
		}
	}
	public void run(){		
		System.out.println("Lectura sensor agua online");
		
		//Variables
		Socket socket;																											//socket de escucha
		BufferedReader in;																										//buffer de entrada
		int numLecturasCorrectas= 0;																							//acumulador con el número de lecturas correctas por cada sensor que se van haciendo
		LinkedList<Integer> lecturas= new LinkedList<Integer>();																//lista con las lecturas
		int lecturaMedia;
		
		//Acciones
		while(true){
			try {
				for (numLecturasCorrectas=0; numLecturasCorrectas<numSensores; numLecturasCorrectas++) {						//leemos del socket tantas veces como sensores haya
					servidor.setSoTimeout(2500);																				//establecemos un tiempo límite de espera
					socket= servidor.accept();																					//aceptamos la conexión
					in= new BufferedReader(new InputStreamReader(socket.getInputStream()));										//le asociamos el buffer
					lecturas.add(Integer.parseInt(in.readLine()));																//almacenamos una lectura de un sensor
					//System.out.println("Lectura agua sensor"+numLecturasCorrectas+":"+lecturas.getLast());						//la mostramos por pantalla
					in.close();																									//cerramos el socket y el buffer
					socket.close();
				}
				lecturaMedia= calcularMedia(lecturas, numLecturasCorrectas);	//calculamos la media de las lecturas recibidas
				p.lecturaAgua(Integer.toString(lecturaMedia));					//la mostramos en pantalla
				controlarBomba(lecturaMedia);									//controlamos la bomba en función de la lectura obtenida
				try {
					Thread.sleep(1000);											//nos dormimos
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}catch(SocketTimeoutException ste){																					//si sobrepasamos el timeout... 
				System.out.println("Hay "+(numSensores-numLecturasCorrectas)+" sensores de agua que no envían información");	//mostramos un error
				p.lecturaAgua(Integer.toString(calcularMedia(lecturas, numLecturasCorrectas)));									//y mostramos la media de los valores que hayamos podido obtener
				
			}catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}