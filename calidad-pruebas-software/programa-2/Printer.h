/* 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de creación: 07/03/2021
 * Fecha de modificación: 11/03/2021
*/
//.b=2
#ifndef PRINTER_H
#define PRINTER_H
#define OUTPUT_FILE_NAME "ConteoLDC.txt"
//.b=3
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include "ClassEntry.h"

//.b=1
using namespace std;

//.b=1
class Printer
{
    ofstream file;
    //.b=2
    public:
        void printStats(queue<ClassEntry*>, queue<ClassEntry*>, queue<ClassEntry*>, int, vector<string>);
};

//.i
void Printer::printStats(queue<ClassEntry*> baseClasses, 
    queue<ClassEntry*> newClasses, queue<ClassEntry*> reusedClasses, int totalGlobal, 
    vector<string> errorLog) //.m
{
    //.d=9
    file.open(OUTPUT_FILE_NAME);
    file << "CLASES BASE:" << endl;

    cout << "CLASES BASE:" << endl;
    ClassEntry* classEntry = NULL;
    while (!baseClasses.empty())
    {
        classEntry = baseClasses.front();
        if (classEntry->getTotal() > 0)
        {
            file << "   " << classEntry->getClassName() << ": ";
            file << "T=" << classEntry->getTotal();
            file << ", I=" << classEntry->getItems();
            file << ", B=" << classEntry->getBase();
            file << ", D=" << classEntry->getDeleted();
            file << ", M=" << classEntry->getModified();
            file << ", A=" << classEntry->getAdded();
            file << endl;

            cout << "   " << classEntry->getClassName() << ": ";
            cout << "T=" << classEntry->getTotal();
            cout << ", I=" << classEntry->getItems();
            cout << ", B=" << classEntry->getBase();
            cout << ", D=" << classEntry->getDeleted();
            cout << ", M=" << classEntry->getModified();
            cout << ", A=" << classEntry->getAdded();
            cout << endl;
        }   

        baseClasses.pop();
        delete classEntry; 
    }
    
    file << "--------------------------------------------" << endl;
    file << "CLASES NUEVAS:" << endl;

    cout << "--------------------------------------------" << endl;
    cout << "CLASES NUEVAS:" << endl;
    while (!newClasses.empty())
    {
        classEntry = newClasses.front();
        if (classEntry->getTotal() > 0)
        {
            file << "   " << classEntry->getClassName() << ": ";
            file << "T=" << classEntry->getTotal();
            file << ", I=" << classEntry->getItems();
            file << endl;

            cout << "   " << classEntry->getClassName() << ": ";
            cout << "T=" << classEntry->getTotal();
            cout << ", I=" << classEntry->getItems();
            cout << endl;
        }   

        newClasses.pop(); 
        delete classEntry;
    }

    file << "--------------------------------------------" << endl;
    file << "CLASES REUSADAS:" << endl;

    cout << "--------------------------------------------" << endl;
    cout << "CLASES REUSADAS:" << endl;
    while (!reusedClasses.empty())
    {
        classEntry = reusedClasses.front();
        if (classEntry->getTotal() > 0)
        {
            file << "   " << classEntry->getClassName() << ": ";
            file << "T=" << classEntry->getTotal();
            file << ", I=" << classEntry->getItems();
            file << ", B=" << classEntry->getBase();
            file << endl;

            cout << "   " << classEntry->getClassName() << ": ";
            cout << "T=" << classEntry->getTotal();
            cout << ", I=" << classEntry->getItems();
            cout << ", B=" << classEntry->getBase();
            cout << endl;
        }   

        reusedClasses.pop();
        delete classEntry;
    }

    file << "--------------------------------------------" << endl;
    file << "Total de LDC=" << totalGlobal << endl;

    cout << "--------------------------------------------" << endl;
    cout << "Total de LDC=" << totalGlobal << endl;

    for (int i = 0; i < errorLog.size(); i++)
    {
        file << errorLog[i] << endl;

        cout << errorLog[i] << endl;
    }
        

    file.close();
}
//.b=1
#endif