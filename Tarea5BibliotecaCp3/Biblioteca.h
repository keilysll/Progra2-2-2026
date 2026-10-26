#pragma once
#include"Libro.h"
#include"LibroDigital.h"
#include"LibroFisico.h"
#include"ModGenerico.h"
#include"Prestamo.h"
#include"PrestamoRenovado.h"
#include"PrestamoSimple.h"
#include"Socio.h"
#include"SingletonSocios.h"

class Biblioteca
{
private:
	ModGenerico<Libro>libros;
	ModGenerico<Prestamo> prestamos;

public:
	Biblioteca();
	~Biblioteca();
	bool operator<<(Libro* l);
	Libro* operator[](int i);
	string toString();
	void registrarPrestamoSimple(int id,int codLib,int ciSocio,int fechIni, int fechDev);
	void registrarPrestamoRenovado(int id, int codLib, int ciSocio, int fechIni, int fechDev,int nuevaFec, string motivo);
	string libroMasPrestado();
	int periodoMaximo();

};

