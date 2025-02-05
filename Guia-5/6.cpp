#include <iostream>
#include "listas.hpp"

using namespace std;

//Hago variante a porque no se que es una frase palindromas y fiaca buscarlo.
bool Capicua(string palabra){
    Nodo<char>*pila = NULL; 
    int length = palabra.size(); //Obtengo el largo de la palabra.
    int i; 

    for (int i = 0; i < length; i++)
    {
        push(pila, palabra[i]); //mientras que i sea menor al largo, pusheo las letras a una pila.
    }
    for(i=0 ; i < length && palabra[i]== pop(pila); i++); // Comparo si la palabra ingresada es igual a la que se guardo en la pila. 

    while (pila != NULL)
    {
        pop(pila); 
    }
    return i == length; 
}
int main(){
    string palabra; 
    cout <<"Ingrese palabra: "<<endl; 
    cin >>palabra;
    
    if (Capicua(palabra))
    {
        cout <<"Es capicua."<< endl;
    }else{
        cout <<"No es capicua."<< endl;
    }
    return 0;
}
   