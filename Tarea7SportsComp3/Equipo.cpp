#include "Equipo.h"

Equipo::Equipo(string nombre, string region):jugadores(10)
{
	this->nombre = nombre;
	this->region = region;
}

Equipo::~Equipo()
{
}

bool Equipo::operator+=(int id)
{
	Jugador* j = SingletonJugadores::getInst().buscar(id);
	Pro* p = dynamic_cast<Pro*>(j);
	if (p == NULL)
	{
		return false;
	}
	jugadores.registrar(p);
	return true;
}

Jugador* Equipo::operator[](int i)
{
	return jugadores.operator[](i);
}

string Equipo::toString()
{
	stringstream ss;
	ss <<"{\"nombre\":\""<<nombre<<"\",\"region\":\""<<region<<"\",\"jugadores\":"<<jugadores.toJson(Jugador::toStringPtr)<<"}";
	return ss.str();
}
