#include <iostream>
using namespace std; 
int main ()
{
    for ( int i = 0; i>=0; i++)
    {
        int a;
        cout <<"Ingrese un numero";
        cin >> a; 
        if (a<0)
        {
            exit (1);
        }
        
         else if (a>=0)
         {
            cout <<"El valor ingresado es positivo" <<endl;
         }
         
    }
}