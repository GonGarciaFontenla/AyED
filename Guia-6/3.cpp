#include <iostream>
#include <fstream>
#include "listasutil.hpp"
#include "listasord.hpp"
#include "rwstring.hpp"

using namespace std; 

struct deuda{
    string cliente; 
    int mes; 
    int monto; 
};
const int longitudCliente {8}; 

ostream& operator << (ostream&os, const deuda& ord)
{
    os<<"Cliente: " << ord.cliente<< "\t \t" << " Mes: " << ord.mes <<" "<< "\t \t"<< " Monto: " << ord.monto; 
    return os; 
}
fstream& operator << (fstream& fs, const deuda& ord)
{
    writestring(fs, ord.cliente, longitudCliente);
    fs.write(reinterpret_cast<const char* >(&ord.mes), sizeof(ord.mes));  
    fs.write(reinterpret_cast<const char*>(&ord.monto), sizeof(ord.monto)); 
    return fs; 
}
fstream& operator >> (fstream& fs, deuda& ord)
{
    ord.cliente = readstring(fs, longitudCliente); 
    fs.read(reinterpret_cast< char*> (&ord.mes), sizeof(ord.mes)); 
    fs.read(reinterpret_cast<char*> (&ord.monto), sizeof(ord.monto));
    return fs; 
}

int Ordenarlista(deuda a, deuda b){
    if (a.cliente == b.cliente)
    {
        return a.mes == b.mes ? 0 : (a.mes > b.mes ? 1 : -1); 
    }else{
        return a.cliente > b.cliente ? 1 : -1; 
    }
}

template <typename dato> void BorrarSiguiente(Nodo<dato>* actual)
{
    if (actual->sig != nullptr)
    {
        Nodo<dato>* borrar = actual->sig;
        actual->sig = actual->sig->sig; 
        delete borrar; 
    }
}

void consolidar (Nodo<deuda>* lista)
{
    while (lista)
    {
        while (lista->sig && Ordenarlista(lista->dato, lista->sig->dato) == 0)
        {
            lista->dato.monto += lista->sig->dato.monto;  
            BorrarSiguiente(lista); 
        }
    lista = lista->sig; 
    }
    
}
int main()
{
    Nodo<deuda>* ListaDeudas = nullptr; 
    deuda dato; 
    fstream archivo; 

    archivo.open("G06E03.bin", ios :: in | ios :: binary); 
    if (!archivo)
    {
        cout<<"Error al abrir archivo"<<endl; 
        return EXIT_FAILURE; 
    }
    while (archivo >> dato)
    {
        insertar(dato, ListaDeudas, Ordenarlista); 
    }
    archivo.close(); 

    cout<<endl<<"Muestro lista de deudas: "<<endl; 
    mostrar(ListaDeudas);
    cout<<endl<<"Fin de lista"<<endl;

    cout<<endl<<"Listado de deudas consolidadas: "<<endl; 
    consolidar(ListaDeudas);
    mostrar(ListaDeudas);
    cout<<"Fin de la lista"<<endl; 

    return 0; 
}