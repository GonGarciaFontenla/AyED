//Lista ordenada de la union de 1 cola y 1 pila

struct Nodo {
	int info; 
	Nodo* sig; 
};  

int suprimir(Nodo* &cFrente, Nodo* &cFin); 
void insertarOrdenado(Nodo* &list, int valor); 
int pop(Nodo* &pila); 

Nodo* listaOrdenada(Nodo* cFrente, Nodo* cFin, Nodo* pila){
	Nodo* list = NULL; 
	int valor; 
	
	while(aux != NULL) {
		valor = suprimir(cFrente, cFin); 
		insertarOrdenado(list, valor);
	}
	
	while(pila != NULL){
		valor = pop(pila);
		insertarOrdenado(list, valor); 
	}
	
	return list; 
}

/*Se tiene un vector de Balance de las cuentas de inversion de un set de clientes, 
que contiene los siguientes campos: Num de cliente - Num de cuenta - Saldo - ultimo mov.
Ademas, se cuenta con una lista que contiene las ultimas transacciones de intereses 
generados (1 nodo 1 transaccion), cada nodo de la lista contiene: Num de cuenta - monto
de interes (positivo o negativo). 
Se pide actualizar el vector de balance con la informacion que hay en la lista, considerando
que debe actualizar el saldo y el valor del ultimo movimineto por cuenta. Maximo 200 cuentas.*/

struct balance {
	int numCli; 
	int numCuenta;
	int saldo; 
	int ultMov; 
}; 

struct transaccion {
	int numCuenta; 
	int monto;
}; 

struct Nodo {
	transaccion info; 
	Nodo* sig; 
}; 

int buscar(balance vec[], int len, int valor); 

void actualizarVector(balance vec[], Nodo* list) {
	Nodo* aux = list;
	int pos; 
	
	while(aux != NULL) {
		pos = buscar(vec, 200, aux->info.numCuenta); 
		if(pos != -1){
			vec[pos].saldo -= aux->info.monto; 
			vec[pos].ultMov = aux->info.monto; 
		}
		aux = aux->sig; 
	}
}



/*Dado los siguientes fragmentos de codigo determine que despliega. Indique la salida por pantalla
del programa, o en caso que no compile, justificar*/

int main() {
    int *p, *y; 
    int w; 
    p = new int(); 
    w = 85; 
    *p = w;
    y = p; 
    w++; 
    cout << *y << endl;  
}

Resultado =  85

int main() {
    int *p; 
    p = new int[5];

    p[0] = 67; 
    p[1] = 70;
    p[2] = 15;
    p[3] = 81;
    p[4] = 23;

    cout << *(p+2) << endl; 
}

Resultado = 15


//Verdadero o falso. 

/*La siguiente funcion esta definida correctamente y retorna una cadena de caracteres es: 
char Funcion(int vec[], int len). 

Falso: La funcion retorna un caracter, no una cadena.
*/

/*
La estrategia de resolucion de corta de control, solo puede aplicarse en archivos. 

Falso: Puede aplicarse en distintas estructuras, por ejemplo, en vectores. 
*/
