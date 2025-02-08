#include <iostream> 

using namespace std; 

/*Desarrolle una funcion que retorne una lista ordenada a partir de la union de una cola y un vector.*/

void ordenarLista(int vec[], int len, Nodo* colaFrente, Nodo* colaFin, Nodo* &list); 
void insertarOrdenado(Nodo* &lista, int valor); 
int suprimir(Nodo* &colaFrente, Nodo* &colaFin); 

struct Nodo {
    int info; 
    Nodo* sig; 
}; 

int main() {
    return 0; 
}

void ordenarLista(int vec[], int len, Nodo* colaFrente, Nodo* colaFin, Nodo* &list) {
    int retorno; 
        while(colaFrente != NULL) {
            retorno = suprimir(colaFrente, colaFin); 
            insertarOrdenado(list, retorno); 
        }

        for(int i = 0; i < len; i++) { 
            insertarOrdenado(list, vec[i]);
        }
}

void insertarOrdenado(Nodo *&lista, int valor) {
    Nodo* newNodo = new Nodo(); 
    Nodo* aux = lista; 
    Nodo* ant = NULL; 

    newNodo->info = valor; 
    newNodo->sig = NULL; 

    while(aux != NULL && valor > aux->info) {
        ant = aux; 
        aux = aux->sig; 
    } 
    if(ant == NULL) {
        lista = newNodo; 
    }else{ 
        ant->sig = newNodo;
    }
    newNodo->sig = aux; 
}

int suprimir(Nodo *&colaFrente, Nodo *&colaFin) {
    int retorno = colaFrente->info; 

    Nodo* aux = colaFrente; 
    colaFrente = aux->sig;
    if(colaFrente == NULL) {
        colaFin = NULL; 
    } 
    delete(aux); 
    return retorno; 
}

/*Se tiene un vector de los productos de un almacen, STOCK, que contiene todos los productos
que se tienen disponibles a la venta, con los siguientes campos: id del producto, tipo (
p "perecedero" y n "no perecedero") y unidades en el almacen. Ademas, se cuenta con una lista
ordenada que contiene los ultimos pedidos al almacen que deben ser entregados a los clientes
finales. La lista contiene el id del producto, el id del cliente y las unidades requeridas.
Se pide actualizar el vector stock con la informacion que hay en la lista, solo para el campo
de unidades. 
Se sabe que como maximo son 50 productos*/

struct producto {
    int id; 
    char tipo; 
    int unidades; 
};

struct venta {
    int idProd; 
    int idCliente; 
    int unidadReq; 
}; 

struct Nodo2 {
    venta info; 
    Nodo2* sig; 
}; 

int main() {
    int len = 50; 
    producto stock[len]; 

    Nodo2* list; 

    actualizarStock(stock, len, list); 

    return 0; 
}

void actualizarStock(producto stock[], int len, Nodo2* list) {
    Nodo2* aux = list; 

    for(int i = 0; i < len; i++) {
        while(aux->info.idProd == stock[i].id) {
            stock[i].unidades -= aux->info.unidadReq;
            aux = aux -> sig; 
        }
    }
}

/*Dado los siguientes fragmentos de codigo determine que despliega. Indique la salida por pantalla
del programa, o en caso que no compile, justificar.*/

int main() {
    int arr[] = {10,20,30,40}; 
    int *ptr = arr; 
    cout << *(ptr + 2) << endl; 
    ptr++; 
    cout << *ptr << endl; 
    return 0; 
}

//Salida = 30 - 20

int recursivo(int n) {
    if(n==0) return 1; 
    return n + recursivo(n-1); 
}

int main() {
    int resultado = recursivo(5); 
    cout << resultado << endl; 
    return 0; 
}

//salida = 16

//Verdadero o falso
/*
Los algoritmos de busqueda binaria funcionan solo con listas ordenadas. 
Verdadero: La condicion previa para la busqueda binaria es que la estructura se encuentre ordenada. 
*/

/*
Es posible sobreescribir solo parte del contenido de un archivo binario sin modificar el resto del archivo. 

NO TENGO NI IDEA!!!
*/