#include "Taller.h"

Taller::Taller():clientes(10),servicios(10),reservas(10)
{
}

Taller::~Taller()
{
}

ModCliente& Taller::getClientes()
{
    return clientes;
}

ModServicio& Taller::getServicios()
{
    return servicios;
}

void Taller::registrar(Cliente* c)
{
    clientes.registrar(c);
}

void Taller::registrarServicio(Servicio* s)
{
    servicios.registrar(s);
}

void Taller::registrar(int ci, Vehiculo* v)
{
    Cliente* c = clientes.buscar(ci);
    if (c != NULL)
    {
        c->registrar(v);
    }
}


void Taller::registrarReserva(int id, int codigoSer, int ci, string placa)
{
    Cliente* c = clientes.buscar(ci);
    Servicio* s = servicios.buscar(codigoSer);
    Vehiculo* v = c->buscar(placa);

    ReservaSimple* r = new ReservaSimple(id, s, c, v);
    reservas.registrar(r);
}

void Taller::registrarReserva(int id, int codigoSer1, int codigoSer2, int ci, string placa)
{
    Cliente* c = clientes.buscar(ci);
    Servicio* s1 = servicios.buscar(codigoSer1);
    Servicio* s2 = servicios.buscar(codigoSer2);
    Vehiculo* v = c->buscar(placa);

    ReservaCombo* rc = new ReservaCombo(id, s1, s2, c, v);
    reservas.registrar(rc);
}

string Taller::toJson()
{
    stringstream ss;
    ss << "{\"clientes\":"<<clientes.toJson()<<",\"servicios\":"<<servicios.toJson()<<",\"reservas\":"<<reservas.toJson()<<"}";
    return ss.str();
}
