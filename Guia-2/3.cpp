#include <iostream>
using namespace std; 
void obtenerfechaAAAAMMDD (int fechaAAAAMMDD, int& dia, int& mes, int& anio){

    anio= (fechaAAAAMMDD /10000);

    mes= (fechaAAAAMMDD /100)%100;

    dia= fechaAAAAMMDD %100;  
}
int main(){
    int fechaAAAAAMMDD; 

    cout <<"Ingrese una fecha en el formato AAAAAMMDD ";
    cin >> fechaAAAAAMMDD;

    int dia,mes,anio;
    obtenerfechaAAAAMMDD (fechaAAAAAMMDD , dia, mes, anio);

    cout <<"Fecha en format0 DD/MM/AAAA es igual a "<< dia<<"/"<<mes<<"/"<<anio<< endl;
    return 0; 
}