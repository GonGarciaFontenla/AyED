#include <iostream>
using namespace std; 
int factorial(int n){
    if (n==0)
    {
        return 1; 
    }
    else 
        return n*factorial(n-1);
}
int main(){
    int n; 
    cout <<"Ingrese un valor a factorizar: "; 
    cin >> n; 
    int resultado= factorial(n); 
    cout <<"Valor factorizado= " << resultado <<endl; 
    return 0; 
}
    