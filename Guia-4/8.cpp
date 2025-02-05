#include <iostream>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 1; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}
int buscar_lineal_did(int clave, int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		if (vec[i] == clave)
			return i;
	return -1;
}
bool valor_repetido(int valor, int vec[], int dim)
{
    for (int i = 1; i < dim; i++)
        if (vec[i] == valor)
            return true;
    return false;
}
int main()
{
	int vec[8];
	int i=0; 
	const int dimvec = 8;
	int valor;
	buscar_lineal_did(valor, vec, dimvec);

	while (i<dimvec)
	{
		i++; 
		cout <<"Ingrese el valor " << i << ": ";
		cin >> valor ; 

	if (valor_repetido(valor,vec,i))
	{
		cout<<"Valor repetido. Ingrese otro valor: "<<endl;
		i--;
	}

	else {
		vec[i]=valor;
	}

	}

	cout <<"Vector= "<<endl;
	mostrar (vec, dimvec+1);

	return 0;
}