#pragma once
#include"Material.h"
#include"MaterialPeso.h"
#include"MaterialUnidad.h"
#include"Registro.h"
class Tarifario
{
private:
	Registro<Material>* materiales;
public:
	~Tarifario();
	static Tarifario& getInst();
	void registrar(Material* m);
	void limpiar();
	string toJson();
	Material* buscar(string nombre);
private:
	Tarifario();

};

