#include "Eleccion.h"

Eleccion::Eleccion(int codigo, string descrip, string fecha):electores(CANT_MAXELECTORES_ELECCION),recintos(CANT_MAXRECINTOS_ELECCION),mesas(CANT_MAXMESAS_ELECCION)
{
	this->codigo = codigo;
	this->descrip = descrip;
	this->fecha = fecha;
}

Eleccion::~Eleccion()
{
}

int Eleccion::getCodigo()
{
	return codigo;
}

void Eleccion::agregarElector(Elector* e)
{
	electores.registrar(e);
}

void Eleccion::agregarRecinto(RecintoAsignado* r)
{
	recintos.registrar(r);
}

void Eleccion::agregarMesaArecinto(Mesa* mesa, int nro, int codigoRecinto)
{
	if (mesa != NULL)
	{
		RecintoAsignado* ra = recintos.buscar(codigoRecinto);
		if (ra != NULL)
		{
			ra->getMesas().registrar(new MesaAsignada(mesa, nro));
		}
	}
}


RecintoAsignado* Eleccion::buscarRecintoAsignado(int codigo)
{
	return recintos.buscar(codigo);
}

string Eleccion::getDescrip()
{
	return descrip;
}

string Eleccion::getFecha()
{
	return fecha;
}

void Eleccion::setCodigo(int codigo)
{
	this->codigo = codigo;
	
}

void Eleccion::setDescrip(string descrip)
{
	this->descrip = descrip;
	
}

void Eleccion::setFecha(string fecha)
{
	this->fecha = fecha;
}

string Eleccion::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Codigo\":" << codigo << ",";
	ss << "\"Descripcion\":\"" << descrip << "\",";
	ss << "\"Fecha\":\"" << fecha << "\",";
	ss << "\"Electores\":" << electores.toJson()<<",";
	ss << "\"Recintos\":" << recintos.toJson();
	ss << "}";
	return ss.str();
}
