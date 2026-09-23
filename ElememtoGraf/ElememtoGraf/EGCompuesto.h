#pragma once
#include"ElementoGrafico.h"
#define TAMAX 10
class EGCompuesto: public ElementoGrafico
{
private:

	ElementoGrafico** elementos;
	int ind;

public:
	EGCompuesto(int ind);
	~EGCompuesto();
	void dibujar();
	void borrar();
	void agregar(ElementoGrafico * e);
	void eliminar();


};
