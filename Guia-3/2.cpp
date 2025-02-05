#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std; 

int main() {
    ifstream archivo("datos.txt"); 
    if (!archivo)
    {
        cout << "No se puede ejecutar el archivos" <<endl;
        return 1;  
    }
    vector<double>cantidades; 
    double cantidad; 
    int orden=1; 
    double menorvalor= ::numeric_limits<double>::max(); 
    int menororden= -1;

    while (archivo >> cantidad)
    {
        cantidades.push_back(cantidad); 
        if (cantidad < menorvalor)
        {
            menorvalor=cantidad; 
            menororden=orden;
        }
        orden++;     
    }
    archivo.close();    
    if (cantidades.empty())
    {
        cout<<"El archivos no muestra cantidades";
    }
    else
    {
        cout<<"El menor valor es "<<menorvalor<<endl; 
        cout<<"El orden del menor valor es "<<menororden<<endl;
    }
}
