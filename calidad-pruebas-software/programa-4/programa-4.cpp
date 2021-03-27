/*
 * 1. Calcula una regresión lineal a partir de un conjunto de datos extraídos de un archivo dado
 * 2. Aplica dicha regresión para utilizar el método PROBE A, el cual es usado para realizar
 * predicciones de tamaño y tiempo de elaboración de código con base en datos históricos
 * 3. Imprime el número de datos, los valores de la ecuación de la regresión lineal, la
 * correlación y cualquier error encontrado durante el proceso
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 20/03/2021
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
double ceilDecimals(double d);

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

    getline(cin, stream);
    if (isNum(stream))
    {
        stringstream(stream) >> x;

        if (x < 0)
        {
            errorLog.push_back(ERROR_X_LESS_THAN_ZERO);
            inputErrorFound = true;
        }
        else
        {
            getline(cin, stream);
            if (isNum(stream))
            {
                stringstream(stream) >> dof;

                if (!isInt(dof))
                    errorLog.push_back(ERROR_DOF_NOT_INT);

                // Truncate all decimals to treat value as integer
                dof = (int) dof;

                if (dof <= 0)
                {
                    errorLog.push_back(ERROR_DOF_LESS_THAN_EQUAL_TO_ZERO);
                    inputErrorFound = true;
                }
            }
            else
            {
                errorLog.push_back(ERROR_DOF_NOT_NUM);
                inputErrorFound = true;
            }
        }
    }
    else
    {
        errorLog.push_back(ERROR_X_NOT_NUM);
        inputErrorFound = true;
    }
            
    if (!inputErrorFound)
        p = nm.integrationFunctionSimpson(x, dof, MAX_ERROR);
    
    //.d=6
    // Print all statistics
    printer.printStats(x, dof, p, errorLog); //.m=1 
}

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

bool isInt(double d)
{
    return (d - (int) d == 0);
}