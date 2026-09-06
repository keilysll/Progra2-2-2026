#pragma once
#include"ModEmpleado.h"
#include"ModSesion.h"
class Capacitacion
{
private:
    int codigo;
    string nombre;
    ModEmpleado instructores; 
    ModEmpleado inscritos;
    ModSesion sesiones;
public:
    Capacitacion(int codigo , string nombre);
    ~Capacitacion();
    int getCodigo();
    string getNombre();
    ModEmpleado& getinstructores();
    ModEmpleado& getinscritos();
    ModSesion&  getsesiones();
    void asignarInstructor(Empleado* e);
    void inscribirEmpleados(Empleado* e);

    void agregaronSesion(Sesion* s);
    void setCodigo(int codigo);
    void setNombre(string nombre);
    string toJson();
};

