#pragma once
#include"Libro.h"
#include"Socio.h"
class Prestamo
{
protected:
	int id;
	Libro* l;
	Socio* s;
	int fechaIni;
	int fechaDev;
public:
	Prestamo(int id,Libro* l,Socio* s, int fechaIni,int fechaDev);
	~Prestamo();
	int getId();
	int getfechaIni();
	int getfechaDev();
	Libro* getLibro();
	static string toStringPtr(Prestamo * p);
	static bool OrdenarFechDevPres(Prestamo * p1, Prestamo* p2);
	virtual string toString() = 0;
};

