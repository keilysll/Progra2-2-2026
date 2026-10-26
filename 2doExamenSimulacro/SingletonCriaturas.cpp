#include "SingletonCriaturas.h"

SingletonCriaturas::~SingletonCriaturas()
{
}
SingletonCriaturas::SingletonCriaturas():criaturas(10)
{
}

SingletonCriaturas& SingletonCriaturas::getInst()
{
	static SingletonCriaturas inst;
	return inst;
}

bool SingletonCriaturas::operator<<(Criatura* c)
{
	if (!c)
	{
		return false;
	}
	criaturas.registrar(c);
	return true;
}

Criatura* SingletonCriaturas::operator[](int id)
{
	Criatura* c = criaturas.buscar(new Terrestre(id));
	return c;
}

string SingletonCriaturas::toString()
{
	criaturas.ordenar(Criatura::OrdenarDesPeli);
	stringstream ss;
	ss << criaturas.toString(Criatura::toStringPtr);
	return ss.str();
}
