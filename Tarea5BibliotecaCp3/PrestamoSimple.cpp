#include "PrestamoSimple.h"

PrestamoSimple::PrestamoSimple(int id, Libro* l, Socio* s, int fechaIni, int fechaDev):Prestamo(id,l,s,fechaIni,fechaDev)
{

}

PrestamoSimple::~PrestamoSimple()
{
}

string PrestamoSimple::toString()
{
	stringstream ss;
	ss << "{\"PrestamoSimple\":{\"id\":" << id << ",\"socio\":" << s->toString() << ",\"libro\":" << l->toString() << ",\"fechaInicio\":" << fechaIni << ",\"fechaDevolucion\":" << fechaDev << "}}";
	return ss.str();
}
