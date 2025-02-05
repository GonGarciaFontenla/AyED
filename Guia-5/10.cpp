#include <iostream>
#include "listas.hpp"

using namespace std; 

#include <iostream>
#include "listas.hpp"

using namespace std; 

template <typename dato> void liberarMemoria(Nodo<dato>* lista) //Funcion para liberar la memoria luego. 
{
    while (lista != NULL) {
        Nodo<dato>* temp = lista;
        lista = lista->sig;
        delete temp;
    }
}
template <typename dato> Nodo<dato>* concatenar(Nodo<dato>* lista1, Nodo<dato>* lista2) //NO LAS PASO POR REFERENCIA. 
{
	Nodo<dato>* lista = nullptr;

    while (lista1 != nullptr){
        agregar(lista, lista1->info); 
        lista1 = lista1->sig; 
    }
    while (lista2 != nullptr){
        agregar(lista, lista2->info); 
        lista2 = lista2->sig; 
    }
	return lista;
}
int main(){
    Nodo<int>* lista1 = NULL;
    Nodo<int>* lista2 = NULL;

    agregar(lista1, 1);
	agregar(lista1, 2);
	agregar(lista1, 3);

	agregar(lista2, 5);
	agregar(lista2, 6);
	agregar(lista2, 7);
	agregar(lista2, 8);
	agregar(lista2, 9);

    cout<<endl<<"Lista 1: "<<endl; 
    mostrar(lista1); 
    cout<<"fin de lista 1."<<endl; 

    cout<<endl<<"Lista 2: "<<endl; 
    mostrar(lista2); 
    cout<<"Fin de la lista 2."<<endl; 

    Nodo<int>*listaconcatenada = concatenar(lista1,lista2); 
    cout<<endl<<"Lista concatenada: "<<endl;
    mostrar(listaconcatenada); 
    cout<<"Fin de la lista concatenada."<<endl;

    cout<<endl<<"Lista 1 luego de concatenacion: "<<endl; 
    mostrar(lista1); 
    cout<<"fin de lista 1."<<endl;

    cout<<endl<<"Lista 2 luego de concatenacion: "<<endl; 
    mostrar(lista2); 
    cout<<"fin de lista 2."<<endl;

    liberarMemoria(lista1);
    liberarMemoria(lista2);
    liberarMemoria(listaconcatenada);
    
    return 0; 
}