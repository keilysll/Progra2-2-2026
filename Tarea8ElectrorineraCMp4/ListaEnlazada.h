#pragma once
#include"Nodo.h"
template<class T>
class ListaEnlazada
{
private:
	Nodo<T>* primerNodo;
	int tam;

public:
	ListaEnlazada();
	~ListaEnlazada();
	void registrar(T* dato);
	bool operator+=(T* dato);
	T* buscar(T* dato);
	string toJson(string(*f)(T*));
	void ordenar(bool (*f)(T*, T*));
	int getTam();
	Nodo<T>* getPrimerNodo();
	T* getDato(int pos);
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
		primerNodo = new Nodo<T>(dato);
	else
	{
		Nodo<T>* tmp = primerNodo;
		while (tmp->getSig() != NULL)
		{
			tmp = tmp->getSig();
		}
		tmp->crearSig(dato);
	}
	tam++;
}

template<class T>
bool ListaEnlazada<T>::operator+=(T* dato)
{
	if (primerNodo == NULL)
		primerNodo = new Nodo<T>(dato);
	else
	{
		Nodo<T>* tmp = primerNodo;
		while (tmp->getSig() != NULL)
		{
			tmp = tmp->getSig();
		}
		tmp->crearSig(dato);
	}
	tam++;
	return dato;
}

template<class T>
T* ListaEnlazada<T>::buscar(T* dato)
{
	Nodo<T>* tmp = primerNodo;
	while (tmp != NULL)
	{
		if (*(tmp->getDato()) == dato)
		{
			return tmp->getDato();
		}
		tmp = tmp->getSig();
	}
	return NULL;

}

template<class T>
string ListaEnlazada<T>::toJson(string(*f)(T*))
{
	stringstream ss;
	ss << "[";
	Nodo<T>* tmp = primerNodo;
	while (tmp != NULL)
	{
		ss << (*f)(tmp->getDato());
		if (tmp->getSig() != NULL)
		{
			ss << ",";
		}
		tmp = tmp->getSig();
		
	}
	
	ss << "]";
	return ss.str();
}

template<class T>
void ListaEnlazada<T>::ordenar(bool(*f)(T*, T*))
{
	if (!primerNodo)return;
	for (Nodo<T>* i = primerNodo; i != NULL; i = i->getSig())
	{
		for (Nodo<T>* j = i->getSig(); j != NULL; j = j->getSig())
		{
			if ((*f)(i->getDato(), j->getDato()))
			{
				swap(i->getDato(), j->getDato());
			}
		}
	}
}

template<class T>
int ListaEnlazada<T>::getTam()
{
	return tam;
}

template<class T>
Nodo<T>* ListaEnlazada<T>::getPrimerNodo()
{
	return primerNodo;
}

template<class T>
T* ListaEnlazada<T>::getDato(int pos)
{
	Nodo<T>* tmp = primerNodo;
	for (int i = 0; i < pos; i++)
	{
		tmp = tmp->getSig();
	}
	return tmp->getDato();
}
	
