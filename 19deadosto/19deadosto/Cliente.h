#pragma once

#include <iostream>
#include <string>
using namespace std;

class Cliente
{
// Atributos
private:
	int ci;
	string nombre;
	int fono;
//Metodos
public:
	Cliente();// cosntructor po defecto
	Cliente(int ci, string nombre, int fono);// constructor sobre cargado
	~Cliente();// destructor

	//GETS
	int getCi();
	string getNombre();
	int getFono();
	// SETS
	void setCi(int ci);
	void serNombre(string nombre);
	void setFono(int fono);
	//OTROS 
	void mostrar();

};

