///////////////////////////////////////////////////////////
// ACTIVIDAD DE EVALUACION CONTINUA                      //
// Parte 2. Tema 3. Algoritmos voraces. Version 2009     //
// Algoritmos y Estructuras de Datos, 2o, ITIS  	 //
// Javier Fernández Vivancos, 15482513-V                 //
///////////////////////////////////////////////////////////

#include <string.h>   // Funcion memset
#include <iostream>   // E/S con cin y cout
using namespace std;

#define MAX 10000
// Para simplificar, fijamos un tamaño maximo de 10000

///////////////////////////////////////////////////////////
//////////        VARIABLES GLOBALES        ///////////////
///////////////////////////////////////////////////////////

int T[MAX];	    // Tiempo que puede esperar cada avión
int B[MAX];	    // Array de beneficios que aporta cada avión
int S[MAX];	    // Array solución con los tiempos de cada avión insertado
int Ut, A;          // Unidades de tiempo disponibles y numero de aviones esperando

///////////////////////////////////////////////////////////
//////////     FUNCIONES DEL PROGRAMA       ///////////////
///////////////////////////////////////////////////////////

void lee (void)
// Procedimiento para leer un caso de la entrada
{
	cin >> Ut;
	cin >> A;
	for (int i= 0; i<A; i++){
		cin >> T[i];
	}
	for (int i= 0; i<A; i++){
		cin >> B[i];
	}
}

void ordenar(void)
//Procedimiento para ordenar los aviones de menor a mayor beneficio
{
	int aux;

	for(int i=1;i<A;i++){
		for(int j=i;j>0;j--){
			if((B[j]<B[j-1]) || (B[j]==B[j-1]&&T[j]>T[j-1])){
				aux= T[j];
				T[j]= T[j-1];
				T[j-1]= aux;
				aux= B[j];
				B[j]= B[j-1];
				B[j-1]= aux;
			}
			else{
				j=0;
			}
		}
	}
}

int factible(void)
{
	int longitud=0; //candidad de elementos del array
	int i=0;	//Posición donde vamos insertar el nuevo candidato

	while(S[longitud]!='\0') longitud++; //Calculamos el número de elementos que tiene el array Solución
	while(S[i]<T[A] && i<longitud) i++; //Calculamos la posición donde debemos insertar el nuevo elemento
	for(int j=longitud;j>i;j--){ //Le hacemos sitio al elemento que vamos a insertar
		S[j] = S[j-1];
	}
	S[i]= T[A]; //Insertamos el nuevo elemento
	longitud++;

	for(int k=1;k<longitud+1;k++){ //comprobamos si el nuevo elemento es factible
		if(S[k-1]<k){ //si no lo es lo sacamos del array de soluciones parciales
			for(int j= i; j<longitud;j++) S[j]= S[j+1];
			return 0;
		}
	}
	return 1;
}

int voraz(void)
{
	int resultado= 0;

	ordenar();
	while(Ut>0 && A>0){
		A--;
		if(factible()){
			resultado+= B[A];
			Ut--;
		}
	}
	return resultado;
}

///////////////////////////////////////////////////////////
//////////        PROGRAMA PRINCIPAL        ///////////////
///////////////////////////////////////////////////////////

int main (void){
	int N;

	cin >> N;
	for (int i= 0; i<N; i++) {
		memset(S, 0, sizeof(S)); //Vaciamos el array de soluciones.
		lee(); //Leemos la entrada
		cout << voraz() << endl;
	}
}

