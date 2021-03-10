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
#include <string>
#include <vector>
#include "ClassEntry.h"

using namespace std;

//.b=3
class Printer
{
    public:
        void printStats(map<string, ClassEntry*>, map<string, ClassEntry*>, map<string, ClassEntry*>, int);
};

/*
 * Imprime el número de líneas vacías, con comentarios y con código, así como el log de 
 * errores, con el formato correspondiente
*/
//.i
//.m=2
void Printer::printStats(map<string, ClassEntry*> baseClasses, 
    map<string, ClassEntry*> newClassses, map<string, ClassEntry*> reusedClasses, int totalGlobal)
{
    cout << "CLASES BASE:" << endl;
    for (map<string, ClassEntry*>::iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
    {
        if (it->second->getTotal() > 0)
        {
            cout << it->second->getClassName() << ": ";
            cout << "T=" << it->second->getTotal();
            
            if (it->second->getItems() > 0)
                cout << ", I=" << it->second->getItems();
            if (it->second->getBase())
                cout << ", B=" << it->second->getBase();
            if (it->second->getDeleted())
                cout << ", D=" << it->second->getDeleted();
            if (it->second->getModified() > 0)
                cout << ", M=" << it->second->getModified();
            if (it->second->getAdded() > 0)
                cout << ", A=" << it->second->getAdded();

            cout << endl;
        }
        
    }
    
    cout << "--------------------------------------------" << endl;
    cout << "CLASES NUEVAS:" << endl;
    for (map<string, ClassEntry*>::iterator it = newClassses.begin(); it != newClassses.end(); it++)
    {
        cout << it->second->getClassName() << ": ";
        cout << "T=" << it->second->getTotal() << ", ";
        cout << "I=" << it->second->getItems() << ", ";
        cout << "B=" << it->second->getBase() << ", ";
        cout << "D=" << it->second->getDeleted() << ", ";
        cout << "M=" << it->second->getModified() << ", ";
        cout << "A=" << it->second->getAdded() << endl;
    }

    cout << "--------------------------------------------" << endl;
    cout << "CLASES REUSADAS:" << endl;
    for (map<string, ClassEntry*>::iterator it = reusedClasses.begin(); it != reusedClasses.end(); it++)
    {
        cout << it->second->getClassName() << ": ";
        cout << "T=" << it->second->getTotal() << ", ";
        cout << "I=" << it->second->getItems() << ", ";
        cout << "B=" << it->second->getBase() << ", ";
        cout << "D=" << it->second->getDeleted() << ", ";
        cout << "M=" << it->second->getModified() << ", ";
        cout << "A=" << it->second->getAdded() << endl;
    }

    cout << "--------------------------------------------" << endl;
    cout << "Total de LDC=" << totalGlobal << endl;
}
#endif