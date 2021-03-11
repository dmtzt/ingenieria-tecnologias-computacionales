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
#include <map>
#include <queue>
#include <string>
#include <vector>
#include "ClassEntry.h"

using namespace std;

//.b=3
class Printer
{
    public:
        void printStats(queue<ClassEntry*>, queue<ClassEntry*>, queue<ClassEntry*>, int);
};

/*
 * Imprime el número de líneas vacías, con comentarios y con código, así como el log de 
 * errores, con el formato correspondiente
*/
//.i
//.m=2
void Printer::printStats(queue<ClassEntry*> baseClasses, 
    queue<ClassEntry*> newClasses, queue<ClassEntry*> reusedClasses, int totalGlobal)
{
    cout << "CLASES BASE:" << endl;
    ClassEntry* classEntry = NULL;
    while (!baseClasses.empty())
    {
        classEntry = baseClasses.front();
        if (classEntry->getTotal() > 0)
        {
            cout << classEntry->getClassName() << ": ";
            cout << "T=" << classEntry->getTotal();
            
            if (classEntry->getItems() > 0)
                cout << ", I=" << classEntry->getItems();
            if (classEntry->getBase())
                cout << ", B=" << classEntry->getBase();
            if (classEntry->getDeleted())
                cout << ", D=" << classEntry->getDeleted();
            if (classEntry->getModified() > 0)
                cout << ", M=" << classEntry->getModified();
            if (classEntry->getAdded() > 0)
                cout << ", A=" << classEntry->getAdded();

            cout << endl;
        }   

        baseClasses.pop();
        delete classEntry; 
    }
    
    cout << "--------------------------------------------" << endl;
    cout << "CLASES NUEVAS:" << endl;
    while (!newClasses.empty())
    {
        classEntry = newClasses.front();
        if (classEntry->getTotal() > 0)
        {
            cout << classEntry->getClassName() << ": ";
            cout << "T=" << classEntry->getTotal();
            
            if (classEntry->getItems() > 0)
                cout << ", I=" << classEntry->getItems();

            cout << endl;
        }   

        newClasses.pop(); 
        delete classEntry;
    }

    cout << "--------------------------------------------" << endl;
    cout << "CLASES REUSADAS:" << endl;
    while (!reusedClasses.empty())
    {
        classEntry = reusedClasses.front();
        if (classEntry->getTotal() > 0)
        {
            cout << classEntry->getClassName() << ": ";
            cout << "T=" << classEntry->getTotal();
            
            if (classEntry->getItems() > 0)
                cout << ", I=" << classEntry->getItems();
            if (classEntry->getBase())
                cout << ", B=" << classEntry->getBase();

            cout << endl;
        }   

        reusedClasses.pop();
        delete classEntry;
    }

    cout << "--------------------------------------------" << endl;
    cout << "Total de LDC=" << totalGlobal << endl;
}
#endif