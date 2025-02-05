#include <iostream>
#include "listas.hpp"

using namespace std;

template <typename T> Nodo<T>* concatd(Nodo<T>*& luno, Nodo<T>*& ldos)
{
	Nodo<T>* lista = nullptr;
	while (luno != nullptr && ldos != nullptr)
    {
        agregar(lista, pop(luno));
		agregar(lista, pop(ldos));
    }
    while (luno != NULL){
        agregar(lista,pop(luno));
    }
    while (ldos!=NULL)
    {
        agregar(lista, pop(ldos)); 
    }

	return lista;
}

int main()
{
	Nodo<int> *lista1 = nullptr;
	Nodo<int> *lista2 = nullptr;

	// pongo datos
	agregar(lista1, 1);
	agregar(lista1, 2);
	agregar(lista1, 3);

	agregar(lista2, 5);
	agregar(lista2, 6);
	agregar(lista2, 7);
	agregar(lista2, 8);
	agregar(lista2, 9);

    Nodo<int> *listar = concatd(lista1, lista2);

	cout << endl << "Muestro Lista intercalada:" << endl;
	mostrar(listar);
	cout << "---Fin" << endl;

	//libero memoria antes de finalizar
	while (listar != nullptr)
		pop(listar);

	return 0;
}