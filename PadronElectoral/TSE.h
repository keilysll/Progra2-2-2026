#pragma once
#include"ModElector.h"
#include"ModMesa.h"
#include"ModRecinto.h"
#include"ModEleccion.h"
class TSE
{
private:
	string nombre;
	ModElector electores;
	ModMesa mesas;
	ModRecinto recintos;
	ModEleccion elecciones;

public:
	TSE(string nombre,int CanMaxElecto,int CantMaxMesas, int CantMaxRecin, int CantMaxElec);
	~TSE();
	string getNombre();
	ModElector& getElector();
	ModMesa& getMesa();
	ModRecinto& getRecinto();
	ModEleccion& getEleccion();

	void agregarElectorAeleccion(int ci, int codigo);
	void agregarRecintoAeleccion(int cod, int codigo);

	void agregarMesaArecintoAsignado(int codMesa, int nro,int codRecinto,int codEleccion);

	void agregarElectorAmesa(int ci, int nro, int codRecinto, int codEleccion);
	void asignarJuradoMesa(int ci, int nro, int codRecinto, int codEleccion);
	string toJson();
};

