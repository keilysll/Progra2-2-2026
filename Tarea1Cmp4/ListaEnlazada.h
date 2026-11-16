#pragma once
#include "Nodo.h"
template <class T>
class ListaEnlazada
{
private:
	Nodo <T>* primerNodo;
	int tam;
public:
	ListaEnlazada();
	~ListaEnlazada();
	void registrar(T* dato);
	T* buscar(T* dato);
	void ordenar(bool(*f)(T*, T*));
	string toJson(string(*json)(T*));
	T*& operator[](int pos);
	int getTam();
	void eliminar(T* dato);
};

template<class T>
ListaEnlazada<T>::ListaEnlazada()
{
	primerNodo = NULL;
	tam = 0;
}

template<class T>
ListaEnlazada<T>::~ListaEnlazada()
{
}

template<class T>
void ListaEnlazada<T>::registrar(T* dato)
{
	if (primerNodo == NULL)
		primerNodo = new Nodo <T>(dato);
	else
	{
		Nodo <T>* tmp = primerNodo;
		while (tmp->getSig() != NULL)
		{
			tmp = tmp->getSig();
		}
		tmp->crearSig(dato);
	}
	tam++;
}

template<class T>
T* ListaEnlazada<T>::buscar(T* dato)
{
	Nodo <T>* tmp = primerNodo;
	while (tmp != NULL)
	{
		if (*(tmp->getDato()) == dato)
			return tmp->getDato();
		tmp = tmp->getSig();
	}
	return NULL;
}

template<class T>
void ListaEnlazada<T>::ordenar(bool(*f)(T*, T*))
{
	if (!primerNodo) return;
	for (Nodo <T>* i = primerNodo; i != NULL; i = i->getSig())
	{
		for (Nodo <T>* j = i->getSig(); j != NULL; j = j->getSig())
		{
			if ((*f)(i->getDato(), j->getDato()))
			{
				swap(i->getDato(), j->getDato());
			}
		}
	}
}

//template<class T>
//void ListaEnlazada<T>::ordenar(bool(*cmp)(T*, T*))
//{
//	for (int i = 0; i < tam; i++)
//	{
//		for (int j = 0; j < tam - 1; j++)
//		{
//			T*& datoJ = (*(this))[j];
//			T*& datoJ1 = (*(this))[j + 1];
//			if ((*cmp)(datoJ, datoJ1))
//			{
//				swap(datoJ, datoJ1);
//			}
//		}
//	}
//}

template<class T>
string ListaEnlazada<T>::toJson(string(*json)(T*))
{
	stringstream ss;
	ss << "[";
	Nodo <T>* tmp = primerNodo;
	while (tmp != NULL) {
		ss << (*json)(tmp->getDato());
		if (tmp->getSig() != NULL)
			ss << ",";
		tmp = tmp->getSig();
	}
	ss << "]";
	return ss.str();
}

template<class T>
T*& ListaEnlazada<T>::operator[](int pos)
{
	Nodo <T>* tmp = primerNodo;
	for (int i = 0; i < pos; i++)
		tmp = tmp->getSig();
	return tmp->getDato();
}

template<class T>
inline int ListaEnlazada<T>::getTam()
{
	return tam;
}

template<class T>
void ListaEnlazada<T>::eliminar(T* dato)
{
	Nodo <T>* tmp = primerNodo;
	Nodo <T>* ant = NULL;
	while (tmp != NULL)
	{
		if (*(tmp->getDato()) == dato)
		{
			if (ant == NULL)
				primerNodo = tmp->getSig();
			else
				ant->setSig(tmp->getSig());
			delete tmp;
			return;
		}
		ant = tmp;
		tmp = tmp->getSig();
	}
}

