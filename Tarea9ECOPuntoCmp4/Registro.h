#pragma once
#include"Nodo.h"
template<class T>
class Registro
{
private:
	Nodo<T>* primerNodo;
	int tam;
public:
	Registro();
	~Registro();
	bool operator +=(T* dato);
	void agregar(T* dato);
	T* buscar(string clave);
	int size();
	T* obtener(int posicion);
	string toJson();
};

template<class T>
inline Registro<T>::Registro()
{
	primerNodo = NULL;
	tam = 0;
}

template<class T>
inline Registro<T>::~Registro()
{
	Nodo<T>* tmp = primerNodo;
	while (tmp != NULL)
	{
		Nodo<T>* sig = tmp->getSig();
		delete tmp->getDato();
		delete tmp;
		tmp = sig;
	}
}

template<class T>
inline bool Registro<T>::operator+=(T* dato)
{
	Nodo<T>* aux = primerNodo;
	while (aux != NULL)
	{
		if (aux->getDato()->getClave() == dato->getClave())
		{
			string clave = dato->getClave();
			delete dato;
			throw exception(("clave duplicada: " + clave).c_str());
		}
		aux = aux->getSig();
	}

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
void Registro<T>::agregar(T* dato)
{
	Nodo<T>* aux = primerNodo;
	while (aux != NULL)
	{
		if (aux->getDato()->getClave() == dato->getClave())
		{
			string clave = dato->getClave();
			delete dato;
			throw exception(("clave duplicada: " + clave).c_str());
		}
		aux = aux->getSig();
	}

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
inline T* Registro<T>::buscar(string clave)
{
	Nodo<T>* tmp = primerNodo;
	while (tmp != NULL)
	{
		if (tmp->getDato()->getClave() == clave)
		{
			return tmp->getDato();
		}
		tmp = tmp->getSig();
	}
	throw exception(("clave no encontrada: " + clave).c_str());
}

template<class T>
inline int Registro<T>::size()
{
	return tam;
}

template<class T>
inline T* Registro<T>::obtener(int posicion)
{
	Nodo<T>* tmp = primerNodo;
	for (int i = 0; i < posicion; i++)
	{
		tmp = tmp->getSig();
	}
	return tmp->getDato();
}

template<class T>
inline string Registro<T>::toJson()
{
	stringstream ss;
	ss << "[";
	Nodo<T>* tmp = primerNodo;
	while (tmp!= NULL)
	{
		ss << tmp->getDato()->toJson();
		if (tmp->getSig() != NULL)
		{
			ss << ",";
		}
		tmp = tmp->getSig();
	}
	ss << "]";
	return ss.str();
}
