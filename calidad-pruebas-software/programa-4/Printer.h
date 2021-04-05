/*
 * Printer
 * 1. Imprime los valores de x, dof, p con el formato especificado
 * 2. Imprime mensajes según los errores encontrados durante la ejecución del programa
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 29/03/2021
 */
//.b=51
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
};

/*
 * Impresión de resultados
 * 1. Imprime los valores de x, dof, p con el formato especificado
 * 2. Imprime mensajes según los errores encontrados durante la ejecución del programa
 *    Cada error definido para el programa posee un mensaje asociado
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
        switch (errorLog[i])
        {
            //.d=27
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

/*
 * Función auxiliar para desplegar un número real con 5 decimales
 * El 5o dígito es redondeado cuando el 6o es mayor o igual a 5
 * Recibe un número como double
 * Devuelve el número formateado en string
 */
//.i
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

    // The double-string conversion keeps only 6 decimals
    string s = to_string(d);    
    // Remove the 6th decimal, keep only 5
    s.erase(s.size() - 1);
    return s;
}
#endif