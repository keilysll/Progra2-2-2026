#include "TSE.h"

TSE::TSE(string nombre, int CanMaxElecto, int CantMaxMesas, int CantMaxRecin, int CantMaxElec):electores(10),mesas(10),recintos(10),elecciones(10)
{
	this->nombre = nombre;
}

TSE::~TSE()
{
}

string TSE::getNombre()
{
	return nombre;
}

ModElector& TSE::getElector()
{
	return electores;
}

ModMesa& TSE::getMesa()
{
	return mesas;
}

ModRecinto& TSE::getRecinto()
{
	return recintos;
}

ModEleccion& TSE::getEleccion()
{
	return elecciones;
}

void TSE::agregarElectorAeleccion(int ci, int codigo)
{
	Elector* e = electores.buscar(ci);

	if (e != NULL)
	{
		Eleccion* ele = elecciones.buscar(codigo);

		if (ele != NULL)
		{
			ele->agregarElector(e);
		}
	}
}

void TSE::agregarRecintoAeleccion(int cod, int codigo)
{
	Recinto* r = recintos.buscar(cod);
	if (r != NULL)
	{
		Eleccion* ele = elecciones.buscar(codigo);
		if (ele != NULL)
		{
			ele->agregarRecinto(new RecintoAsignado(r));
		}
	}
}

void TSE::agregarMesaArecintoAsignado(int codMesa, int nro, int codRecinto, int codEleccion)
{
	Mesa* m = mesas.buscar(codMesa);
	if (m != NULL)
	{
		Eleccion* ele = elecciones.buscar(codEleccion);
		if (ele != NULL)
		{
			ele->agregarMesaArecinto(m, nro, codRecinto);
		}
	}
}

void TSE::agregarElectorAmesa(int ci, int nro, int codRecinto, int codEleccion)
{

	Elector* e = electores.buscar(ci);
	if (e != NULL)
	{
		Eleccion* ele = elecciones.buscar(codEleccion);
		if (ele != NULL)
		{
			RecintoAsignado* ra = ele->buscarRecintoAsignado(codRecinto);
			if (ra != NULL)
			{
				MesaAsignada* ma = ra->getMesas().buscar(nro);
				if (ma != NULL)
				{
					ma->getElectores().registrar(e);
				}
			}
		}
	}
}

void TSE::asignarJuradoMesa(int ci, int nro, int codRecinto, int codEleccion)
{
	Elector* e = electores.buscar(ci);
	if (e != NULL)
	{
		Eleccion* ele = elecciones.buscar(codEleccion);
		if (ele != NULL)
		{
			RecintoAsignado* ra = ele->buscarRecintoAsignado(codRecinto);
			if (ra != NULL)
			{
				MesaAsignada* ma = ra->getMesas().buscar(nro);
				if (ma != NULL)
				{
					ma->getJurados().registrar(e);
				}
			}
		}
	}
}



string TSE::toJson()
{
	stringstream ss;
	ss<<"{";
	ss << "\"Nombre\":\"" << nombre << "\",";
	ss << "\"Electores\":" << electores.toJson() << ",";
	ss << "\"Recintos\":" << recintos.toJson() << ",";
	ss << "\"Mesas\":" << mesas.toJson()<<",";
	ss << "\"Elecciones\":" <<elecciones.toJson();
	ss<<"}";
	return ss.str();
}
