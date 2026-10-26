#include "SingletonJugadores.h"
SingletonJugadores::SingletonJugadores():jugadores(10)
{
}

SingletonJugadores::~SingletonJugadores()
{
}

SingletonJugadores& SingletonJugadores::getInst()
{
	static SingletonJugadores inst;
	return inst;
}

bool SingletonJugadores::operator+=(Amateur* a)
{
	if (!a)
	{
		return false;

	}
     jugadores.registrar(a);
	 return true;
}

bool SingletonJugadores::operator+=(Pro* p)
{
	if (!p)
	{
		return false;

	}
	jugadores.registrar(p);
	return true;
}

Jugador* SingletonJugadores::buscar(int id)
{
	Jugador* j = jugadores.buscar(new Amateur(id));

	return j;
}

	
