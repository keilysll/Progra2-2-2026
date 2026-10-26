#pragma once
#include"Grupo.h"
#include"ListaArray.h"
class Disciplina
{
private:
	string nombre;
	ListaArray<Grupo> grupos;
public:
	Disciplina(string nombre);
	~Disciplina();
	string getNombre();
	ListaArray<Grupo>* getGrupos();
	string toString();
};

