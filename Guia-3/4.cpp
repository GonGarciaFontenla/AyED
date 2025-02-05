#include <iostream>
#include <fstream>
#include <string>

using namespace std; 
 int main (){
    ifstream archivoOrigen1("texto1.txt");
    if (!archivoOrigen1)
    {
        cout<<"No existe el archivo"; 
        return 1; 
    }
    ifstream archivoOrigen2("texto2.txt"); 
    if (!archivoOrigen2){
        cout<<"No existe el archivo";
        return 1;
    }
    ofstream archivoConcatenacion("Concatenacion.txt");
    if (!archivoConcatenacion){
        cout<<"No se pudo crear el archivo";
        return 1; 
    }
    string informacion;
    while (archivoOrigen1 >> informacion)
    {
        archivoConcatenacion << informacion << endl; 
    }
    while (archivoOrigen2 >> informacion){
        archivoConcatenacion << informacion << endl;
    }
    archivoConcatenacion.close(); 
    archivoOrigen1.close();
    archivoOrigen2.close(); 
 }