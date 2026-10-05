#include "MedicoEspecialista.h"

MedicoEspecialista::MedicoEspecialista(string nombre, string especialidad):Medico(nombre)
{
	this->especialidad = especialidad;
}

MedicoEspecialista::~MedicoEspecialista()
{
}

string MedicoEspecialista::getEspe()
{
	return especialidad;
}

string MedicoEspecialista::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"especialidad\":\""<<especialidad<<"\",\"consultas\":"<<consultas.toJson()<<"}";
	return ss.str();
}
