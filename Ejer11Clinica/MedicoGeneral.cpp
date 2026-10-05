#include "MedicoGeneral.h"

MedicoGeneral::MedicoGeneral(string nombre, string turno):Medico(nombre)
{
	this->turno = turno;
}

MedicoGeneral::~MedicoGeneral()
{
}

string MedicoGeneral::getTurno()
{
	return turno;
}

string MedicoGeneral::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"turno\":\""<<turno<<"\",\"consultas\":"<<consultas.toJson()<<"}";
	return ss.str();
}
