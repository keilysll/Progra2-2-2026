#include "Telefonica.h"

Telefonica::Telefonica(string nombre, string direccion)
{
	this->nombre = nombre;
	this->direccion = direccion;
}

Telefonica::~Telefonica()
{
}

string Telefonica::getNombre()
{
	return nombre;
}

string Telefonica::getDicc()
{
	return direccion;
}

void Telefonica::registrarCliente(string nombre, int saldo)
{
	clientes.registrar(new Usuario(nombre, saldo));
}

void Telefonica::registrarPaquete(string nombre, Paquete* p)
{
	Usuario* u = clientes.buscar(new Usuario(nombre));
	u->registrarPaquete(p);
}

void Telefonica::registrarLlamada(string nombre, int id, int fecha, int duracion)
{
	Usuario* u = clientes.buscar(new Usuario(nombre));
	u->ejecutarAccion(new Llamada(id, fecha, duracion));

}

void Telefonica::registrarSMS(string nombre, int id, int fecha, int megas)
{
	Usuario* u = clientes.buscar(new Usuario(nombre));
	u->ejecutarAccion(new Descarga(id, megas, fecha));
}

string Telefonica::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"dirreccion\":\""<<direccion<<"\",\"clientes\":"<<clientes.toJson(Usuario::toJsonPtr)<<"}";
	return ss.str();
}
