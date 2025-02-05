#include <iostream>
using namespace std; 
int main ()
{
    int a,b,c; 
    cout << "ingrese un valor para a ";
        cin >> a; 
    cout << "ingrese un valor para b "; 
        cin >> b; 
    cout << "ingrese un valor para c ";
        cin >> c; 
    if (a<=0 || b<=0 || c<=0)
    {
        cout << "ERROR";
    }
        else if (a==b && a==c)
        {
            cout <<"Este triangulo es equilatero";
        }
        else if (a!=b && a!=c && b!=c)
        {
            cout <<"Este triangulo es escaleno";
        }
        else 
        {
            cout <<"Este triangulo es isoceles";
        }    
}