#pragma once
#include"Entrega.h"
#include"Registro.h"
#include"EntregaPeso.h"
#include"EntregaUnidad.h"
#include"Tarifario.h"
class Participantes
{
protected:
	string nombre;
	int puntos;
	Registro<Entrega>entregas;

public:
	Participantes(string nombre);
	~Participantes();
	string getNombre();
	int getPuntos();
	virtual string toJson() = 0;
	virtual void entregar(Entrega* e) = 0;
	void canjear(int pts);
	string getClave() const;   
	int totalOtorgado();
	int totalGramos();
	

};

