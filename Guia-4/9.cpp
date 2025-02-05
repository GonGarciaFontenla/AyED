#include <iostream>
using namespace std; 

void mostrar(int vec[], int dim)
{
	for (int i = 1; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

void selection_sort(int v[], int dim)
{
	int i, pos, imin, temp;

	for (pos = 0; pos < dim - 1 ; pos++) {
		imin = pos;
		for (i = pos+1 ; i < dim ; i++)
			if (v[i] < v[imin])
				imin = i;
		temp = v[pos];
		v[pos] = v[imin];
		v[imin] = temp;
	}
}
int main(){  
    const int dimvec = 10;
    int vec[dimvec];
	int i=0; 
	int valor;

	while (i<dimvec)
	{
		cout <<"Ingrese el valor " << i+1 << ": ";
		cin >> valor; 
        vec[i]=valor; 
        i++; 
        
}
    cout<<"Vector ingresado: "<<endl; 
    mostrar (vec, dimvec);

    selection_sort(vec, dimvec);
    cout<<"Vector ordenado= "<<endl;
    mostrar (vec, dimvec);

}