#include "ModProducto.h"

ModProducto::ModProducto(int tamMax)
{
	this->tam = tam;
	this->ind = 0;
	Productos = new Producto * [tam];
}

ModProducto::~ModProducto()
{
	delete[] Productos;
}

void ModProducto::registrar(Producto* c)
{
	if (ind < tam)
	{
		Productos[ind] = c;
		ind++;
	}

}

Producto* ModProducto::buscar(int codigo)
{
	for (int i = 0; i < ind; i++)
	{
		if (Productos[i]->getCodigo() == codigo)
			return Productos[i];
	}
	return NULL;
}

void ModProducto::mostrar()
{

	for (int i = 0; i < ind; i++)
		Productos[i]->mostrar();
}


