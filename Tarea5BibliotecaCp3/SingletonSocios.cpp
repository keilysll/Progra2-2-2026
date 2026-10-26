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

bool SingletonSocios::operator<<(Socio* s)
{
	if (!s)
	{
		return false;
	}

	socios.registrar(s);
	return true;
	
}

string SingletonSocios::toString()
{
	socios.ordenar(Socio::ordenarNomSoc);
	stringstream ss;
	ss <<socios.toString(Socio::toStringPtr);
	return ss.str();
}

Socio* SingletonSocios::buscar(int ci)
{
	return socios.buscar(new Socio(ci));
}
