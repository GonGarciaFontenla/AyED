#include <iostream>
using namespace std;
int sucesion(int n){
    if (n<=1)
    {
        return n; 
    }
    return sucesion(n-1) + sucesion(n-2);
}
int main(){
    int n; 
    cout <<"Ingrese un valor de n para la secuencia: ";
    cin >>n;
    int sumatoria= sucesion(n);
    cout <<"El termino numero "<<n<<" de la funcion es "<<sumatoria << endl;
    return sumatoria;
}