#include "EGCompuesto.h"

EGCompuesto::EGCompuesto(int ind) :ElementoGrafico(id)
{
	this->ind = 0;
	elementos = new ElementoGrafico * [TAMAX];
}

EGCompuesto::~EGCompuesto()
{
	delete[] elementos;
}

void EGCompuesto::dibujar()
{
}

void EGCompuesto::borrar()
{
}

void EGCompuesto::agregar(ElementoGrafico* e)
{
	if (ind < TAMAX)
	{
		elementos[ind] = e;
		ind++;
	}
}

void EGCompuesto::eliminar()
{
}
