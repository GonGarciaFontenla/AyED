#include <iostream>
using namespace std;
int main()
{
    float mm, pulgadas; 
    cout << "ingrese medida en mm:";
    cin>> mm;
    pulgadas= mm/25.4;
    cout<<mm<< "mm son equivalentes a " << pulgadas<< " pulgadas " << endl; 
    return 0;
}