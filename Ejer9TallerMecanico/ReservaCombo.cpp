#include "ReservaCombo.h"

ReservaCombo::ReservaCombo(int id, Servicio* s1, Servicio* s2, Cliente* c, Vehiculo* v):Reserva(id)
{
	this->servicio1 = s1;
	this->servicio2 = s2;
	this->cliente = c;
	this->vehiculo = v;
}

ReservaCombo::~ReservaCombo()
{
}

string ReservaCombo::toJson()
{
	stringstream ss;
	ss << "{\"ReservaCombo\":{\"id\":"<<id<<",\"cliente\":{\"ci\":"<<cliente->getCi()<<",\"nombre\":\""<<cliente->getNombre()<<"\",\"fono\":"<<cliente->getFono()<<"},\"vehiculo\":"<<vehiculo->toJson()<<"},\"atencion1\":"<<servicio1->toJson()<<",\"atencion2\":"<<servicio2->toJson()<<"}";
	
	return ss.str();
}
