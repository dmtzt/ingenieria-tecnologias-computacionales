/*
 * Recibe el número de líneas de cada categoría y los imprime con el formato correspondiente
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de creación: 22/feb/2021
 * Fecha de modificación: 23/feb/2021
*/
#ifndef PRINTER_H
#define PRINTER_H
#define OUTPUT_FILE_NAME "ConteoLDC.txt"
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "ClassEntry.h"

using namespace std;

//.b=3
class Printer
{
    ofstream file;
    public:
        void printStats(queue<ClassEntry*>, queue<ClassEntry*>, queue<ClassEntry*>, int, vector<string>);
};

/*
 * Imprime el número de líneas vacías, con comentarios y con código, así como el log de 
 * errores, con el formato correspondiente
*/
//.i
//.m=2
void Printer::printStats(queue<ClassEntry*> baseClasses, 
    queue<ClassEntry*> newClasses, queue<ClassEntry*> reusedClasses, int totalGlobal, 
    vector<string> errorLog)
{
    file.open(OUTPUT_FILE_NAME);
    file << "CLASES BASE:" << endl;
    ClassEntry* classEntry = NULL;
    while (!baseClasses.empty())
    {
        classEntry = baseClasses.front();
        if (classEntry->getTotal() > 0)
        {
            file << classEntry->getClassName() << ": ";
            file << "T=" << classEntry->getTotal();
            file << ", I=" << classEntry->getItems();
            file << ", B=" << classEntry->getBase();
            file << ", D=" << classEntry->getDeleted();
            file << ", M=" << classEntry->getModified();
            file << ", A=" << classEntry->getAdded();

            file << endl;
        }   

        baseClasses.pop();
        delete classEntry; 
    }
    
    file << "--------------------------------------------" << endl;
    file << "CLASES NUEVAS:" << endl;
    while (!newClasses.empty())
    {
        classEntry = newClasses.front();
        if (classEntry->getTotal() > 0)
        {
            file << classEntry->getClassName() << ": ";
            file << "T=" << classEntry->getTotal();
            file << ", I=" << classEntry->getItems();

            file << endl;
        }   

        newClasses.pop(); 
        delete classEntry;
    }

    file << "--------------------------------------------" << endl;
    file << "CLASES REUSADAS:" << endl;
    while (!reusedClasses.empty())
    {
        classEntry = reusedClasses.front();
        if (classEntry->getTotal() > 0)
        {
            file << classEntry->getClassName() << ": ";
            file << "T=" << classEntry->getTotal();
            file << ", I=" << classEntry->getItems();
            file << ", B=" << classEntry->getBase();

            file << endl;
        }   

        reusedClasses.pop();
        delete classEntry;
    }

    file << "--------------------------------------------" << endl;
    file << "Total de LDC=" << totalGlobal << endl;

    cout << errorLog.size() << endl;

    for (int i = 0; i < errorLog.size(); i++)
        cout << errorLog[i] << endl;

    file.close();
}
#endif