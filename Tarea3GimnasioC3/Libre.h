#pragma once
#include "Grupo.h"
class Libre :
    public Grupo
{
public:
    Libre(string id);
    ~Libre();
    string toString();
};

