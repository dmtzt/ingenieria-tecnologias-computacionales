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
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Errors.h"

using namespace std;

class Printer
{
    string ceilDecimals(double);
    public:
        void printStats(double, int, double, vector<int>); //.m
    //.d=1
};

/*
 * 1. Imprime el valor de la regresión lineal y sus parámetros, siguiendo el formato 
 * especificado en los requerimientos del programa
 * 2. Imprime mensajes según los errores encontrados durante la ejecución del programa
 * Hay un mensaje definido para cada error especificado
 */
//.i
void Printer::printStats(double x, int dof, double p, vector<int> errorLog) //.m
{
    //.d=8

    cout << "  x: " << ceilDecimals(x) << endl;
    cout << "dof: " << dof << endl;
    cout << "  p: " << ceilDecimals(p) << endl;

    for (int i = 0; i < errorLog.size(); i++)
    {
        switch (errorLog[i]) //.m
        {
            case ERROR_X_NOT_NUM:
                cout << "El valor de x no es un número" << endl;
                break;
            case ERROR_X_LESS_THAN_ZERO:
                cout << "El valor de x no es un número mayor o igual a 0" << endl;
                break;
            case ERROR_DOF_NOT_NUM:
                cout << "El valor de dof no es un número" << endl;
                break;
            case ERROR_DOF_NOT_INT:
                cout << "El valor de dof no es un número entero: los decimales fueron truncados" << endl;
                break;
            case ERROR_DOF_LESS_THAN_EQUAL_TO_ZERO:
                cout << "El valor de dof no es un número mayor a 0" << endl;
                break;
            default:
                break;
        }
    }
}

string Printer::ceilDecimals(double d)
{
    d *= 100000;
    
    if (d - (int) d >= 0.5)
    {
        if (d - (int)d >= 0.9)
            d += 0.1;
        else
            d++;
    }

    d /= 100000;

    string s = to_string(d);    
    s.erase(s.size() - 1);
    return s;
}
#endif