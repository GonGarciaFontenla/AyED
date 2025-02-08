#include <iostream>

using namespace std; 

/*Desarrolle una funcion que retorne una lista ordenada a partir de la union
de una cola y una pila.*/

struct Nodo {
    int info; 
    Nodo* sig; 
};

Nodo listaOrdenada(Nodo* pila, Nodo* colaFrente, Nodo* colaFin, Nodo* &list); 
void insertarOrdenado(Nodo* lista, int valor); 
int pop(Nodo* pila); 
int suprimir(Nodo* colaFrente, Nodo* colaFin); 

int main() {


    return 0; 
}

Nodo listaOrdenada(Nodo* pila, Nodo* colaFrente, Nodo* colaFin, Nodo* &list) {
    int valor; 
    while(colaFrente != NULL) {
        valor = suprimir(colaFrente, colaFin); 
        insertarOrdenado(list, valor); 
    }

    while(pila != NULL) {
        valor = pop(pila); 
        insertarOrdenado(list, valor); 
    }
}

/*Se tiene un vector de Notas de los alumnos de algoritmos y estructura de datos del 2023, que
contiene los siguientes campos: Legajo - Nota 1er parcial - Nota 2do parcial.
Ademas, se cuenta con una lista que contiene las ultimas notas de los recuperatorios del 2do
parcial, cada nodo de la lista contiene: Legajo - Nota recuperatorio 2do parcial.
Se pide actualizar el vector Notas con la informacion que hay en la lista, considerando que
si aprobo (6 o mas) debe pisar la nota que se encuentra en el vector. Si no aprobo, debe
mantener la original. Maximo hay 1500 alumnos.*/

struct alumno {
    int legajo;
    int nota1; 
    int nota2; 
}; 

struct recuperatorio {
    int legajo; 
    int nota; 
}; 

struct Nodo {
    recuperatorio info; 
    Nodo* sig; 
}; 

int buscar(alumno vec[], int len, int value); 

int main() {
    Nodo* lista; 
    int len = 1500; 
    alumno notas[len]; 

    actualizarNotas(notas, len,  lista); 

    return 0; 
}

void actualizarNotas(alumno notas[], int len, Nodo* list) {
    Nodo* aux = list; 
    int position; 

    while(aux != NULL) {
        if(aux->info.nota >= 6) {
            position = buscar(notas, len, aux->info.legajo);

            if(position > 0) { 
                notas[position].nota2 = aux->info.nota; 
            }
        }
        aux = aux->sig; 
    }
}

int buscar(alumno vec[], int len, int value) {
    int i = 0; 
    while(i < len && value != vec[i].legajo) {
        i++; 
    }
    if(value == vec[i].legajo) 
        return i; 
    else 
        return -1;
}

//Verdadero o falso

/*
En el apareo el conjunto resultante siempre contendra todos los elementos unicos
presentes en ambos conjuntos originales sin ninguna perdida de informacion. 

El apareo no garantiza que el conjunto resultante contenga solo elementos únicos. 
Si hay elementos repetidos en los conjuntos originales, seguirán apareciendo en el 
resultado. Además, el apareo no es una intersección, ya que incluye todos los elementos 
de ambos conjuntos, incluso si no están en ambos.
*/

/*
El corte de control en archivo solo puede aplicarse si el archivo esta ordenado
y no tiene claves repetidas. 

Falso: El archivo no debe estar ordenado y tampoco debe tener claves unicas. El 
requisito para el corte control es el archivo se encuentre agrupado por las claves. 
*/