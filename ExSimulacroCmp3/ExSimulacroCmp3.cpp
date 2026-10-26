/*
SkyDrop: sistema de gestion de drones de delivery y vigilancia.

Tipos de dron:
- Delivery(id, modelo, autonomiaMin, capacidadKg)
- Vigilancia(id, modelo, autonomiaMin, resolucionMP)

Tipos de mision:
- MisionEntrega(id, dronId, duracionMin, pesoKg, origen, destino)
- MisionVigilancia(id, dronId, duracionMin, zona, areaKm2)

Reglas:
- Delivery solo hace MisionEntrega; Vigilancia solo hace MisionVigilancia.
- duracionMin <= autonomia del dron.
- Un dron no puede tener dos misiones activas.

Requisitos de diseno:
- Dron y Mision son clases abstractas.
- Colecciones sobre ListaGen<T> (tu ModGenerico<T>).
- CentroControl::asignar y CentroControl::dronMasUsado deben usar dynamic_cast.
- Los calculos de capacidad/peso deben usar static_cast.
- SingletonDrones: operador <<, [], ==.
*/

#include "SingletonDrones.h"
#include "CentroControl.h"

#include<iostream>
using namespace std;

int pregunta1()
{
    cout << "----Pregunta 1----" << endl;
    cout << "[{\"tipo\":\"delivery\",\"id\":103,\"modelo\":\"Falcon-Pro\",\"autonomiaMin\":90,\"capacidadKg\":5},{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5},{\"tipo\":\"vigilancia\",\"id\":205,\"modelo\":\"EyeSky\",\"autonomiaMin\":60,\"resolucionMP\":12},{\"tipo\":\"vigilancia\",\"id\":202,\"modelo\":\"EyeSky-Mini\",\"autonomiaMin\":30,\"resolucionMP\":8}]" << endl;
    
    SingletonDrones::getInst() << new Delivery(101, "Falcon-X", 45, 2.5);
    SingletonDrones::getInst() << new Vigilancia(205, "EyeSky", 60, 12);
    SingletonDrones::getInst() << new Delivery(103, "Falcon-Pro", 90, 5.0);
    SingletonDrones::getInst() << new Vigilancia(202, "EyeSky-Mini", 30, 8);

    Dron* d = SingletonDrones::getInst()[205];

    bool iguales = *d == *SingletonDrones::getInst()[205];
    bool distintos = *d == *SingletonDrones::getInst()[101];

    cout << "Resultado esperado:" << endl;
    cout << "{\"tipo\":\"vigilancia\",\"id\":205,\"modelo\":\"EyeSky\",\"autonomiaMin\":60,\"resolucionMP\":12}" << endl;
    cout << "1 0" << endl;
    cout << "[{\"tipo\":\"delivery\",\"id\":103,\"modelo\":\"Falcon-Pro\",\"autonomiaMin\":90,\"capacidadKg\":5},{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5},{\"tipo\":\"vigilancia\",\"id\":205,\"modelo\":\"EyeSky\",\"autonomiaMin\":60,\"resolucionMP\":12},{\"tipo\":\"vigilancia\",\"id\":202,\"modelo\":\"EyeSky-Mini\",\"autonomiaMin\":30,\"resolucionMP\":8}]" << endl;

    string result = SingletonDrones::getInst().toString();
    cout << "Resultado obtenido:" << endl;
    cout << d->toString() << endl;
    cout << iguales << " " << distintos << endl;
    cout << result << endl;

    if (d->toString() == "{\"tipo\":\"vigilancia\",\"id\":205,\"modelo\":\"EyeSky\",\"autonomiaMin\":60,\"resolucionMP\":12}" &&
        iguales && !distintos &&
        result == "[{\"tipo\":\"delivery\",\"id\":103,\"modelo\":\"Falcon-Pro\",\"autonomiaMin\":90,\"capacidadKg\":5},{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5},{\"tipo\":\"vigilancia\",\"id\":205,\"modelo\":\"EyeSky\",\"autonomiaMin\":60,\"resolucionMP\":12},{\"tipo\":\"vigilancia\",\"id\":202,\"modelo\":\"EyeSky-Mini\",\"autonomiaMin\":30,\"resolucionMP\":8}]")
    {
        cout << "Resultado: correcto" << endl;
        return 20;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}


int pregunta2()
{
    cout << "----Pregunta 2----" << endl;
    CentroControl centro("SkyDrop Sur", "La Paz");

    centro += new Delivery(101, "Falcon-X", 45, 2.5);
    centro += new Vigilancia(205, "EyeSky", 60, 12);
    centro += new Delivery(103, "Falcon-Pro", 90, 5.0);

    // Acceder por indice con []
    string primero = centro[0]->toString();
    string result = centro.toString();

    cout << "Resultado esperado:" << endl;
    cout << "{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5}" << endl;
    cout << "{\"nombre\":\"SkyDrop Sur\",\"ciudad\":\"La Paz\",\"drones\":[{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5},{\"tipo\":\"delivery\",\"id\":103,\"modelo\":\"Falcon-Pro\",\"autonomiaMin\":90,\"capacidadKg\":5},{\"tipo\":\"vigilancia\",\"id\":205,\"modelo\":\"EyeSky\",\"autonomiaMin\":60,\"resolucionMP\":12}],\"misiones\":[]}" << endl;

    cout << "Resultado obtenido:" << endl;
    cout << primero << endl;
    cout << result << endl;

    if (primero == "{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5}" &&
        result == "{\"nombre\":\"SkyDrop Sur\",\"ciudad\":\"La Paz\",\"drones\":[{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5},{\"tipo\":\"delivery\",\"id\":103,\"modelo\":\"Falcon-Pro\",\"autonomiaMin\":90,\"capacidadKg\":5},{\"tipo\":\"vigilancia\",\"id\":205,\"modelo\":\"EyeSky\",\"autonomiaMin\":60,\"resolucionMP\":12}],\"misiones\":[]}")
    {
        cout << "Resultado: correcto" << endl;
        return 25;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}
int pregunta3()
{
    cout << "----Pregunta 3----" << endl;
    cout << "Resultado esperado:" << endl;
    cout << "1 0 1 0 1 0 0" << endl;
    cout << "{\"nombre\":\"SkyDrop Sur\",\"ciudad\":\"La Paz\",\"drones\":[{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5},{\"tipo\":\"delivery\",\"id\":103,\"modelo\":\"Falcon-Pro\",\"autonomiaMin\":90,\"capacidadKg\":5.0},{\"tipo\":\"vigilancia\",\"id\":205,\"modelo\":\"EyeSky\",\"autonomiaMin\":60,\"resolucionMP\":12}],\"misiones\":[{\"tipo\":\"entrega\",\"id\":1,\"dronId\":101,\"duracionMin\":30,\"pesoKg\":1.5,\"origen\":\"Centro\",\"destino\":\"Miraflores\"},{\"tipo\":\"entrega\",\"id\":5,\"dronId\":103,\"duracionMin\":80,\"pesoKg\":4.0,\"origen\":\"Centro\",\"destino\":\"Sopocachi\"},{\"tipo\":\"vigilancia\",\"id\":3,\"dronId\":205,\"duracionMin\":60,\"zona\":\"Zona Norte\",\"areaKm2\":5.0}]}" << endl;
   
    CentroControl centro("SkyDrop Sur", "La Paz");
    centro += new Delivery(101, "Falcon-X", 45, 2.5);
    centro += new Vigilancia(205, "EyeSky", 60, 12);
    centro += new Delivery(103, "Falcon-Pro", 90, 5.0);
    // MisionEntrega: (id, dronId, duracionMin, pesoKg, origen, destino)
    bool r1 = centro.asignar(new MisionEntrega(1, 101, 30, 1.5, "Centro", "Miraflores"));
    // 101 es Delivery -> OK, dura 30 <= 45

    // MisionVigilancia sobre dron Delivery -> debe fallar (dynamic_cast)
    bool r2 = centro.asignar(new MisionVigilancia(2, 101, 20, "Zona Sur", 3.0));

    // 205 es Vigilancia -> OK, dura 60 <= 60 (justo en el limite)
    bool r3 = centro.asignar(new MisionVigilancia(3, 205, 60, "Zona Norte", 5.0));

    // 103 es Delivery, duracion 100 > 90 -> falla
    bool r4 = centro.asignar(new MisionEntrega(4, 103, 100, 3.0, "Centro", "El Alto"));

    // 103 ya tiene mision? No, la de arriba fallo, ahora una valida
    bool r5 = centro.asignar(new MisionEntrega(5, 103, 80, 4.0, "Centro", "Sopocachi"));

    // 103 ya tiene mision activa -> falla
    bool r6 = centro.asignar(new MisionEntrega(6, 103, 10, 1.0, "A", "B"));

    // dron 999 no existe -> falla
    bool r7 = centro.asignar(new MisionEntrega(7, 999, 10, 1.0, "A", "B"));

    string result = centro.toString();
    cout << "Resultado esperado:" << endl;
    cout << "1 0 1 0 1 0 0" << endl;
    cout << "{\"nombre\":\"SkyDrop Sur\",\"ciudad\":\"La Paz\",\"drones\":[{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5},{\"tipo\":\"delivery\",\"id\":103,\"modelo\":\"Falcon-Pro\",\"autonomiaMin\":90,\"capacidadKg\":5},{\"tipo\":\"vigilancia\",\"id\":205,\"modelo\":\"EyeSky\",\"autonomiaMin\":60,\"resolucionMP\":12}],\"misiones\":[{\"tipo\":\"entrega\",\"id\":1,\"dronId\":101,\"duracionMin\":30,\"pesoKg\":1.5,\"origen\":\"Centro\",\"destino\":\"Miraflores\"},{\"tipo\":\"entrega\",\"id\":5,\"dronId\":103,\"duracionMin\":80,\"pesoKg\":4.0,\"origen\":\"Centro\",\"destino\":\"Sopocachi\"},{\"tipo\":\"vigilancia\",\"id\":3,\"dronId\":205,\"duracionMin\":60,\"zona\":\"Zona Norte\",\"areaKm2\":5}]}" << endl;

    cout << "Resultado obtenido:" << endl;
    cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << " " << r6 << " " << r7 << endl;
    cout << result << endl;

    if (r1 && !r2 && r3 && !r4 && r5 && !r6 && !r7 &&
        result == "{\"nombre\":\"SkyDrop Sur\",\"ciudad\":\"La Paz\",\"drones\":[{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5},{\"tipo\":\"delivery\",\"id\":103,\"modelo\":\"Falcon-Pro\",\"autonomiaMin\":90,\"capacidadKg\":5},{\"tipo\":\"vigilancia\",\"id\":205,\"modelo\":\"EyeSky\",\"autonomiaMin\":60,\"resolucionMP\":12}],\"misiones\":[{\"tipo\":\"entrega\",\"id\":1,\"dronId\":101,\"duracionMin\":30,\"pesoKg\":1.5,\"origen\":\"Centro\",\"destino\":\"Miraflores\"},{\"tipo\":\"entrega\",\"id\":5,\"dronId\":103,\"duracionMin\":80,\"pesoKg\":4.0,\"origen\":\"Centro\",\"destino\":\"Sopocachi\"},{\"tipo\":\"vigilancia\",\"id\":3,\"dronId\":205,\"duracionMin\":60,\"zona\":\"Zona Norte\",\"areaKm2\":5}]}")
    {
        cout << "Resultado: correcto" << endl;
        return 30;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

int pregunta4()
{
    cout << "----Pregunta 4----" << endl;
    CentroControl centro("SkyDrop Norte", "La Paz");
    centro += new Delivery(101, "Falcon-X", 45, 2.5);
    centro += new Delivery(103, "Falcon-Pro", 90, 5.0);
    centro += new Vigilancia(205, "EyeSky", 60, 12);
    centro += new Vigilancia(207, "EyeSky-Max", 120, 20);

    centro.asignar(new MisionEntrega(1, 101, 30, 1.5, "A", "B"));
    centro.asignar(new MisionVigilancia(2, 205, 60, "Norte", 5.0));
    centro.asignar(new MisionEntrega(3, 103, 80, 4.0, "A", "C"));
    centro.asignar(new MisionVigilancia(4, 207, 100, "Sur", 10.0));
    centro.asignar(new MisionEntrega(5, 101, 10, 1.0, "B", "A")); // 101 ya tiene mision -> falla
    centro.asignar(new MisionVigilancia(6, 205, 20, "Este", 2.0)); // 205 ya tiene mision -> falla

    // Dron con mas misiones: todos tienen 1 -> el de menor id (101)
    // En caso de empate, devolver el de menor id
    string masUsado = centro.dronMasUsado();
    int duracionMax = centro.duracionMaxima();
    // suma de peso entregado por drones Delivery (static_cast)
    double pesoTotal = centro.pesoTotalEntregado();
    // area total vigilada (static_cast)
    double areaTotal = centro.areaTotalVigilada();

    cout << "Resultado esperado dronMasUsado: " << "{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5}" << endl;
    cout << "Resultado obtenido dronMasUsado: " << masUsado << endl;
    cout << "Resultado esperado duracionMaxima: 100" << endl;
    cout << "Resultado obtenido duracionMaxima: " << duracionMax << endl;
    cout << "Resultado esperado pesoTotalEntregado: 5.5" << endl;
    cout << "Resultado obtenido pesoTotalEntregado: " << pesoTotal << endl;
    cout << "Resultado esperado areaTotalVigilada: 15" << endl;
    cout << "Resultado obtenido areaTotalVigilada: " << areaTotal << endl;

    if (masUsado == "{\"tipo\":\"delivery\",\"id\":101,\"modelo\":\"Falcon-X\",\"autonomiaMin\":45,\"capacidadKg\":2.5}" &&
        duracionMax == 100 && pesoTotal == 5.5 && areaTotal == 15.0)
    {
        cout << "Resultado: correcto" << endl;
        return 25;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}
int main()
{
    int nota = pregunta1()+pregunta2()+ pregunta3() + pregunta4();
    cout << endl;
    cout << "====================" << endl;
    cout << "===> NOTA: " << nota << "/100" << endl;
    cout << "====================" << endl;
    system("pause");
    return 0;
}