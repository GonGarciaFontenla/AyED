#include <iostream>

using namespace std; 

//Crear una función que devuelva una lista conteniendo la unión de una pila, una cola y un vector. 

struct Nodo {
    int info; 
    Nodo* sig; 
}; 

Nodo* unionEnLista(Nodo* pila, Nodo* cFrente, Nodo* cFin, Nodo* vec[], Nodo* &list); 
void addList(Nodo *&list, int valor); 
void addList(Nodo *&list, int valor); 
int buscar(Nodo* list, int valor); 
int pop(Nodo* &pila); 
int suprimir(Nodo* &colaFrente, Nodo* &colaFin); 

Nodo* unionEnLista(Nodo* pila, Nodo* cFrente, Nodo* cFin, Nodo* vec[], int len) {
    Nodo* list = NULL; 
    Nodo* aux = pila; 
    int valor; 

    while(aux != NULL) { 
        valor = pop(aux); 
        addList(list, valor); 
    }

    for(int i = 0; i < len; i++) {
        int found = buscar(list, vec[i]->info); 
        if(found == -1){
            addList(list, vec[i]->info); 
        }
    }

    while(cFrente != NULL) {
        valor = suprimir(cFrente, cFin); 

        int found = buscar(list, valor); 
        if(found == -1){
            addList(list, valor); 
        }
    }

    return list; 
}

void addList(Nodo *&list, int valor) {
    Nodo* newNodo = new Nodo(); 
    newNodo->info = valor; 
    newNodo->sig = list;  
    list = newNodo; 
}

int buscar(Nodo* list, int valor){
    Nodo* aux = list;  

    while(aux != NULL){
        if(aux->info == valor){ 
            return 1; 
        }
        aux = aux -> sig; 
    }
    return -1;  
}

int pop(Nodo *&pila) {
    int retorno = pila->info;  
    Nodo *aux = pila; 
    pila = aux->sig; 
    delete(aux); 
    return retorno; 
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

/*Se tiene un vector de Matriculas (codigo de curso, cantidad de alumnos, monto pagado) y
una lista con las nuevas reservas (codigo de curso, monto pagado). Actualizar el vector 
con los contenidos de la lista, considerando que por cada reserva se aumenta en 1 la cantidad 
de alumnos. */

struct matriculas {
    int curso; 
    int alumnos; 
    int monto;
};

struct reserva {
    int codCurso; 
    int montoPag; 
}; 

struct Nodo2 {
    reserva info; 
    Nodo2* sig; 
}; 

void actualizarMatriculas(matriculas vec[], int len, Nodo2* list){
    Nodo2* aux = list; 
    int found; 

    while(aux != NULL) {
        found = search(vec, len, aux->info.codCurso); 
        vec[found].alumnos++; 
        aux = aux->sig; 
    }
}

//Otra version!!! 

void actualizarMatriculas2(matriculas vec[], int len, Nodo2* list){
    Nodo2* aux = list; 

    while(aux != NULL) {
        for(int i = 0; i < len; i++){
            if(vec[i].curso == aux->info.codCurso){
                vec[i].alumnos++; 
                aux = aux->sig; 
            }
        }
        aux = aux->sig;     
    }
}


int search(matriculas vec[], int len, int value) {
    int i = 0; 
    while(i < len && value != vec[i].curso) {
        i++; 
    }
    if(value == vec[i].curso) 
        return i; 
    else 
        return -1;
}

//El punto este no lo tengo, es el de siempre de los dos bloques de codigo!

//Verdadero o faslo

/*
El vector es la mejor estructura para ordenar un archivo. 
Faslo: El vector es una estructura estatica, por ende se deberia saber la dimension del archivo
para poder ordenar a este. 
*/

/*
El corte de control se encarga de unir dos archivos con todos sus registros
Falso: El apareo es el encargado de unir dos archivos (no exclusivamente) con todos sus registros. 
*/
