#include "Estacion.h"

Estacion::Estacion(string nombre, string zona):cargadores(10),sesiones(10)
{
	this->nombre = nombre;
	this->zona = zona;
}

Estacion::~Estacion()
{
}

bool Estacion::operator+=(Cargador* c)
{
	if(!c) return false;
	cargadores.registrar(c);
	cargadores.ordenar(Cargador::OrdenarPotenciaAsc);
	return true;
}

Cargador* Estacion::operator[](int i)
{

	return cargadores[i];
}

bool Estacion::cargar(int id, string codCarg, string placa, int km)
{
	Cargador* c = NULL;
	for (int i = 0; cargadores[i] != NULL; i++)
	{
		if (cargadores[i]->getCodigo() == codCarg)
		{
			c = cargadores[i];
			break;
		}
	}
	Vehiculo* vehiculo = SingletonVehiculos::getInst()[placa];
	if (!c || !vehiculo)
	{
		return false;
	}
	if (dynamic_cast<CargadorRapido*>(c) && dynamic_cast<Hibrido*>(vehiculo))
	{
		return false;
	}
	if (km > vehiculo->getCapBat()) return false;
	sesiones.registrar(new Sesion(id, c, vehiculo, km));
	return true;
}

string Estacion::toString()
{
	cargadores.ordenar(Cargador::OrdenarPotenciaAsc);
	sesiones.ordenar(Sesion::CmpCostoAsc);
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"zona\":\""<<zona<<"\",\"cargadores\":"<<cargadores.toString(Cargador::toStringPtr)<<",\"sesiones\":"<<sesiones.toString(Sesion::toStringPtr)<<"}";
	return ss.str();
}

int Estacion::recaudacionTotal()
{
	int total = 0;
	for (int i = 0; sesiones[i] != NULL; i++)
	{
		total = total + sesiones[i]->getCosto();
	}
	return total;
}

int Estacion::energiaRapida()
{
	int total = 0;
	for (int i = 0; sesiones[i] != NULL; i++)
	{
		if (dynamic_cast<CargadorRapido*>(sesiones[i]->getCargador()))
		{
			total = total + sesiones[i]->getKwh();
		}
	}
	return total;
}

string Estacion::vehiculoQueMasCargo()
{
	Vehiculo* mejor = NULL;
	int maxEnergia = 0;
	for (int i = 0; sesiones[i] != NULL; i++)
	{
		Vehiculo* v = sesiones[i]->getVehiculo();
		int energia = 0;
		for (int j = 0; sesiones[j] != NULL; j++)
		{
			if (sesiones[j]->getVehiculo()->getPlaca() == v->getPlaca())
			{
				energia = energia + sesiones[j]->getKwh();
			}
		}
		if (energia > maxEnergia)
		{
			maxEnergia = energia;
			mejor = v;
		}
	}
	if (!mejor) return "";
	return mejor->toString();
}
