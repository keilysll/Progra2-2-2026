#include "Revista.h"

Revista::Revista(string codigo, string titulo, int edicion):Material(codigo,titulo)
{
	this->edicion = edicion;
}

Revista::~Revista()
{
}

int Revista::getEdicion()
{
	return edicion;
}

string Revista::toJson()
{
	stringstream ss;
	ss << "{\"codigo\":\""<<codigo<<"\",\"titulo\":\""<<titulo<<"\",\"edicion\":"<<edicion<<",\"tipo\":\"revista\"}";
	return ss.str();
}

int Revista::diasPrestamoMax()
{
	return 7;
}
