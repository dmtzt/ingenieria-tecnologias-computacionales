/*
 * Calcula una regresion multiple para estimar el numero de horas para un nuevo proyecto
 * con un numero determinado de LOC agregadas, reusadas y modificadas
 *
 * Utiliza datos almacenados en un archivo de horas de desarrollo y LOC agregadas, reusadas
 * y modificadas de proyectos anteriores para realizar el calculo
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 10/05/2021
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

    // Print results
    printer.printResults(fileReader.getN(), fileReader.getWk(), fileReader.getXk(),
    fileReader.getYk(), fileReader.getZk(), fileReader.getB0(), fileReader.getB1(),
    fileReader.getB2(), fileReader.getB3(), fileReader.getErrorLog());
    //.m
    //.m
    //.m
}