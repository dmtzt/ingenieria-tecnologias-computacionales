/*
 * 1. Imprime el valor de la regresión lineal y sus parámetros, siguiendo el formato 
 * especificado en los requerimientos del programa
 * 2. Imprime mensajes según los errores encontrados durante la ejecución del programa
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 20/03/2021
 */
#ifndef PRINTER_H
#define PRINTER_H
//.d=2
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
//.d=2

using namespace std;

//.b=90

class Printer
{
    //.d=1
    public:
        void printStats(int, int, double, double, double, double, double, vector<int>); //.m
};

/*
 * 1. Imprime el valor de la regresión lineal y sus parámetros, siguiendo el formato 
 * especificado en los requerimientos del programa
 * 2. Imprime mensajes según los errores encontrados durante la ejecución del programa
 * Hay un mensaje definido para cada error especificado
 */
//.d=2
//.i
void Printer::printStats(int n, int xk, double r, double r2, double b0, double b1, 
                         double yk, vector<int> errorLog) //.m
{
    //.d=67
    cout << "N  = " << n << endl;
    cout << "xk = " << xk << endl;
    cout << "r  = " << fixed << setprecision(5) << r << endl;
    cout << "r2 = " << fixed << setprecision(5) << r2 << endl;
    cout << "b0 = " << fixed << setprecision(5) << b0 << endl;
    cout << "b1 = " << fixed << setprecision(5) << b1 << endl;
    cout << "yk = " << fixed << setprecision(5) << yk << endl;

    for (int i = 0; i < errorLog.size(); i++)
    {
        switch (errorLog[i]) //.m
        {
        case ERROR_FILE_NOT_EXISTS:
            cout << "El archivo no existe" << endl;
            break;
        case ERROR_FILE_EMPTY:
            cout << "El archivo está vacío" << endl;
            break;
        case ERROR_XK_NOT_EXISTS:
            cout << "El valor de xk no existe o no tiene el formato correcto" << endl;
            break;
        case ERROR_XK_NOT_NUM:
            cout << "El valor de xk no es un número" << endl;
            break;
        case ERROR_VALUE_NOT_EXISTS:
            cout << "El valor de un par ordenado no existe y ha sido omitido" << endl;
            break;
        case ERROR_VALUE_NOT_NUM:
            cout << "El valor de un par ordenado no es un número y ha sido omitido" << endl;
            break;
        case ERROR_VALUE_NEGATIVE:
            cout << "El valor de un par ordenado es negativo y ha sido omitido" << endl;
            break;
        case ERROR_NO_PAIRS:
            cout << "El archivo no contiene pares ordenados" << endl;
            break;
        case ERROR_DIVISION_BY_ZERO:
            cout << "Ocurrió una división por 0 durante una operación" << endl;
            break;
        default:
            break;
        }
    }
}
#endif