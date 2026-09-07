// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

void reservar(int*** matriz, int n)
{
    int filas = 2 * n - 1;

    *matriz = new int* [filas];

    for (int i = 0; i < filas; i++)
    {
        if (i < n)
        {
            (*matriz)[i] = new int[n - i];
        }
        else
        {
            (*matriz)[i] = new int[i - n + 2];
        }
    }
}

void mostrar(int** mat, int n)
{
    int filas = 2 * n - 1;

    for (int i = 0; i < filas; i++)
    {
        int cantidad;
    
        if (i < n)
        {
          cantidad =n - i;
        }
        else
        {
            cantidad=i - n + 2;
        }
        for (int j = 0; j < cantidad; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;

    }
}
void liberar(int** mat, int n)
{
    int filas = 2 * n - 1;
    for (int i = 0; i < filas ;i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

int main()
{
    int** mat;
    int n;
    cout << "escribe n";
    cin >> n;

    reservar(&mat, n);
    mostrar(mat,n);
     
}

