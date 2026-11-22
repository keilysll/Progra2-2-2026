#include "Vecino.h"

Vecino::Vecino(string nombre):Participantes(nombre)
{
}

Vecino::~Vecino()
{
}

string Vecino::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"tipo\":\"vecino\",\"puntos\":"<<puntos<<",\"entregas\":"<<entregas.toJson()<<"}";
	return ss.str();
}

void Vecino::entregar(Entrega* e)
{
	int id = e->getId();

	// 1. cantidad valida
	if (e->getCantidad() <= 0)
	{
		delete e;
		throw exception(("cantidad invalida en la entrega " + to_string(id)).c_str());
	}

	// 2. el material existe (si no existe, buscar lanza el error)
	Material* m;
	try
	{
		m = Tarifario::getInst().buscar(e->getMaterial());
	}
	catch (exception&)
	{
		delete e;
		throw;
	}

	// 3. el material es del tipo de la entrega
	EntregaPeso* ep = dynamic_cast<EntregaPeso*>(e);
	EntregaUnidad* eu = dynamic_cast<EntregaUnidad*>(e);
	MaterialPeso* mp = dynamic_cast<MaterialPeso*>(m);
	MaterialUnidad* mu = dynamic_cast<MaterialUnidad*>(m);
	if ((ep != NULL && mp == NULL) || (eu != NULL && mu == NULL))
	{
		delete e;
		throw exception(("el material " + m->getNombre() + " no es compatible con la entrega " + to_string(id)).c_str());
	}

	// 4. limite de 20 kg (solo para entregas por peso)
	if (ep != NULL)
	{
		int total = ep->getCantidad();
		for (int i = 0; i < entregas.size(); i++)
		{
			EntregaPeso* anterior = dynamic_cast<EntregaPeso*>(entregas.obtener(i));
			if (anterior != NULL)
			{
				total = total + anterior->getCantidad();
			}
		}
		if (total > 20000)
		{
			delete e;
			throw exception((nombre + " supero el limite de 20 kg en la entrega " + to_string(id)).c_str());
		}
	}

	// 5. todo bien: calcular puntos, sumar y guardar
	int pts = m->puntos(e->getCantidad());
	e->setPuntos(pts);
	entregas.agregar(e);
	puntos = puntos + pts;
}
