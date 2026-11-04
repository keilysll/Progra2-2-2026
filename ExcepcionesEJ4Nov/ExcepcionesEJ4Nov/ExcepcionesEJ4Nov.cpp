#include <iostream>
#include<sstream>
#include<string>
using namespace std;

#include"DivZeroException.h"
#include"NegValueExcep.h"


void ejem1(int a , int b)
{
    try {
        int suma = a + b;
        if (b == 0)
            throw string("Error, div zero");
        int div = a / b;
        int dif = a - b;
        int prod = a * b;
        cout << " sum: " << suma << " div: " << div << " dif: " << dif << " produc: " << prod << endl;
    }
    catch (string& err)
    {
        cout << "No se puedo completar: " << err << endl;
    }

}

void ejem2(int a , int b)
{
    int suma = a + b;
    if (b == 0)
        throw string("Error, div zero");
    int div = a / b;
    int dif = a - b;
    int prod = a * b;
    cout << " sum: " << suma << " div: " << div << " dif: " << dif << " produc: " << prod << endl;
}

void ejem3(int a, int b)
{
    try {
        ejem2(a, b);
    }
    catch (string& err)
    {
        cout << "No se puedo completar: " << err << endl;
    }
}

void ejem4(int a , int b) // clase exception
{
    try {
        int suma = a + b;
        if (b == 0)
            throw exception("Error, div zero");
        int div = a / b;
        int dif = a - b;
        int prod = a * b;
        cout << " sum: " << suma << " div: " << div << " dif: " << dif << " produc: " << prod << endl;
    }
    catch (exception& err)
    {
        cout << "No se puedo completar: " << err.what() << endl; // what() que paso
    }
}

void ejem5(int a, int b)
{
    try {
        int suma = a + b;
        if (b == 0)
            throw DivZeroException(a,b);
        int div = a / b;
        int dif = a - b;
        int prod = a * b;
        cout << " sum: " << suma << " div: " << div << " dif: " << dif << " produc: " << prod << endl;
    }
    catch (DivZeroException& err)
    {
        cout << "No se puedo completar: " << err.what() << endl;
    }

}

void ejem6(int a, int b) // 2 throws con 2 catchs
{
    try {
        if (a < 0 || b < 0)
            throw NegValueExcep(a, b);
        int suma = a + b;
        if (b == 0)
            throw DivZeroException(a, b);
        int div = a / b;
        int dif = a - b;
        int prod = a * b;
        cout << " sum: " << suma << " div: " << div << " dif: " << dif << " produc: " << prod << endl;
    }
    catch (DivZeroException& err)
    {
        cout << "No se puedo completar: " << err.what() << endl;
    }

    catch (NegValueExcep& err)
    {
        cout << "No se puedo completar: " << err.what() << endl;
    }
}

void ejem7(int a, int b)// dos throws coon un solo catch clase padre exception
{
    try {
        if (a < 0 || b < 0)
            throw NegValueExcep(a, b);
        int suma = a + b;
        if (b == 0)
            throw DivZeroException(a, b);
        int div = a / b;
        int dif = a - b;
        int prod = a * b;
        cout << " sum: " << suma << " div: " << div << " dif: " << dif << " produc: " << prod << endl;
    }
    catch (exception& err)
    {
        cout << "No se puedo completar: " << err.what() << endl;
    }
}

void ejem8(int a, int b) 
{
    try {
        if (a > 1000 || b > 1000)
            throw exception("valores muy altos");
        if (a < 0 || b < 0)
            throw NegValueExcep(a, b);
        int suma = a + b;
        if (b == 0)
            throw DivZeroException(a, b);
        int div = a / b;
        int dif = a - b;
        int prod = a * b;
        cout << " sum: " << suma << " div: " << div << " dif: " << dif << " produc: " << prod << endl;
    }
    catch (DivZeroException& err)// un divZeroEx es una exception pero un exception no es divZer
    {
        cout << "No se puedo completar: " << err.what() << endl;
    }

    catch (NegValueExcep& err)
    {
        cout << "No se puedo completar: " << err.what() << endl;
    }
    catch (exception& err) // agarra cualquier tipo de excepciones
    {
        cout << "No se puedo completar: " << err.what() << endl;
    }
}
int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    ejem8(a,b);
}

