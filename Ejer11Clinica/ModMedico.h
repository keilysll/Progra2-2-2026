#pragma once
#include"Medico.h"
#include"MedicoEspecialista.h"
#include"MedicoGeneral.h"
class ModMedico
{
private:
	Medico** medicos;
	int tam;
	int ind;
public:
	ModMedico(int tam);
	~ModMedico();
	int getTam();
	int getInd();
	void registrar(Medico* m);
	Medico* buscar(string nombre);
	string toJson();
	int totalIngresos();
	Medico* medicoConMasIngresos();
};

