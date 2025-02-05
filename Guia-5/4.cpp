#include <iostream>
#include "listas.hpp"

//Hago solo la variante b, considero que es mas dificil que la a. 
template <typename dato> void liberarMemoria(Nodo<dato>* lista) //Funcion para liberar la memoria luego. 
{
    while (lista != NULL) {
        Nodo<dato>* temp = lista;
        lista = lista->sig;
        delete temp;
    }
}
template <typename dato> Nodo<dato>* concatenar(Nodo<dato>*& lista1, Nodo<dato>*& lista2)
{
	Nodo<dato>* lista = NULL;
	Nodo<dato>* listaaux = NULL; 
	dato info;

	//copio lista1 en lista
	while (lista1 != nullptr) {
		info = pop(lista1);
		agregar(lista, info);
		push(listaaux, info);
	}
	//restauro lista1
	while (listaaux != nullptr) {
		push(lista1, pop(listaaux)); //Hago al reves que antes. Paso de la lista auxiliar a la lista1.
	}
	//copio lista2 en lista. 
	while (lista2 != nullptr) {
		info = pop(lista2);
		agregar(lista, info);
		push(listaaux, info);
	}
	//restauro lista2
	while (listaaux != nullptr) {
		push(lista2, pop(listaaux)); //Hago al reves que antes. Paso de la lista auxiliar a la lista2.
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
    cout<<"Fin de la lista concatenada.";

    liberarMemoria(lista1);
    liberarMemoria(lista2);
    liberarMemoria(listaconcatenada);
    
    return 0; 
}