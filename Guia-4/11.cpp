#include <iostream>
using namespace std; 

void mostrar(string equipos[] ,int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << equipos[i] << ": " << vec[i] << endl;
}

void selection_sort(int vec[], string equipos[], int dim)
{
	int i, pos, imin, temp;
    string temp_equipo; 
	for (pos = 0; pos < dim - 1 ; pos++) {
		imin = pos;
		for (i = pos+1 ; i < dim ; i++){
            if (vec[i] < vec[imin]){
                imin = i;
            }
        }
		temp = vec[pos];
		vec[pos] = vec[imin];
		vec[imin] = temp;

        temp_equipo= equipos[pos]; 
        equipos[pos]=equipos[imin];
        equipos[imin]= temp_equipo;
	}
}

int main(){
    int dimvec= 8;  
    string equipos[dimvec]; 
    int vec[dimvec]; 
    int i= 0; 
    string nombre_equipo;
    int valor;  

    while (i<dimvec)
	{
		cout <<"Ingrese el nombre del equipo " << i+1 << ": ";
        cin >> nombre_equipo; 
        equipos[i]= nombre_equipo;
        cout<< "Ingrese el puntaje del equipo "<<nombre_equipo <<": "; 
        cin >> valor; 
        vec[i]=valor; 
        i++;  
    }
    selection_sort(vec, equipos ,dimvec);
    cout<<"puntajes ordenados= "<<endl;
    mostrar (equipos, vec, dimvec);

    return 0;
}