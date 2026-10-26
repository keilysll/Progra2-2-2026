#include "Cargador.h"

Cargador::Cargador(string codigo, int potencia)
{
	this->codigo = codigo;
	this->potencia = potencia;
}

Cargador::~Cargador()
{
}

string Cargador::getCodigo()
{
	return codigo;
}

int Cargador::getPotencia()
{
	return potencia;
}

bool Cargador::OrdenarPotenciaAsc(Cargador* c1, Cargador* c2)
{
	return c1->getPotencia() > c2->getPotencia();
}

string Cargador::toStringPtr(Cargador* c)
{
	return c->toString();
}
