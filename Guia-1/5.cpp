#include <iostream> 
using namespace std; 
int main ()
{
    const int a= 180; 
    float b,c,d; 
        cout << "ingrese el valor de un angulo";
            cin >>b;
        cout << "ingrese el valor del otro angulo";
        cin >>c; 
    d= a-b-c; 
        cout <<"el valor del tercer angulo es "<<d<< " grados";
    if (d<1)
    {
        cout << " (no existe tal triangulo)"<<endl; 
    }
    return 0; 
}