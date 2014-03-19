import java.sql.*;
import java.io.*;
/*
 javac -classpath ojdbc14.jar PruebaBD.java
java -classpath ojdbc14.jar;. PruebaBD
CREATE OR REPLACE TABLE MIEDITORIAL	AS SELECT * FROM EDITORIAL;
CREATE OR REPLACE TABLE MILIBRO		AS SELECT * FROM LIBRO;
CREATE OR REPLACE TABLE MIPUBLICACION  AS SELECT * FROM PUBLICACION;
CREATE OR REPLACE TABLE MIAUTOR		AS SELECT * FROM AUTOR;
CREATE OR REPLACE TABLE MILIBRO_AUTOR  AS SELECT * FROM LIBRO_AUTOR;
CREATE OR REPLACE TABLE MITEMA			AS SELECT * FROM TEMA;
CREATE OR REPLACE TABLE MIARTICULO     AS SELECT * FROM ARTICULO;

 */

public class b4 {
	
	/**
	 * @param args
	 */

	private Connection connection;

	private String serverName = "oracle10.inf.um.es";
	private String portNumber = "1521";
	private String sid = "orcl10g";
	private String username = "FBDS201";
	private String password = "Ania";
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
			String query="SELECT DISTINCT libro FROM mipublicacion WHERE f_publicacion>=to_date(?, 'dd/mm/yyyy') AND f_publicacion<=to_date(?, 'dd/mm/yyyy')";		
			PreparedStatement stmt = connection.prepareStatement(query);		
			stmt.setString(1, fecha1);
			stmt.setString(2, fecha2);
			ResultSet rs= stmt.executeQuery();
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
			String query="SELECT * FROM miarticulo WHERE autor=? ORDER BY f_creacion";
			PreparedStatement stmt = connection.prepareStatement(query);		
			stmt.setString(1, aut);
			ResultSet rs= stmt.executeQuery();
			
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
			
			String query= "UPDATE MIlibro_autor SET es_principal= 'S' WHERE autor=? AND libro=?";
			PreparedStatement stmt = connection.prepareStatement(query);
			stmt.setString(1, aut);
			stmt.setString(2, lib);
			stmt.executeUpdate();
			connection.commit();
			connection.setAutoCommit(true);
			stmt.close();
			
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	private void J3(int numeroLibros){
		String titulo, f_creacion, tema, editorial, f_publicacion, autor, es_principal, libro;
		int precio, nAutores;
		
		
		for(int i=0;i<numeroLibros;i++){
			System.out.println("Datos del libro "+(i+1));
			System.out.println("-------------------------------");
			//Datos de la tabla libro
			System.out.println("Introduce el libro");
			libro= leeString();			
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
				System.out.println("Introduce el autor "+(j+1)+", escribe 'help' para obtener la lista de autores");
				autor= leeString();
				if(autor.compareTo("help")==0){
					mostrarAutores();
					System.out.println("Introduce el autor, si el que deseas no se encuentra en la lista escribe 'new'");
					autor= leeString();
					if(autor.compareTo("new")==0){
						//Creamos el autor
						autor= crearAutor();
					}
				}
				System.out.println("¿Es principal el autor que ha introducido S/N?");
				es_principal= leeString();
				//crear libro_autor
				crearLibro_autor(libro, autor, es_principal);
			}
			//creamos la publicacion
			
		try{	
			connection.setAutoCommit(false);
			
			
			crearPublicacion(editorial, libro, precio, f_publicacion);
			//creamos el libro
			crearLibro(libro, titulo, f_creacion, tema);
			connection.commit();
			connection.setAutoCommit(true);
			System.out.print("\n\n");
		}catch(Exception e){
		System.out.print(e.toString());
		}	
			
		}		
	}
	private void crearLibro(String libro, String titulo, String f_creacion, String tema){
		try {

			
			PreparedStatement updateLibro = connection.prepareStatement("INSERT INTO MIlibro(libro,titulo, f_creacion, tema) VALUES(?,?,TO_DATE(?, 'DD/MM/YYYY'),?)");
			
			updateLibro.setString(1, libro );
			updateLibro.setString(2, titulo);
			updateLibro.setString(3, f_creacion);
			updateLibro.setString(4, tema);
			updateLibro.executeUpdate();
			updateLibro.close();
		
		} catch (Exception e) {
			System.out.println(e.toString());

		}
	}

	private void crearPublicacion(String editorial, String libro, int precio, String f_publicacion){

		String publi="";
		try {
		
		
		
			Statement stmt = connection.createStatement();
			ResultSet rs = stmt.executeQuery("select publicacion from mipublicacion");
			//		  Procesa los resultados

			while (rs.next()) {
				publi=rs.getString("publicacion");
			}
			
			publi=publi.substring(0,1)+(Integer.parseInt(publi.substring(1,publi.length()))+1);
			rs.close();
			stmt.close();

			
		} catch (Exception e) {
			System.out.println(e.toString());
			// Could not connect to the database
		}
		

		try{
				
			
			PreparedStatement updatePublicacion = connection.prepareStatement("INSERT INTO MIPublicacion(publicacion, editorial, libro,precio, f_publicacion) VALUES(?,?,?,?,TO_DATE(?, 'DD/MM/YYYY'))");
			
			updatePublicacion.setString(1, publi );
			updatePublicacion.setString(2, editorial);
			updatePublicacion.setString(3, libro);
			updatePublicacion.setInt(4, precio);
			updatePublicacion.setString(5, f_publicacion);
		
			updatePublicacion.executeUpdate();
			updatePublicacion.close();
		
		} catch (Exception e) {
			System.out.println(e.toString());

		}
	}

	private void crearLibro_autor(String libro, String autor, String es_principal){
		try {

			
			PreparedStatement updateLibro_autor = connection.prepareStatement("INSERT INTO MIlibro_autor(libro,autor, es_principal) VALUES(?,?,?)");
			
			updateLibro_autor.setString(1, libro );
			updateLibro_autor.setString(2, autor);
			updateLibro_autor.setString(3, es_principal);
		
			updateLibro_autor.executeUpdate();
			updateLibro_autor.close();
		
		} catch (Exception e) {
			System.out.println(e.toString());

		}
	}


	private String crearAutor(){
		//Variables
		String nombre, f_nacimiento, autor;
		
		//Acciones
		//leemos de la entrada los datos que nos hacen falta
		System.out.println("Se va a crear un autor");
		System.out.println("Introduce el autor");
		autor=leeString();
		System.out.println("Introduce el nombre del autor");
		nombre= leeString();
		System.out.println("Introduce la fecha de nacimiento del autor");
		f_nacimiento= leeString();
		
		//creamos el autor
		try {

			connection.setAutoCommit(false);
			PreparedStatement updateAutor = connection.prepareStatement("INSERT INTO MIAUTOR(AUTOR,NOMBRE, F_NACIMIENTO) VALUES(?,?, TO_DATE(?, 'DD/MM/YYYY'))");
			
			updateAutor.setString(1, autor );
			updateAutor.setString(2, nombre);
			updateAutor.setString(3, f_nacimiento);
		
			updateAutor.executeUpdate();
			updateAutor.close();

		} catch (Exception e) {
			System.out.println(e.toString());

		}
		return autor;
		
	}
	private String crearEditorial(){
		//Variables
		String denominacion, direccion, f_constitucion, editorial;
		
		//Acciones
		System.out.println("Se va a crear una editorial");		
		System.out.println("Introduce el nombre");
		editorial= leeString();
		System.out.println("Introduce la denominación");
		denominacion= leeString();
		System.out.println("Introduce la fecha de constitución");
		f_constitucion= leeString();
		System.out.println("Introduce la dirección");
		direccion= leeString();
		
		//Creamos la editorial
		try {

			connection.setAutoCommit(false);
			PreparedStatement updateEditorial = connection.prepareStatement("INSERT INTO MIEDITORIAL(EDITORIAL, DENOMINACION, DIRECCION, F_CONSTITUCION) VALUES(?,?,?, TO_DATE(?, 'DD/MM/YYYY'))");
			
			updateEditorial.setString(1, editorial );
			updateEditorial.setString(2, denominacion);
			updateEditorial.setString(3, direccion);
			updateEditorial.setString(4, f_constitucion);
			updateEditorial.executeUpdate();
			updateEditorial.close();			
			System.out.println("Editorial creada "+editorial);
		} catch (Exception e) {
			System.out.println(e.toString());

		}
		return editorial;
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
	private void mostrarLibro_autor(){
		try{
			Statement stmt= connection.createStatement();
			ResultSet rs= stmt.executeQuery("SELECT * FROM libro_autor");
			//Procesa los resultados			
			System.out.println("autor  libro  es_principal");
			while(rs.next()){
				String libro= rs.getString("libro");
				String autor= rs.getString("autor");
				String es_principal= rs.getString("es_principal");
				System.out.println(autor+"	"+libro+"	"+es_principal);
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
		
		int opcion;
		String dato1, dato2;
		int dato3;
		
		//Acciones
		miBD.initDB();			//inicializamos la BD
		System.out.println("OK");		
		while(true){	//mostramos el menú principal del programa
			
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
				System.out.println("escriba 'help' para mostrar la tabla libro_autor");
				dato1=leeString();
				if(dato1.compareTo("help")==0){
					miBD.mostrarLibro_autor();					
					System.out.println("Introduce el nombre del autor secundario");					
					dato1=leeString();
				}
				System.out.println("Introduce el libro que ha escrito");
				dato2=leeString();
				miBD.J2(dato1, dato2);
			}
			else if(opcion==4){
				System.out.println("¿Cuál es el número de libros que va a introducir?");
				dato3=leeEntero();
				miBD.J3(dato3);
			}
			else if(opcion==9){
				return;
			}
		}
		
	}
	
}
