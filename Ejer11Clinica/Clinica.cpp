#include "Clinica.h"

Clinica::Clinica(string nombre, string direccion):consultorios(10)
{
	this->nombre = nombre;
	this->direccion = direccion;
}

Clinica::~Clinica()
{
}

string Clinica::getNombre()
{
	return nombre;
}

string Clinica::getDirecc()
{
	return direccion;
}

ModConsultorio& Clinica::getConsult()
{
	return consultorios;
}

void Clinica::registrarConsultorio(int nroConsul)
{
	consultorios.registrar(new Consultorio(nroConsul));
}

void Clinica::registrarMedicoEnConsultorio(int nroConsul, Medico* m)
{
	Consultorio* consul = consultorios.buscar(nroConsul);
	if (consul != NULL)
	{
		consul->registrar(m);
	}
}

void Clinica::registrarConsultaEnMedico(int nroConsul, string nomMedic, Consulta* c)
{
	Consultorio* consul = consultorios.buscar(nroConsul);
	if (consul != NULL)
	{
		Medico* m = consul->buscarMed(nomMedic);
		if (m != NULL)
	{
		m->registrar(c);
	}

	}
	
}

string Clinica::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"direccion\":\"" << direccion << "\",\"consultorios\":" << consultorios.toJson() << "}";
	return ss.str();
}

int Clinica::totalIngresos()
{
	return consultorios.totalIngresos();
}

string Clinica::medicoConMasIngresos()
{
	Medico* m = consultorios.medicoConMasIngresos();
	if (m == NULL)
	{
		return "";
	}
	return m->getNombre();
}

