#include <iostream>
//incluyo biblioteca iomanip para controlar cantidad de decimales
#include <iomanip>
//incluyo biblioteca cmath para calcular el valor absoluto (abs)
#include <cmath>
using namespace std; 

double calcularpi(){
    //declaro variable Valor_pi_1 para almacenar valor de pi en iteracion
    double Valor_pi_1 = 0.0;
    double divisor = 1.0;
    int signo = 1;
    double precision=0.00000011;

    while (true) {
    //creo variable Valor_pi_2 para comparar con Valor_pi_1 en cada iteracion
        double Valor_pi_2 = Valor_pi_1 ;
    //utilizo la serie de Leibniz= "(-1)^n/(2*n+1)=pi/4" 
        Valor_pi_1 += signo * (1.0 / divisor);
        divisor += 2;
    //multiplico a la variable signo por -1 para que el numerador intercale entre 1 y -1  
        signo *= -1;
    //establesco la precision de la serie para cumplir con el valor de Pi solicitado
        if (abs(Valor_pi_1 - Valor_pi_2) < precision)
            break;
    }
    //como la serie de Leibniz es=pi/4 --> multiplico a Valor_pi_1 por 4, y asi obtengo valor de Pi
    return Valor_pi_1 * 4;
}
int main(){
    //llamo a la funcion calcularpi()
    double valorpi_calculado = calcularpi();
    //fijo la precision en 6 y asi obtener 6 decimales atras de la coma
    cout<< fixed << setprecision (6);
    cout<<"El valor de pi es igual a "<< valorpi_calculado << endl; 
    return 0; 
}