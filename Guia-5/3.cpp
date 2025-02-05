#include <iostream>
#include "listas.hpp"

using namespace std; 

template <typename dato> bool rot(Nodo<dato>*&pila){

    dato primero, segundo, tercero; 
    
    if (pila == NULL || pila->sig == NULL || pila->sig->sig == NULL) {
        cout <<endl<< "Error: La pila debe tener al menos tres elementos para realizar el rot." << endl;
        return false;
    }
        primero = pop(pila); 
        segundo = pop(pila); 
        tercero = pop(pila); 
        push(pila, segundo); 
        push(pila, primero); 
        push(pila, tercero); 
        return true; 
}


int main(){
    Nodo<int>*pilaint = NULL; 

    cout<<endl<<"=============INT================"<<endl; 
    cout<<endl<<"Pila vacia"<<endl; 
    mostrar(pilaint); 
    cout<<"Fin de la pila"<<endl;

    push(pilaint, 4);
    push(pilaint, 3);
    push(pilaint, 2);
    push(pilaint, 1);
    cout<<endl<<"Pila con datos: "<<endl; 
    mostrar(pilaint); 
    cout<<"Fin de pila"<<endl;

    if (rot(pilaint)){
        cout<<endl<<"Pila despues de rotar: "<<endl;
        mostrar(pilaint);
        cout<<"Fin de pila"<<endl; 
    }
    return 0; 
}