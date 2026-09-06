#pragma once
#include"ModElector.h"
#include"ModMesaAsignada.h"
#include"ModRecintoAsignado.h"
#define CANT_MAXELECTORES_ELECCION 10
#define CANT_MAXRECINTOS_ELECCION 10
#define CANT_MAXMESAS_ELECCION 10


class Eleccion
{
private:
	int codigo;
	string descrip;
	string fecha;
	ModElector electores;
	ModRecintoAsignado recintos;
	ModMesaAsignada mesas;

public:
	Eleccion(int codigo,string descrip,string fecha);
	~Eleccion();
	int getCodigo();

	void agregarElector(Elector* e);
	void agregarRecinto(RecintoAsignado* r);
	void agregarMesaArecinto(Mesa* mesa, int nro,int codigoRecinto);


	RecintoAsignado* buscarRecintoAsignado(int codigo);
	string getDescrip();
	string getFecha();
	void setCodigo(int codigo);
	void setDescrip(string descrip);
	void setFecha(string fecha);
	string toJson();

};

