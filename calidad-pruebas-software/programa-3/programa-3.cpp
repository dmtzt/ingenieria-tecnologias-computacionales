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
//.b=59
//.d=2
#include <string>
#include "FileReader.h"
#include "Printer.h"
//.d=3

using namespace std;

int main(void)
{
    string fileName;
    FileReader fileReader;
    Printer printer;
    //.d=5

    // Set initial values to all variables used during the program execution
    fileReader.reset();

    // Read file name
    getline(cin, fileName);
    
    //.d=1
    // Open file
    fileReader.openFile(fileName);

    // Proceed if file could be opened
    if (fileReader.getFileStatus())
    {
        // Read file, extract data and do calculations
        fileReader.readFile();  
        //.d=6
        // Close file
        fileReader.closeFile();
    }

    //.d=13
    // Print all statistics
    printer.printStats(fileReader.getN(), fileReader.getXk(), fileReader.getR(), 
                       fileReader.getR2(), fileReader.getB0(), fileReader.getB1(), 
                       fileReader.getYk(), fileReader.getErrorLog()); //.m

    //.d=3
}
//.d=11