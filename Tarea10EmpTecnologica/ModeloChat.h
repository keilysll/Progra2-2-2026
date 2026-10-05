#pragma once
#include "Modelo.h"
class ModeloChat :
    public Modelo
{
private:
    int tokens;
public:
    ModeloChat(string nombre,int tokens);
    ~ModeloChat();
    int getToken();
    string toJson();

};

