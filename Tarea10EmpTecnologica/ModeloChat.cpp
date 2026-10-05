#include "ModeloChat.h"

ModeloChat::ModeloChat(string nombre,int tokens):Modelo(nombre)
{
	this->tokens = tokens;
}

ModeloChat::~ModeloChat()
{
}

int ModeloChat::getToken()
{
	return tokens;
}

string ModeloChat::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"contexto\":"<<tokens<<",\"tipo\":\"chat\"}";
	return ss.str();
}
