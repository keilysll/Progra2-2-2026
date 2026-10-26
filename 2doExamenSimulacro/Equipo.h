#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include"Investigador.h"
#include"ListaArray.h"
#include"SingletonInvestigadores.h"
using namespace std;


class Equipo
{
private:
	string nombre;
	int capac;
	int seguridad;
	ListaArray<Investigador> investigadores;
public:
	Equipo(string nombre,int capac, int seguridad);
	~Equipo();
	string getNombre();
	int getCapc();
	int getSeguridad();
	bool operator+= (int codigo);
	Investigador* operator[](int i);
	string toString();
	bool operator==(Equipo* e);
};

