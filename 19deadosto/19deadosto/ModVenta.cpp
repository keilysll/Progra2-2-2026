#include "ModVenta.h"
ModVenta::ModVenta(int tamMax)
{
	this->tam = tam;
	this->ind = 0;
	ventas = new Venta * [tam];
}

ModVenta::~ModVenta()
{
	delete[] ventas;
}

void ModVenta::registrar(Venta* v)
{
	if (ind < tam)
	{
		ventas[ind] = v;
		ind++;
	}

}

Venta* ModVenta::buscar(int num)
{
	for (int i = 0; i < ind; i++)
	{
		if (ventas[i]->getNum() == num)
			return ventas[i];
	}
	return NULL;
}

void ModVenta::mostrar()
{

	for (int i = 0; i < ind; i++)
		ventas[i]->mostrar();
}

