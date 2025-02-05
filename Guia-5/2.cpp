#include <iostream>
#include "Listas.hpp"

using namespace std; 

template <typename dato> bool swap(Nodo<dato>* &pila){

     if (pila == NULL || pila->sig == NULL || pila->sig ==NULL) {
        cout <<endl<< "Error: La pila debe tener al menos dos elementos para realizar el swap." << endl;
        return false;
    }
		dato primero = pop(pila);
        dato segundo = pop(pila); 
        push(pila, primero); 
        push(pila, segundo); 
        return true;
}

int main()
{
    Nodo<int>*pilaint = NULL; 

    cout<<endl<<"===========INT==========="<<endl; 
    cout<<endl<<"Pila vacia"<<endl; 
    mostrar(pilaint); 
    cout<<"Fin de la pila"<<endl;

    push(pilaint, 1);
    push(pilaint, 2);
    push(pilaint, 3);
    cout<<endl<<"Pila con datos: "<<endl; 
    mostrar(pilaint); 
    cout<<"Fin de pila"<<endl; 
  
    if(swap(pilaint)){
        cout<<endl<<"Pila luego del swap: "<<endl;  
        mostrar(pilaint);
        cout<<"Fin de pila"<<endl;
    } 

    Nodo<char>*pilachar = NULL; 

    cout<<endl<<"===========CHAR==========="<<endl; 
    cout<<endl<<"Pila vacia"<<endl; 
    mostrar(pilachar); 
    cout<<"Fin de la pila"<<endl;

    push(pilachar, 'c');
    cout<<endl<<"Pila con datos: "<<endl; 
    mostrar(pilachar); 
    cout<<"Fin de pila"<<endl; 
  
    if(swap(pilachar)){
        cout<<endl<<"Pila luego del swap: "<<endl;  
        mostrar(pilachar);
        cout<<"Fin de pila"<<endl;
    } 

    return 0; 
}