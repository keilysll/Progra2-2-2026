#include <iostream> 
using namespace std;

//EJERCICIO 1

void reservarMatrizEjer1(int*** matriz, int n) 
{
    *matriz = new int* [n];
    for (int i = 0; i < n; i++) {
        (*matriz)[i] = new int[i + 1];
        
    }
}

void llenarRecursivoEjer1(int** matriz, int n, int i, int j) {
    

    if (i == n) {
        
        return;
       
    }
    matriz[i][j] = i + j + 1;
    
    if (j == i) {
        llenarRecursivoEjer1(matriz, n, i + 1, 0);
       
    }

    else {

        llenarRecursivoEjer1(matriz, n, i, j + 1);
     
    }
}


void mostrarMatriz(int** matriz, int n) {
   
    for (int i = 0; i < n; i++) {
   
        for (int j = 0; j <= i; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
       
    }
}


void liberarMatriz(int** matriz, int n) 
{
    for (int i = 0; i < n; i++) 
    {

        delete[] matriz[i];
    }
    delete[] matriz;
}

//EJERCICIO 2

void reservarEjer2(int*** matriz, int n)
{
    *matriz = new int* [n];
    for (int i = 0; i < n; i++)
    {
        int cantidad;
        if (i == n / 2)
        {
            cantidad = i + 1;
        }
        else
        {
            cantidad = n - i;
        }
        (*matriz)[i] = new int[cantidad];
    }
}

void llenarEjer2(int ** matriz,int nrofila,int nrocolum,int f, int c)
 {
    if (f == nrofila)
    {
        return;
    }

    int cantidad;

    if (f <= nrofila / 2)
    {
        cantidad = f + 1;
    }
    else
    {
        cantidad = nrofila - f;
    }

    if (c == cantidad)
    {
        llenarEjer2(matriz, nrofila, 0, f + 1, 0);
    }
    else
    {
        matriz[f][c] = cantidad - c;

        llenarEjer2(matriz, nrofila, cantidad, f, c + 1);
    }
 }

void mostrarMatriz2(int** matriz, int n)
{
    for (int i = 0; i < n; i++)
    {
        int cantidad;

        if (i <= n / 2)
        {
            cantidad = i + 1;
        }
        else
        {
            cantidad = n - i;
        }

        for (int j = 0; j < cantidad; j++)
        {
            cout << matriz[i][j] << " ";
        }

        cout << endl;
    }
}



//EJERCICIO 3
void reservarEjer3(int*** matriz, int n)
{
    int totalFilas = n * 2;

    *matriz = new int* [totalFilas];

    for (int i = 0; i < totalFilas; i++)
    {
        int cantidad;

        if (i % 2 == 0)
        {
            cantidad = i / 2 + 1;
        }
        else
        {
            cantidad = (i + 1) / 2 + 1;
        }

        (*matriz)[i] = new int[cantidad];
    }
}

void llenarEjer3(int** matriz, int totalFilas, int f, int c)
{
    if (f == totalFilas)
    {
        return;
    }

    int cantidad;

    if (f % 2 == 0)
    {
        cantidad = f / 2 + 1;
    }
    else
    {
        cantidad = (f + 1) / 2 + 1;
    }

    if (c == cantidad)
    {
        llenarEjer3(matriz, totalFilas, f + 1, 0);
    }
    else
    {
        matriz[f][c] = f + c + 1;

        llenarEjer3(matriz, totalFilas, f, c + 1);
    }
}

void mostrarMatriz3(int** matriz, int totalFilas)
{
    for (int i = 0; i < totalFilas; i++)
    {
        int cantidad;

        if (i % 2 == 0)
        {
            cantidad = i / 2 + 1;
        }
        else
        {
            cantidad = (i + 1) / 2 + 1;
        }

        for (int j = 0; j < cantidad; j++)
        {
            cout << matriz[i][j] << " ";
        }

        cout << endl;
    }
}

void liberarMatriz3(int** matriz, int totalFilas)
{
    for (int i = 0; i < totalFilas; i++)
    {

        delete[] matriz[i];
    }
    delete[] matriz;
}



void liberarMatriz(int** matriz, int n)
{
    for (int i = 0; i < n; i++)
    {

        delete[] matriz[i];
    }
    delete[] matriz;
}


void reservarEjer5(int*** matriz, int n, int m)
{
    *matriz = new int* [n];

    for (int i = 0; i < n; i++)
    {
        int cantidad;

        if (i < m)
        {
            cantidad = n;
        }
        else
        {
            cantidad = m;
        }

        (*matriz)[i] = new int[cantidad];
    }
}



void llenarEjer5(int** matriz, int n, int m, int f, int c)
{
    if (f == n)
    {
        return;
    }

    int cantidad;

    if (f < m)
    {
        cantidad = n;
    }
    else
    {
        cantidad = m;
    }

    if (c == cantidad)
    {
        llenarEjer5(matriz, n, m, f + 1, 0);
    }
    else
    {
        if (f < m)
        {
            if (c < f + 1)
            {
                matriz[f][c] = c + 1;
            }
            else
            {
                matriz[f][c] = f + 1;
            }
        }
        else
        {
            matriz[f][c] = c + 1;
        }

        llenarEjer5(matriz, n, m, f, c + 1);
    }
}

void mostrarEjer5(int** matriz, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int cantidad;

        if (i < m)
        {
            cantidad = n;
        }
        else
        {
            cantidad = m;
        }

        for (int j = 0; j < cantidad; j++)
        {
            cout << matriz[i][j] << " ";
        }

        cout << endl;
    }
}
int main() 
{
    int n;
   int** matriz;
   cout << "Ingrese N: ";
   cin >> n;
   reservarMatrizEjer1(&matriz, n);
   llenarRecursivoEjer1(matriz, n, 0, 0);
  
    reservarEjer2(&matriz, n);
    llenarEjer2(matriz, n, 0, 0, 0);
    mostrarMatriz2(matriz, n);

    int totalFilas = n * 2;
    reservarEjer3(&matriz, n);
    llenarEjer3(matriz, totalFilas, 0, 0);
    mostrarMatriz3(matriz , totalFilas);
    liberarMatriz3(matriz, totalFilas);


    int n;
    int m;
    int** matriz;
    cout << "Ingrese N: ";
    cin >> n;
    cout<<"Ingrese M: ";
    cin >> m;
    reservarEjer5(&matriz,n,m);
    llenarEjer5(matriz, n, m, 0, 0);
    mostrarEjer5(matriz, n, m);
    liberarMatriz(matriz, n);

    return 0;
}

