#include <iostream>
using namespace std; 

int sumatoriadegauss(int n){
    int suma= 0; 
    int a= 1; 
    do
    {
        suma += a; 
        a++;     
    } while (a<=n);
    return suma;
}
int main(){
    int n; 
    cout <<"Ingrese un valor de n= ";
    cin >>n; 
    int numero = sumatoriadegauss (n); 
    cout << "La sumatoria del valor ingresado es igual a "<<numero<<endl; 
    return 0; 
}
