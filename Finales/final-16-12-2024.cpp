//Crear una función que devuelva una lista conteniendo la unión de una pila, una cola y un vector. 

struct Nodo {
  int info; 
  Nodo* sig; 
}; 

int suprimir(Nodo* &cFrente, Nodo* &cFin); 
int pop(Nodo* &pila); 
void agregar(Nodo* &list, int valor); 

Node* unionCPV(Nodo* pila, Nodo* cFrente, Nodo* cFin, int vec[], int len){
	Nodo* list = null; 
	int valor; 
	
	while(cFrente != NULL) {
		valor = suprimir(cFrente, cFin); 
		agregar(list, valor); 
	}
	
	while(pila != NULL){
		valor = pop(pila); 
		agregar(list, valor); 
	}
	
	for(int i = 0; i < len; i++){
		agregar(list, vec[i]); 
	}
}


/*Se tiene un vector de Matriculas (codigo de curso, cantidad de alumnos, monto pagado) y
una lista con las nuevas reservas (codigo de curso, monto pagado). Actualizar el vector 
con los contenidos de la lista, considerando que por cada reserva se aumenta en 1 la cantidad 
de alumnos. */


struct matricula{
	int codCurso; 
	int cantAlumnos; 
	int monto; 
}; 

struct reserva {
	int codCurso; 
	int monto; 
}; 

struct Nodo {
	reserva info; 
	Nodo* sig; 
}; 

int buscar(matricula vec[], int len, int valor); 

void actualizarVector(matriculas vec[], int len, Nodo* list) {
	Nodo* aux = list; 
	int pos; 
	
	while(aux != NULL) {
		pos = buscar(vec, len, aux->info.codCurso); 
		if(pos != -1) {
			vec[pos].cantAlumos++; 
		}
		aux = aux->sig; 
	}
}

void actualizarVector2(matriculas vec[], int len, Nodo* list){
	Nodo* aux = list; 
	
	while(aux != NULL){
		for(int i = 0; i < len; i++){
			if(vec[i].codCurso == aux->info.codCurso) {
				vec[i].cantAlumnos++; 
			}
		}
		aux = aux->sig; 
	}
}


//Verdadero o faslo

/*
El vector es la mejor estructura para ordenar un archivo. 
Faslo: El vector es una estructura estatica, por ende se deberia saber la dimension del archivo
para poder ordenar a este. 
*/

/*
El corte de control se encarga de unir dos archivos con todos sus registros
Falso: El apareo es el encargado de unir dos archivos (no exclusivamente) con todos sus registros. 
*/
