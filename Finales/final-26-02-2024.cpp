/*Desarrolle una funcion que retorne una lista ordenada a partir 
de la interseccion de una pila y una lista.*/

struct Nodo{
	int info; 
	Nodo* sig; 
}; 

int pop(Nodo* &pila); 
void insertarOrdenado(Nodo* &list, int valor); 

Nodo* interseccionPL(Nodo* pila, Nodo* list){
	Nodo* listInter = NULL; 
	Nodo* aux = list;  
	Nodo* found; 
	int valor; 
	
	while(aux != NULL) {
		valor = pop(pila); 
		
		found = buscar(aux, valor); 
		
		if(found != NULL){
			insertarOrdenado(listInter, valor); 
		} 
		aux = aux->sig; 
	}
	
	return listInter; 
}


/*Se tiene un vector de saldos de las cuentas Bancarias de una empresa, que contiene los siguientes
campos: Numero de cuenta - cantidad de transacciones - saldo.
Ademas, se cuenta con una lista que contiene las ultimas transacciones (1 nodo 1 transaccion), cada
nodo de la lista contiene: Numero de cuenta - Monto.
Se pide actualizar el vector de Saldos con la informacion que hay en la lista, considerando que debe
actualizar el saldo y actualizar la cantidad de transacciones por cuenta.
Maximo hay 150 cuentas.*/

void proc(int v[], int len){
    *v = 10;
}

int main() {
    int *p = NULL; 
    int x = 30; 
    p = new int[3]; 
    p[1] = x; 
    proc(p,3);
    p[2] = *(p+1)+x; 
    for(int i = 0; i < 3; i++){
        cout << *(p+i)<< " "<<endl; 
    }
    delete []p;
    return 0; 
}

Resultado = 10 30 60

int main() {
    int *p; 
    int x = 10; 
    p = new int[10]; 
    p[0] = 20; 
    p[1] = 21; 
    p[2] = *p; 
    p[3] = *(p+1); 
    p[4] = *p + *(p+1); 

    cout << *(p+4) << endl; 

    return 0; 
}

Resultado = 41

//Indique V o F y justifique.

/*
La manera correcta de enviar como parametro por referencia un vector es "int* vec[]"
RTA= Falso, los vectores siempren se pasan por referencia, no es necesario agregar
ninguna sintaxis adicional. int vec[]. 
*/

/*
Falsa: La estrategia de apareo se puede aplicar a distintas estructuras, ya sea vectores, 
listas, archivos, etc...
*/
