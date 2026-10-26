#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
template<class T>
class ModGenerico
{
private:
	T** datos;
	int tam;
	int ind;
public:
	ModGenerico(int tam);
	~ModGenerico();
	void registrar(T* dato);
	T* buscar(T* dato);
	string toString(string (*json)(T*));
	void ordenar(bool(*cmp)(T*, T*));
	T* operator[] (int i);
	int getInd();
};

template<class T>
ModGenerico<T>::ModGenerico(int tam)
{
	this ->tam = tam;
	ind = 0;
	datos = new T * [tam];
}

template<class T>
ModGenerico<T>::~ModGenerico()
{
	delete[] datos;
}

template<class T>
void ModGenerico<T>::registrar(T* dato)
{
	if (ind<tam)
	{
		datos[ind] = dato;
		ind++;
	}
}

template<class T>
T* ModGenerico<T>::buscar(T* dato)
{
	for (int i = 0;i<ind ;i++)
	{
		if ((*datos[i]) == dato)
		{
			return datos[i];
		}
	}
	return NULL;
}

template<class T>
string ModGenerico<T>::toString(string(*json)(T*))
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
void ModGenerico<T>::ordenar(bool(*cmp)(T*, T*))
{
	for (int i = 0; i < ind; i++)
	{
		for (int j = 0; j < ind - 1 - i; j++)
		{
			if ((*cmp)(datos[j], datos[j + 1]))
			{
				swap(datos[j], datos[j + 1]);
			}
		}
	}
}

template<class T>
T* ModGenerico<T>::operator[](int i)
{
	if (i >= 0 && i < ind) return datos[i];
	return NULL;
}

template<class T>
int ModGenerico<T>::getInd()
{
	return ind;
}
