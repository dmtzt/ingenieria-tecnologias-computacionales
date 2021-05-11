/*
 * Imprime el valor de la regresión múltiple y sus parámetros, siguiendo el formato 
 * especificado en los requerimientos del programa
 * Imprime mensajes según los errores encontrados durante la ejecución del programa
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 10/05/2021
 */
#ifndef PRINTER_H
#define PRINTER_H
//.b=51
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Errors.h"

using namespace std;

class Printer
{
    public:
        void printResults(int, double, double, double, double, double, double, double, double, vector<int>); //.m
};

/*
 * Imprime el valor de la regresión múltiple y sus parámetros, siguiendo el formato 
 * especificado en los requerimientos del programa
 * Imprime mensajes según los errores encontrados durante la ejecución del programa
 */
//.i
void Printer::printResults(int n, double wk, double xk, double yk, double zk, double b0, double b1, 
                        double b2, double b3, vector<int> errorLog) //.m
{
    cout << "N  = " << n << endl;
    cout << "wk = " << fixed << setprecision(5) << wk << endl;
    cout << "xk = " << fixed << setprecision(5) << xk << endl; //.m
    cout << "yk = " << fixed << setprecision(5) << yk << endl;
    cout << "------------" << endl;
    cout << "b0 = " << fixed << setprecision(5) << b0 << endl;
    cout << "b1 = " << fixed << setprecision(5) << b1 << endl;
    cout << "b2 = " << fixed << setprecision(5) << b2 << endl;
    cout << "b3 = " << fixed << setprecision(5) << b3 << endl;
    cout << "------------" << endl;
    cout << "zk = " << fixed << setprecision(5) << zk << endl;

    //.d=2

    for (int i = 0; i < errorLog.size(); i++)
    {
        switch (errorLog[i])
        {
        case ERROR_FILE_NOT_EXISTS:
            cout << "El archivo no existe" << endl;
            break;
        case ERROR_FILE_EMPTY:
            cout << "El archivo está vacío" << endl;
            break;
        //.d=21
        default:
            break;
        }
    }
}
#endif