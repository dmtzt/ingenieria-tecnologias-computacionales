/*
 * 1. Imprime el valor de la regresión lineal ysus parámetros, la significancia,
 * el intervalo de predicción al 70%, el límite superior y el límite inferior, siguiendo
 * el formato especificado en los requerimientos del programa, así como los mensajes de
 * los códigos de error encontrados en el programa
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 25/04/2021
 */
//.b=51
#ifndef PRINTER_H
#define PRINTER_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Printer
{
    string ceilDecimals(double);
    public:
        void printResults(int, double, double, double, double, double, double, double, double, double, double, vector<int>); //.m
};

/*
 * 1. Imprime el valor de la regresión lineal ysus parámetros, la significancia,
 * el intervalo de predicción al 70%, el límite superior y el límite inferior, siguiendo
 * el formato especificado en los requerimientos del programa
 * 2. Imprime los mensajes de los códigos de error encontrados durante la ejecución del programa
 */
//.i
void Printer::printResults(int n, double xk, double r, double r2, double b0, double b1, 
                         double yk, double sig, double ran, double LS, double LI, vector<int> errorLog) //.m
{
    cout << "N  = " << n << endl;
    cout << "xk = " << ceilDecimals((double) xk) << endl; //.m
    cout << "r  = " << ceilDecimals(r) << endl; //.m
    cout << "r2 = " << ceilDecimals(r2) << endl; //.m
    cout << "b0 = " << ceilDecimals(b0) << endl; //.m
    cout << "b1 = " << ceilDecimals(b1) << endl; //.m
    cout << "yk = " << ceilDecimals(yk) << endl; //.m
    cout << "sig= " << fixed << setprecision(10) << sig << endl;
    cout << "ran= " << ceilDecimals(ran) << endl;
    cout << "LS = " << ceilDecimals(LS) << endl;
    cout << "LI = " << ceilDecimals(LI) << endl;

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

/*
 * Redondea un valor de tipo double a 5 decimales hacia arriba según la especificación del programa
 */
//.b=11
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