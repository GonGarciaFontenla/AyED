#include <iostream>

using namespace std; 

const int N = 4; 

struct parCiudad{
    int i; 
    int j;
    int distancia;  
}; 

int diagonal(int matriz[][N]);
parCiudad masAlejadas(int matriz[][N]); 


int main(){
    int distancias[N][N] = {
        {0, 10, 20 , 30},
        {40, 0, 25, 16},
        {90, 56, 0,80},
        {104, 89, 21, 0}
    }; 

    int sumaDiagonal; 
    parCiudad alejadas; 

    sumaDiagonal = diagonal(distancias); 
    alejadas = masAlejadas(distancias); 

    return 0; 
}

int diagonal(int matriz[][N]){
    int suma = 0; 

    for(int i = 0; i < N; i++){
        suma += matriz[i][i];
    }

    return suma; 
}

parCiudad masAlejadas(int matriz[][N]){
    parCiudad lejos = {0,0,0};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(matriz[i][j] > lejos.distancia){
                lejos.i = i; 
                lejos.j = j; 
                lejos.distancia = matriz[i][j];
            }
        }
    }

    return lejos;  
}