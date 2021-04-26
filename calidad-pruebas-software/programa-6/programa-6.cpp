/*
 * 1. Calcula una regresión lineal a partir de un conjunto de datos extraídos de un archivo dado,
 * junto con su significancia y su intervalo de predicción al 70%
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 25/04/2021
 */
//.b=17
#include <string>
#include "FileReader.h"
#include "Printer.h"

using namespace std;

int main(void)
{
    string fileName;
    FileReader fileReader;
    Printer printer;

    // Set initial values to all variables used during the program execution
    fileReader.reset();

    // Read file name
    getline(cin, fileName);
    
    // Open file
    fileReader.openFile(fileName);

    // Proceed if file could be opened
    if (fileReader.getFileStatus())
    {
        // Read file, extract data and do calculations
        fileReader.readFile();  
        // Close file
        fileReader.closeFile();
    }

    // Print all statistics
    printer.printResults(fileReader.getN(), fileReader.getXk(), fileReader.getR(), 
                       fileReader.getR2(), fileReader.getB0(), fileReader.getB1(), 
                       fileReader.getYk(), fileReader.getSig(), fileReader.getRan(),
                       fileReader.getLS(), fileReader.getLI(), fileReader.getErrorLog()); //.m
}