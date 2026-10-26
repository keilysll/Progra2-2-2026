#include "PrestamoRenovado.h"

PrestamoRenovado::PrestamoRenovado(int id, Libro* l, Socio* s, int fechaIni, int fechaDev, int nuevaFech, string motivo):Prestamo(id,l,s,fechaIni,fechaDev)
{
	this->nuevaFech = nuevaFech;
	this-> motivo = motivo;

}

PrestamoRenovado::~PrestamoRenovado()
{
}

int PrestamoRenovado::getnuevaFech()
{
	return nuevaFech;
}

string PrestamoRenovado::getMotivo()
{
	return motivo;
}

string PrestamoRenovado::toString()
{
	stringstream ss;
	ss << "{\"PrestamoRenovado\":{\"id\":" << id << ",\"socio\":" << s->toString() << ",\"libro\":" << l->toString() << ",\"fechaInicio\":" << fechaIni << ",\"fechaDevolucion\":" << fechaDev << "},\"nuevaFecha\":" << nuevaFech << ",\"motivo\":\"" << motivo << "\"}";
	return ss.str();
}
