#include <iostream>

using namespace std; 

/*El punto 1 ya lo hice en otro modelo*/

/*Se tiene un vector de Balance de las cuentas de inversion de un set de clientes, 
que contiene los siguientes campos: Num de cliente - Num de cuenta - Saldo - ultimo mov.
Ademas, se cuenta con una lista que contiene las ultimas transacciones de intereses 
generados (1 nodo 1 transaccion), cada nodo de la lista contiene: Num de cuenta - monto
de interes (positivo o negativo). 
Se pide actualizar el vector de balance con la informacion que hay en la lista, considerando
que debe actualizar el saldo y el valor del ultimo movimineto por cuenta. Maximo 200 cuentas.*/

struct balance {
    int numCli; 
    int numCuenta; 
    int saldo; 
    int ultMov; 
}; 

struct transaccion {
    int numCuenta; 
    int interes; 
}; 

struct Nodo {
    transaccion info; 
    Nodo* sig;
}; 

void actualizarBalance(balance Balanc[], int len, Nodo* list); 
int buscar(balance vec[], int len, int value); 


int main() {
    Nodo* lista; 
    
    int len;
    balance Balance[len]; 

    return 0; 
}

void actualizarBalance(balance Balance[], int len, Nodo* list) {
    Nodo* aux = list; 
    int pos;

    while(aux != NULL) {
        pos = buscar(Balance, len, aux->info.numCuenta); 
        if(pos > 0) {
            Balance[pos].saldo += aux->info.interes; 
            Balance[pos].ultMov = aux->info.interes; 
        }
        aux = aux -> sig; 
    }
} 


int buscar(balance vec[], int len, int value) {
    int i = 0; 
    while(i < len && value != vec[i].numCuenta) {
        i++; 
    }
    if(value == vec[i].numCuenta) 
        return i; 
    else 
        return -1;
}


/*Dado los siguientes fragmentos de codigo determine que despliega. Indique la salida por pantalla
del programa, o en caso que no compile, justificar*/

int main() {
    int *p, *y; 
    int w; 
    p = new int(); 
    w = 85; 
    *p = w;
    y = p; 
    w++; 
    cout << *y << endl;  
}

//Salida = 85

int main() {
    int *p; 
    p = new int[5];

    p[0] = 67; 
    p[1] = 70;
    p[2] = 15;
    p[3] = 81;
    p[4] = 23;

    cout << *(p+2) << endl; 
}

//Salida = 15;

//Verdadero o falso.
/*
La siguiente funcion esta definida correctamente y retorna una cadena de caracteres es: 
char Funcion(int vec[], int len). 

Falso: La funcion retorna un caracter, no una cadena. 
*/

/*
La estrategia de resolucion de corta de control, solo puede aplicarse en archivos. 

Falso: Puede aplicarse en distintas estructuras, por ejemplo, en vectores. Lo importante
es que sea una estructura secuencial (NO ESTOY SEGURO DE LA ULTIMA ORACION).
*/