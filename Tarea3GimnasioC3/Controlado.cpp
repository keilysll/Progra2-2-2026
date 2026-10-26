#include "Controlado.h"

Controlado::Controlado(string id):Grupo(id)
{
}

Controlado::~Controlado()
{
}

string Controlado::toString()
{
	stringstream ss;
	ss << "{\"id\":\"" << id << "\",\"inscritos\":" << inscritos.toJson(Socio::toStringPtr);
	if (sesiones.getInd() > 0)
	{
		ss << ",\"sesiones\":" << sesiones.toJson(Sesion::toStringPtr);
	}
	ss << "}";
	return ss.str();
}

void Controlado::registrarAsistente(int ci, int fecha)
{
	Socio* a= inscritos.buscar(new Socio(ci));
	Sesion* s = sesiones.buscar(new Sesion(fecha));
	if (a != NULL && s != NULL)
	{
		s->registrarAsistente(a);
	}
}
