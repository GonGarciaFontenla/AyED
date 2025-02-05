#include <iostream>
using namespace std; 
int main() {
    int v[10] {2,4,6,8,10,12,14,16,18,20};
    int suma=0;
    for (int i=0; i < 10; i++)
    {
        suma += v[i]; 
    }
    cout << "La suma es igual a "<<suma; 
    
}