/*
 * Programa 5
 * 
 * Calcula el valor aproximado de x tal que al integrar de 0 a x con una función de
 * distribución t con dof grados de libertad, se obtenga como resultado el valor p objetivo
 *
 * Recibe dos datos:
 *  p: número real entre 0 y 0.5
 *  dof: número entero mayor a cero
 *
 * Maneja los siguientes casos de error:
 *  p no es un valor numérico
 *  p se encuentra fuera del rango: 0 >= p >= 0.5
 *  dof no es un valor numérico
 *  dof no es un entero
 *  dof se encuentra fuera del rango: p > 0
 *
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 08/04/2021
 */
//.b=55
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include "Printer.h"
#include "NumericalMethods.h"
#include "Errors.h"
#define DEFAULT_VALUE 0.0
#define INITIAL_TRIAL_VALUE 1.0
#define INITIAL_DELTA_VALUE 0.5
#define MAX_ERROR_I 0.0001
#define MAX_ERROR_P 0.0000001
#define MAX_NUM_ITERATIONS 30

using namespace std;

bool isNum(string stream);
bool isInt(double d);

//.i
int main(void)
{
    Printer printer;
    NumericalMethods nm;
    vector<int> errorLog;
    string stream;
    double x = INITIAL_TRIAL_VALUE; //.m
    double dof = DEFAULT_VALUE;
    double pT = DEFAULT_VALUE; //.m
    double d = INITIAL_DELTA_VALUE;
    double pCurr = DEFAULT_VALUE;
    double pPrev = DEFAULT_VALUE;
    double error = DEFAULT_VALUE;
    bool inputErrorFound = false;
    int numIterations = MAX_NUM_ITERATIONS;
    enum direction_ {left, right} direction;

    // Read first line of data
    getline(cin, stream);
    // If the line contains a real number
    if (isNum(stream))
    {
        // Read number and store in p
        stringstream(stream) >> pT; //.m

        // If p is outside the limits
        if (pT < 0 || pT > 0.5)
        {
            // Add error and stop normal flow of execution
            errorLog.push_back(ERROR_P_OUT_OF_LIMITS); //.m
            inputErrorFound = true;
        }
        // If p is inside of the limits
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
                    errorLog.push_back(ERROR_DOF_OUT_OF_LIMITS); //.m
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
        // Add error and stop normal flow of execution
        errorLog.push_back(ERROR_P_NOT_NUM); //.m
        inputErrorFound = true;
    }
            
    // The normal flow of execution was not interrupted
    // Calculate the x estimate valuefor the given p and dof values
    if (!inputErrorFound)
    {   
        pPrev = pT;
        // Calculate initial p estimate given the initial x
        pCurr = nm.integrationFunctionSimpson(x, dof, MAX_ERROR_I);
        // Set initial adjustment direction
        direction = (pCurr - pPrev > 0) ? right : left;

        // Calculate new x values until the absolute difference between p target and 
        // p estimate is less than or equal to the max error
        while (abs(error = pCurr - pPrev) > MAX_ERROR_P && --numIterations > 0)
        {
            // Update d value when the sign of error changes
            // Change from negative to positive
            if (error > 0 && direction == left)
            {
                direction = right;
                d /= 2;
            }
            // Change from positive to negative
            else if (error < 0 && direction == right)
            {
                direction = left;
                d /= 2;
            }

            // The value is too low: add d to trial x
            if (pCurr < pT)
                x += d;
            // The value is too high: subtract d to trial x
            else
                x -= d;

            // Try new x value with a new p approximation
            pPrev = pCurr;
            pCurr = nm.integrationFunctionSimpson(x, dof, MAX_ERROR_I);
        }  
    }
       
    // Print results
    printer.printResults(x, dof, pCurr, errorLog); //.m
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