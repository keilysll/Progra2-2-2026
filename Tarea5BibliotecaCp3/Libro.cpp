#include "Libro.h"

Libro::Libro(int codigo, string titulo, string autor)
{
	this->codigo = codigo;
	this->titulo = titulo;
	this->autor = autor;
}

Libro::~Libro()
{
}

int Libro::getCod()
{
	return codigo;
}

string Libro::getTitulo()
{
	return titulo;
}

string Libro::getAutor()
{
	return autor;
}

string Libro::toStringPtr(Libro* l)
{
	return l->toString();
}

bool Libro::ordenarCodLib(Libro* l1, Libro* l2)
{
	return l1->getCod() > l2->getCod();
}

bool Libro::operator==(Libro* l)
{
	return codigo == l->codigo;
}
