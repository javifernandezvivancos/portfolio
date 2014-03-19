///////////////////////////////////////////////////////////
// ACTIVIDAD DE EVALUACION CONTINUA                      //
// Parte 2. Tema 5. Backtracking. Version 2009     	 //
// Algoritmos y Estructuras de Datos, 2o, ITIS  	 //
// Javier Fernández Vivancos, 15482513-V                 //
///////////////////////////////////////////////////////////

#include <string.h>   // Funcion memset
#include <iostream>   // E/S con cin y cout
using namespace std;

///////////   VARIABLES GLOBALES   ////////////////
#define MAXPRENDAS 20
#define MAXMODELOS 20

int tienda[MAXPRENDAS+1][MAXMODELOS+1];
int M;				//Dinero disponible
int C;				//Cantidad de prendas


int longFila(int i)
{
/*función para calcular el número de modelos de la prenda i*/
	int l=0;

	while(tienda[i][l]!=0){
		l++;
	}
	return l;
}

void lee()
/*función que lee la entrada*/
{
	int i, j;			//iteradores
	int n;

	cin >> M;			//guardamos el dinero disponible
	cin >> C;			//guardamos el número de prendas
	for(i=0;i<C;i++){
		cin >> n;
		for(j=0;j<n;j++){
			cin >> tienda[i][j];
		}
		tienda[i][j]=0;		//ponemos un 0 al final de la fila para saber que no quedan más modelos de esta prenda
	}
	tienda[i][0]=0;			//ponemos un 0 en la última fila para saber que no quedan más prendas
}

void ordenarFila(int x)
/*función para ordenar la fila x de mayor a menor precio (método similar al de la burbuja)*/
{
	int aux;

	for(int i=1;i<longFila(x);i++){
		for(int j=i;j>0;j--){
			if(tienda[x][j]>tienda[x][j-1]){
				aux= tienda[x][j];
				tienda[x][j]= tienda[x][j-1];
				tienda[x][j-1]= aux;
			}
			else{
				j=0;
			}
		}
	}
}
void ordenar()
{
/*función que ordena todos las prendas de mayor a menor precio*/
	for(int i=0;i<C;i++){
		ordenarFila(i);
	}
}

int voraz(int nivel, int peso)
{
/*algoritmo voraz que obtiene la solución óptima al problema (suponiendo que cogemos las prendas más caras aunque se salgan del presupuesto*/
	int solucion=0;
	for(int i=nivel;i<C;i++){
		solucion+= tienda[i][0];	//Vamos cogiendo las prendas más caras
	}
	if(peso<solucion)
		return peso;			//si sobrepasamos el presupuesto devolvemos como benficio el propio presupuesto de entrada
	else
		return solucion;		//en otro caso devolvemos la solución óptima.
}
bool solucion(int nivel, int gasto_act)
{
/*trataremos como soluciones los nodos con gasto menor que el presupuesto y con nivel igual al número de prendas*/
	return (gasto_act <= M && nivel == C);
}
bool criterio(int nivel, int gasto_act, int *VOA)
{
/*seguiremos profundizando sólo si el gasto actual es menor que el dinero disponible, si el nivel del árbol es menor que el número de prendas y si
el gasto actual más lo máximo que podríamos gastar siguiendo por este camino(algoritmo voraz) es mayor que el valor óptimo actual*/
	return (gasto_act < M && nivel < C && gasto_act+voraz(nivel,M-gasto_act) > *VOA);
}
bool mashermanos(int nivel, int s[MAXPRENDAS+1])
{
/*devolvemos true si hay más modelos de esa prenda y false si no quedan más*/
	return s[nivel-1] != longFila(nivel-1)-1;
}
void generar(int nivel, int s[MAXPRENDAS+1], int *gasto_act)
{
/*función para generar un nuevo nodo*/
	if(s[nivel-1]!=-1){				
		*gasto_act= *gasto_act-tienda[nivel-1][s[nivel-1]];	//decrementamos del gasto del nodo que vamos a quitar.
	}
	s[nivel-1] = s[nivel-1]+1;					//creamos un nuevo nodo (hijo o hermano).
	*gasto_act= *gasto_act+tienda[nivel-1][s[nivel-1]];		//incrementamos el gasto de la nueva prenda seleccinoada.
}
void retroceder(int nivel, int s[MAXPRENDAS+1], int *gasto_act)
{
/*restamos al gasto actual el precio de la prenda que vamos a eliminar y ponemos un -1 en su posición para eliminarla*/
	*gasto_act= *gasto_act-tienda[nivel-1][s[nivel-1]];
	s[nivel-1]=-1;
}
void tratar(int gasto_act, int *VOA, int s[MAXPRENDAS+1])
{
/*si el gasto de la posible solución es superior al actual lo guardamos, si no no*/
	if(gasto_act>*VOA){
		*VOA= gasto_act;
	}
}
int calcula(void)
{
/*backtracking aplicado al problema*/
	int gasto_act=0;
	int s[MAXPRENDAS+1];
	memset(s, -1, sizeof(s));
	int VOA=0;
	int nivel= 1;
	do{
		generar(nivel,s,&gasto_act);				//generamos un nuevo nodo.
		if(solucion(nivel, gasto_act))				//si tenemos una posible solución la tratamos.
			tratar(gasto_act, &VOA, s);
		if(criterio(nivel, gasto_act, &VOA))			//si es un nodo prometedor profundizamos
			nivel= nivel+1;					//y aumentamos en uno el nivel del árbol.
		else
			while(nivel!=0 && (!mashermanos(nivel, s))){	//mientras el nivel sea distinto de 0 y no queden más hermanos
				retroceder(nivel, s, &gasto_act);	//retrocedemos y
				nivel= nivel-1;				//volvemos al nivel anterior.
			}
	}
	while(nivel!=0);						//seguimos calculando hasta que el nivel sea distinto de 0
	
	return VOA;
}
int main(void)
{
	int N;
	int solucion;
	cin >> N;
	for(int i=0;i<N;i++){
		lee();						//Leemos la entrada,
		ordenar();					//la ordenamos de mayor a menor precio y
		solucion= calcula();				//calculamos la solución mediante backtracking.
		if (solucion==0) cout << "no solution";		//Si no se modifica la varible solucion es porque no la hay
		else cout << solucion;				//en otro caso la imprimimos.
		cout << endl;
	}	
	return 0;
}
