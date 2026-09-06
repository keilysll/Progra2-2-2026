#include "ModCliente.h"

ModCliente::ModCliente(int tam)
{
	this->tam = tam;
	this->ind = 0;
	clientes = new Cliente * [tam];
}

ModCliente::~ModCliente()
{
	delete[] clientes;
}

int ModCliente::getTam()
{
	return tam;
}

int ModCliente::getInd()
{
	return ind;
}

void ModCliente::registrar(Cliente* c)
{
	if (ind < tam)
	{
		clientes[ind] = c;
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

string ModCliente::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss<<clientes[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}