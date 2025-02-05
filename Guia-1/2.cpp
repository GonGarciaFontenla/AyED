#include <iostream>
using namespace std; 
int main()
{
    int number;
    cout << "ingrese un numero del 1 al 7";
    cin >> number;
    switch (number)
    {
    case 45:
        cout << "El numero del dia " <<number<< " corresponde al dia lunes";
        break;
    case 59: 
        cout << "El numero del dia " <<number<< " corresponde al dia martes";
        break;
    case 123: 
        cout << "El numero del dia " <<number<< " corresponde al dia miercoles";
        break;
    case 506: 
        cout << "El numero del dia " <<number<< " corresponde al dia jueves";
        break;
    case 908: 
        cout << "El numero del dia " <<number<< " corresponde al dia viernes";
        break;
    case 6: 
        cout << "El numero del dia " <<number<< " corresponde al dia sabado";
        break;
    case 7: 
        cout << "El numero del dia " <<number<< " corresponde al dia domingo";
        break;
    default:
        cout << "El numero no es valido, debe estar entre 1 y 7" << endl;
        break;
    }
    return 0; 
}