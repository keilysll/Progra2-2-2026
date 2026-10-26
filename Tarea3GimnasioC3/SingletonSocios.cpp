#include "SingletonSocios.h"

SingletonSocios::~SingletonSocios()
{
}

SingletonSocios::SingletonSocios():socios(10)
{
}
SingletonSocios& SingletonSocios::getInst()
{
	static SingletonSocios inst;
	return inst;
}

ListaArray<Socio>* SingletonSocios::getSocios()
{
	return &socios;
}

string SingletonSocios::toString()
{
	socios.ordenar(Socio::OrdenarSociNom);
	stringstream ss;
	ss << "{\"socios\":"<<socios.toJson(Socio::toStringPtr)<<"}";
	return ss.str();
}


