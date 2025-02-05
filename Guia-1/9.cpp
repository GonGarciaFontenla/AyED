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
    cout <<"el valor de a= " << a << endl;
    cout <<"el valor de b= " << b << endl;
    cout <<"el valor de c= " << c << endl;
    if (a < b) {
        int d = a;
        a = b;
        b = d;
    }
    if (b < c) {
        int d = b;
        b = c;
        c = d;
    }
    if (a < b) {
        int d = a;
        a = b;
        b = d;   
    }
     cout << "Las variables ordenadas son: " << a << ", " << b << ", " << c << endl;
    return 0; 
}