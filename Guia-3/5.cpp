#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

void LimitarCaracter (const string& texto, const string& nombreArchivo, int limite){
    ofstream archivo(nombreArchivo); 
    if (archivo.is_open())
    {
        int longitud= texto.length(); 
        for (int i = 0; i < longitud; i += limite)
        {
            archivo <<texto.substr(i, limite)<<endl; 
        }
        archivo.close();
        cout <<"El texto fue guardado en " <<nombreArchivo<<endl; 
    }
    else {
        cout <<"El archivo no se puede ejecutar";
        }
}
int main(){
    string texto;

    cout <<"Ingrese un texto";  
    getline(cin, texto); 

    int Limiteporlinea=80; 
    LimitarCaracter(texto, "text.txt" , Limiteporlinea);
    
    return 0; 
}
