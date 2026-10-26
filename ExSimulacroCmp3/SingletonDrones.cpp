#include "SingletonDrones.h"
SingletonDrones::SingletonDrones():drones(10)
{
}
SingletonDrones::~SingletonDrones()
{
	
}

SingletonDrones& SingletonDrones::getInst()
{
	static SingletonDrones inst;
	return inst;
}

bool SingletonDrones::operator<<(Dron* d)
{
	if (!d)
	{
		return false;
	}
	drones.registrar(d);
		return true;
}

string SingletonDrones::toString()
{
	drones.ordenar(Dron::CmpDesc);
	stringstream ss;
	ss <<drones.toString(Dron::toStringPtr);
	return ss.str();
}

Dron* SingletonDrones::operator[](int id)
{
	Dron* dr = drones.buscar(new Vigilancia(id));
	return dr;
}
