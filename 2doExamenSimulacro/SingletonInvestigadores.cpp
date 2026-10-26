#include "SingletonInvestigadores.h"

SingletonInvestigadores::~SingletonInvestigadores()
{
}
SingletonInvestigadores::SingletonInvestigadores():investigadores(10)
{
}

SingletonInvestigadores& SingletonInvestigadores::getInst()
{
	static SingletonInvestigadores inst;
	return inst;
}

bool SingletonInvestigadores::operator<<(Investigador* i)
{
	if (!i)
	{
		return false;
	}
	investigadores.registrar(i);
	return true;
}

Investigador* SingletonInvestigadores::operator[](int codigo)
{
	Investigador* i = investigadores.buscar(new Investigador(codigo));
	return i;
}
