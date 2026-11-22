#include "Tarifario.h"
Tarifario::Tarifario()
{
	materiales = new Registro<Material>();
}
Tarifario::~Tarifario()
{
	delete materiales;
}

Tarifario& Tarifario::getInst()
{
	static Tarifario inst;
	return inst;
}

void Tarifario::registrar(Material* m)
{
	materiales->agregar(m);
}

void Tarifario::limpiar()
{
	delete materiales;      
	materiales = new Registro<Material>();
}

string Tarifario::toJson()
{
	stringstream ss;
	ss << "{\"materiales\":" + materiales->toJson() + "}";;
	return ss.str();
}

Material* Tarifario::buscar(string nombre)
{
	return materiales->buscar(nombre);
}


