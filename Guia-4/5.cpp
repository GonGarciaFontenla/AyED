#include <iostream>
#include <cmath>

using namespace std; 

void Calculardiferencia(const int numeros[],int size, int& posicion1, int& posicion2){
    int max=numeros[1] - numeros[0];
    int posicionmax=0; 

    for (int i = 2; i < size; i++){
        int diferencia= numeros[i]-numeros[posicionmax]; 
        if (diferencia>max)
        {
            max=diferencia; 
            posicionmax=i;
        } 
    }
    posicion1 = posicionmax;
    posicion2 = posicionmax+1 ;
}
int main() {
    int seriesize=8; 
    int vec[seriesize];
    cout << "Ingrese los elementos del vector uno por uno:\n";
    for (int i = 0; i < seriesize; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vec[i]; 
    } 
    int posicion1, posicion2; 
    Calculardiferencia(vec, seriesize, posicion1, posicion2);  
    cout<<"La mayor diferencia entre dos elementos del vector es "<< vec[posicion1]-vec[posicion2]<<endl; 
    cout<<"Los elementos se encuentran en la posicion "<<posicion1<<" y "<<posicion2<<endl; 

}