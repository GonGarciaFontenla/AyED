#include <iostream>
#include "listasutil.hpp"
#include "listasord.hpp"

using namespace std; 

struct alumno
{
    string nombre; 
    int legajo; 
    double promedio; 
}; 
int comparar(alumno a, alumno b){
    if (a.promedio == b.promedio)
    {
        return a.nombre.compare(b.nombre);
    }else{ 
        return a.promedio > b.promedio ? 1 : -1; 
    }
}
ostream & operator << (ostream&os, const alumno a){
    os<<a.nombre<< "\t(legajo: "<<a.legajo<<") : "<<a.promedio;
    return os; 
}

int main()
{
    const int dimActivos {9};
    const int dimBajas {3}; 

    alumno vectorActivos[dimActivos]{
        "Maria", 721, 8.4, "Pedro", 847, 7.2, "Ana",
        614, 9.1, "Jose", 578, 8.9, "Juan", 927,
        8.4,"Unai", 325, 8.1, "Ramon", 418, 8.4,
        "Elaia", 892, 9.6, "Carlos", 733, 8.5};
    alumno vectorBaja[dimBajas]{
        "Pedro", 847, 7.2, "Ramon", 418, 8.4, "Unai", 325, 8.1
    }; 

    Nodo<alumno>* lista = nullptr; 

    for (int i = 0; i < dimActivos; i++)
    {
        insertar(vectorActivos[i], lista, comparar); 
    }

    cout<<"Lista ordenada: "<<endl; 
    mostrar(lista); 
    cout<<"Fin de lista"<<endl; 

    cout<<endl<<"Listado de alumnos dados de baja: "<<endl; 
    for (int i = 0; i < dimBajas; i++)
    {
       cout<<vectorBaja[i]<<endl; 
    }

    for (int i = 0; i < dimBajas; i++)
    {
        borrar(vectorBaja[i], lista, comparar); 
    }
    cout<<endl<<"Lista final: "<<endl; 
    mostrar(lista); 
    cout<<"Fin de lista"<<endl; 

    return 0;     
}