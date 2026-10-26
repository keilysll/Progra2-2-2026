#include "Sesion.h"

Sesion::Sesion(int id, Cargador* cargador, Vehiculo* vehiculo, int kwh)
{
	this->id = id;
	this->cargador = cargador;
	this->vehiculo = vehiculo;
	this->kwh = kwh;
}

Sesion::~Sesion()
{
}

int Sesion::getId()
{ 
	return id; 
}
int Sesion::getKwh() 
{ 
	return kwh; 
}
Cargador* Sesion::getCargador() { return cargador; }
Vehiculo* Sesion::getVehiculo() { return vehiculo; }

int Sesion::getCosto()
{
	return kwh * cargador->getCosto();
}

string Sesion::toString()
{
	stringstream ss;
	ss << "{\"id\":" << id << ",\"cargador\":\"" << cargador->getCodigo()
		<< "\",\"placa\":\"" << vehiculo->getPlaca()
		<< "\",\"kwh\":" << kwh << ",\"costo\":" << getCosto() << "}";
	return ss.str();
}

// ListaArray::ordenar intercambia cuando devuelve true -> ">" deja orden ascendente
bool Sesion::CmpCostoAsc(Sesion* s1, Sesion* s2)
{
	return s1->getCosto() > s2->getCosto();
}

string Sesion::toStringPtr(Sesion* s)
{
	return s->toString();
}