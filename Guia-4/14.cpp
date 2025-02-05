#include <iostream>
#include <fstream>
using namespace std;

int mayor(int vec[], int dim)
{
	int imax {};
	for (int i = 1; i < dim; i++)
		if (vec[i] > vec[imax])
			imax = i;
	return imax;
}

int main(){ 
    const int dim=10; 
    int vec[dim] {};
    const int desplazamiento{15};

    ifstream archivoEntegras("Entregas.txt"); 
    if(!archivoEntegras) {
        cout<<"Error al leer el archivo"<< endl;
        return 1; 
    }
    int codigoVehiculo;
    while (archivoEntegras>>codigoVehiculo)
    {
        vec[codigoVehiculo-desplazamiento]++;
    }
    archivoEntegras.close(); 

    codigoVehiculo=mayor(vec,dim); 
    cout<<"El vehiculo que hizo la mayor cantidad de entregas tiene el codigo "<< codigoVehiculo+desplazamiento <<
    " e hizo "<< vec[codigoVehiculo]<< " entregas"<<endl; 
    return 0; 
}