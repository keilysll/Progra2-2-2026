#include "Pro.h"

Pro::Pro(int id) :Jugador(id," "," ")
{
	this->id = id;
}
Pro::Pro(int id, string nick, string pais, int ranking, int salario):Jugador(id,nick,pais)

{
	this->ranking = ranking;
	this->salario = salario;

}

Pro::~Pro()
{
}

int Pro::getRank()
{
	return ranking;
}

int Pro::getSalario()
{
	return salario;
}

string Pro::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"pro\",\"id\":"<<id<<",\"nickname\":\""<<nick<<"\",\"pais\":\""<<pais<<"\",\"ranking\":"<<ranking<<",\"salario\":"<<salario<<"}";
	return ss.str();
}


