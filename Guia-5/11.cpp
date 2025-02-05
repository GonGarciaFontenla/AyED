#include <iostream>
#include "listas.hpp"

using namespace std; 

template <typename dato> void dup(Nodo<dato>*& pila)
{
    if(pila != nullptr)
    {
        push(pila, pila->info);
    } 
}
template <typename dato> void swap(Nodo<dato>*& pila)
{ 
    if (pila != nullptr && pila->sig != nullptr)
    {
        Nodo<dato>* inicial = pila; 
        pila = inicial->sig;
        inicial->sig = pila->sig; 
        pila->sig = inicial;  
    }
}
template <typename dato> void rot(Nodo<dato>* &pila)
{
    Nodo<dato>* aux = pila;
    int i; 

    for (int i = 0; aux != nullptr && i < 3; i++)
        aux = aux->sig; 
    if (i<3)   
        return;
    //Imaginemos con el ejemplo de los numeros 1, 2, 3, 4 y tiene que quedar 3, 1, 2, 4 luego del rot.
    aux = pila->sig->sig; //Puntero auxiliar igual a la tercera posicion inicial (3)
    pila->sig->sig = pila->sig; //Paso el valor del segundo nodo (2) al tercero.  
    pila->sig = pila; // Paso el valor del primer nodo (1) al segundo. 
    pila = aux; // Paso el valor de la tercera posicion inicial (3) al primer lugar.
}

int main(){ 
    Nodo<int>* pilaint = nullptr; 

    cout<<"Pila vacia: "<<endl; 
    mostrar (pilaint); 
    cout<<"Fin de la pila"<<endl; 

    push(pilaint, 1);

    cout<<endl<<"Pila con datos: "<<endl; 
    mostrar(pilaint); 
    cout<<"Fin de la pila"<<endl;
    
    cout<<endl<<"Pila luego del dup: "<<endl;
    dup(pilaint);  
    mostrar(pilaint);
    cout<<"Fin de pila: "<<endl;

    push(pilaint, 2);

    cout<<endl<<"Pila luego del swap: "<<endl; 
    swap(pilaint);
    mostrar(pilaint);
    cout<<"Fin de pila: "<<endl;

    push(pilaint, 3);
    
    cout<<endl<<"Pila luego del rot: "<<endl; 
    rot(pilaint);
    mostrar(pilaint);
    cout<<"Fin de pila: "<<endl;

    while (pilaint != nullptr)
    {
        pop(pilaint);
    }

    return 0; 
}