#include <iostream>
#include "listas.hpp"

using namespace std; 

template <typename dato> void dup(Nodo<dato>*&pila){
    dato primero; 
    if (pila!=NULL){
        primero= pop(pila); 
        push(pila, primero); 
        push(pila, primero); 
    }
}

int main(){

    Nodo<int>* pilaint = NULL;
    cout<<endl<<"========INT========"<<endl; 
    cout<<endl<<"Pila vacia"<<endl; 
    mostrar(pilaint); 
    cout<<"Fin de la pila"<<endl; 
    
    push(pilaint, 1); 
    push(pilaint, 2); 
    cout<<endl<<"Pila con datos: "<<endl; 
    mostrar(pilaint); 
    cout<<"Fin de pila"<<endl;

    dup(pilaint); 
    cout<<endl<<"Pila despues de duplicar: "<<endl;
    mostrar(pilaint);
    cout<<"Fin de pila"<<endl; 

    Nodo<char>* pilachar = NULL; 

     cout<<endl<<"=============CHAR================"<<endl;

    push(pilachar, 'a'); 
    push(pilachar, 'b');
    cout<<endl<<"Pila con datos tipo char: "<<endl;
    mostrar(pilachar);
    cout<<"Fin de pila"<<endl;

    dup(pilachar); 
    cout<<endl<<"Pila luego del dup: "<<endl; 
    mostrar(pilachar);
    cout<<"Fin de pila"<<endl; 

return 0;     
}