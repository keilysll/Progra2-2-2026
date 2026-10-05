#pragma once
#include"ModModelo.h"
class Proyecto
{
protected:
	string nombre;
	ModModelo modelos;
public:
	Proyecto(string nombre);
	~Proyecto();
	string getNombre();
	ModModelo& getModelos();
	void asignar(Modelo* m);
	virtual string toJson() = 0;
};

