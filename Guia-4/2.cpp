#include <iostream> 
#include <fstream>

using namespace std; 

void mostrar(double vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

float calcularpromedios(double vec[], int dim, double valorsuperar){
    double sumar=0; 
    int cantidad=0;

    for (int i = 0; i < dim; i++)
    {
        if (vec[i]>valorsuperar)
        {
            sumar+=vec[i];
            cantidad++; 
        } 
    } 
    return cantidad > 0 ? sumar/cantidad : 0;  
}

int main(){
    const int dim=7; 
    double vec[dim]; 

    ifstream archivo("Promedios.txt");
    if (!archivo)
    {
        cout <<"Error al ejecutar el archivo"<< endl; 
        return 1; 
    }

    for (int i = 0; i<dim; i++)
    {
        archivo >> vec[i]; 
    }
    archivo.close();

    cout<<"Datos guardados en el vector= "<<endl;
    mostrar(vec, dim);
    //Promedios. 
    cout<<"El promedio de las notas que superar a 0 es "<<calcularpromedios(vec, dim, 0)<<endl;
    cout<<"El promedio de las notas que superar a 6 es "<<calcularpromedios(vec, dim, 6)<<endl;
    cout<<"El promedio de las notas que superar a 9 es "<<calcularpromedios(vec, dim, 9)<<endl;
    cout<<"El promedio de las notas que superar a 15 es "<<calcularpromedios(vec, dim, 15)<<endl;
    
    return 0; 
}