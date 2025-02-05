#include <iostream>
using namespace std; 

void valormaximo(const int numeros[], int size, int&maximo, int& posicionMaximo){
    maximo=numeros[0];
    posicionMaximo=0; 

    for (int i = 1; i < size; i++){

        if (numeros[i]>maximo)
        {
            maximo=numeros[i];
            posicionMaximo=i+1;
        }
    }
}
int main(){
    int n=10; 
    int vec[n];
    cout << "Ingrese los elementos del vector uno por uno:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vec[i]; 
    }    
    int maximo, posicionMaximo; 
    valormaximo(vec, n, maximo, posicionMaximo); 
    cout <<"El valor maximo es "<<maximo<<endl;
    cout <<"Este se encuentra en la posicion "<<posicionMaximo<<endl;
    return 0; 
} 