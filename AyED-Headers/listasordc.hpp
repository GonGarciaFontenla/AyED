#ifndef LISTASORDC_HPP_INCLUDED
#define LISTASORDC_HPP_INCLUDED

//Completa

template <typename T> Nodo<T>* buscar(T clave, Nodo<T>* lista, int (*criterio)(T, T))
{
	while (lista != nullptr && criterio(clave, lista->dato) > 0)
		lista = lista->sig;

	return lista != nullptr && criterio(clave, lista->dato) == 0 ? lista : nullptr;
}

template <typename T> void insertar(T valor, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;

	Nodo<T>** pp = &lista;
	while (*pp != nullptr && criterio(nuevo->dato, (*pp)->dato) >= 0)
		pp = &((*pp)->sig);
	nuevo->sig = *pp;
	*pp = nuevo;
}

template <typename T> Nodo<T>* extraer(T clave, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T> *aux;
	Nodo<T> **pp = &lista;

	while (*pp != nullptr && criterio(clave, (*pp)->dato) > 0)
		pp = &((*pp)->sig);

	if (*pp != nullptr && criterio(clave, (*pp)->dato) == 0) {
		aux = *pp;
		*pp = (*pp)->sig;
		return aux;
	} else {
		return nullptr;
	}
}

template <typename T> bool borrar(T clave, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>* extraido = extraer(clave, lista, criterio);
	if (extraido) {
		delete extraido;
		return true;
	} else {
		return false;
	}
}

template <typename T> Nodo<T>* insertar_unico(T valor, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>** pp = &lista;
	while (*pp != nullptr && criterio(valor, (*pp)->dato) > 0)
		pp = &((*pp)->sig);
	if (*pp != nullptr && criterio(valor, (*pp)->dato) == 0) {
		return *pp;//devuelvo el que ya estaba y acabo de encontrar
	} else {
		Nodo<T>* nuevo = new Nodo<T>; //Genero nodo
		nuevo->dato = valor; // y guardo el valor
		//Ahora lo inserto en su lugar
		nuevo->sig = *pp;
		*pp = nuevo;
		return nuevo;
	}
}

#endif // LISTASORDC_HPP_INCLUDED
