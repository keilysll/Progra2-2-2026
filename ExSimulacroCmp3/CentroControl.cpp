#include "CentroControl.h"

CentroControl::CentroControl(string nombre, string ciudad):drones(10),misiones(10)
{
	this->nombre = nombre;
	this->ciudad = ciudad;
}

CentroControl::~CentroControl()
{
}

string CentroControl::getNombre()
{
	return nombre;
}

string CentroControl::getCiudad()
{
	return ciudad;
}

bool CentroControl::operator+=(Dron* d)
{
	if (!d)
	{
		return false;

	}
	drones.registrar(d);
	return true;
}

bool CentroControl::asignar(Mision* m)
{
	if (!m) return false;

	// 1. el dron debe existir
	Delivery del(m->getDronid());
	Dron* d = drones.buscar(&del);
	if (d == NULL) return false;

	// 2. duracion <= autonomia
	if (m->getDurMin() > d->getAutomin()) return false;

	// 3. el dron no tiene otra mision
	for (int i = 0; i < misiones.getInd(); i++)
	{
		if (misiones[i]->getDronid() == d->getId()) return false;
	}

	// 4. tipo de dron = tipo de mision
	bool dronDelivery = dynamic_cast<Delivery*>(d) != NULL;
	bool misionEntrega = dynamic_cast<MisionEntrega*>(m) != NULL;
	if (dronDelivery != misionEntrega) return false;

	misiones.registrar(m);
	return true;

	
}

Dron* CentroControl::operator[](int i)
{
	return drones.operator[](i);
}

string CentroControl::dronMasUsado()
{
	Dron* mejor = NULL;
	int masPres = 0;
	for (int i = 0; i < drones.getInd(); i++)
	{
		Dron* d = drones[i];
		bool dronDelivery = dynamic_cast<Delivery*>(d) != NULL;
		int cont = 0;
		for (int j = 0; j < misiones.getInd(); j++)
		{
			Mision* m = misiones[j];
			if (m->getDronid() != d->getId()) continue;
			bool misionEntrega = dynamic_cast<MisionEntrega*>(m) != NULL;
			if (dronDelivery == misionEntrega) cont++;
		}
		if (cont > masPres || (cont == masPres && mejor != NULL && d->getId() < mejor->getId()))
		{
			mejor = d;
			masPres = cont;
		}
	}
	if (mejor == NULL) return "";
	return mejor->toString();
}

int CentroControl::duracionMaxima()
{
	int max = 0;
	for (int i = 0; i < misiones.getInd(); i++)
	{
		if (misiones[i]->getDurMin() > max)
		{
			max = misiones[i]->getDurMin();
		}
	}
	return max;
}

double CentroControl::pesoTotalEntregado()
{
	double total = 0;
	for (int i = 0; i < misiones.getInd(); i++)
	{
		Mision* m = misiones[i];
		if (m->getTipo() == "entrega")
		{
			total += static_cast<MisionEntrega*>(m)->getPeso();
		}
	}
	return total;
}

double CentroControl::areaTotalVigilada()
{
	double total = 0;
	for (int i = 0; i < misiones.getInd(); i++)
	{
		Mision* m = misiones[i];
		if (m->getTipo() == "vigilancia")
		{
			total += static_cast<MisionVigilancia*>(m)->getArea();
		}
	}
	return total;
}

string CentroControl::toString()
{
	misiones.ordenar(Mision::OrdMision);
	drones.ordenar(Dron::CmpAscID);
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"ciudad\":\""<<ciudad<<"\",\"drones\":"<< drones.toString(Dron::toStringPtr)<<",\"misiones\":"<<misiones.toString(Mision::toStringPtr)<<"}";
	return ss.str();
}
