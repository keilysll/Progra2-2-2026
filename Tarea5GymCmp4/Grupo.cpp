#include "Grupo.h"

Grupo::Grupo(string id)
{
	this->id= id;
}

Grupo::~Grupo()
{
}

void Grupo::inscribir(int ci)
{
	Socio* s= SingletonSocios::getInst().getSocios()->buscar(new Socio(ci));
	inscritos.registrar(s);
}

string Grupo::toString()
{
	stringstream ss;
	ss << "{\"id\":\"" << id << "\",\"inscritos\":"<<inscritos.toJson(Socio::toStringPtr)<<"}";
	return ss.str();
}

string Grupo::toStringPtr(Grupo* g)
{
	return g->toString();
}
