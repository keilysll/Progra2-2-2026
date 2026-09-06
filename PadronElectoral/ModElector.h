#pragma once
#include"Elector.h"
class ModElector
{
private:
	Elector** electores;
	int tam;
	int ind;
public:
	ModElector(int tam);
	~ModElector();
	void registrar(Elector* e);
	Elector* buscar(int ci);
	int getInd();
	int getTam();
	string toJson();
};

