#include <iostream> 

using namespace std;

/*Desarrolle una funcion que retorne una lista ordenada a partir 
de la interseccion de una pila y una lista.*/

struct Nodo {
    int info; 
    Nodo* sig; 
}; 

void listaOrdenada(Nodo* list, Nodo* pila, Nodo*& newList); 
void insertarOrdenado(Nodo* &list, int valor); 
int pop(Nodo* &pila); 
int buscar(Nodo* list, int valor); 
void push(Nodo* &pila, int valor); 
void addList(Nodo *&list, int valor); 
void showList(Nodo* list); 
void freeList(Nodo *&list); 

int main() {
    Nodo* pila = NULL; 
    Nodo* lista = NULL;
    Nodo* listaInterseccion = NULL; 

    addList(lista, 1);
    addList(lista, 3);
    addList(lista, 5);
    addList(lista, 7);
    addList(lista, 9);

    // Cargar la pila con algunos valores
    push(pila, 3);
    push(pila, 5);
    push(pila, 8);
    push(pila, 9);
    push(pila, 10);

    listaOrdenada(lista, pila, listaInterseccion); 

    showList(listaInterseccion); 

    freeList(lista); 
    freeList(listaInterseccion); 
    return 0; 
}

void listaOrdenada(Nodo* list, Nodo* pila, Nodo* &newList){
    Nodo* auxP = pila; 
    Nodo* auxL = list; 

    while(auxP != NULL && auxL != NULL) {
        int valor = pop(auxP); 

        int found = buscar(auxL, valor); 

        if(found != -1){
            insertarOrdenado(newList, valor); 
        }
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

int pop(Nodo *&pila) {
    int retorno = pila->info;  
    Nodo *aux = pila; 
    pila = aux->sig; 
    delete(aux); 
    return retorno; 
}

void push(Nodo *&pila, int valor) {
    //Creo el nodo y pido memoria; 
    Nodo* newNodo = new Nodo(); 
    //Cargo el nodo; 
    newNodo->info = valor; 
    newNodo->sig = pila;
    //Conecto pila con el nuevo nodo; 
    pila =  newNodo; 
}


int buscar(Nodo* list, int valor){
    Nodo* aux = list;  

    while(aux != NULL){
        if(aux->info == valor){ 
            return aux->info; 
        }
        aux = aux -> sig; 
    }
    return -1;  
}

void addList(Nodo *&list, int valor) {
    Nodo* newNodo = new Nodo(); 
    newNodo->info = valor; 
    newNodo->sig = list;  
    list = newNodo; 
}

void showList(Nodo* list) {
    Nodo* aux = list;

    while(aux != NULL) {
        cout << aux->info << endl; 
        aux = aux->sig; 
    }
}

void freeList(Nodo *&list) {
    Nodo* aux; 

    while(list != NULL) {
        aux = list;
        list = list->sig;  
        delete(aux);
    }
}

/*Se tiene un vector de saldos de las cuentas Bancarias de una empresa, que contiene los siguientes
campos: Numero de cuenta - cantidad de transacciones - saldo.
Ademas, se cuenta con una lista que contiene las ultimas transacciones (1 nodo 1 transaccion), cada
nodo de la lista contiene: Numero de cuenta - Monto.
Se pide actualizar el vector de Saldos con la informacion que hay en la lista, considerando que debe
actualizar el saldo y actualizar la cantidad de transacciones por cuenta.
Maximo hay 150 cuentas.*/

struct cuentas {
    int numCuenta; 
    int transacciones; 
    int saldo; 
}; 

struct transaccion {
    int cuenta; 
    int monto; 
}; 

struct Nodo2 {
    transaccion info; 
    Nodo2* sig; 
}; 

void actualizarSaldos(cuentas vec[], int len, Nodo2* list);
int search(cuentas vec[], int len, int valor);  

int main() {
    int len = 150; 
    cuentas vec[len];

    Nodo2* list = NULL; 

    actualizarSaldos(vec, len, list);
    return 0; 
}

void actualizarSaldos(cuentas vec[], int len, Nodo2* list){
    Nodo2* aux = list; 
    int position; 

    while(aux != NULL){
        position = search(vec, len, aux->info.cuenta); 

        if(position != -1) {
            vec[position].saldo += aux->info.monto; 
            vec[position].transacciones++; 
        }
        aux = aux->sig; 
    }
}

int search(cuentas vec[], int len, int value) {
    int i = 0; 
    while(i < len && value != vec[i].numCuenta) {
        i++; 
    }
    if(value == vec[i].numCuenta) 
        return i; 
    else 
        return -1;
}

//Dado los siguientes fragmentos de codigo determine que despliega.Indique la salida por
//pantalla del programa, o en caso de que no compile, justique: 
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

//Salida= 10 30 60

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

//Salida= 41; 


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
