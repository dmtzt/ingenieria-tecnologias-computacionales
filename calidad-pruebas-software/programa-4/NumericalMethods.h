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

double NumericalMethods::distFunctionT(double x, double dof)
{
    double numA = gammaFunction((dof + 1) / 2);
    double numB = pow(1 + pow(x, 2) / dof, -(dof + 1) / 2);
    double denomA = sqrt(dof * PI);
    double denomB = gammaFunction(dof / 2.0);

    return (numA * numB) / (denomA * denomB);
}

double NumericalMethods::gammaFunction(double x)
{
    if (x == 1)
        return 1;
    else if (x == 0.5)
        return sqrt(PI);
    else
        return (x - 1) * gammaFunction(x - 1);
}

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
        
    p = (w / 3) * (fInitial + fSumOdd + fSumEven + fFinal);

    // Calculate the integral value again with double the number of segments
    do
    {
        // Update number of segments
        numSeg *= 2;
        // Calculate new width of each segment
        w = x / numSeg;
        // Reset values for the sums of even and odd terms
        fSumEven = fSumOdd = 0;

        for (int i = 1; i <= numSeg - 1; i++)
        {
            fx = distFunctionT(i * w, dof);
            if (i % 2 == 0)
                fSumEven += 2 * fx;
            else
                fSumOdd += 4 * fx;
        }
        
        pPrev = p;
        p = (w / 3) * (fInitial + fSumOdd + fSumEven + fFinal);
    }
    while(abs(pPrev - p) > maxError);

    return p;
}
#endif