#include <iostream>
using namespace std; 
int main()
{
    int a,b,c,d; 
    cout <<"ingrese cantidad de bultos"; 
    cin >>a; 
    cout <<"ingrese cantidad de bultos que entran por caja";
    cin >>b; 
    c=a/b; 
    cout<< "cantidad de cajas completas= "<<c<<endl; 
    d=a % b;
    cout<< "La cantidad de bultos que sombran es = "<<d; 
}