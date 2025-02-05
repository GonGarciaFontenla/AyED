#include <iostream>
#include <stdio.h>

using namespace std; 

/*Desarrollar un procedimiento que genere una lista sin 
order a partir de la interseccion de 2 listas.*/

struct Nodo {
    int info;
    Nodo* sig; 
}; 

void intersectarListas(Nodo* lista1, Nodo* lista2, Nodo* &lista3); 
int buscar(Nodo* lista, int valor);
void agregarNodo(Nodo* &list, int valor);  

int main() {
    Nodo* lista1 = NULL;
    Nodo* lista2 = NULL;
    Nodo* lista3 = NULL; 

    return 0;
}

void intersectarListas(Nodo* lista1, Nodo* lista2, Nodo* &lista3) {
    Nodo* aux = lista1; 
    int find; 

    while(aux != NULL) {
        find = buscar(lista2, aux->info); 
        if(find){
            agregarNodo(lista3, aux->info); 
        }
        aux = aux->sig;
    }
}

int buscar(Nodo* lista, int valor){
    Nodo* aux = lista;  

    while(aux != NULL){ 
        if(aux->info == valor){
            return 1; 
        }
        aux = aux -> sig; 
    }
    return 0;
}

void agregarNodo(Nodo* &list, int valor) {
    Nodo* newNodo = new Nodo(); 
    newNodo->info = valor; 
    newNodo->sig = list;  
    list = newNodo; 
}

/*Se tiene un vector de reservas de los hoteles de pinamar para el verano 2024, que contiene
el detalle de las reservas de cada hotel con los siguientes campos: codigo de hotel - cantidad
de reservas - cantidad de dias disponibles en la temporada.
Ademas, se cuenta con una lista ordenada que contiene las ultimas reservas realizadas por un sitio
web de viajes, cada nodo de la list contiene: codigo de hotel - cantidad de dias reservados. 
Se pide actualizar el vector de reservas con la informacion que hay en la lista, incrementando 
la cantidad de reservas por cada una que aparezca en la lista, como asi actualizando la cantidad
de dias disponibles en base a los dias reservados.*/

struct reservas {
    int codHotel; 
    int cantReservas;
    int cantDias; 
}; 

struct ultimaReserva {
    int codHotel; 
    int diasReserva; 
}; 

struct Nodo2 {
    ultimaReserva info; 
    Nodo2* sig; 
}; 

int main() {
    Nodo2* lista; 

    int len = 50; 
    reservas Reservas[len]; 
}

void actualizarReservas(reservas vec[], int len, Nodo2* list) {
    Nodo2* aux = list; 

    for(int i = 0; i < len; i++) {
        while(aux->info.codHotel == vec[i].codHotel) {
            vec[i].cantReservas++; 
            vec[i].cantDias -= aux->info.diasReserva; 
            aux = aux->sig; 
        }
    }
}

/*Se tiene un archivo de registros de bultos de productos almacenados en un deposito,
con el nombre STOCK.DAT (sin orden), que posee el siguiente formato: codigo de producto-
peso por bulto - tipo 'A' o 'B' - cantidad de bultos en stock. 
Se pide: 
a) Ordenar el archivo STOCK.DAT por codigo de producto. 
b) Generar dos listas y mostrarlas por pantalla: 
    a) la primero con los productos que no tienen unidades en Stock.
    b) La segunda con los productos PESADOS (peso mayor a 100kg) y Bebidas (B). */

struct bulto {
    int codProd; 
    int peso; 
    char type; 
    int cant; 
}; 

struct Nodo3 {
    bulto info; 
    Nodo3* sig; 
}; 

void insertarOrdenado(Nodo3* &list, bulto valor);
void freeList(Nodo3* &list);
void showList(Nodo3* list);  

int main() {
    FILE* arch; 
    bulto auxF; 
    Nodo3* listOrd = NULL; 
    Nodo3* listUni = NULL; 
    Nodo3* listPeso = NULL; 

    arch = fopen("stock.dat", "rb"); 

    fread(&auxF, sizeof(bulto), 1, arch); 

    while(!feof(arch)) {
        insertarOrdenado(listOrd, auxF); 

        if(auxF.cant == 0) {
            insertarOrdenado(listUni, auxF); 
        }

        if(auxF.peso > 100) {
            insertarOrdenado(listPeso, auxF); 
        }
        fread(&auxF, sizeof(bulto), 1, arch); 
    }

    fclose(arch);

    arch = fopen("stock.dat", "wb"); 
    Nodo3* auxL = listOrd; 

    while(auxL != NULL) {
        fwrite(&auxL->info, sizeof(bulto), 1, arch); 
        auxL = auxL->sig; 
    }

    fclose(arch); 

    freeList(listOrd); 

    showList(listUni); 
    showList(listPeso); 

    freeList(listUni);
    freeList(listPeso);
}

void insertarOrdenado(Nodo3 *&lista, bulto valor) {
    Nodo3* newNodo = new Nodo3(); 
    Nodo3* aux = lista; 
    Nodo3* ant = NULL; 

    newNodo->info.codProd = valor.codProd;
    newNodo->info.peso = valor.peso;  
    newNodo->info.type = valor.type; 
    newNodo->info.cant = valor.cant; 
    newNodo->sig = NULL; 

    while(aux != NULL && valor.codProd > aux->info.codProd) {
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

void showList(Nodo3 *list) {
    Nodo3* aux = list; 

    while(aux != NULL) {
        cout << "Codigo de producto: " << aux->info.codProd << ", peso: " << aux->info.peso 
        << ", tipo: " << aux->info.type << ", cantidad: " << aux->info.cant << endl; 

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