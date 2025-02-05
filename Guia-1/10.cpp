#include <iostream>
using namespace std; 
int main ()
{
    int a,contador=0;
    cout <<"Ingrese un numero: ";
        cin >>a;
    while (a!=0)
    {
        a=a/10; 
        contador++; 
    }
    cout <<"La cantidad de digitos es = " <<contador; 
     return 0; 
}