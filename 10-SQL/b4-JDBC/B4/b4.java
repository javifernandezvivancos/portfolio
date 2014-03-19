import java.sql.*;
import java.io.*;
/*
 
CREATE TABLE MIEDITORIAL	AS SELECT * FROM EDITORIAL;
CREATE TABLE MILIBRO		AS SELECT * FROM LIBRO;
CREATE TABLE MIPUBLICACION  AS SELECT * FROM PUBLICACION;
CREATE TABLE MIAUTOR		AS SELECT * FROM AUTOR;
CREATE TABLE MILIBRO_AUTOR  AS SELECT * FROM LIBRO_AUTOR;
CREATE TABLE MITEMA			AS SELECT * FROM TEMA;
CREATE TABLE MIARTICULO     AS SELECT * FROM ARTICULO;

 */

public class b4 {
	
	/**
	 * @param args
	 */

	private Connection connection;

	private String serverName = "oracle10.inf.um.es";
	private String portNumber = "1521";
	private String sid = "orcl10g";
	private String username = "usuario";
	private String password = "clave";
	private Savepoint sv1;

	private Connection initDB() {

		connection = null;
		sv1 = null;
		try {
			// Load the JDBC driver
			String driverName = "oracle.jdbc.driver.OracleDriver";
			Class.forName(driverName);

			// Create a connection to the database

			String url = "jdbc:oracle:thin:@" + serverName + ":" + portNumber
					+ ":" + sid;

			connection = DriverManager.getConnection(url, username, password);
		} catch (ClassNotFoundException e) {
			System.out.println(e.toString());// Could not find the database driver
		} catch (SQLException e) {
			System.out.println(e.toString());
			// Could not connect to the database
		}
		System.out.println(connection.toString());
		return connection;

	}

	public b4() {

		connection = null;

	}
	
	private void J11(String fecha1, String fecha2){
		try{
			Statement stmt= connection.createStatement();
			ResultSet rs= stmt.executeQuery("SELECT * FROM publicacion WHERE f_publicacion>="+fecha1+" AND f_publicacion<="+fecha2+" GROUP BY libro");
			//Procesa los resultados
			while (rs.next()){
				String libro= rs.getString("libro");
				System.out.println("libro: "+ libro);
			}
			rs.close();
			stmt.close();
		} catch (Exception e){
			System.out.println(e.toString());
			//Could no connect to the database
		}
	}
	private void J12(String aut){
		try{
			Statement stmt= connection.createStatement();
			ResultSet rs= stmt.executeQuery("SELECT * FROM articulo WHERE autor="+aut+" ORDER BY f_creacion");
			//Procesa los resultados
			while(rs.next()){
				String articulo= rs.getString("articulo");
				String f_creacion= rs.getString("f_creacion");
				System.out.println("articulo: "+ articulo+", f_creacion: "+f_creacion);
			}
		}catch(Exception e){
			System.out.println(e.toString());
			//could no connect to the database
		}
	}
	private void J2(String aut, String lib){
		//Método que pone el autor aut del libro lib como principal
		try{
			connection.setAutoCommit(false);

			PreparedStatement updateLibro_autor = connection.prepareStatement("UPDATE libro_autor SET es_principal= 'S' WHERE autor= '"+aut+"' AND libro= '"+lib+"';");
			updateLibro_autor.executeUpdate();
			connection.commit();
			connection.setAutoCommit(true);
			updateLibro_autor.close();			
			/*
			Statement stmt= connection.createStatement();
			ResultSet rs= stmt.executeQuery("SELECT autor, libro FROM libro_autor WHERE autor="+aut+" AND libro="+lib);
			
			while(rs.next()){
				String autor= rs.getString("autor");
				String libro= rs.getString("libro");
				
			}*/
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	private void J3(int numeroLibros){
		String titulo, f_creacion, tema, editorial, f_publicacion, autor;
		int precio, nAutores, es_principal;
		boolean correcto= true;
		
		
		for(int i=0;i<numeroLibros;i++){
			System.out.println("Datos del libro "+(i+1));
			System.out.println("-------------------------------");
			//Datos de la tabla libro
			System.out.println("Introduce el título");
			titulo= leeString();
			System.out.println("Introduce la fecha de creación");
			f_creacion= leeString();			
			System.out.println("Introduce el tema, para obtener la lista de temas disponibles escriba 'help'");
			tema= leeString();
			if(tema.compareTo("help")==0){
				mostrarTemas();
				System.out.println("Introduce el tema");
				tema= leeString();
			}			
			//Datos de la tabla publicación
			System.out.println("Introduce el precio");
			precio= leeEntero();
			System.out.println("Introduce la fecha de publicación");
			f_publicacion= leeString();
			System.out.println("Introduce la editorial, pulsa 'help' para mostrar las disponibles");
			editorial= leeString();
			if(editorial.compareTo("help")==0){
				mostrarEditoriales();
				System.out.println("Introduce la editorial, si la que deseas no se encuentra en la lista escriba 'new'");
				editorial= leeString();
				if(editorial.compareTo("new")==0){
					editorial= crearEditorial();
				}
			}
			//Datos de la tabla libro_autor:
			System.out.println("¿Cuántos autores tiene el libro?");
			nAutores= leeEntero();
			for(int j=0;j<nAutores;j++){
				System.out.println("Introduce el autor "+j+", escribe 'help' para obtener la lista de autores");
				autor= leeString();
				if(autor.compareTo("help")==0){
					mostrarAutores();
					System.out.println("Introduce el autor, si el que deseas no se encuentra en la lista escribe 'new'");
					autor= leeString();
					if(autor.compareTo("new")==0){
						autor= crearAutor();
					}
				}
				System.out.println("¿Es principal el autor que ha introducido?");
				System.out.println("1) SI");
				System.out.println("2) NO");
				es_principal= leeEntero();
			}			
		}
		
	}
	private String crearAutor(){
		//Variables
		String nombre, f_nacimiento;
		
		//Acciones
		//leemos de la entrada los datos que nos hacen falta
		System.out.println("Se va a crear un autor");
		System.out.println("Introduce el nombre del autor");
		nombre= leeString();
		System.out.println("Introduce la fecha de nacimiento del autor");
		f_nacimiento= leeString();
		
	}
	private String crearEditorial(){
		//Variables
		String denominacion, direccion, f_constitucion;
		
		//Acciones
		System.out.println("Se va a crear una editorial");
		System.out.println("Introduce la denominación");
		denominacion= leeString();
		System.out.println("Introduce la fecha de constitución");
		f_constitucion= leeString();
		System.out.println("Introduce la dirección");
		direccion= leeString();
	}
	private void mostrarTemas(){
		try{
			Statement stmt= connection.createStatement();
			ResultSet rs= stmt.executeQuery("SELECT * FROM tema");
			//Procesa los resultados
			while(rs.next()){
				String tema= rs.getString("tema");
				System.out.println(tema);
			}
		}catch(Exception e){
			System.out.println(e.toString());
			//could no connect to the database
		}
	}
	private void mostrarAutores(){
		try{
			Statement stmt= connection.createStatement();
			ResultSet rs= stmt.executeQuery("SELECT * FROM autor");
			//Procesa los resultados
			while(rs.next()){
				String autor= rs.getString("autor");
				System.out.println(autor);
			}
		}catch(Exception e){
			System.out.println(e.toString());
			//could no connect to the database
		}
	}
	private void mostrarEditoriales(){
		try{
			Statement stmt= connection.createStatement();
			ResultSet rs= stmt.executeQuery("SELECT * FROM editorial");
			//Procesa los resultados
			while(rs.next()){
				String tema= rs.getString("editorial");
				System.out.println(tema);
			}
		}catch(Exception e){
			System.out.println(e.toString());
			//could no connect to the database
		}
	}
	private static int leeEntero(){
		InputStreamReader teclado; //Conexión entre el teclado y mi software
		BufferedReader bufferLectura; //lugar donde se almacena lo que he introducido en el teclado
		int entero;
		
		teclado = new InputStreamReader(System.in);
		bufferLectura = new BufferedReader(teclado);//creamos el buffer para leer de teclado
		try{	//leemos el número que introduce el usuario
			entero= Integer.parseInt(bufferLectura.readLine());
		}catch(Exception e){
			throw new IllegalArgumentException("Error:"+
			"IOException, no se ha introducido un número");
		}
		
		return entero;
	}
	private static String leeString(){
		InputStreamReader teclado; //Conexión entre el teclado y mi software
		BufferedReader bufferLectura; //lugar donde se almacena lo que he introducido en el teclado
		String cadena;
		
		teclado = new InputStreamReader(System.in);
		bufferLectura = new BufferedReader(teclado);//creamos el buffer para leer de teclado
		try{	//leemos el número que introduce el usuario
			cadena= bufferLectura.readLine();
		}catch(Exception e){
			throw new IllegalArgumentException("Error:"+
			"IOException, no se ha introducido un número");
		}
		
		return cadena;
	}
	
	public static void main(String[] args) {
		//Variables
		b4 miBD = new b4();
		
		boolean salir= false;
		int opcion;
		String dato1, dato2;
		int dato3;
		
		//Acciones
		miBD.initDB();			//inicializamos la BD
		System.out.println("OK");		
		while(salir!=false){	//mostramos el menú principal del programa
			
			System.out.println("Práctica B4 JDBC, introduzca la acción que desea realizar");
			System.out.println("1) Mostrar todos los libros publicados entre dos fechas dadas");
			System.out.println("2) Mostrar todos los artículos de un autor");
			System.out.println("3) Pasar un autor secundario de un libro a autor principal");
			System.out.println("4) Introducir una serie de libros nuevos");
			System.out.println("9) Salir");
			
			opcion= leeEntero();
			
			if(opcion==1){
				System.out.println("Introduce la fecha de inicio");
				dato1=leeString();
				System.out.println("Introduce la fecha de fin");
				dato2= leeString();
				miBD.J11(dato1, dato2);
			}
			else if(opcion==2){
				System.out.println("Introduce el nombre del autor");
				dato1=leeString();
				miBD.J12(dato1);
			}
			else if(opcion==3){
				System.out.println("Introduce el nombre del autor secundario");
				dato1=leeString();
				System.out.println("Introduce el nombre del libro que ha escrito");
				dato2=leeString();
				miBD.J2(dato1, dato2);
			}
			else if(opcion==4){
				System.out.println("¿Cuál es el número de libros que va a introducir?");
				dato3=leeEntero();
				miBD.J3(dato3);
			}
			else if(opcion==9){
				salir= true;
			}
		}
		
	}
	
}
