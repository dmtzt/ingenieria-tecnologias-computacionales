/*
 * Programa principal
 * 1. Lee de la consola el nombre de uno o más archivos con código fuente que compila exitosamente
 * 2. Calcula el número de items
 * 3. Calcula el número de LDC totales, base, borradas, modificadas y agregadas
 * 4. Clasifica cada clase en base, nueva o reusada según sus registros
 * 5. Imprime los resultados en consola y en un archivo de texto
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 12/03/2021
 */
#include <map>
#include <queue>
#include <string>
//.d=1
#include "FileReader.h"
#include "Printer.h"
//.d=1
#include "ClassEntry.h"
#include "ClassCategories.h"

//.b=1
using namespace std;

int getCategory(ClassEntry* classEntry);

int main(void)
{
    //.b=1
    string fileName; //.m
    //.b=2
    FileReader fileReader;
    Printer printer;
    map<string, ClassEntry*> globalClasses;
    queue<ClassEntry*> baseClasses;
    queue<ClassEntry*> newClasses;
    queue<ClassEntry*> reusedClasses;
    int totalGlobal = 0;

    //.b=2
    fileReader.reset(); //.m

    getline(cin, fileName); //.m

    while (!fileName.empty())
    {
        //.b=1
        fileReader.openFile(fileName); //.m

        //.b=2
        if (fileReader.getFileStatus())
        {
            fileReader.readFile();
            
            totalGlobal += fileReader.getTotal();

            // Add class entry to global map if it does not exist
            if (globalClasses.find(fileReader.getClassName()) == globalClasses.end())
                globalClasses[fileReader.getClassName()] = fileReader.createClassEntry();
            // Update class entry from global map if it exists
            else
                fileReader.updateClassEntry(globalClasses[fileReader.getClassName()]);
                
            //.b=1
            fileReader.closeFile();
            fileReader.reset();
        }

        getline(cin, fileName);
    }

    //.b=6
    //.d=6

    // Add each class to its corresponding category
    for (map<string, ClassEntry*>::iterator it = globalClasses.begin(); it != globalClasses.end(); it++)
    {
        switch (getCategory(it->second))
        {
            case BASE_CLASS:
                baseClasses.push(it->second);
                break;
            case NEW_CLASS:
                newClasses.push(it->second);
                break;
            case REUSED_CLASS:
                reusedClasses.push(it->second);
                break;
            default:
                break;
        }
    }

    // Clear the map after all its data has been copied to the three categories
    globalClasses.clear();

    // Print the statistics for all classes
    //.b=1
    printer.printStats(baseClasses, newClasses, reusedClasses, totalGlobal, fileReader.getErrorLog()); //.m
    return 0;
}

/*
 * Define la categoría de cada clase según los criterios definidos en los requerimientos del programa
 * Devuelve la categoría como constante entera, valor que será utilizado para asignar el registro
 * de cada clase a su estructura correspondiente
 */

//.i
int getCategory(ClassEntry* classEntry)
{
    if (classEntry->getBase() > 0 && (classEntry->getModified() > 0 
        || classEntry->getDeleted() > 0 || classEntry->getAdded() > 0))
        return BASE_CLASS;
    else if (classEntry->getBase() == 0 && classEntry->getModified() == 0 
             && classEntry->getDeleted() == 0 && classEntry->getAdded() > 0)
        return NEW_CLASS;
    else if (classEntry->getBase() > 0 && classEntry->getModified() == 0 
             && classEntry->getDeleted() == 0 && classEntry->getAdded() == 0)
        return REUSED_CLASS;

    return INVALID_CLASS;
}