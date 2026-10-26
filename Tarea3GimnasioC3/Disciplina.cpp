#include "Disciplina.h"

Disciplina::Disciplina(string nombre):grupos(10)
{
	this->nombre = nombre;
}

Disciplina::~Disciplina()
{
}

string Disciplina::getNombre()
{
	return nombre;
}

ListaArray<Grupo>* Disciplina::getGrupos()
{
	return &grupos;
}

string Disciplina::toString()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"grupos\":"<<grupos.toJson(Grupo::toStringPtr)<<"}";
	return ss.str();
}
