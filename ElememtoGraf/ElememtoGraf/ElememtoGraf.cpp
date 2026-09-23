
#include "ElementoGrafico.h"

#include "EGSimple.h"
#include "Punto.h"
void ejem1()
{
    //ERROR
   // ElementoGrafico eg(1);
   // ERROR 2
   // EGSimple egs(1);
}
void ejem2()
{
  
   Punto p (1,3,4);
   p.dibujar();
}

int main()
{
    ejem2();
}

