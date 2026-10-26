#include "Equipo.h"

Equipo::Equipo(string nombre, int capac, int seguridad):investigadores(10)
{
	this->nombre = nombre;
	this->capac = capac;
	this->seguridad = seguridad;
}

Equipo::~Equipo()
{
}

string Equipo::getNombre()
{
	return nombre;
}

int Equipo::getCapc()
{
	return capac;
}

int Equipo::getSeguridad()
{
	return seguridad;
}


bool Equipo::operator+=(int codigo)
{
	Investigador* i = SingletonInvestigadores::getInst()[codigo];
	if (i && !investigadores.buscar(i))
	{
		investigadores.registrar(i);
		return true;
	}
	return false;
}

Investigador* Equipo::operator[](int i)
{
	return investigadores.operator[](i);
}

string Equipo::toString()
{
	investigadores.ordenar(Investigador::OrdenarPorNombre);
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"capacidadKg\":" << capac << ",\"nivelSeguridad\":" << seguridad << ",""\"investigadores\":" << investigadores.toString(Investigador::toStringPtr) << "}";
	return ss.str();
}

bool Equipo::operator==(Equipo* e)
{
	return  nombre == e->nombre;
}
