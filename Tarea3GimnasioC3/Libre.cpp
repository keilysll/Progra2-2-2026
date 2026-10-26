#include "Libre.h"

Libre::Libre(string id):Grupo(id)
{
}

Libre::~Libre()
{
}

string Libre::toString()
{
	stringstream ss;
	ss << "{\"id\":\"" << id << "\",\"inscritos\":" << inscritos.toJson(Socio::toStringPtr) << "}";
	return ss.str();
}
