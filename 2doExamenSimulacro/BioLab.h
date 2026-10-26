#pragma once
#include"ListaArray.h"
#include"Criatura.h"
#include"Mistica.h"
#include"Terrestre.h"
#include"Equipo.h"
#include"Expedicion.h"
#include"Biologica.h"
#include"Energetica.h"
class BioLab
{
private:
	ListaArray<Criatura> criaturas;
	ListaArray<Equipo> equipos;
	ListaArray<Expedicion> expediciones;
public:
	BioLab();
	~BioLab();
	bool registrarCriatura(Criatura* c);
	bool registrarEquipo(Equipo* e);
	bool crearExpedicion(int id, int codigoCriatura, string nombreEquipo);
	Expedicion& operator[](int id);
	string expedicionesToString();
	string criaturaMasInvestigada();
	int expedicionMayorValor();
	int energiaMagicaTotal();
	string generarInforme();
};