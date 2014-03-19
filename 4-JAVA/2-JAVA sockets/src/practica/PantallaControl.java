package practica;


import java.awt.Color;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.LinkedList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class PantallaControl  extends JFrame implements  ActionListener{
	private LectorSensorGas sensorGas;
	private LectorSensorAgua sensorAgua;
	private static final long serialVersionUID = 1L;
	private JPanel pantalla=new JPanel();
	private LinkedList<Lectura> lecturasDiferidas= new LinkedList<Lectura>();
	GridBagConstraints restricciones=new GridBagConstraints();
	JButton bLeerSensor, bLeerSensor2, bLeerSensor3;
	JTextField tsensor1;
	JTextField tsensor2;
	JLabel lalerta;
	static JLabel valorBomba;
	JLabel agua;
	JLabel gas;
	Connection conn;
	
	public PantallaControl(Connection conn) {
		this.conn=conn;
		pantalla.setLayout(new GridBagLayout());
		restricciones.gridx=0;
		restricciones.gridy=0;
		restricciones.gridwidth=1;
		restricciones.gridheight=1;
		bLeerSensor=new JButton("Auto/Manual");
		bLeerSensor.addActionListener(this);
		bLeerSensor.setActionCommand("leer");
		pantalla.add(bLeerSensor,restricciones);
		
		
		bLeerSensor2= new JButton("Encender/Apagar Bomba");
		bLeerSensor2.addActionListener(this);
		bLeerSensor2.setActionCommand("Bomba");
		GridBagConstraints restricciones2= new GridBagConstraints();
		restricciones2.gridx= 0;
		restricciones2.gridy= 2;
		restricciones.gridwidth= 1;
		restricciones.gridheight= 1;
		pantalla.add(bLeerSensor2,restricciones2);
		valorBomba= new JLabel("Parada");
		valorBomba.setForeground(Color.orange);
		restricciones2.gridx= 2;
		restricciones2.gridy= 2;
		pantalla.add(valorBomba,restricciones2);
		
		bLeerSensor3= new JButton("Volcar BBDD");
		bLeerSensor3.addActionListener(this);
		bLeerSensor3.setActionCommand("BBDD");
		restricciones2.gridx= 0;
		restricciones2.gridy= -2;
		restricciones.gridwidth= 1;
		restricciones.gridheight= 1;
		pantalla.add(bLeerSensor3,restricciones2);
		
		restricciones.gridx=1;
		restricciones.gridy=0;
		tsensor1=new JTextField(4);
		pantalla.add(tsensor1,restricciones);
		restricciones.gridx=2;
		restricciones.gridy=0;
		tsensor2=new JTextField(4);
		pantalla.add(tsensor2,restricciones);
		lalerta=new JLabel("Auto");
		lalerta.setForeground(Color.green);
		
		/*gas= new JLabel("Gas");
		gas.setForeground(Color.gray);
		agua= new JLabel("Agua");
		agua.setForeground(Color.gray);
		*/
		restricciones.gridx=0;
		restricciones.gridy=1;
		pantalla.add(lalerta,restricciones);
		setContentPane(pantalla);
		setSize(400,400);
		setTitle("Control Bomba");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	
		setVisible(true);
		
		try{
			PreparedStatement st = null;
			st= conn.prepareStatement("CREATE TABLE EVENTOS (IDEVENTO VARCHAR, VALOR VARCHAR, DIFERIDA VARCHAR)");
			st.executeUpdate();
		} catch (SQLException e1) {
			System.out.println("Error al crear la tabla eventos");
			e1.printStackTrace();
		}
		
		lanzarSensores();
	}

	private void lanzarSensores() {
		sensorGas=new LectorSensorGas(this);
		sensorGas.start();
		sensorAgua=new LectorSensorAgua(this);
		sensorAgua.start();		
	}

	public void actionPerformed(ActionEvent arg0) {
		String comando = arg0.getActionCommand();
		
		if(comando.equals("leer")){
			if(lalerta.getText().equals("Auto")){
				ControlBomba.ponerManual();
				lalerta.setForeground(Color.red);
				lalerta.setText("Manual");
			}else{
				ControlBomba.ponerAuto();
				lalerta.setForeground(Color.green);
				lalerta.setText("Auto");
			}
		}
		if(comando.equals("Bomba")){
			if(lalerta.getText().equals("Manual")){
				if(valorBomba.getText().equals("Parada")){	
					ControlBomba.encenderBomba();					
					valorBomba.setText("Encendida");
				}
				else{
					ControlBomba.pararBomba();
					valorBomba.setText("Parada");
				}
			}
		}
		if(comando.equals("BBDD")){			
			try {
				Statement st1= conn.createStatement();
				ResultSet rst= st1.executeQuery("SELECT IDEVENTO, VALOR, DIFERIDA FROM EVENTOS");
				while(rst.next()){
					System.out.println(rst.getObject(1).toString()+" "+rst.getObject(2).toString()+" "+rst.getObject(3).toString());
				}
			} catch (SQLException e1) {
				e1.printStackTrace();
			}
		}
	}
	
	public void introducirBBDD(Lectura lectura){
		PreparedStatement st= null;
		try{											//intentamos introducir la lectura
			st = conn.prepareStatement("INSERT INTO EVENTOS (IDEVENTO,VALOR,DIFERIDA)" +
			" VALUES(?,?,?)");
			st.setString(1,lectura.getIdEvento());
			st.setString(2,lectura.getValor());
			st.setString(3,"en tiempo real");
			st.executeUpdate();
		}catch (SQLException e1) {						//si no podemos la agregamos a la lista de lecturas diferidas
			System.out.println("Error en el acceso a la BBDD");
			lecturasDiferidas.add(lectura);
		}/*
		catch(NullPointerException npe){
			lecturasDiferidas.add(lectura);
		}*/
	}
	
	private void gestionarBBDD(Lectura lectura){
		if(lecturasDiferidas.isEmpty()){				//si no hay lecturas diferidas pendientes introducimos la actual
			introducirBBDD(lectura);
		}
		else{
			PreparedStatement st= null;						//si sí que las hay las recorremos y las vamos almacenando como diferidas
			try{
				for (Lectura lecturaDiferida : lecturasDiferidas) {
					st = conn.prepareStatement("INSERT INTO EVENTOS (IDEVENTO,VALOR,DIFERIDA)" +
					" VALUES(?,?,?)");
					st.setString(1,lecturaDiferida.getIdEvento());
					st.setString(2,lecturaDiferida.getValor());
					st.setString(3,"DIFERIDA");
					st.executeUpdate();
				}
				introducirBBDD(lectura);
			} catch (SQLException e1) {
				System.out.println("Error en el acceso a la BBDD");
				lecturasDiferidas.add(lectura);
			}
		}
	}
	
	public void lecturaGas(String s) {
		tsensor1.setText(s);
		repaint();
		gestionarBBDD(new Lectura("LecturaSensorGas", s));
		
		/*
		PreparedStatement st = null;
		try {
			st = conn.prepareStatement("INSERT INTO EVENTOS (IDEVENTO,VALOR,ERROR)" +
			" VALUES(?,?,?)");
			st.setString(1,"Lectura Sensor Gas");
			st.setString(2,s);
			st.setString(3,"");
			st.executeUpdate();
		} catch (SQLException e1) {
			e1.printStackTrace();
		}
		*/
	}

	public void lecturaAgua(String s) {
		tsensor2.setText(s);
		repaint();
		gestionarBBDD(new Lectura("LecturaSensorAgua", s));
	}
	static void valorBomba(String s){
		valorBomba.setText(s);
	}
}
