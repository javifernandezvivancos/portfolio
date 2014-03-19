package practica;

public class Lectura {
	String idEvento; 
	String valor;
	String error;
	
	public Lectura(String idEvento, String valor){
		this.idEvento= idEvento;
		this.valor= valor;
	}
	
	public String getIdEvento(){
		return idEvento;
	}
	public String getValor(){
		return valor;
	}
}
