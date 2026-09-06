#pragma once
#include"Mesa.h"
class ModMesa
{
private:
	Mesa** mesas;
	int tam;
	int ind;
public:
	ModMesa(int tam);
	~ModMesa();
	void registrar(Mesa* m);
	Mesa* buscar(int codigo);
	int getInd();
	int getTam();
	string toJson();
};

