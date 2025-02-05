#ifndef LISTASORDUNI_HPP_INCLUDED
#define LISTASORDUNI_HPP_INCLUDED

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

#endif // LISTASORDUNI_HPP_INCLUDED
