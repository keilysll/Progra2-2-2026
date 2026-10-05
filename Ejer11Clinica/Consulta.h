#pragma once
using namespace std;
#include<iostream>
#include<sstream>
#include<string>
class Consulta
{
protected:
	string paciente;
	int costo;
public:
	Consulta(string paciente,int costo);
	~Consulta();
	string getPaciente();
	int getCosto();
	virtual int ingreso() = 0;
	virtual string toJson() = 0;
};

