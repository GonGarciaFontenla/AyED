#include <iostream>
#include "listas.hpp"
using namespace std; 

//Con este codigo hay problemas para la compilacion de las dos funciones en simulteneo
//Se debe comentar una de las funciones para que ande correctamente
template <typename dato> void restaurarLista(Nodo<dato>* lista, Nodo<dato>* pila) {
    while (pila != NULL) {
        agregar(lista, pop(pila));
    }
}
template <typename dato> dato mayor(Nodo<dato>* &lista){

    Nodo<int>* pila= NULL;

    while (lista!=NULL)
    {
        agregar(pila, pop(lista)); 
    }

    if (pila != NULL)
    {
        dato mayor = pop(pila); 

         while (pila != NULL)
         {
            dato valor= pop(pila); 
                if (valor>mayor)
                {
                    mayor=valor;
                }
        } 
    return mayor;
    }else
    {
        cout<<"No hay elementos en la pila"<<endl; 
        return -1; 
    }
} 

Nodo<int>*nodomayor(Nodo<int>* &lista)
{
    Nodo<int>* mayor = lista;

    while (lista != NULL)
    {
        if (lista->info > mayor->info){
            mayor=lista; 
        }
            lista = lista->sig;     
    }
    return mayor;
}

     
int main(){
    Nodo<int>* lista1 = NULL;

    agregar(lista1, 1);
	agregar(lista1, 2);
	agregar(lista1, 3);
    agregar(lista1, 43);
	agregar(lista1, 203);
	agregar(lista1, 353);

   cout<<"El mayor valor de la lista es: "<<endl; 
   cout << mayor(lista1)<<endl;

    Nodo<int>* maxptr = nodomayor(lista1); 

    cout<<"El mayor valor de la lista es: " <<(maxptr != nullptr ? maxptr->info: 0)<<endl;  


    return 0;
}