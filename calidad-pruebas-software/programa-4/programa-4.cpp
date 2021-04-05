/*
 * Programa 4
 * 
 * Calcula la distribución t de 0 a x con dof grados de libertad p = t(x, dof), 
 * utilizando el método de Simpson para calcular la integral de 0 a x,
 * con un error máximo de 0.0001
 *
 * Recibe dos datos:
 *  x: número real mayor o igual a cero
 *  dof: número entero mayor a cero
 *
 * Maneja los siguientes casos de error:
 *  x no es un valor numérico
 *  x es menor a cero
 *  dof no es un valor numérico
 *  dof es menor o igual a cero
 *  dof no es un entero
 *
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 29/03/2021
 */
//.b=17
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include "Printer.h"
#include "NumericalMethods.h"
#include "Errors.h"
#define DEFAULT_VALUE 0.0
#define MAX_ERROR 0.0001

using namespace std;

bool isNum(string stream);
bool isInt(double d);

//.i
int main(void)
{
    //.d=4
    Printer printer;
    NumericalMethods nm;
    vector<int> errorLog;
    string stream;
    double x = DEFAULT_VALUE;
    double dof = DEFAULT_VALUE;
    double p = DEFAULT_VALUE;
    bool inputErrorFound = false;

    // Read first line of data
    getline(cin, stream);
    // If the line contains a real number
    if (isNum(stream))
    {
        // Read number and store in x
        stringstream(stream) >> x;

        // If x is negative
        if (x < 0)
        {
            // Add error and stop normal flow of execution
            errorLog.push_back(ERROR_X_LESS_THAN_ZERO);
            inputErrorFound = true;
        }
        // If x is positive or zero
        else
        {
            // Read second line of data
            getline(cin, stream);
            // If the line contains a real number
            if (isNum(stream))
            {
                // Read number and store in dof
                stringstream(stream) >> dof;

                // If dof is not integer, add error
                if (!isInt(dof))
                    errorLog.push_back(ERROR_DOF_NOT_INT);

                // Truncate all decimals to treat value as integer
                dof = (int) dof;

                // If dof is negative or zero
                if (dof <= 0)
                {
                    // Add error and stop normal flow of execution
                    errorLog.push_back(ERROR_DOF_LESS_THAN_EQUAL_TO_ZERO);
                    inputErrorFound = true;
                }
            }
            // Line does not contain a real number
            else
            {
                // Add error and stop normal flow of execution
                errorLog.push_back(ERROR_DOF_NOT_NUM);
                inputErrorFound = true;
            }
        }
    }
    // Line does not contain a real number
    else
    {
        errorLog.push_back(ERROR_X_NOT_NUM);
        inputErrorFound = true;
    }
            
    // The normal flow of execution was not interrupted
    // Calculate the t distribution given the x and dof values
    if (!inputErrorFound)
        p = nm.integrationFunctionSimpson(x, dof, MAX_ERROR);
    
    //.d=6
    // Print results
    printer.printStats(x, dof, p, errorLog); //.m=1 
    return 0;
}

/*
 * Función auxiliar para verificar si una línea contiene un número real
 * Considera como válidos a los caracteres numéricos, '.' y '-'
 * Cualquier otro caracter se considera como no válido
 */
//.i
bool isNum(string stream)
{
    for (char c : stream)
    {
        if (!isspace(c))
            if (!isdigit(c) && c != '-' && c != '.')
                return false;
    }
    
    return true;
}

/*
 * Función auxiliar para verificar si un número real es entero
 */
//.i
bool isInt(double d)
{
    return (d - (int) d == 0);
}