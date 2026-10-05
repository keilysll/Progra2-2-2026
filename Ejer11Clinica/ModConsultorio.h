#pragma once
#include"Consultorio.h"
class ModConsultorio
{
private:
	Consultorio** consultorios;
	int tam;
	int ind;
public:
	ModConsultorio(int tam);
	~ModConsultorio();
	int getTam();
	int getInd();
	void registrar(Consultorio* c);
	Consultorio* buscar(int nro);
	string toJson();
	int totalIngresos();
	Medico* medicoConMasIngresos();

};

