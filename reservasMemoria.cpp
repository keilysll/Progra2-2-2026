// reservasMemoria.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
//
//X X X X
//X X X X
//X X X X
//X X X X
void reservar(int*** matriz, int n)
{
    *matriz = new int* [n];

    for (int i = 0; i < n; i++)
    {
        (*matriz)[i] = new int[n];
    }
}


//X . . .
//X X . .
//X X X .
//X X X X

void reservar(int*** matriz, int n)
{
    *matriz = new int* [n];

    for (int i = 0; i < n; i++)
    {
        (*matriz)[i] = new int[i + 1];
    }
}


//X X X X
//X X X .
//X X . .
//X . . .
void reservar(int*** matriz, int n)
{
    *matriz = new int* [n];

    for (int i = 0; i < n; i++)
    {
        (*matriz)[i] = new int[n - i];
    }
}


//X X X X
//..X X X
//....X X
//......X
void reservar(int*** matriz, int n)
{
    *matriz = new int* [n];

    for (int i = 0; i < n; i++)
    {
        (*matriz)[i] = new int[n - i];
    }
}


//. ....X
//....X X
//..X X X
//X X X X

void reservar(int*** matriz, int n)
{
    *matriz = new int* [n];

    for (int i = 0; i < n; i++)
    {
        (*matriz)[i] = new int[i + 1];
    }
}
