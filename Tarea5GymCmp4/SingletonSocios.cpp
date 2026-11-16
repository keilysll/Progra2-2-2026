#include "SingletonSocios.h"
SingletonSocios::SingletonSocios()
{
}
SingletonSocios::~SingletonSocios()
{
}

SingletonSocios& SingletonSocios::getInst()
{
	static SingletonSocios inst;
	return inst;
}

ListaEnlazada<Socio>* SingletonSocios::getSocios()
{
	return &socios;
}

string SingletonSocios::toString()
{
	socios.ordenar(Socio::ordenarNombreAs);
	stringstream ss;
	ss << "{\"socios\":"<<socios.toJson(Socio::toStringPtr)<<"}";
	return ss.str();
}

