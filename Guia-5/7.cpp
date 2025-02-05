#include <iostream>
#include "listas.hpp"

using namespace std;

template <typename dato> float promedio(Nodo<dato>*& lista){

    Nodo<int>* pila= NULL; 
    float suma=0; 
    int tamaño = 0;

    Nodo<dato>*temp =lista; 
    while(temp != NULL){
        tamaño++; 
        temp=temp->sig; 
    }

    while (lista!=NULL){
        agregar(pila, pop(lista)); 
    }

    while (pila != NULL){
        suma += pop(pila); 
    }
    if (tamaño != 0)
    {
        return suma/tamaño; 
    }
    else{
        cout<<"La lista no contiene elementos."<<endl; 
        return 0; 
    }
}

int main(){
    Nodo<int>* lista1 = NULL;

    agregar(lista1, 1);
	agregar(lista1, 2);
	agregar(lista1, 3);
    agregar(lista1, 43);
	agregar(lista1, 203);
	agregar(lista1, 353);

    cout<<"Lista: "<<endl; 
    mostrar(lista1);
    cout<<"Fin de la lista."<<endl; 

    cout<<endl<<"El promedio de la lista es: "<<endl; 
    cout << promedio(lista1) << endl;

    while (lista1 != NULL){
        pop(lista1); 
    }
    return 0; 
}