#include "ModProducto.h"

ModProducto::ModProducto(int tam)
{
	this->tam = tam;
	this->ind = 0;
	productos = new Producto * [tam];
}

ModProducto::~ModProducto()
{
	delete[] productos;
}

void ModProducto::registrar(Producto* p)
{
	if (ind < tam)
	{
		productos[ind] = p;
		ind++;
	}
}

Producto* ModProducto::buscar(int codigo)
{
	for (int i = 0; i < ind; i++)
	{
		if (productos[i]->getCodigo() == codigo)
			return productos[i];
	}
	return NULL;
}

void ModProducto::mostrar()
{
	for (int i = 0; i < ind; i++)
		productos[i]->mostrar();
}
