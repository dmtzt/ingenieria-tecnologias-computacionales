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
    string fileName; //.m
    //.b=2
    FileReader fileReader;
    Printer printer;
    map<string, ClassEntry*> globalClasses;
    queue<ClassEntry*> baseClasses;
    queue<ClassEntry*> newClasses;
    queue<ClassEntry*> reusedClasses;
    int totalGlobal = 0;

    fileReader.reset(); //.m

    getline(cin, fileName); //.m

    while (!fileName.empty())
    {
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

    globalClasses.clear();

    printer.printStats(baseClasses, newClasses, reusedClasses, totalGlobal, fileReader.getErrorLog()); //.m
    return 0;
}

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