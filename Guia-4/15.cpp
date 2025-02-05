#include <iostream>
#include <fstream>
using namespace std; 

void valormaximo(int matriz[][3], int& posicionmaximoF, int& posicionmaximoC, int filas)
{
    posicionmaximoF=0;
    posicionmaximoC=0; 
    const int numcolum{3}; 

    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < filas; ++j)
        {
            if (matriz[i][j] > matriz[posicionmaximoF][posicionmaximoC])
            {
                posicionmaximoF=i;
                posicionmaximoC=j;
            }
        }
    }
}

int valorminimo(const int vec[], int size)
{
    int imin{}; 
    for (int i = 1; i < size; i++)
    {
        if (vec[i]<vec[imin])
        {
            imin=i; 
        }
    }
    return imin; 
}

void calcularpromedioMax(float matriz[][3], int& posicionmaximoF, int& posicionmaximoC, int filas)
{
    posicionmaximoF=0;
    posicionmaximoC=0; 
    const int numcolum{3}; 

    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < filas; ++j)
        {
            if (matriz[i][j] > matriz[posicionmaximoF][posicionmaximoC])
            {
                posicionmaximoF=i;
                posicionmaximoC=j;
            }
        }
    }
}

int main(){
    const int numfilas{6};
    const int numcolum{3}; 
    int MatrizProducto[numfilas][numcolum] {}; 
    int MatrizLote[numfilas][numcolum] {};
    int vecUnidad[numfilas]{};
    float MatrizPromedio[numfilas][numcolum]; 

    string productos[numfilas]; 
    string colores[numcolum]; 

    ifstream archivo("DatosProductos.txt");  
    if (!archivo)
    {
        cout<<"El archivo no puede ejecutarse"; 
        return 1; 
    }
    for (int i = 0; i < numfilas &&  archivo >> productos[i]; i++);
    for (int i = 0; i < numcolum && archivo >> colores[i]; i++);
    archivo.close(); 

    ifstream archivoProduc("DatosProduccion.txt"); 
    if (!archivoProduc)
    {
        std::cout<<"El archivo no puede ejecutarse"; 
        return 1; 
    }
    int iproduc, icolor, cantidad;
    while (archivoProduc>>iproduc>>icolor>>cantidad)
    {
        MatrizProducto[iproduc][icolor]+=cantidad; 
        MatrizLote[iproduc][icolor]++;
    }
    archivoProduc.close();
    //ejercicio A
    valormaximo(MatrizProducto, iproduc, icolor, numcolum);
    cout <<"La mayor cantidad de unidades producidas fue "<< MatrizProducto[iproduc][icolor]
    <<" correspondiente al producto "<< productos[iproduc]
    <<" en color "<< colores[icolor] << endl; 

    //ejercicio B
    for (int i = 0; i < numfilas; i++)
    {
        for (int j = 0; j < numcolum; j++)
        {
            vecUnidad[i]+=MatrizProducto[i][j];
        }
    }
    iproduc= valorminimo(vecUnidad, numfilas); 
    cout<< "La menor cantidad de unidades producidos fue "<< vecUnidad[iproduc]
    << " correpondiente al producto " << productos[iproduc]<<endl; 

    //Ejercicio C 
    for (int i = 0; i < numfilas; ++i)
    {
        for (int j = 0; j < numcolum; ++j)
        {
            MatrizPromedio[i][j]= (float) MatrizProducto[i][j]/ MatrizLote[i][j];
        }
    }
    calcularpromedioMax(MatrizPromedio, iproduc, icolor, numcolum); 
    cout <<"El promedio maximo por lote es "<< MatrizPromedio[iproduc][icolor]
    << " del producto "<< productos[iproduc]
    << " de color " << colores[icolor] << endl; 

    return 0; 
}