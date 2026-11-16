#pragma once
#include"ListaEnlazada.h"
#include"Grupo.h"
class Disciplina
{
private:
	string nombre;
	ListaEnlazada<Grupo> grupos;
public:
	Disciplina(string nombre);
	~Disciplina();
	string getNombre();
	ListaEnlazada<Grupo>* getGrupos();
	void registrar(Grupo* g);
	string toString();
};

