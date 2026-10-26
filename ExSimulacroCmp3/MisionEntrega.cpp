#include "MisionEntrega.h"

MisionEntrega::MisionEntrega(int id, int idDron, int durMin, double peso, string origen, string destino):Mision(id, idDron,durMin)
{
	tipo = "entrega";
	this->peso = peso;
	this->origen = origen;
	this ->destino = destino;
}

MisionEntrega::~MisionEntrega()
{
}

double MisionEntrega::getPeso()
{
	return peso;
}

string MisionEntrega::getOrigen()
{
	return origen;
}

string MisionEntrega::getDestino()
{
	return destino;
}

string MisionEntrega::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\""<<tipo<<"\",\"id\":"<<id<<",\"dronId\":"<<idDron<<",\"duracionMin\":"<<durMin<<",\"pesoKg\":"<< peso;
	if (peso == (int)peso) ss << ".0"; 
	ss<<",\"origen\":\""<<origen<<"\",\"destino\":\""<<destino<<"\"}";
	return ss.str();
}
