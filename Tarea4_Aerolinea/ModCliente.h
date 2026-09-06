#pragma once
#include"Cliente.h"
class ModCliente
{
private:
	int tam;
	int ind;
	Cliente** clientes;
public:
	ModCliente(int tam);
	~ModCliente();
	int getTam();
	int getInd();
	void registrar(Cliente* c);
	Cliente* buscar(int ci);
	string toJson();

};

