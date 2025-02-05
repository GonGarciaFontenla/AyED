#include <iostream>
#include <fstream>
#include <string>

using namespace std; 
int main() {
    ifstream archivoOrigen("datos.txt"); 
    if (!archivoOrigen)
    {
        cout << "No se puede ejecutar el archivos" <<endl;
        return 1;  
    }
    ofstream archivoPares("pares.txt"); 
    if (!archivoPares){
        cout << "No se puede crear el archivo" <<endl;
        return 1;  
    }
    ofstream archivoInpares("Impares.txt"); 
    if (!archivoInpares){
        cout << "No se puede crear el archivo" <<endl;
        return 1;  
    }
    int numeros;
    while (archivoOrigen >> numeros) {
        if (numeros % 2 == 0) {
            archivoPares << numeros<<endl;
        } 
        else {
            archivoInpares <<numeros<<endl; 
        }
    }
    archivoOrigen.close(); 
    archivoPares.close();
    archivoInpares.close();
}