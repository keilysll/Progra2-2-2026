#include "Libro.h"

Libro::Libro(string codigo):Material(codigo," ")
{
}

Libro::Libro(string codigo, string titulo, string autor, int nroPag):Material(codigo,titulo)
{
	this->autor = autor;
	this->nroPag = nroPag;
}

Libro::~Libro()
{
}

string Libro::getAutor()
{
	return autor;
}

int Libro::getNroPag()
{
	return nroPag;
}

string Libro::toJson()
{
	stringstream ss;
	ss << "{\"codigo\":\""<<codigo<<"\",\"titulo\":\""<<titulo<<"\",\"autor\":\""<<autor<<"\",\"paginas\":"<<nroPag<<",\"tipo\":\"libro\"}";
	return ss.str();
}

int Libro::diasPrestamoMax()
{
	return 14;
}
