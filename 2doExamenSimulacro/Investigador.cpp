#include "Investigador.h"

Investigador::Investigador(int codigo)
{
	this->codigo = codigo;
}

Investigador::Investigador(int codigo, string nombre, string especialidad)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this ->especialidad = especialidad;
}

Investigador::~Investigador()
{
}

int Investigador::getCodigo()
{
	return codigo;
}

string Investigador::getNombre()
{
	return nombre;
}

string Investigador::getEspec()
{
	return especialidad;
}

string Investigador::toString()
{
	stringstream ss;
	ss << "{\"codigo\":"<<codigo<<",\"nombre\":\""<<nombre<<"\",\"especialidad\":\""<<especialidad<<"\"}";
	return ss.str();
}

string Investigador::toStringPtr(Investigador* i)
{
	return i->toString();
}

bool Investigador::operator==(Investigador* i)
{
	return codigo == i->codigo;
}

bool Investigador::OrdenarPorNombre(Investigador* a, Investigador* b)
{
	return a->nombre > b->nombre;
}

