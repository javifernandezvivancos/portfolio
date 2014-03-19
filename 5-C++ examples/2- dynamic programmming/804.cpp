///////////////////////////////////////////////////////////
// ACTIVIDAD DE EVALUACION CONTINUA                      //
// Parte 2. Tema 4. Algoritmos voraces. Version 2009     //
// Algoritmos y Estructuras de Datos, 2o, ITIS  	 //
// Javier Fernández Vivancos, 15482513-V                 //
///////////////////////////////////////////////////////////

#include <string.h>   // Funcion memset
#include <iostream>   // E/S con cin y cout
using namespace std;

////////////  	  CONSTANTES	  ////////////////
#define MAXPAL 200				//
//////////////////////////////////////////////////


////////////  VARIABLES GLOBALES  ////////////////
string clave[MAXPAL];				//
int longClave;					//
						//
string mensaje[MAXPAL];				//
int longMensaje;				//
//////////////////////////////////////////////////


////////////    PROCEDIMIENTOS	  ////////////////
void inicializar(void)
/*Inicializamos las variables globales a 0 o a vacío. Esta rutina es prescindible*/
{
	for(int i=0;i<MAXPAL;i++)   clave[i]="";
	for(int i=0;i<MAXPAL;i++)   mensaje[i]="";
	longClave=0;
	longMensaje=0;
}

void simplifica(string claveLar[MAXPAL], string mensajeLar[MAXPAL])
{
/*rutina que simplifica los datos de entrada para resolver el ejercicio de forma eficiente*/

	int pos=0;

	for(int i=0;claveLar[i]!="";i++){			//recorremos los 2 arrays
		for(int j=0;mensajeLar[j]!="";j++){
			if(claveLar[i]==mensajeLar[j]){		//si una palabra está en los 2 arrays
				clave[pos]= claveLar[i];	//la guardamos en la variable global
				pos++;
				break;
			}
		}
	}
	longClave=pos;						//Actualizamos la longitud de la clave simplificada

	pos=0;
	for(int i=0;mensajeLar[i]!="";i++){			//recorremos los 2 arrays
		for(int j=0;claveLar[j]!="";j++){
			if(mensajeLar[i]==claveLar[j]){		//si una palabra está en los 2 arrays
				mensaje[pos]= mensajeLar[i];	//la guardamos en la variable global
				pos++;
				break;
			}
		}
	}
	longMensaje=pos;					//Actualizamos la longitud del mensaje simplificado
}
bool lee()
{
/*leemos uno de los casos de la entrada y almacenamos los datos de entrada
    - devolvemos 1 si se ha podido realizar correctamente
    - devolvemos 0 si no se ha podido (porque no hay más casos en la entrada estándar
*/
	string claveLar[MAXPAL+1];
	string mensajeLar[MAXPAL+1];

	///Leemos la clave///
	char c= ' ';
	int i;

	for(i=0; c!='\n'; i++)
	{
		cin >> claveLar[i];	//guardamos la palabra en su posición correspondiente
		for(int j=0;claveLar[i][j];j++)	
			claveLar[i][j]= (char)tolower(claveLar[i][j]); //convertimos la palabra a minúsculas
		if(claveLar[i]=="")  return 0;  //Si no quedan más palabras en la entrada devolvemos un 0
		cin.get(c);		//guardamos el siguiente carácter en c1, que puede ser un espacio, retorno de carro o el valor NULL
	}
	claveLar[i]="";			//guardamos una cadena vacía al final del array para saber que es su final

	///Leemos el mensaje///
	c=' ';
	for(i=0; c!='\n'; i++)
	{		
		cin >> mensajeLar[i];	//guardamos la palabra en su posición correspondiente
		for(int j=0;mensajeLar[i][j];j++) 
			mensajeLar[i][j]= (char)tolower(mensajeLar[i][j]); //convertimos la palabra a minúsculas
		cin.get(c);		//guardamos el siguiente carácter en c1, que puede ser un espacio, retorno de carro o el valor NULL
	}
	mensajeLar[i]="";		//guardamos una cadena vacía al final del array para saber que es su final

	///Simplificamos la clave y el mensaje///
	simplifica(claveLar, mensajeLar);
	return 1;		//devolvemos un 1 porque se ha podido leer correctamente de la entrada
}

void copiarCeldaSup(int *pTabla, int i, int j)
/*rutina para copiar en la celda que nos dan su superior*/
{
	int *celda, *celdaSup;

	celda= pTabla+(longMensaje*i+j);
	celdaSup= celda-1;
	if(j>0)		*celda= *celdaSup;		//tabla[i][j]= tabla[i][j-1];
}
int obtenerMax(int *pTabla, int i, int j)
{
/*rutina para hallar el máximo valor de la fila j desde la columna 0 hasta i*/
	int max= 0;
	int *celda = pTabla+j;
	if(j<0) return 0;	

	for(int k=0;k<i;k++){
		if(*celda>max)	max= *celda;
		celda+= longMensaje;
	}
	return max;
}
int resolver(void)
{
/*rutina que resuelve el problema de forma dinámica almacenando soluciones en la tabla*/
	int tabla[longClave][longMensaje];
	memset(tabla, 0, sizeof(tabla));
	int *pTabla= &tabla[0][0];

	for(int j=0;j<longMensaje;j++){
		for(int i=0;i<longClave;i++){				//Vamos recorriendo la fila copiando cada una de las celdas superiores
			copiarCeldaSup(pTabla,i,j);
			if(clave[i]==mensaje[j])			//Si coincide la clave con el mensaje actualizamos el nuevo valor en la tabla
				tabla[i][j]= obtenerMax(pTabla,i,j-1)+1;
		}	
	}

	return obtenerMax(pTabla,longClave,longMensaje-1);		//Devolvemos el valor máximo que hay en la ultima fila de la tabla (resultado).
}

int main(void)
{
	inicializar();							//inicializamos las variables globales
	while(lee()){							//mientras queden casos en la entrada vamos leyéndolos
		cout << resolver() << endl;				//resolvemos el caso actual
		inicializar();						//volvemos a inicializar las variables globales
	}

	return 0;
}
