/*Desarrollar un procedimiento que genere una lista sin 
order a partir de la interseccion de 2 listas.*/

struct Nodo {
	int info; 
	Nodo* sig; 
}; 

Nodo* buscar(Nodo* list, int valor); 
void agregar(Nodo* &list, int valor); 	

Nodo* interseccionListas(Nodo* list1, Nodo* list2) {
	Nodo* listIntersec = NULL; 
	Nodo* aux1 = list1;
	Nodo* aux2 = list2; 
	Nodo* found; 
	
	while(aux1 != NULL){
			found = buscar(aux2, aux1->info); 
			if(found != NULL) {
				agregar(listIntersec, aux1->info); 
			}
			aux1 = aux1->sig;
	}
	
	return listIntersec;
}


/*Se tiene un vector de reservas de los hoteles de pinamar para el verano 2024, que contiene
el detalle de las reservas de cada hotel con los siguientes campos: codigo de hotel - cantidad
de reservas - cantidad de dias disponibles en la temporada.
Ademas, se cuenta con una lista ordenada que contiene las ultimas reservas realizadas por un sitio
web de viajes, cada nodo de la list contiene: codigo de hotel - cantidad de dias reservados. 
Se pide actualizar el vector de reservas con la informacion que hay en la lista, incrementando 
la cantidad de reservas por cada una que aparezca en la lista, como asi actualizando la cantidad
de dias disponibles en base a los dias reservados.
Hay 50 reservas como maximo. 
*/


struct hotel {
	int codHotel; 
	int cant; 
	int dias; 
}; 

struct reserva {
	int codHotel; 
	int diasReserv; 
}; 

struct Nodo {
	reserva info; 
	Nodo* sig; 
}; 

void actualizarVector(hotel vec[], Nodo* list) {
	Nodo* aux = list; 
	
	for(int i = 0; i < 50, i++) {
		while(vec[i].codHotel == aux->info.codHotel) {
			vec[i].cant++; 
			vec[i].dias -= aux->info.diasReserv; 
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

struct Nodo {
	bulto info; 
	Nodo* sig; 
}; 

insertarOrdenado(Nodo* &list, bulto valor); 
freeList(Nodo* &list); 
showList(Nodo* list);

int main(){
	FILE* arch; 
	Nodo* list = NULL;
	Nodo* listUni = NULL;
	Nodo* listPeso = NULL;
	
	bulto aux; 
	
	arch = fopen("stock.dat", "rb");
	
	fread(&aux, sizeof(struct bulto), 1, arch); 
	
	while(!feof(arch)){
		insertarOrdenado(list, aux); 
		if(aux.cant == 0) {
			insertarOrdenado(listUni, aux); 
		}
		
		if(aux.peso > 100 && aux.type == 'B') {
			insertarOrdenado(listPeso, aux); 
		}
		
		fread(&aux, sizeof(struct bulto), 1, arch);
	}
	
	fclose(arch); 
	
	Nodo* auxL = list; 
	
	arch = fopen("stock.dat", "wb"); 
	
	while(aux != NULL){
		fwrite(&aux->info, sizeof(bulto), 1, arch); 
		aux = aux->sig; 
	}
	
	freeList(list); 
	fclose(arch); 
	
	showList(listUni);
	freeList(listUni);
	
	showList(listPeso); 
	freeList(listPeso);
	
	return 0; 
}

fi
