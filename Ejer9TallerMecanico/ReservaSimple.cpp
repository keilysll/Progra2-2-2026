#include "ReservaSimple.h"

ReservaSimple::ReservaSimple(int id, Servicio* s, Cliente* c, Vehiculo* v) :Reserva(id)
{
	this->cliente = c;
	this->vehiculo = v;
	this->servicio = s;
}

ReservaSimple::~ReservaSimple()
{
}

string ReservaSimple::toJson()
{
	stringstream ss;
	ss << "{\"ReservaSimple\":{\"id\":" << id << ",\"cliente\":{\"ci\":"<<cliente->getCi()<<",\"nombre\":\""<<cliente->getNombre()<<"\",\"fono\":"<<cliente->getFono()<<"},\"vehiculo\":"<<vehiculo->toJson()<<"},\"atencion\":"<<servicio->toJson()<<"}";
	return ss.str();
}
