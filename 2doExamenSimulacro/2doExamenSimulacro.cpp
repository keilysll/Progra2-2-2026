/*
BioLab: centro de investigacion de criaturas fantasticas.

Tipos de criatura:
- Terrestre(codigo, nombre, peligrosidad, velocidadMax)
- Mistica(codigo, nombre, peligrosidad, energiaMagica)

Tipos de muestra:
- Biologica(codigo, descripcion, pesoGramos, pureza)
- Energetica(codigo, descripcion, energia, radiacion)

Reglas de expedicion:
- peligrosidad de la criatura <= nivelSeguridad del equipo
- capacidad del equipo: peso total en kg de muestras biologicas
  no debe exceder capacidadKg; energia total de energeticas no debe
  exceder capacidadKg * 10.
- criaturas misticas pueden generar informe especial con energia usada
- valor cientifico depende de las muestras y del tipo de criatura

FORMULAS (impleméntalas tal cual, sin operador ?:):

  valorMuestraBiologica  = pureza + pesoGramos / 100
  valorMuestraEnergetica = energia + radiacion * 2
  valorExpedicion        = suma(valorMuestra) + bonusCriatura

  bonusCriatura:
     si la criatura es Mistica    -> energiaMagica / 10
     si la criatura es Terrestre  -> velocidadMax / 10

  capacidadUsadaKg:
     suma(pesoGramos de biologicas) convertida a kg con static_cast
  energiaUsada:
     suma(energia de energeticas)

Requisitos:
- Criatura y Muestra son clases abstractas (metodos virtuales puros).
- Colecciones sobre ModGenerico<T>.
- Sobrecarga de operadores: <<, +=, [], ==.
- Funciones estaticas para comparacion y JSON.
- dynamic_cast y static_cast obligatorios desde la pregunta 3.
*/


#include "SingletonCriaturas.h"
#include "SingletonInvestigadores.h"
#include "BioLab.h"

// ============================================================
// PREGUNTA 1 — Registro de criaturas (20 pts)
// ============================================================

using namespace std;
#include<iostream>

int pregunta1()
{
    cout << "----Pregunta 1----" << endl;
    cout << "Resultado esperado:" << endl;
    cout << "[{\"tipo\":\"terrestre\",\"codigo\":3,\"nombre\":\"Basilisco\",\"peligrosidad\":8,\"velocidadMax\":40},"
        "{\"tipo\":\"mistica\",\"codigo\":1,\"nombre\":\"Fenix\",\"peligrosidad\":6,\"energiaMagica\":150},"
        "{\"tipo\":\"terrestre\",\"codigo\":2,\"nombre\":\"Grifo\",\"peligrosidad\":5,\"velocidadMax\":80},"
        "{\"tipo\":\"mistica\",\"codigo\":4,\"nombre\":\"Unicornio\",\"peligrosidad\":2,\"energiaMagica\":90}]" << endl;

    SingletonCriaturas::getInst() << new Mistica(1, "Fenix", 6, 150);
    SingletonCriaturas::getInst() << new Terrestre(2, "Grifo", 5, 80);
    SingletonCriaturas::getInst() << new Terrestre(3, "Basilisco", 8, 40);
    SingletonCriaturas::getInst() << new Mistica(4, "Unicornio", 2, 90);

    Criatura* c = SingletonCriaturas::getInst()[2];
    bool iguales = *c == *SingletonCriaturas::getInst()[2];
    bool distintos = *c == *SingletonCriaturas::getInst()[1];

    string result = SingletonCriaturas::getInst().toString();
    cout << "Resultado obtenido:" << endl;
    cout << "Buscado codigo = 2: " << c->toString() << endl;
    cout << iguales << " " << distintos << endl;
    cout << result << endl;

    if (c->toString() == "{\"tipo\":\"terrestre\",\"codigo\":2,\"nombre\":\"Grifo\",\"peligrosidad\":5,\"velocidadMax\":80}" &&
        iguales && !distintos &&
        result == "[{\"tipo\":\"terrestre\",\"codigo\":3,\"nombre\":\"Basilisco\",\"peligrosidad\":8,\"velocidadMax\":40},"
        "{\"tipo\":\"mistica\",\"codigo\":1,\"nombre\":\"Fenix\",\"peligrosidad\":6,\"energiaMagica\":150},"
        "{\"tipo\":\"terrestre\",\"codigo\":2,\"nombre\":\"Grifo\",\"peligrosidad\":5,\"velocidadMax\":80},"
        "{\"tipo\":\"mistica\",\"codigo\":4,\"nombre\":\"Unicornio\",\"peligrosidad\":2,\"energiaMagica\":90}]")
    {
        cout << "Resultado: correcto" << endl;
        return 20;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

// ============================================================
// PREGUNTA 2 — Equipos de investigacion (25 pts)
// ============================================================

#include"Equipo.h"

int pregunta2()
{
    cout << "----Pregunta 2----" << endl;
    cout << "Resultado esperado:" << endl;
    cout << "{\"nombre\":\"Equipo Alpha\",\"capacidadKg\":50,\"nivelSeguridad\":7,"
        "\"investigadores\":["
        "{\"codigo\":101,\"nombre\":\"Ana Rojas\",\"especialidad\":\"Biologia\"},"
        "{\"codigo\":103,\"nombre\":\"Carla Mendez\",\"especialidad\":\"Astrobiologia\"},"
        "{\"codigo\":102,\"nombre\":\"Luis Paz\",\"especialidad\":\"Criptozoologia\"}]}" << endl;

    SingletonInvestigadores::getInst() << new Investigador(101, "Ana Rojas", "Biologia");
    SingletonInvestigadores::getInst() << new Investigador(102, "Luis Paz", "Criptozoologia");
    SingletonInvestigadores::getInst() << new Investigador(103, "Carla Mendez", "Astrobiologia");

    Equipo equipo("Equipo Alpha", 50, 7);
    equipo += 101;
    equipo += 102;
    equipo += 103;

    string primero = equipo[0]->toString();
    string result = equipo.toString();
    cout << "Resultado obtenido:" << endl;
    cout << primero << endl;
    cout << result << endl;

    if (primero == "{\"codigo\":101,\"nombre\":\"Ana Rojas\",\"especialidad\":\"Biologia\"}" &&
        result == "{\"nombre\":\"Equipo Alpha\",\"capacidadKg\":50,\"nivelSeguridad\":7,"
        "\"investigadores\":["
        "{\"codigo\":101,\"nombre\":\"Ana Rojas\",\"especialidad\":\"Biologia\"},"
        "{\"codigo\":103,\"nombre\":\"Carla Mendez\",\"especialidad\":\"Astrobiologia\"},"
        "{\"codigo\":102,\"nombre\":\"Luis Paz\",\"especialidad\":\"Criptozoologia\"}]}")
    {
        cout << "Resultado: correcto" << endl;
        return 25;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

// ============================================================
// PREGUNTA 3 — Expediciones y muestras (30 pts)
// ============================================================
int pregunta3()
{
    cout << "----Pregunta 3----" << endl;
    cout << "Resultado esperado:" << endl;
    cout << "1 0 1 0 1 0" << endl;
    cout << "{\"expediciones\":["
        "{\"id\":1,\"criaturaCodigo\":1,\"equipo\":\"Equipo Alpha\","
        "\"muestras\":["
        "{\"tipo\":\"biologica\",\"codigo\":10,\"descripcion\":\"Pluma de fenix\",\"pesoGramos\":200,\"pureza\":95},"
        "{\"tipo\":\"energetica\",\"codigo\":11,\"descripcion\":\"Residuo magico\",\"energia\":30,\"radiacion\":4}],"
        "\"valorCientifico\":150},"
        "{\"id\":3,\"criaturaCodigo\":2,\"equipo\":\"Equipo Alpha\","
        "\"muestras\":["
        "{\"tipo\":\"biologica\",\"codigo\":12,\"descripcion\":\"Pluma de grifo\",\"pesoGramos\":150,\"pureza\":80}],"
        "\"valorCientifico\":89}]}" << endl;
    BioLab lab;
    lab.registrarCriatura(new Mistica(1, "Fenix", 6, 150));
    lab.registrarCriatura(new Terrestre(2, "Grifo", 5, 80));
    lab.registrarCriatura(new Terrestre(3, "Basilisco", 8, 40));
    lab.registrarEquipo(new Equipo("Equipo Alpha", 50, 7));

    bool r1 = lab.crearExpedicion(1, 1, "Equipo Alpha"); // Fenix 6<=7 OK
    bool r2 = lab.crearExpedicion(2, 3, "Equipo Alpha"); // Basilisco 8>7 falla
    bool r3 = lab.crearExpedicion(3, 2, "Equipo Alpha"); // Grifo 5<=7 OK
    bool r4 = lab.crearExpedicion(4, 99, "Equipo Alpha"); // criatura no existe
    bool r5 = lab.crearExpedicion(5, 1, "Equipo Omega");  // equipo no existe
    bool r6 = lab.crearExpedicion(1, 2, "Equipo Alpha");  // id duplicado

    lab[1] << new Biologica(10, "Pluma de fenix", 200, 95);
    lab[1] << new Energetica(11, "Residuo magico", 30, 4);
    lab[3] << new Biologica(12, "Pluma de grifo", 150, 80);

    string result = lab.expedicionesToString();
    cout << "Resultado obtenido:" << endl;
    cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << " " << r6 << endl;
    cout << result << endl;

    if (r1 && !r2 && r3 && !r4 && !r5 && !r6 &&
        result == "{\"expediciones\":["
        "{\"id\":1,\"criaturaCodigo\":1,\"equipo\":\"Equipo Alpha\","
        "\"muestras\":["
        "{\"tipo\":\"biologica\",\"codigo\":10,\"descripcion\":\"Pluma de fenix\",\"pesoGramos\":200,\"pureza\":95},"
        "{\"tipo\":\"energetica\",\"codigo\":11,\"descripcion\":\"Residuo magico\",\"energia\":30,\"radiacion\":4}],"
        "\"valorCientifico\":150},"
        "{\"id\":3,\"criaturaCodigo\":2,\"equipo\":\"Equipo Alpha\","
        "\"muestras\":["
        "{\"tipo\":\"biologica\",\"codigo\":12,\"descripcion\":\"Pluma de grifo\",\"pesoGramos\":150,\"pureza\":80}],"
        "\"valorCientifico\":89}]}")
    {
        cout << "Resultado: correcto" << endl;
        return 30;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;

}

// ============================================================
// PREGUNTA 4 — Informe cientifico (25 pts)
// ============================================================
int pregunta4()
{
    cout << "----Pregunta 4----" << endl;
    BioLab lab;
    lab.registrarCriatura(new Mistica(1, "Fenix", 6, 150));
    lab.registrarCriatura(new Terrestre(2, "Grifo", 5, 80));
    lab.registrarCriatura(new Terrestre(3, "Basilisco", 8, 40));
    lab.registrarCriatura(new Mistica(4, "Unicornio", 2, 90));
    lab.registrarEquipo(new Equipo("Equipo Alpha", 50, 7));
    lab.registrarEquipo(new Equipo("Equipo Beta", 100, 9));

    lab.crearExpedicion(1, 1, "Equipo Alpha");
    lab.crearExpedicion(2, 2, "Equipo Alpha");
    lab.crearExpedicion(3, 1, "Equipo Beta");
    lab.crearExpedicion(4, 4, "Equipo Beta");

    lab[1] << new Energetica(20, "Chispa magica", 40, 3);
    lab[1] << new Biologica(21, "Pluma", 100, 90);
    lab[2] << new Biologica(22, "Garra", 80, 70);
    lab[3] << new Energetica(23, "Aura", 60, 5);
    lab[3] << new Energetica(24, "Aura2", 20, 2);
    lab[4] << new Biologica(25, "Cuerno", 120, 99);

    string masInv = lab.criaturaMasInvestigada();
    int mayorValor = lab.expedicionMayorValor();
    int energiaTotal = lab.energiaMagicaTotal();
    string informe = lab.generarInforme();

    cout << "Resultado esperado criaturaMasInvestigada: "
        << "{\"tipo\":\"mistica\",\"codigo\":1,\"nombre\":\"Fenix\",\"peligrosidad\":6,\"energiaMagica\":150}" << endl;
    cout << "Resultado obtenido criaturaMasInvestigada: " << masInv << endl;
    cout << "Resultado esperado expedicionMayorValor: 3" << endl;
    cout << "Resultado obtenido expedicionMayorValor: " << mayorValor << endl;
    cout << "Resultado esperado energiaMagicaTotal: 120" << endl;
    cout << "Resultado obtenido energiaMagicaTotal: " << energiaTotal << endl;
    cout << "Informe obtenido:" << endl;
    cout << informe << endl;

    if (masInv == "{\"tipo\":\"mistica\",\"codigo\":1,\"nombre\":\"Fenix\",\"peligrosidad\":6,\"energiaMagica\":150}" &&
        mayorValor == 3 && energiaTotal == 120 &&
        informe == "{\"criaturaMasInvestigada\":{\"tipo\":\"mistica\",\"codigo\":1,\"nombre\":\"Fenix\",\"peligrosidad\":6,\"energiaMagica\":150},"
        "\"expedicionMayorValor\":3,"
        "\"energiaMagicaTotal\":120,"
        "\"detalleExpediciones\":["
        "{\"id\":1,\"tipoCriatura\":\"mistica\",\"energiaMagica\":150},"
        "{\"id\":2,\"tipoCriatura\":\"terrestre\",\"velocidadMax\":80},"
        "{\"id\":3,\"tipoCriatura\":\"mistica\",\"energiaMagica\":150},"
        "{\"id\":4,\"tipoCriatura\":\"mistica\",\"energiaMagica\":90}]}")
    {
        cout << "Resultado: correcto" << endl;
        return 25;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

// ============================================================
// MAIN
// ============================================================
int main()
{
    int nota = pregunta1() + pregunta2() + pregunta3() + pregunta4();
    cout << endl;
    cout << "====================" << endl;
    cout << "===> NOTA: " << nota << "/100" << endl;
    cout << "====================" << endl;
    system("pause");
    return 0;
}