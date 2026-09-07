#include <iostream>
using namespace std;
/*
//ejercicio 1
void reservar(int*** matriz, int n)
{
    *matriz = new int* [n];

    for (int i = 0; i < n; i++)
    {
        (*matriz)[i] = new int[n];
    }
}

void llenar(int** matriz, int f, int n, int& cont)
{
    if (f == n)
    {
        return;
    }

    for (int j = 0; j < n; j++)
    {
        matriz[f][j] = cont;
        cont++;
    }

    llenar(matriz, f + 1, n, cont);
}

void mostrar(int** matriz, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matriz[i][j] << " ";
        }

        cout << endl;
    }
}
*/

//ejercicio 2
/*
void reservar2(int*** matriz, int n)
{
    int filas = 2 * n - 1;

    *matriz = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        int cantidad;
        if (i < n)
        {
            cantidad = n - i;
        }
        else
        {
            cantidad = i - n + 2;
        }
        (*matriz)[i] = new int[cantidad];
    }
}

void llenar2(int** matriz, int n, int f, int c)
{
    int filas = 2 * n - 1;
    if (f == filas)
    {
        return;
    }
    int cantidad;
    if (f < n)
    {
        cantidad = n - f;
    }
    else
    {
        cantidad = f - n + 2;
    }
    if (c == cantidad) 
    { 
        llenar2(matriz, n, f + 1, 0); 
    }
    else 
    {
        matriz[f][c] = cantidad - c;
        llenar2(matriz, n, f, c + 1);
    }
     
}

void mostrar2(int** matriz, int n)
{
    int filas = 2 * n - 1;
    for (int i = 0; i < filas; i++)
    {
        int cantidad;
        if (i < n)
        {
            cantidad = n - i;
        }
        else
        {
            cantidad = i - n + 2;
        }
        for (int j = 0; j < cantidad; j++)
        {
            cout << matriz[i][j];
       }

        cout << endl;
    }

}
*/

//ejercicio 3

// Reservar memoria
void reservar3(int*** matriz, int n)
{
    int filas = 4 * n - 2;

    *matriz = new int* [filas];

    for (int i = 0; i < filas; i++)
    {
        int cantidad;

        if (i < 2 * n)
        {
            cantidad = n - i / 2;
        }

        else
        {
            cantidad = (i - 2 * n + 2) / 2;
        }

        (*matriz)[i] = new int[cantidad];
    }
}

// Llenar recursivamente
void llenar3(int** matriz, int n, int f, int c)
{
    int filas = 4 * n - 2;

    // Caso base
    if (f == filas)
    {
        return;
    }

    int cantidad;

    // Determinar cantidad de columnas
    if (f < 2 * n)
    {
        cantidad = n - f / 2;
    }
    else
    {
        cantidad = (f - 2 * n ) / 2+2;
    }

    // Pasar a la siguiente fila
    if (c == cantidad)
    {
        llenar3(matriz, n, f + 1, 0);
    }
    else
    {
     
        if (f % 2 == 0)
        {
            matriz[f][c] = cantidad - c;
        }
        else
        {
            matriz[f][c] = c + 1;
        }

        // Siguiente columna
        llenar3(matriz, n, f, c + 1);
    }
}

// Mostrar
void mostrar3(int** matriz, int n)
{
    int filas = 4 * n - 2;

    for (int i = 0; i < filas; i++)
    {
        int cantidad;

        if (i < 2 * n)
        {
            cantidad = n - i / 2;
        }
        else
        {
            cantidad = (i - 2 * n) / 2+2;
        }

        for (int j = 0; j < cantidad; j++)
        {
            cout << matriz[i][j];
        }

        cout << endl;
    }
}



void liberar3(int** matriz, int n) 
{ int filas = 4 * n - 2; 
for (int i = 0; i < filas; i++)
    { delete[] matriz[i]; 
    } delete[] matriz; 
}
// Liberar memoria

void liberar(int** matriz, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matriz[i];
    }

    delete[] matriz;
}

int main()
{
    int n;
    int** mat;
    int cont = 1;

    cout << "Escribe n: ";
    cin >> n;

    //reservar(&mat, n);
    //llenar(mat, 0, n, cont);
    //mostrar(mat, n);

    //reservar2(&mat, n);
    //llenar2(mat, n, 0,0);
    //mostrar2(mat, n);
    //liberar(mat, n);

    reservar3(&mat,n);
    llenar3(mat,n,0,0);
    mostrar3(mat,n);
    liberar3(mat, n);

    return 0;
}

