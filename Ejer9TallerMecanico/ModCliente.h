#pragma once
#include"Cliente.h"
class ModCliente
{
private:
	Cliente** clientes;
	int tam;
	int ind;
public:
	ModCliente(int tam);
	~ModCliente();
	int getTam();
	int getInd();
	void registrar(Cliente* c);
	Cliente* buscar(int ci);
	void ordenar();
	string toJson();
};

