#pragma once
#include"Modelo.h"
#include"ModeloChat.h"
#include"ModeloCodigo.h"
class ModModelo
{
private:
	Modelo** modelos;
	int tam;
	int ind;
public:
	ModModelo(int tam);
	~ModModelo();
	int getTam();
	int getInd();
	void registrar(Modelo* m);
	Modelo* buscar(string nombre);
	string toJson();
};

