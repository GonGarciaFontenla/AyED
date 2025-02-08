//Ejercicio 1: 

//Lista ordenada a partir de union de cola y vector. 

struct Nodo {
	int info; 
	Nodo* sig; 
}; 

int suprimir(Nodo* &cFrente, Nodo* &cFin);
void insertarOrdenado(Nodo* &lista, int valor); 

Nodo* listaOrdenada(Nodo* cFrente, Nodo* cFin, int vec[], int len){
	Nodo* list = NULL; 
	int valor; 
	
	while(cFrente != NULL) {
		valor = suprimir(cFrente, cFin); 
		insertarOrdenado(list, valor); 
	}
	
	for(int i = 0; i < len; i++){
		insertarOrdenado(list, vec[i]); 
	}
	
	return list; 
}




//Ejercicio 2:
/*Se tiene un vector de los productos de un almacen, STOCK, que contiene todos los productos
que se tienen disponibles a la venta, con los siguientes campos: id del producto, tipo (
p "perecedero" y n "no perecedero") y unidades en el almacen. Ademas, se cuenta con una lista
ordenada que contiene los ultimos pedidos al almacen que deben ser entregados a los clientes
finales. La lista contiene el id del producto, el id del cliente y las unidades requeridas.
Se pide actualizar el vector stock con la informacion que hay en la lista, solo para el campo
de unidades. 
Se sabe que como maximo son 50 productos*/

struct producto {
	int idProd; 
	char typeProd; 
	int unidades; 
}; 

struct entrega {
	int idProd; 
	int idCli; 
	int uni; 
}; 

struct Nodo {
	entrega info; 
	Nodo* sig;
}; 


//Opcion 1: 
void actualizarVec(producto vec[], Nodo* list) {
	Nodo* aux = list; 
	int position; 
	
	while(aux != NULL) {
		position = buscar(vec, aux->info.idProd); 
		
		if(position != -1){
			vec[position].unidades -= aux->info-uni; 
		}
	}
}

//Opcion 2: Esta me gusta mucho mas. Aprovecha que la lista esta ordenada!!!
void actualizarVec(producto vec[], Nodo* list){
	Nodo* aux = list; 

	for(int i = 0; i < 50; i++){
		while(vec[i].codProd == aux->info.codProd) {
				vec[i].unidades -= aux->info.uni; 
			} 
			aux = aux->sig; 
		}
	}
}


//Decir la respuesta: 

int main() {
    int arr[] = {10,20,30,40}; 
    int *ptr = arr; 
    cout << *(ptr + 2) << endl; 
    ptr++; 
    cout << *ptr << endl; 
    return 0; 
}

salida = 30 - 20


int recursivo(int n) {
    if(n==0) return 1; 
    return n + recursivo(n-1); 
}

int main() {
    int resultado = recursivo(5); 
    cout << resultado << endl; 
    return 0; 
}

salida = 16


