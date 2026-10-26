#include "LibroFisico.h"

LibroFisico::LibroFisico(int codigo):Libro(codigo, " ", " ")
{
}

LibroFisico::LibroFisico(int codigo, string titulo, string autor, int nroEj):Libro(codigo,titulo,autor)
{
	this->nroEj = nroEj;
}

LibroFisico::~LibroFisico()
{
}

int LibroFisico::getNroEj()
{
	return nroEj;
}

string LibroFisico::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"fisico\",\"codigo\":"<<codigo<<",\"titulo\":\""<<titulo<<"\",\"autor\":\""<<autor<<"\",\"ejemplares\":"<<nroEj<<"}";
	return ss.str();
}
