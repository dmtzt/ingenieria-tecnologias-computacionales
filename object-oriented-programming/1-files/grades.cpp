/* 
 * grades.cpp
 * 
 * Lee una lista de calificaciones y obtiene
 * la mayor, la menor, el promedio y la cantidad de calificaciones.
 * Omite valores que no se encuentren dentro del rango 0-100.
 *
 * David Alejandro Martinez Tristan
 * 21/01/2019
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    double curr;
    double small = 100;
    double big = 0;
    double avg = 0;
    double quantity = 0;

    ifstream infile;

    infile.open("grades.txt");

    while(!infile.eof())
    {
        infile >> curr;
        if (curr >= 0 && curr <= 100)
        {
            if (curr > big)
                big = curr;
            
            if (curr < small)
                small = curr;

            avg += curr;
            quantity++;
        }
    }

    infile.close();

    avg /= quantity;

    cout << "small: " << small << " ";
    cout << "big: " << big << " ";
    cout << "avg: " << avg << " ";
    cout << "quantity: " << quantity << endl;

    return 0;
}
