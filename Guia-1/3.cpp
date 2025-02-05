#include <iostream> 
using namespace std;  
int main ()
{
    int a,b,c; 
    cout << "ingrese un valor para a";
        cin >>a; 
    cout << "ingrese un valor para b"; 
        cin >>b; 
    cout <<"a= "<<a<< " b= "<<b<< endl; 

   /*intercambio valores*/
    c= a; 
    a= b; 
    b= c;  
    cout <<"a= "<< a << "b= "<< b << endl; 
    return 0; 
} 