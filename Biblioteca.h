#pragma once
#include"Material.h"
#include"Revista.h"
#include"Libro.h"
#include"ListaEnlazada.h"
class Biblioteca
{
private:
	string nombre;
	ListaEnlazada<Material> materiales;
	double totalMultas;
public:
	Biblioteca(string nombre);
	~Biblioteca();
	void operator+=(Material* m);
	string toJson();
	int prestar(string codigo, int diasUsados);
	double getTotalMultas();
	int detalleLibro(string codigo);

};

