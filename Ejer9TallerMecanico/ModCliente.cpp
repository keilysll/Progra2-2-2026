#include "ModCliente.h"

ModCliente::ModCliente(int tam)
{
	this->tam = tam;
	this->ind = 0;
	clientes = new Cliente * [tam];
}

ModCliente::~ModCliente()
{
	delete[]clientes;
}

int ModCliente::getTam()
{
	return tam;
}

int ModCliente::getInd()
{
	return ind;
}

void ModCliente::registrar(Cliente* v)
{
	if (ind < tam)
	{
		clientes[ind] = v;
		ind++;
	}

}

Cliente* ModCliente::buscar(int ci)
{
	for (int i = 0; i < ind; i++)
	{
		if (clientes[i]->getCi() == ci)
		{
			return clientes[i];
		}
	}
	return NULL;
}

void ModCliente::ordenar()
{
	for (int i=0; i< ind-1;i++) 
	{
		for (int j = i+1; j < ind; j++)
		{
			if (clientes[i]->getNombre() > clientes[j]->getNombre())
			{
				Cliente* aux = clientes[i];
				clientes[i] = clientes[j];
				clientes[j] = aux;
			}
		}
	}
	
}

string ModCliente::toJson()
{
	ordenar();
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << clientes[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";

	return ss.str();
}