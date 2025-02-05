#include <iostream>
#include <stdio.h>

using namespace std; 

void vecOrdenado(int vec[], int &len);
void insertarOrdenado(int vec[], int &len, int value);
void insertAndKeepPosition(int vec[], int &len, int value, int position);

int main() {
    int vec[20]; 
    int len = 0; 

    vecOrdenado(vec, len); 

    for(int i =0; i < len; i++) {
        cout << "Num " << i << ": " << vec[i] << endl; 
    }
    return 0;
}


//Desarrolle una funcion que determine: Dadas las 3 notas
//obtenidas el promedio obtenido por un estudiante. 
int promedio(int n1, int n2, int n3) {
    int suma = n1 + n2 + n3; 

    return (suma/3); 
}

/*
Desarrolle un procedimiento que, dado un lote de numeros que termina
cuando ingresa 0, ingresados por el usuario, genere un vector ordenado. 
*/

void vecOrdenado(int vec[], int &len) {
    int num; 

    cout << "Ingrese numeros (corte con 0): "; 
    cin >> num; 

    while(num != 0) {
        insertarOrdenado(vec, len, num); 
        cout << "Ingrese numeros (corte con 0): "; 
        cin >> num; 
    }
}

void insertarOrdenado(int vec[], int &len, int value) {
    int i = 0; 

    while(i < len && value > vec[i]) {
        i++;  
    }
    if(i == len) {
        vec[i] = value; 
        len++;
    }else insertAndKeepPosition(vec, len, value, i); 
}

void insertAndKeepPosition(int vec[], int &len, int value, int position) {
    for(int i= len; i > position; i--) {
        vec[i] = vec[i-1];  
    }
    vec[position] = value; 
    len++; 
}

/*Desarrolle los siguientes subprogramas: 
a) Una funcion que retorne una lista ordenada a partir de la union de dos colas. 
b) Un procedimiento que genere una lista sin orden a partir de la interseccion de una cola y una lista. 
*/

struct Nodo {
    int info; 
    Nodo* sig; 
}; 

Nodo* unionColas(Nodo* cFrente1, Nodo* cFin1, Nodo* cFrente2, Nodo* cFin2) {
    Nodo* list = NULL; 
    int valor; 

    while(cFrente1 != NULL) {
        valor = suprimir(cFrente1, cFin1); 
        insertarOrdenado2(list, valor); 
    }

    while(cFrente2 != NULL) {
        valor = suprimir(cFrente2, cFin2); 
        insertarOrdenado2(list, valor); 
    }

    return list; 
}

Nodo* interseccionColaLista(Nodo* cFrente, Nodo* cFin, Nodo* list) {
    Nodo* listInter = NULL; 
    int valor; 
    Nodo* found; 
    Nodo* aux = list; 

    while(aux != NULL) {
        valor = suprimir(cFrente, cFin); 
        found = buscar(list, valor); 

        if(found != NULL){
            addList(listInter, valor); 
        }   
        aux = aux->sig; 
    }

    return listInter; 
}

int suprimir(Nodo *&colaFrente, Nodo *&colaFin) {
    int retorno = colaFrente->info; 

    Nodo* aux = colaFrente; 
    colaFrente = aux->sig;
    if(colaFrente == NULL) {
        colaFin = NULL; 
    } 
    delete(aux); 
    return retorno; 
}

void insertarOrdenado2(Nodo *&lista, int valor) {
    Nodo* newNodo = new Nodo(); 
    Nodo* aux = lista; 
    Nodo* ant = NULL; 

    newNodo->info = valor; 
    newNodo->sig = NULL; 

    while(aux != NULL && valor > aux->info) {
        ant = aux; 
        aux = aux->sig; 
    } 
    if(ant == NULL) {
        lista = newNodo; 
    }else{ 
        ant->sig = newNodo;
    }
    newNodo->sig = aux; 
}

void addList(Nodo* &list, int valor) {
    Nodo* newNodo = new Nodo(); 
    newNodo->info = valor; 
    newNodo->sig = list;  
    list = newNodo; 
}

Nodo* buscar(Nodo* lista, int valor) {
    Nodo* aux = lista;  

    while(aux != NULL && aux->info != valor){ 
        aux = aux -> sig; 
    }

    return aux; 
}


/*Dado un vector de Ballotage que indica los votos en la Argentina por provincia
(23 y CABA) para presidente. El vecotr contiene el codigo de la provincia, codigo
de partido politico ['A' o 'B'], y la cantidad de votos. Se sabe que el vector
muestra por cada provincia y por cada partido los resultados, determinar: 
a) Cual es el total de votos recibidos para el partido A? 
b) Cual es el promedio de voto, por provincia, que recibio el partido b? 
c) Cual es el maximo de votos recibidos y en que provincia y para que partido fue?
*/

struct ballotage {
    int codProv; 
    char codPart; 
    int votos; 
}; 

int calcularVotosA(ballotage vec[]);
int promedioB(ballotage vec[]); 
void maxVotos(ballotage vec[]); 

int main() {
    ballotage vec[48] = {
        {1, 'A', 100}, {1, 'B', 200}, {2, 'A', 150}, {2, 'B', 180},
        {3, 'A', 120}, {3, 'B', 160}, {4, 'A', 130}, {4, 'B', 140},
        {5, 'A', 170}, {5, 'B', 190}, {6, 'A', 110}, {6, 'B', 90},
        {7, 'A', 140}, {7, 'B', 130}, {8, 'A', 160}, {8, 'B', 200},
        {9, 'A', 180}, {9, 'B', 210}, {10, 'A', 190}, {10, 'B', 220},
        {11, 'A', 200}, {11, 'B', 150}, {12, 'A', 210}, {12, 'B', 180},
        {13, 'A', 220}, {13, 'B', 100}, {14, 'A', 230}, {14, 'B', 200},
        {15, 'A', 240}, {15, 'B', 170}, {16, 'A', 250}, {16, 'B', 140},
        {17, 'A', 260}, {17, 'B', 160}, {18, 'A', 270}, {18, 'B', 180},
        {19, 'A', 280}, {19, 'B', 190}, {20, 'A', 290}, {20, 'B', 220},
        {21, 'A', 300}, {21, 'B', 230}, {22, 'A', 310}, {22, 'B', 240},
        {23, 'A', 320}, {23, 'B', 250}, {24, 'A', 330}, {24, 'B', 260}
    }; 
    
    int votosA; 
    int promB;

    votosA = calcularVotosA(vec); 
    cout << "Total de votos para el partido A: " << votosA << endl;  

    promB = promedioB(vec);
    cout << "\nPromedio de votos por provincia para el partido B: " << promB << endl; 

    maxVotos(vec); 
}

int calcularVotosA(ballotage vec[]) {
    int sum = 0; 

    for(int i = 0; i < 48; i++){
        if(vec[i].codPart == 'A')
             sum += vec[i].votos; 
    }

    return sum; 
}

int promedioB(ballotage vec[]) {
    int sum = 0; 

    for(int i = 0; i < 48; i++) {
        if(vec[i].codPart == 'B') {
            sum += vec[i].votos;  
        }
    }

    return(sum/24); 
}

void maxVotos(ballotage vec[]) {
    int pos; 

    for(int i = 0; i < 48; i++){
        if(vec[i].votos > vec[i+1].votos) {
            pos = i;
        }
    }

    cout << "\nEl maximo de votos recibidos fueron: " << vec[pos].votos << endl <<
    "Para la provincia con codigo " << vec[pos].codProv << endl << "Para el partido " << 
    vec[pos].codPart << endl; 
}

/*
Se tiene un vector de reservas de cabañas de la patagonia, en las que se aplico un beneficio
para turistas argentinos con los siguientes campos: Codigo de la cabaña - Cantidad de reservas
de turisticas argentinos - Cantidad de huespedes - monto abonado. 
Ademas se cuenta con una lista ordenada que contiene las ultimas reservas realizadas, cada nodo
de la lista contiene: Codigo de la cabaña - Aplicar beneficio de turismo ('S' o 'N') - Cantidad
de huespedes . Monto abonado. 

Se pide, actualizar el vector reservas con la informacion que hay en la lista. Por cada reserva
en la que se haya aplicado el beneficio, debe actualizar la cantidad de huespedes en el vector, 
incrementar en 1 la cantidad de reservas y acumular el monto abonado. 
Se sabe que maximo hay 100 cabañas. 
*/

struct cabania {
    int codCab;
    int cantReserv; 
    int cantHuesped;
    int monto;
}; 

struct reserva {
    int codCaba; 
    char beneficio; 
    int cantHuespedes; 
    int montoAbonado; 
}; 

struct Nodo2 {
    reserva info; 
    Nodo2* sig; 
}; 

int main() {
    cabania cabanias[100];
    Nodo2* listReservas; 

    actualizarCabanias(cabanias, listReservas); 
}

void actualizarCabanias(cabania vec[], Nodo2* list) {
    Nodo2* aux = list; 
    int pos; 

    while(aux != NULL){
        if(aux->info.beneficio == 'S'){
            pos = search(vec, 100, aux->info.codCaba); 
            if(pos != -1) {
                vec[pos].cantHuesped += aux->info.cantHuespedes; 
                vec[pos].cantReserv++; 
                vec[pos].monto += aux->info.montoAbonado;
            }
        }
        aux = aux->sig; 
    }
}

int search(cabania vec[], int len, int value) {
    int i = 0; 
    while(i < len && value != vec[i].codCab) {
        i++; 
    }
    if(value == vec[i].codCab) 
        return i; 
    else 
        return -1;
}

/*
Se tiene un archivo de disponibilidad de pasajes en tren Viajes2024.dat (sin orden): 
id del tramo - tipo de reserva ('P', 'E', 'S' (premium, ejecutivo, standar)) - precio. 

Se pide: 
a) Ordenar el archivo Viajes2024.dat por id del tramo. 
b) Armar una lista y mostrarla por pantalla, ordenada por precio, si el tipo de reserva
es 'P' o 'E' y el precio supera los 2500.
*/

struct pasaje {
    int idTramo; 
    char typeReserv; 
    int precio; 
}; 

struct Nodo3 {
    pasaje info; 
    Nodo3* sig; 
}; 

void insertarOrdenado3(Nodo3 *&lista, pasaje valor);
void showList(Nodo3* list);
void freeList(Nodo3 *&list); 
void showFile(const char* fileName, pasaje aux); 

int main() {
    FILE* arch; 
    pasaje aux; 
    Nodo3* listOrd = NULL;
    Nodo3* listPrice = NULL;  

    showFile("Viajes2024.dat", aux); 

    arch = fopen("Viajes2024.dat", "rb"); 

    if(!arch) {
        cout << "Error al abrir el archivo" << endl; 
        return -1; 
    }

    fread(&aux, sizeof(pasaje), 1, arch); 

    while(!feof(arch)) {
        insertarOrdenado3(listOrd, aux);
        if((aux.typeReserv == 'P' || aux.typeReserv == 'E') && aux.precio > 2500) {
            insertarOrdenado3(listPrice, aux); 
        }
        fread(&aux, sizeof(pasaje), 1, arch);  
    }

    fclose(arch); 

    arch = fopen("Viajes2024.dat", "wb"); 

    Nodo3* auxL = listOrd; 

    while(auxL != NULL) {
        fwrite(&auxL->info, sizeof(pasaje), 1, arch);
        auxL = auxL->sig; 
    }

    fclose(arch); 
    freeList(listOrd); 

    cout << "\n\n" << endl; 
    showFile("Viajes2024.dat", aux); 

    cout << "\n\nListadoooo" << endl; 

    showList(listPrice); 

    freeList(listPrice);
}

void insertarOrdenado3(Nodo3 *&lista, pasaje valor) {
    Nodo3* newNodo = new Nodo3(); 
    Nodo3* aux = lista; 
    Nodo3* ant = NULL; 

    newNodo->info.idTramo = valor.idTramo;
    newNodo->info.precio = valor.precio;
    newNodo->info.typeReserv = valor.typeReserv;
    newNodo->sig = NULL; 

    while(aux != NULL && valor.idTramo > aux->info.idTramo) {
        ant = aux; 
        aux = aux->sig; 
    } 
    if(ant == NULL) {
        lista = newNodo; 
    }else{ 
        ant->sig = newNodo;
    }
    newNodo->sig = aux; 
}

void showList(Nodo3* list) {
    Nodo3* aux = list;

    while(aux != NULL) {
        cout << "Precio: " << aux->info.precio << " Tipo de reserva: " << aux->info.typeReserv << " idTramo: " << aux->info.idTramo << endl; 
        aux = aux->sig; 
    }
}

void freeList(Nodo3 *&list) {
    Nodo3* aux; 

    while(list != NULL) {
        aux = list;
        list = list->sig;  
        delete(aux);
    }
}

void showFile(const char* fileName, pasaje aux) {
    FILE* alumnos = fopen(fileName, "rb"); 

    fread(&aux, sizeof(pasaje), 1, alumnos);

    while(!feof(alumnos)) {
        cout << "Tramo: " << aux.idTramo
        << ", precio: " << aux.precio
        << ", Tipo de reserva: " << aux.typeReserv
        << endl; 
        fread(&aux, sizeof(pasaje), 1, alumnos);
    }
}