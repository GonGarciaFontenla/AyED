#include <iostream>
using namespace std; 

void mostrar(double matriz[5][4], int filas, int columnas){
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<< matriz[i][j]<< " "; 
        }
    cout<< endl; 
    }
    
}

void insertar_array_matriz(const double* array,int filas, int columnas, double matriz[5][4]){
    int contador=0; 
    for (int i = 0; i < filas; i++) 
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j]=array[contador]; 
            contador++; 
        }
    }
}

void valorminimo(const double matriz[5][4], double& minimo, int& posicionMinimoF, int& posicionMinimoC, int filas, int columnas){
    minimo=matriz[0][0];
    posicionMinimoF=0;
    posicionMinimoC=0; 

    for (int i = 0; i < filas; i++){
        for (int j = 0; j < filas; j++)
        {
        if (matriz[i][j] < minimo){
            minimo =matriz[i][j];
            posicionMinimoF=i+1;
            posicionMinimoC=j+1;
        }
        }
    }

}

int main(){ 
    double array [20];
    cout<< "Ingrese valores para una matriz de 5x4:"; 

    for (int i = 0; i < 20; i++)
    {
        cin >> array[i]; 
    }
    int filas=5;    
    int columnas=4; 
    double matriz[5][4]; 

    insertar_array_matriz(array, filas, columnas, matriz);  

    mostrar(matriz, filas, columnas);  
    int posicionMinimaF, posicionMinimaC; 
    double minimo; 
    valorminimo(matriz, minimo, posicionMinimaF, posicionMinimaC, filas,columnas);
    cout<<"El valor minimo es ingresado es: "<<minimo<<endl; 
    cout <<"Se encuentra en la fila: "<< posicionMinimaF<<endl; 
    cout<<"Se encuentra en la columna:"<< posicionMinimaC<<endl; 
}