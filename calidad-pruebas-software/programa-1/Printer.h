/*
 * Recibe el número de líneas de cada categoría y los imprime con el formato correspondiente
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de creación: 22/feb/2021
 * Fecha de modificación: 23/feb/2021
*/
#ifndef PRINTER_H
#define PRINTER_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Printer
{
    public:
        void printStats(string, int, int, int, vector<string>);
};

/*
 * Imprime el número de líneas vacías, con comentarios y con código, así como el log de 
 * errores, con el formato correspondiente
*/
void Printer::printStats(string filename, int blankCount, int commentsCount, int codeCount, vector<string> errorLog)
{
    cout << "Nombre del archivo: " << filename << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Cantidad de líneas en blanco: " << blankCount << endl;
    cout << "Cantidad de líneas con comentarios: " << commentsCount << endl;
    cout << "Cantidad de líneas con código: " << codeCount << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Cantidad total de líneas: " << (blankCount + commentsCount + codeCount) << endl;

    for (string error : errorLog)
        cout << error << endl;
}
#endif