#include <iostream> 
using namespace std; 
float cambiotemp (float tempF){
    float TempC= (tempF-32)/1.8;
    return TempC;
}
int main(){
    float TempF;

    cout << "Ingresa temperatura en Fahrenheit: ";
    cin >> TempF;
    float TempCel= cambiotemp(TempF);
    cout <<"La temperatura en grados Celcius es: " << TempCel <<endl;
}