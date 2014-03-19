package practica;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import org.hsqldb.Database;

public class AccesoBBDD {

	/**
	 * 
	 * CREATE TABLE EVENTOS(
IDEVENTO VARCHAR,
FECHA TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL,
VALOR VARCHAR,
ERROR VARCHAR )
	 */
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
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		PreparedStatement st = null;
		
		try{
		st= conn.prepareStatement("CREATE TABLE EVENTOS (IDEVENTO VARCHAR, TIPO VARCHAR, VALOR VARCHAR)");
		st.executeUpdate();
		} catch (SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		try {
			st = conn.prepareStatement("INSERT INTO EVENTOS" +
			" VALUES(?,?,?)");
			st.setString(1,"Sesor Superior Agua");
			st.setString(2,"20");
			st.setString(3,"");
			st.executeUpdate();
		} catch (SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		try {
			Statement st1= conn.createStatement();
			ResultSet rst= st1.executeQuery("SELECT IDEVENTO, TIPO, VALOR FROM EVENTOS");
			rst.next();
			System.out.println(rst.getObject(1).toString());
		} catch (SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	}

}
