#include "Amateur.h"

Amateur::Amateur(int id) :Jugador(id, " ", " ")
{
	this->id = id;
}

Amateur::Amateur(int id, string nick, string pais, string nivel):Jugador(id,nick,pais)
{
	this->nivel = nivel;
}

Amateur::~Amateur()
{
}

string Amateur::getNivel()
{
	return nivel;
}

string Amateur::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"amateur\",\"id\":"<<id<<",\"nickname\":\""<<nick<<"\",\"pais\":\""<<pais<<"\",\"nivel\":\""<<nivel<<"\"}";
	return ss.str();
}
