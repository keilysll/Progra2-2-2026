#pragma once
#include"ModMedico.h"
class Consultorio
{
private:
	int nro;
	ModMedico medicos;

public:
	Consultorio(int nro);
	~Consultorio();
	int getNro();
	ModMedico& getMedicos();
	void registrar(Medico* m);
	Medico* buscarMed(string nombre);
	string toJson();
	int totalIngresos();
	Medico* medicoConMasIngresos();


};

