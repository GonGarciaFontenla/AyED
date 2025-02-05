#include <iostream>
#include <fstream>
#include "listasutil.hpp"
#include "listasord.hpp"
#include "rwstring.hpp"

using namespace std; 

struct compra
{
    int id; 
    string cliente; 
    string producto;
    int cantidad;  
}; 
const int longitudCliente {8};
const int longitudProducto {10};

ostream& operator << (ostream& os, const compra& ord)
{
    os << "id: " << ord.id << " - " << ord.cliente << " - " << ord.producto
	<< " - cant " << ord.cantidad;
    return os; 
}

fstream& operator << (fstream &fs, const compra& ord)
{
    fs.write(reinterpret_cast<const char*> (&ord.id), sizeof(ord.id));
    writestring(fs, ord.cliente, longitudCliente); 
    writestring(fs, ord.producto, longitudProducto);
    fs.write(reinterpret_cast<const char*> (&ord.cantidad), sizeof (ord.cantidad));
    return fs;  
}

fstream& operator >> (fstream& fs, compra& ord)
{
    fs.read(reinterpret_cast<char* > (&ord.id), sizeof (ord.id));
    ord.cliente = readstring(fs, longitudCliente);
    ord.producto = readstring(fs, longitudProducto);
    fs.read(reinterpret_cast<char*> (&ord.cantidad), sizeof (ord.cantidad));
    return fs;  
}

int compararCliente(compra a, compra b)
{
    if (a.cliente == b.cliente)
    {
        return a.producto.compare(b.producto);
    }else{ 
        return a.cliente > b.cliente ? 1 : -1; 
    }
}

int compararId(compra a, compra b){
    return a.id - b.id; 
}   


int main()
{
    Nodo<compra>* listaId =nullptr; 
    Nodo<compra>* listaOrdenada = nullptr; 
    compra orden;
    fstream archivo; 

    archivo.open("G06E02.bin", ios :: in | ios::binary); 
    if (!archivo)
    {
        cout<<"No se puede abrir el archivo binario."<<endl; 
        exit(-1);
    }
    while (archivo >> orden)
    {
        insertar(orden, listaId, compararId); 
        insertar(orden, listaOrdenada, compararCliente);
    }
    archivo.close(); 

    cout<<"Lista ordenada de los Clientes: "<<endl;
    mostrar (listaOrdenada); 
    cout<<"Fin de la lista."<<endl; 

    cout<<endl<<"Lista ordenada por Id: "<<endl; 
    mostrar(listaId); 
    cout<<"Fin de la lista."<<endl; 
    
    cout<<endl<<"Ingrese id a buscar: "<<endl; 
    Nodo<compra>* pord;
    cin>>orden.id;
    
    while (orden.id > 0)
    {
        pord = buscar(orden, listaId, compararId);
 
        if (pord != nullptr)
            cout<<pord->dato <<endl;
        else
            cout<<"No se encuentran datos asociados al Id: "<<orden.id<<endl;
            cout<<"Ingrese id a buscar: "<<endl;
            cin>>orden.id; 
    }

    cout<<endl<<"======================================"<<endl; 
    cout<<endl<<"Ingrese cliente a buscar: "<<endl;  
    if (cin >> orden.cliente)
        cout<<endl<<"Ingrese un producto: "<<endl; 
    while (cin>>orden.producto)
    {
        cout<<"Eliminados: "<<endl; 
        while(pord = extraer(orden, listaOrdenada, compararCliente)){ 
            cout<<pord->dato<<endl; 
            orden.id= pord->dato.id; 
            delete pord;  
        if (!borrar(orden, listaOrdenada, compararCliente))
        {
            cout<<"ERROR al intentar borrar la orden con Id: "<<orden.id<<endl; 
        }
        }
        cout<<endl<<"Remanente de la lista ordenada por Cliente: "<<endl; 
        mostrar(listaOrdenada); 
        cout<<"Fin de lista"<<endl; 

        cout<<endl<<"Remanente de la lista ordenada por Id: "<<endl; 
        mostrar(listaId); 
        cout<<"Fin de lista"<<endl; 

        cout << endl << "Ingrese el Cliente:" << endl;
		if (cin >> orden.cliente)
			cout << "Ingrese el producto: ";
    }
    return 0; 
}