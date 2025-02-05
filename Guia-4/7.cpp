#include <iostream>
using namespace std;

void valormaximo(int vec[], int dim, int& maximo, int& maximo2, int& posicionMaximo, int& posicionMaximo2){
    maximo=vec[0];
    maximo2=vec[1]; 
    posicionMaximo=0;
    posicionMaximo2=1;  

    for (int i = 2; i < dim; i++){
        if (vec[i]>maximo)
        {
            maximo2=maximo; 
            posicionMaximo2=posicionMaximo; 
            maximo=vec[i];
            posicionMaximo=i; 
        }
        else if (vec[i]>maximo2)
        {
            maximo2=vec[i]; 
            posicionMaximo2=i; 
        }  
    }
}
int main(){ 
    int dim=10; 
    int vec[dim]= {6, 1, 3, 7, 9, 4, 10, 2, 8, 5 }; 

    int maximo, maximo2,posicionMaximo,posicionMaximo2;

    valormaximo(vec,dim,maximo,maximo2,posicionMaximo,posicionMaximo2);

    cout << "El valor máximo es: "<< maximo<< " y se encuentra en la posicion: "<<posicionMaximo<<endl; 
    cout <<"El segundo valor maximo es: "<< maximo2 << " y se encuentra en la posicion: "<<posicionMaximo2<<endl; 

    return 0; 
}