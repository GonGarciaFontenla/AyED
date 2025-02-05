#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    for (unsigned long long i = 2; i < 65; i++)
    {
        unsigned long long base= 2.0;
        unsigned long long exponente= i;
        unsigned long long resultado = pow (base, exponente);
        cout <<exponente << " casilleros es igual a " <<resultado<< " arroces"<< endl; 
    }
}