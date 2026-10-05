#pragma once
#include"ModConsultorio.h"
class Clinica
{
private:
	string nombre;
	string direccion;
	ModConsultorio consultorios;
public:
	Clinica(string nombre,string direccion);
	~Clinica();
	string getNombre();
	string getDirecc();
	ModConsultorio& getConsult();
	void registrarConsultorio(int nroConsul);
	void registrarMedicoEnConsultorio(int nroConsul,Medico* m);
	void registrarConsultaEnMedico(int nroConsul, string nomMedic,Consulta* c);
	string toJson();
	int totalIngresos();
	string medicoConMasIngresos();
};

