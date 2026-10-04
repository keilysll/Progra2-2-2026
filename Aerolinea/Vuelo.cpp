#include "Vuelo.h"

Vuelo::Vuelo(int numero, Avion* avion):asientos(avion->getFilas() * avion->getColumnas())
{
	this->numero = numero;
	this->avion = avion;
	for (int f = 1; f <= avion->getFilas(); f++)
	{
		for (int c = 1; c <= avion->getColumnas(); c++)
		{
			asientos.registrar(new Asiento(f, c));
		}
	}
}

Vuelo::~Vuelo()
{
}

int Vuelo::getNumero()
{
	return numero;
}

Avion* Vuelo::getAvion()
{
	return avion;
}

ModAsiento& Vuelo::getAsientos()
{
	return asientos;
}

void Vuelo::registrarPasajero(int fila, int columna, Persona* p)
{
	Asiento* a = asientos.buscar(fila, columna);
	if (a != NULL && a->estaVacio())
	{
		a->setPasajero(p);
	}
}

void Vuelo::intercambiarAsiento(Asiento* a1, Asiento* a2)
{
	Asiento* x = asientos.buscar(a1->getFila(), a1->getColumna());
	Asiento* y = asientos.buscar(a2->getFila(), a2->getColumna());
	if (x != NULL && y != NULL)
	{
		Persona* temp = x->getPasajero();
		x->setPasajero(y->getPasajero());
		y->setPasajero(temp);
	}
}

string Vuelo::toJson()
{
	stringstream ss;
	ss << "{\"numero\":" << numero << ",\"avion\":" << avion->toJson() << ",\"asientos\":" << asientos.toJson() << "}";
	return ss.str();
}
