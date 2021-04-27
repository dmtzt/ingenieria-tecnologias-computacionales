/*
 * NumericalMethods
 * Contiene los métodos numéricos necesarios para calcular la distribución t,
 * los cuales están definidos en la especificación del programa:
 *  Función gamma
 *  Distribución t para un punto x
 *  Método de Simpson para integración de la distribución t, de 0 a x
 *
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 29/03/2021
 */
//.b=59
#ifndef NUMERICALMETHODS_H
#define NUMERICALMETHODS_H
#include <cmath>
#define PI 3.14159265358979323846
#define INITIAL_NUM_SEG 2.0

using namespace std;

class NumericalMethods
{
    private:
        double distFunctionT(double, double);
        double gammaFunction(double);
    public:
        double integrationFunctionSimpson(double, double, double);
};

/*
 * Función de distribución t para un valor x, con dof grados de libertad
 * Recibe el valor de x y los grados de libertad
 * Regresa el valor de la distribución para x
 */
//.i
double NumericalMethods::distFunctionT(double x, double dof)
{
    // Calculate each term separately and then perform global product and division
    double numA = gammaFunction((dof + 1) / 2);
    double numB = pow(1 + pow(x, 2) / dof, -(dof + 1) / 2);
    double denomA = sqrt(dof * PI);
    double denomB = gammaFunction(dof / 2.0);

    return (numA * numB) / (denomA * denomB);
}

/*
 * Función gamma para un valor x
 * Es utilizada para el cálculo de la distribución t
 * Presenta recursividad para los casos en los que x no es igual a 1 o a 1/2
 */
//.i
double NumericalMethods::gammaFunction(double x)
{
    if (x == 1)
        return 1;
    else if (x == 0.5)
        return sqrt(PI);
    else
        return (x - 1) * gammaFunction(x - 1);
}

/*
 * Aplicación del método de Simpson para calcular la distribución t desde 0 hasta un valor x
 * 1. Calcula el valor de la integral con un número inicial de 2 segmentos
 * 2. Calcula un nuevo valor de la integral con el doble de segmentos que el número inicial
 * 3. Compara la diferencia absoluta entre el valor anterior y el actual de la integral
 * 4. Si la diferencia absoluta es mayor que el error máximo, vuelve a calcular un nuevo
 *    valor con el doble de segmentos hasta que ésta sea menor o igual que el error máximo
 */
//.i
double NumericalMethods::integrationFunctionSimpson(double x, double dof, double maxError)
{
    double numSeg;
    double w;
    double fInitial, fFinal;
    double fSumEven, fSumOdd;
    double p, pPrev;
    double fx;

    // Define initial number of segments
    numSeg = INITIAL_NUM_SEG;
    // Calculate width of each segment
    w = x / numSeg;
    // Reset values for the sums of even and odd terms
    fSumEven = fSumOdd = 0;

    // Calculate the area for the first and the last segments
    fInitial = distFunctionT(0, dof);
    fFinal = distFunctionT(x, dof);
    
    // Calculate the area for the intermediate segments
    for (int i = 1; i <= numSeg - 1; i++)
    {
        fx = distFunctionT(i * w, dof);
        if (i % 2 == 0)
            fSumEven += 2 * fx;
        else
            fSumOdd += 4 * fx;
    }
        
    // Calculate the integral value
    p = (w / 3) * (fInitial + fSumOdd + fSumEven + fFinal);

    // Calculate the integral value again with double the number of segments unitl the
    // absolute difference between the current and previous values is less than or equal
    // to the maximum error
    do
    {
        // Update number of segments
        numSeg *= 2;
        // Calculate new width of each segment
        w = x / numSeg;
        // Reset values for the sums of even and odd terms
        fSumEven = fSumOdd = 0;

        // Calculate the area for the intermediate segments
        for (int i = 1; i <= numSeg - 1; i++)
        {
            fx = distFunctionT(i * w, dof);
            if (i % 2 == 0)
                fSumEven += 2 * fx;
            else
                fSumOdd += 4 * fx;
        }
        
        // Save previous integral value
        pPrev = p;
        // Calculate the new integral value
        p = (w / 3) * (fInitial + fSumOdd + fSumEven + fFinal);
    }
    while(abs(pPrev - p) > maxError);

    // Return the integral value
    return p;
}
#endif