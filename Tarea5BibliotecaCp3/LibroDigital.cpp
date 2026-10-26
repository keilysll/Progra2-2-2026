#include "LibroDigital.h"

LibroDigital::LibroDigital(int codigo) :Libro(codigo," ", " ")
{
}

LibroDigital::LibroDigital(int codigo, string titulo, string autor, int tamMb):Libro(codigo,titulo,autor)
{
	this->tamMB = tamMb;
}

LibroDigital::~LibroDigital()
{
}

int LibroDigital::getTam()
{
	return tamMB;
}

string LibroDigital::toString()
{
	stringstream ss;
	ss <<"{\"tipo\":\"digital\",\"codigo\":"<<codigo<<",\"titulo\":\""<<titulo<<"\",\"autor\":\""<<autor<<"\",\"tamanioMB\":"<<tamMB<<"}";
	return ss.str();
}
