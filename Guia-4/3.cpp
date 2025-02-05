#include <iostream>
#include <fstream>
using namespace std;                                        

const int alumnos=10;                                       

void Cargarnotas(const string& notas, float promedios[]) {
    ifstream archivo(notas); 
    for (int i = 0; i < alumnos; i++)
        {
        archivo >> promedios[i];
        }
    archivo.close();
}
float calcularpromedios(const float notasAlum[]){
    float total=0.0;
    for (int i = 0; i < alumnos; i++)
    {
        total+=notasAlum[i]; 
    }
    float promedio= total/alumnos; 
    return promedio; 
}
int encimapromedio(const float promedio[], float promediogeneral){
    int contador=0; 
    for (int i = 0; i < alumnos; i++)
    {
        if (promedio[i] > promediogeneral)
        {
            contador ++; 
        }
    }
    return contador;
}
int main(){
    string notas = "notas.txt"; 
    float promedioalumnos[alumnos]; 
    Cargarnotas(notas, promedioalumnos); 
    float promediogeneral=calcularpromedios(promedioalumnos); 
    int alumnosPorEncima= encimapromedio(promedioalumnos, promediogeneral);
    cout << "El promedio general de las notas es: " << promediogeneral << endl;
    cout << "La cantidad de alumnos que superan el promedio es: " << alumnosPorEncima << endl;
    return 0;
}