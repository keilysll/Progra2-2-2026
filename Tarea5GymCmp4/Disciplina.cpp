#include "Disciplina.h"

Disciplina::Disciplina(string nombre)
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

ListaEnlazada<Grupo>* Disciplina::getGrupos()
{
	return &grupos;
}

void Disciplina::registrar(Grupo* g)
{
	grupos.registrar(g);
}

string Disciplina::toString()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"grupos\":"<<grupos.toJson(Grupo::toStringPtr)<<"}";
	return ss.str();
}

