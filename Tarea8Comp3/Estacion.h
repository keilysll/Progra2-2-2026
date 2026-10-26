#pragma once
#include"Cargador.h"
#include"CargadorRapido.h"
#include"CargadorLento.h"
#include"ListaArray.h"
#include"Vehiculo.h"
#include"SingletonVehiculos.h"
#include"Sesion.h"
class Estacion
{
private:
	string nombre;
	string zona;
	ListaArray<Cargador> cargadores;
	ListaArray<Sesion> sesiones;
public:
	Estacion(string nombre, string zona);
	~Estacion();
	bool operator+=(Cargador* c);
	Cargador* operator[](int i);
	bool cargar(int id,string codCarg,string placa, int km);
	string toString();
	int recaudacionTotal();
	int energiaRapida();
	string vehiculoQueMasCargo();
};

