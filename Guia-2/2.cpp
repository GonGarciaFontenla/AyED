#include <iostream>
using namespace std; 
int cambiarfecha(){
    int dia, mes, anio;    
    cout <<"Ingrese un año "; 
    cin >>anio;
    if (anio<1000 || anio >9999)
    {
        cout <<"Año introducido no es valido";
        exit(1);
    }
    cout <<"ingrese un mes ";
    cin >>mes; 
    if (mes<1 || mes >12)
    {
        cout << "Mes introducido no es valido";
        exit (1);
    }
    cout <<"ingrese un dia ";
    cin >>dia;
    if (dia<1 || dia>31)
    {
        cout << "Dia introducido no valido";
        exit (1);
    } 
    int fechaenAAAAMMDD= anio*10000 + mes*100 + dia;
    return fechaenAAAAMMDD; 
}
int main()
{
    int fechaenAAAAMMDD= cambiarfecha();
    cout <<"La fecha introducida en formate AAAAMMDD es igual a " <<fechaenAAAAMMDD <<endl;
    return 0;  
}