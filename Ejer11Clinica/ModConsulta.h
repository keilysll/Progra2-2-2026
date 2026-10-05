#pragma once
#include"Consulta.h"
#include"ConsultaPresencial.h"
#include"ConsultaVirtual.h"
class ModConsulta
{
private:
	Consulta** consultas;
	int tam;
	int ind;
public:
	ModConsulta(int tam);
	~ModConsulta();
	int getTam();
	int getInd();
	void registrar(Consulta* c);
	Consulta* buscar(string paciente);
	int totalIngresos();
	string toJson();
};

