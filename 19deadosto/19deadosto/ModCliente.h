#pragma once
#include"Cliente.h"
class ModCliente
{
private:
	Cliente** clientes;
	int tam;
	int ind;
public:
	ModCliente(int tamMax);
	~ModCliente();
	void registrar(Cliente* c);
	Cliente* buscar(int ci);
	void mostrar();


};

