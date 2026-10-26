#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
template<class T>
class ListaArray
{
private:
	T** datos;
	int tam;
	int ind;
public:
	ListaArray(int tam);
	~ListaArray();
	void registrar(T* dato);
	T* buscar(T* dato);
	string toString(string (*json)(T*));
	void ordenar(bool(*cmp)(T*, T*));
	T* operator[](int i);
};

template<class T>
ListaArray<T>::ListaArray(int tam)
{
	this ->tam = tam;
	ind = 0;
	datos = new T * [tam];
}

template<class T>
ListaArray<T>::~ListaArray()
{
}

template<class T>
void ListaArray<T>::registrar(T* dato)
{
	if (ind < tam)
	{
		datos[ind] = dato;
		ind++;
	}
}

template<class T>
T* ListaArray<T>::buscar(T* dato)
{
	for (int i = 0; i < ind; i++)
	{
		if (*(datos[i]) == dato)
		{
			return datos[i];
		}
	}
	return NULL;
}

template<class T>
string ListaArray<T>::toString(string(*json)(T*))
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << (*json)(datos[i]);
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}

template<class T>
void ListaArray<T>::ordenar(bool(*cmp)(T*, T*))
{
	for (int i = 0; i < ind; i++)
	{
		for (int j = 0; j < ind - 1; j++)
		{
			if ((*cmp)(datos[j], datos[j + 1]))
			{
				swap(datos[j], datos[j + 1]);
			}
		}
	}
}

template<class T>
T* ListaArray<T>::operator[](int i)
{
	if (i >= 0 && i < ind)
	{
		return datos[i];
	}
	return NULL;
}

