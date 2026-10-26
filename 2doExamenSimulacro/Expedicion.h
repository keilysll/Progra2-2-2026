#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include"ListaArray.h"
#include"Criatura.h"
#include"Equipo.h"
#include"Muestra.h"
#include"Biologica.h"
#include"Energetica.h"
#include"Mistica.h"
#include"Terrestre.h"
using namespace std;
class Expedicion
{
private:
	int id;
	Criatura* criatura;
	Equipo* equipo;
	ListaArray<Muestra> muestras;
public:
	Expedicion(int id);
	Expedicion(int id, Criatura* criatura, Equipo* equipo);
	~Expedicion();
	int getId();
	double capacidadUsadaKg();
	int energiaUsada();
	int valorCientifico();
	bool operator<<(Muestra* m);
	bool operator==(Expedicion* e);
	string toString();
	static string toStringPtr(Expedicion* e);
	static bool OrdenarPorId(Expedicion* a, Expedicion* b);
	Criatura* getCriatura();
	string detalleToString();
	static string detalleToStringPtr(Expedicion* e);
};