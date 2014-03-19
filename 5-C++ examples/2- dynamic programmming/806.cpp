///////////////////////////////////////////////////////////
// ACTIVIDAD DE EVALUACION CONTINUA                      //
// Parte 2. Tema 4. Algoritmos voraces. Version 2009     //
// Algoritmos y Estructuras de Datos, 2o, ITIS  	 //
// Javier Fernández Vivancos, 15482513-V                 //
///////////////////////////////////////////////////////////

#include <string.h>   // Funcion memset
#include <iostream>   // E/S con cin y cout
using namespace std;

///////////   VARIABLES GLOBALES   ////////////////
#define MAXPESO 90
#define MAXPERS 50

int pesos[MAXPERS+1];
int nPers;

/////////////   PROCEDIMIENTOS   //////////////////
int max(int x, int y)
/*función que calcula el mínimo entre dos números*/
{
	if(x<y)	return y;
	else	return x;
}
void imprime(int numero1, int pesoTotal)
/*Procedimiento para imprimir el resultado*/
{
	int numero2= pesoTotal-numero1;
	
	if(numero2<numero1)	cout << numero2 << " " << numero1;	//Imprimimos primero el menor de los 2 valores
	else			cout << numero1 << " " << numero2;
	cout << endl;
}
void calcula(int pesoTotal)
/*función que resuelve el problema de forma dinámica*/
{
	int tabla[nPers+1][pesoTotal/2+1];

	//Inicializamos los casos base
	for(int i=0;i<=nPers;i++){		//rellenamos la primera fila
		tabla[i][0]= 0;		
	}
	
	for(int j=0;j<=pesoTotal/2;j++){	//rellenamos la primera columna
		tabla[0][j]= 0;
	}
	for(int i=1;i<=nPers;i++){		//Calculamos el resto de celdas
		for(int j=1;j<=pesoTotal/2;j++){
			if(j-pesos[i-1] < 0)	//Evitamos un posible acceso fuera de la tabla
				tabla[i][j]= tabla[i-1][j];
			else
				tabla[i][j]= max(tabla[i-1][j], pesos[i-1]+tabla[i-1][j-pesos[i-1]]);
		}
	}
	
	imprime(tabla[nPers][pesoTotal/2], pesoTotal);
}

int lee()
/*función que lee la entrada*/
{
	int i;
	int pesoTotal= 0;

	cin >> nPers;				//obtenemos el número de personas que participan
	for(i=0;i<nPers;i++){
		cin >> pesos[i];		//vamos guardando los pesos de los concursantes en un array de pesos
	}
	pesos[i]= 0;				//guardamos un 0 al final del array para saber que ya no hay más pesos

	i=0;
	while(pesos[i]!= 0){
		pesoTotal+= pesos[i];		//Calculamos la suma de todos los pesos de los participantes
		i++;
	}

	return pesoTotal;			//Devolvemos la suma de todos los pesos
}
int main(void)
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		memset(pesos, 0, sizeof(pesos));
		calcula(lee());
	}
	return 0;
}
