#include <iostream>

using namespace std; 

void mostrar(double matriz[4][3], int filas, int columnas){
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<< matriz[i][j]<< " "; 
        }
    cout<< endl; 
    }
    
}
void insertar_array_matriz(const double* array,int filas, int columnas, double matriz[4][3]){
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

double calcularpromededio(double matriz[4][3], int filas, int columnas ){
    int sumatotal=0; 
    int cantidadElementos= filas * columnas; 

    if (cantidadElementos!=filas * columnas)
    {
        cout<<"Error: La cantidad de columnas o filas no es correcta"<<endl;
        exit (1);  
    }
    

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            sumatotal+=matriz[i][j]; 
        }
    }
    double promedio= static_cast<double>(sumatotal) / cantidadElementos;  
    return promedio; 
}

int main(){
    double array [12];
    cout<< "Ingrese valores para una matriz de 4x3:"; 

    for (int i = 0; i < 12; i++)
    {
        cin >> array[i]; 
    }
    int filas=4;    
    int columnas=3; 
    double matriz[4][3]; 

    insertar_array_matriz(array, filas, columnas, matriz);  

    mostrar(matriz, filas, columnas); 

    double promedio=calcularpromededio(matriz, filas, columnas); 
    cout <<"El promedio de los elementos de la matriz ingresado es: "<<promedio; 
    return 0 ;
}