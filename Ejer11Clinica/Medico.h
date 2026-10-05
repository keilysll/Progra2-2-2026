#pragma once
using namespace std;
#include<iostream>
#include<sstream>
#include<string>
#include"ModConsulta.h"
class Medico
{
protected:
	string nombre;
	ModConsulta consultas;
public:
	Medico(string nombre);
	~Medico();
	string getNombre();
	ModConsulta& getConsultas();
	void registrar(Consulta* c);
	virtual string toJson() = 0;
	int ingreso();
};

