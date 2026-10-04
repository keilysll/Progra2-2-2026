#pragma once
#include"Persona.h"
class ModPersona
{
private:
	Persona** personas;
	int tam;
	int ind;
public:
	ModPersona(int tam);
	~ModPersona();
	int getTam();
	int getInd();
	void registrar(Persona* p);
	Persona* buscar(int ci);
	void ordenar();
	string toJson();
};
