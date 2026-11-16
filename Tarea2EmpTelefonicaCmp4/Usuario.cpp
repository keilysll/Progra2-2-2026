#include "Usuario.h"

Usuario::Usuario(string nombre, int saldo)
{
	this->nombre = nombre;
	this->saldo = saldo;
}

Usuario::Usuario(string nombre)
{
	this->nombre = nombre;
}

Usuario::~Usuario()
{
}

string Usuario::getNombre()
{
	return nombre;
}

int Usuario::getSaldo()
{
	return saldo;
}

Usuario& Usuario::getPaquetes()
{
	return *this;
}

void Usuario::registrar(Paquete* p)
{
	paquetes.registrar(p);
}

void Usuario::ejecutarAccion(Detalle* d)
{
	int total = saldo;
	for (int i = 0; i < paquetes.getTam(); i++)
		total = total + d->disponible(paquetes[i]);
	if(total < d->getCantidad())
		throw exception(("saldo insuficiente " + nombre + " no pudo realizar "+ d->getTipo() + " " + to_string(d->getId())).c_str());



	int pendiente = d->getCantidad();
	for (int i = 0; i < paquetes.getTam() && pendiente>0; i++)
	{
		pendiente = pendiente - d->consumir(paquetes[i],pendiente);
	}
	if (pendiente > 0)
		saldo = saldo - pendiente;
	detalles.registrar(d);

	
}

void Usuario::registrarPaquete(Paquete* p)
{
	paquetes.registrar(p);
}

string Usuario::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"saldo\":"<<saldo<<",\"paquetes\":"<<paquetes.toJson(Paquete::toJsonPtr)<<",\"detalle\":"<<detalles.toJson(Detalle::toJsonPtr)<<"}";
	return ss.str();
}

bool Usuario::operator==(Usuario* u)
{
	return nombre == u->nombre;
}

string Usuario::toJsonPtr(Usuario* u)
{
	return u->toJson();
}


