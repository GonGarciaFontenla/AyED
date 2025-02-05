#include <iostream>
#include <fstream>
using namespace std; 

void mostrar(int vec[], int dim)
{
	for (int i = 1; i < dim+1; i++)
		cout << i << ": " << vec[i] << endl;
}

void valorminimoMin(const int numeros[], int size, int&minimo, int& posicionMinimo){
    minimo=numeros[0];
    posicionMinimo=0; 

    for (int i = 1; i < size; i++){

        if (numeros[i]<minimo)
        {
            minimo=numeros[i];
            posicionMinimo=i;
        }
    }
}

void valorminimoMax(const int numeros[], int size, int&minimo, int& posicionMinimoMax){
    minimo=numeros[0];
    posicionMinimoMax=0; 

    for (int i = 1; i < size; i++){

        if (numeros[i]<=minimo)
        {
            minimo=numeros[i];
            posicionMinimoMax=i;
        }
    }
}

int contar_repeticiones(const int numeros[], int size, int minimo){
    int contador=0; 
    for (int i = 0; i < size; i++)
    {
        if (numeros[i]== minimo)
        {
            contador++;
        }
    }
    return contador; 
}

int main(){
    const int tamañovec= 10; 
    int numeros[tamañovec];
    ifstream archivo("datosG04E06-dos.txt");
        if (!archivo){
            cout<<"No existe el archivo"; 
            return 1; 
        }
    
    for (int i = 0; i < tamañovec; i++)
    {
        archivo >> numeros[i];
    }
    archivo.close(); 

    int size=tamañovec, minimo, posicionMinimo; 
    valorminimoMin(numeros, size, minimo, posicionMinimo); 
    cout<<"El valor mínimo es: "<<minimo<<" en la posicion "<< posicionMinimo<<endl;

    int posicionMinimoMax; 
    valorminimoMax(numeros, size, minimo, posicionMinimoMax); 
    cout<<"El ultimo valor mínimo es: "<<minimo<<" en la posicion "<< posicionMinimoMax<<endl;   

    int repeticion_minimo= contar_repeticiones(numeros, size, minimo); 
    cout <<"El valor minimo se repite: "<< repeticion_minimo<< "veces"<<endl; 

    return 0;
}