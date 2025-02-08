//Desarrolle una funcion que determine: Dadas las 3 notas
//obtenidas el promedio obtenido por un estudiante.

int promedio(int n1, int n2, int n3){
  int suma = n1 + n2 + n3; 
  
  return (suma/3); 
}

/*
Desarrolle un procedimiento que, dado un lote de numeros que termina
cuando ingresa 0, ingresados por el usuario, genere un vector ordenado. 
*/
void insertarOrdenado(int vec[], int len, int valor); 

void vecOrd(int vec[], int &len) {
  cout << "Ingrese numeros (0 para cortar)" << endl; 
  cin >> num;
  
  while(num != 0){
    insertarOrdenado(vec, len, num); 
    cout << "Ingrese numeros (0 para cortar)" << endl; 
    cin >> num;
  }
}

/*Desarrolle los siguientes subprogramas: 
a) Una funcion que retorne una lista ordenada a partir de la union de dos colas. 
b) Un procedimiento que genere una lista sin orden a partir de la interseccion de una cola y una lista. 
*/

int suprimir(Nodo* &cFrente, Nodo* &cFin); 
void insertarOrdenado(Nodo* &list, int valor); 
Nodo* buscar(Nodo* list, int valor); 

struct Nodo {
  int info; 
  Nodo* sig; 
}; 

Nodo* unionColas(Nodo* cFrente1, Nodo* cFin1, Nodo* cFrente2, Nodo* cFin2){
  Nodo* list = NULL; 
  int valor; 
  
  while(cFrente1 != NULL){
    valor = suprimir(cFrente1, cFin1); 
    insertarOrdenado(list, valor); 
  }
  
  while(cFrente2 != NULL){
    valor = suprimir(cFrente2, cFin2); 
    insertarOrdenado(list, valor); 
  }
  
  return list; 
}

Nodo* interseccionCL(Nodo* cFrente, Nodo* cFin, Nodo* list) {
  Nodo* listInter = NULL; 
  int valor; 
  Nodo* found; 
  
  while(cFrente != NULL){
    valor = suprimir(cFrente, cFin); 
    
    found = buscar(list, valor); 
    
    if(found != NULL){
      agregar(listInter, valor); 
    }
  }
  
  return listInter; 
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

int totalVotos(ballotage vec[]){
  int total = 0; 
  
  for(int i = 0; i < 48; i++){
    if(vec[i].codPart == 'A'){
      total += vec[i].votos; 
    }
  }
  
  return total; 
}

int promedioB(ballotage vec[]){
  int total = 0; 
  
  for(int i = 0; i < 48; i++){
    if(vec[i].codPart == 'B'){
      total += vec[i].votos; 
    }
  }
  return (total/24); 
}

void maxVotos(ballotage vec[]){
  int max = 0; 
  
  for(int i = 1; i < 48; i++){
    if(vec[max].votos < vec[i].votos){
      max = i; 
    }
  }

  cout << "El maximo de votos recibidos fueron " << vec[max].votos 
  << " para el partido " << vec[max].codPart << " en la provincia " 
  << vec[max].codProv << endl;  
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

struct reserva {
  int cod; 
  int reservas; 
  int huespedes; 
  int monto; 
}; 

struct ultReserv {
  int cod; 
  char beneficio;
  int huespedes; 
  int monto; 
}; 

struct Nodo{
  ultReserv info;
  Nodo* sig; 
}; 

void actualizarReservas(reserva vec[], Nodo* list){
  Nodo* aux = list; 
  
  for(int i = 0; i < 100; i++){
    while(vec[i].cod == aux->info.cod){
      if(aux->info.beneficio == 'S'){
        vec[i].huespedes += aux->info.huespedes; 
        vec[i].reservas++; 
        vec[i].monto += aux->info.monto; 
      }
      aux = aux->sig; 
    }
  }
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
  char type; 
  int precio; 
}; 

struct Nodo{
  pasaje info; 
  Nodo* sig; 
}; 

int main(){
  FILE* arch; 
  Nodo* listOrd = NULL;
  Nodo* filterList = NULL; 
  pasaje aux; 
  
  arch = fopen("viajes2024.dat", "rb"); 
  
  if(!arch){
    cout << "Error al intentar abrir el archivo" << endl; 
    return -1; 
  }
  
  fread(&aux, sizeof(pasaje), 1, arch); 
  
  while(!feof(arch)){
    insertarOrdenado(listOrd, aux); 
    
    if((aux.type == 'P' || aux.type == 'E') && aux.precio > 2500){
      insertarOrdenado2(filterList, aux); 
    }
    fread(&aux, sizeof(pasaje), 1, arch); 
  }
  
  fclose(arch); 
  
  Nodo* auxL = list; 
  
  arch = fopen("viajes2024.dat", "wb");
  
  while(auxL != NULL){
    fwrite(&auxL->info, sizeof(pasaje), 1, arch); 
    auxL = auxL->sig; 
  }
  
  fclose(arch); 
  
  freeList(listOrd);
  
  showList(filterList); 
  freeList(filterList); 
  
  return 0; 
}
