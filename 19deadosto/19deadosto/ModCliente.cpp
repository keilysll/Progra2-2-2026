#include "ModCliente.h"

ModCliente::ModCliente(int tamMax)
{
	this->tam = tam;
	this->ind = 0;
	clientes = new Cliente * [tam];
}

ModCliente::~ModCliente()
{
	delete[] clientes;
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
			return clientes[i];
	}
	return NULL;
}

void ModCliente::mostrar()
{

	for (int i = 0; i < ind; i++)
		clientes[i]->mostrar();
}

