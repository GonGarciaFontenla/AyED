#ifndef LISTASUTIL_HPP_INCLUDED
#define LISTASUTIL_HPP_INCLUDED

template <typename T> struct Nodo {
	T dato; // valor que contiene el nodo
	Nodo<T>* sig; // puntero al siguiente nodo
};

template <typename T> void mostrar(Nodo<T>* lista)
{ //Presupone que de ser neceario se hizo la sobrecarga de << para dato
	while (lista != nullptr) {
		std::cout << lista->dato << std::endl;
		lista = lista->sig;
	}
}

#endif // LISTASUTIL_HPP_INCLUDED
