/*
 * Una empresa de tecnología desea una aplicación para administrar los proyectos
 * de IA que desarrolla con distintos modelos de lenguaje (LLM).
 * La aplicación debe permitir:
 *   - Registrar modelos LLM.
 *   - Registrar proyectos.
 *   - Asignar modelos LLM a proyectos.
 */
#include "Empresa.h"

#include<iostream>
using namespace std;

int pregunta1()
{
    cout << "----Pregunta 1----" << endl;
    cout << "Resultado esperado:" << endl;
    cout << "{\"nombre\":\"TechCorp\",\"modelos\":[{\"nombre\":\"GPT-4\",\"contexto\":128000,\"tipo\":\"chat\"},{\"nombre\":\"CodeLlama\",\"lenguajes\":\"Python,C++\",\"tipo\":\"codigo\"},{\"nombre\":\"Mistral\",\"lenguajes\":\"Java,JS\",\"tipo\":\"codigo\"}],\"proyectos\":[]}" << endl;
    // crear empresa(nombre)
    Empresa empresa("TechCorp");
    // registrar modelo de chat(nombre, ventana de contexto en tokens)
    empresa.registrar(new ModeloChat("GPT-4", 128000));
    // registrar modelo de codigo(nombre, lenguajes soportados)
    empresa.registrar(new ModeloCodigo("CodeLlama", "Python,C++"));
    empresa.registrar(new ModeloCodigo("Mistral", "Java,JS"));

    cout << "Resultado obtenido:" << endl;
    cout << empresa.toJson() << endl;

    if (empresa.toJson() == "{\"nombre\":\"TechCorp\",\"modelos\":[{\"nombre\":\"GPT-4\",\"contexto\":128000,\"tipo\":\"chat\"},{\"nombre\":\"CodeLlama\",\"lenguajes\":\"Python,C++\",\"tipo\":\"codigo\"},{\"nombre\":\"Mistral\",\"lenguajes\":\"Java,JS\",\"tipo\":\"codigo\"}],\"proyectos\":[]}")
    {
        cout << "Resultado: correcto" << endl;
        return 30;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

int pregunta2()
{
    cout << "----Pregunta 2----" << endl;
    cout << "Resultado esperado:" << endl;
    cout << "{\"nombre\":\"TechCorp\",\"modelos\":[],\"proyectos\":[{\"nombre\":\"Portal Ventas\",\"tecnologia\":\"React\",\"tipo\":\"web\",\"modelos\":[{\"nombre\":\"GPT-4\",\"contexto\":128000,\"tipo\":\"chat\"},{\"nombre\":\"CodeLlama\",\"lenguajes\":\"Python,C++\",\"tipo\":\"codigo\"}]},{\"nombre\":\"AppMovil\",\"plataforma\":\"Android\",\"tipo\":\"movil\",\"modelos\":[{\"nombre\":\"Mistral\",\"lenguajes\":\"Java,JS\",\"tipo\":\"codigo\"}]}]}" << endl;
  
    // crear empresa(nombre)
    Empresa empresa("TechCorp");

    // crear proyecto web(nombre, tecnologia frontend)
    Proyecto* p1 = new ProyectoWeb("Portal Ventas", "React");
    // asignar modelos al proyecto
    p1->asignar(new ModeloChat("GPT-4", 128000));
    p1->asignar(new ModeloCodigo("CodeLlama", "Python,C++"));
    empresa.registrar(p1);

    // crear proyecto movil(nombre, plataforma)
    Proyecto* p2 = new ProyectoMovil("AppMovil", "Android");
    p2->asignar(new ModeloCodigo("Mistral", "Java,JS"));
    empresa.registrar(p2);

    cout << "Resultado obtenido:" << endl;
    cout << empresa.toJson() << endl;

    if (empresa.toJson() == "{\"nombre\":\"TechCorp\",\"modelos\":[],\"proyectos\":[{\"nombre\":\"Portal Ventas\",\"tecnologia\":\"React\",\"tipo\":\"web\",\"modelos\":[{\"nombre\":\"GPT-4\",\"contexto\":128000,\"tipo\":\"chat\"},{\"nombre\":\"CodeLlama\",\"lenguajes\":\"Python,C++\",\"tipo\":\"codigo\"}]},{\"nombre\":\"AppMovil\",\"plataforma\":\"Android\",\"tipo\":\"movil\",\"modelos\":[{\"nombre\":\"Mistral\",\"lenguajes\":\"Java,JS\",\"tipo\":\"codigo\"}]}]}")
    {
        cout << "Resultado: correcto" << endl;
        return 30;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

int pregunta3()
{
    cout << "----Pregunta 3----" << endl;
    cout << "Resultado esperado:" << endl;
    cout << "{\"nombre\":\"TechCorp\",\"modelos\":[{\"nombre\":\"GPT-4\",\"contexto\":128000,\"tipo\":\"chat\"},{\"nombre\":\"CodeLlama\",\"lenguajes\":\"Python,C++\",\"tipo\":\"codigo\"},{\"nombre\":\"Mistral\",\"lenguajes\":\"Java,JS\",\"tipo\":\"codigo\"}],\"proyectos\":[{\"nombre\":\"Portal Ventas\",\"tecnologia\":\"React\",\"tipo\":\"web\",\"modelos\":[{\"nombre\":\"GPT-4\",\"contexto\":128000,\"tipo\":\"chat\"},{\"nombre\":\"CodeLlama\",\"lenguajes\":\"Python,C++\",\"tipo\":\"codigo\"}]},{\"nombre\":\"AppMovil\",\"plataforma\":\"Android\",\"tipo\":\"movil\",\"modelos\":[{\"nombre\":\"Mistral\",\"lenguajes\":\"Java,JS\",\"tipo\":\"codigo\"},{\"nombre\":\"Gemini\",\"contexto\":32000,\"tipo\":\"chat\"}]}]}" << endl;
 
    // crear empresa(nombre)
    Empresa empresa("TechCorp");
    // registrar modelos
    empresa.registrar(new ModeloChat("GPT-4", 128000));
    empresa.registrar(new ModeloCodigo("CodeLlama", "Python,C++"));
    empresa.registrar(new ModeloCodigo("Mistral", "Java,JS"));

    // registrar proyectos
    empresa.registrarProyecto(new ProyectoWeb("Portal Ventas", "React"));
    empresa.registrarProyecto(new ProyectoMovil("AppMovil", "Android"));

    // asignar modelos a proyectos por nombre de proyecto
    empresa.asignarModeloAProyecto("Portal Ventas", new ModeloChat("GPT-4", 128000));
    empresa.asignarModeloAProyecto("AppMovil", new ModeloCodigo("Mistral", "Java,JS"));
    empresa.asignarModeloAProyecto("Portal Ventas", new ModeloCodigo("CodeLlama", "Python,C++"));
    empresa.asignarModeloAProyecto("AppMovil", new ModeloChat("Gemini", 32000));

    cout << "Resultado obtenido:" << endl;
    cout << empresa.toJson() << endl;

    if (empresa.toJson() == "{\"nombre\":\"TechCorp\",\"modelos\":[{\"nombre\":\"GPT-4\",\"contexto\":128000,\"tipo\":\"chat\"},{\"nombre\":\"CodeLlama\",\"lenguajes\":\"Python,C++\",\"tipo\":\"codigo\"},{\"nombre\":\"Mistral\",\"lenguajes\":\"Java,JS\",\"tipo\":\"codigo\"}],\"proyectos\":[{\"nombre\":\"Portal Ventas\",\"tecnologia\":\"React\",\"tipo\":\"web\",\"modelos\":[{\"nombre\":\"GPT-4\",\"contexto\":128000,\"tipo\":\"chat\"},{\"nombre\":\"CodeLlama\",\"lenguajes\":\"Python,C++\",\"tipo\":\"codigo\"}]},{\"nombre\":\"AppMovil\",\"plataforma\":\"Android\",\"tipo\":\"movil\",\"modelos\":[{\"nombre\":\"Mistral\",\"lenguajes\":\"Java,JS\",\"tipo\":\"codigo\"},{\"nombre\":\"Gemini\",\"contexto\":32000,\"tipo\":\"chat\"}]}]}")
    {
        cout << "Resultado: correcto" << endl;
        return 40;
    }
    cout << "Resultado: incorrecto" << endl;
 
    return 0;
}
/*
int pregunta4()
{
    cout << "----Pregunta 4----" << endl;

    // presupuesto = costoFijo del proyecto + suma del costo de cada modelo
    // Portal Ventas (costoFijo=1000): GPT-4(300) + CodeLlama(200) = 1500
    // AppMovil      (costoFijo=1500): Mistral(250) + Gemini(400) + CodeLlama(200) = 2350
    // Dashboard     (costoFijo=1000): GPT-4(300) = 1300
    // total = 5150, masCostoso = AppMovil

    Empresa empresa("TechCorp");

    empresa.registrar(new ModeloChat("GPT-4", 128000, 300));
    empresa.registrar(new ModeloCodigo("CodeLlama", "Python,C++", 200));
    empresa.registrar(new ModeloCodigo("Mistral", "Java,JS", 250));
    empresa.registrar(new ModeloChat("Gemini", 32000, 400));

    empresa.registrarProyecto(new ProyectoWeb("Portal Ventas", "React", 1000));
    empresa.registrarProyecto(new ProyectoMovil("AppMovil", "Android", 1500));
    empresa.registrarProyecto(new ProyectoWeb("Dashboard", "Vue", 1000));

    empresa.asignarModeloAProyecto("Portal Ventas", "GPT-4");
    empresa.asignarModeloAProyecto("Portal Ventas", "CodeLlama");
    empresa.asignarModeloAProyecto("AppMovil", "Mistral");
    empresa.asignarModeloAProyecto("AppMovil", "Gemini");
    empresa.asignarModeloAProyecto("AppMovil", "CodeLlama");
    empresa.asignarModeloAProyecto("Dashboard", "GPT-4");

    cout << "Resultado esperado totalPresupuesto: 5150" << endl;
    cout << "Resultado obtenido totalPresupuesto: " << empresa.totalPresupuesto() << endl;

    cout << "Resultado esperado proyectoMasCostoso: AppMovil" << endl;
    cout << "Resultado obtenido proyectoMasCostoso: " << empresa.proyectoMasCostoso() << endl;

    if (empresa.totalPresupuesto() == 5150 && empresa.proyectoMasCostoso() == "AppMovil")
    {
        cout << "Resultado: correcto" << endl;
        return 25;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

int main()
{
    int nota = pregunta1()+pregunta2() + pregunta3();
    cout << endl;
    cout << "====================" << endl;
    cout << "===> NOTA: " << nota << "/100" << endl;
    cout << "====================" << endl;
    system("pause");
    return 0;
}

