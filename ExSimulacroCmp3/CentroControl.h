#pragma once
#include"Dron.h"
#include"Delivery.h"
#include"Vigilancia.h"
#include"ModGenerico.h"
#include"Mision.h"
#include"MisionEntrega.h"
#include"MisionVigilancia.h"
class CentroControl
{
private:
	string nombre;
	string ciudad;
	ModGenerico<Dron> drones;
	ModGenerico<Mision> misiones;
public:
	CentroControl(string nombre,string ciudad);
	~CentroControl();
	string getNombre();
	string getCiudad();
	bool operator+= (Dron* d);
	bool asignar(Mision* m);
	Dron* operator[](int i);
	string dronMasUsado();
	int duracionMaxima();
	double pesoTotalEntregado();
	double areaTotalVigilada();
	string toString();
};

