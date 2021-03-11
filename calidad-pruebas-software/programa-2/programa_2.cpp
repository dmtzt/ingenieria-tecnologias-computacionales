#include <map>
#include <queue>
#include <string>
#include "FileReader.h"
#include "ClassEntry.h"
#include "ClassCategories.h"
#include "Printer.h"

using namespace std;

int getCategory(ClassEntry* classEntry);

int main(void)
{
    //.b=2
    FileReader fileReader;
    Printer printer;
    map<string, ClassEntry*> globalClasses;
    queue<ClassEntry*> baseClasses;
    queue<ClassEntry*> newClasses;
    queue<ClassEntry*> reusedClasses;
    //.m
    string fileName;
    int totalGlobal = 0;

    //.m
    fileReader.reset();

    //.m
    getline(cin, fileName);

    //.m
    while (!fileName.empty())
    {
        //.m
        fileReader.openFile(fileName);

        if (fileReader.getFileStatus())
        {
            fileReader.readFile();
            
            totalGlobal += fileReader.getTotal();

            // Add class entry to global map if it does not exist
            if (globalClasses.find(fileReader.getClassName()) == globalClasses.end())
            {
                globalClasses[fileReader.getClassName()] = fileReader.createClassEntry();
                cout << "ADDED" << endl;
            }
            // Update class entry from global map if it exists
            else
            {
                fileReader.updateClassEntry(globalClasses[fileReader.getClassName()]);
                cout << "UPDATED" << endl;
            }
                

            fileReader.closeFile();
            fileReader.print();
            fileReader.reset();
        }
        else
        {

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
                cout << "INVALID CLASS" << endl;
                break;
        }
    }

    globalClasses.clear();

    printer.printStats(baseClasses, newClasses, reusedClasses, totalGlobal);
    return 0;
}

int getCategory(ClassEntry* classEntry)
{
    cout << "CATEGORY" << endl;
    if (classEntry->getBase() > 0 && (classEntry->getModified() > 0 
        || classEntry->getDeleted() > 0 || classEntry->getAdded() > 0))
    {
        cout << "BASE CLASS" << endl;
        return BASE_CLASS;
    }
        
    else if (classEntry->getBase() == 0 && classEntry->getModified() == 0 
             && classEntry->getDeleted() == 0 && classEntry->getAdded() > 0)
    {
        cout << "NEW CLASS" << endl;
        return NEW_CLASS;
    }
    else if (classEntry->getBase() > 0 && classEntry->getModified() == 0 
             && classEntry->getDeleted() == 0 && classEntry->getAdded() == 0)
    {
        cout << "REUSED CLASS" << endl;
        return REUSED_CLASS;
    }

    return INVALID_CLASS;
}

// reusedClasses[fileReader.getClassName()]->updateCounters(
                        //     reusedClasses[fileReader.getClassName()]->getTotal() + fileReader.getTotal(),
                        //     reusedClasses[fileReader.getClassName()]->getItems() + fileReader.getItems(),
                        //     reusedClasses[fileReader.getClassName()]->getBase() + fileReader.getBase(),
                        //     reusedClasses[fileReader.getClassName()]->getDeleted() + fileReader.getDeleted(),
                        //     reusedClasses[fileReader.getClassName()]->getModified() + fileReader.getModified(),
                        //     reusedClasses[fileReader.getClassName()]->getAdded() + fileReader.getAdded());

// new ClassEntry(
                        //     fileReader.getClassName(), fileReader.getTotal(), 
                        //     fileReader.getItems(), fileReader.getBase(), 
                        //     fileReader.getDeleted(), fileReader.getModified(), 
                        //     fileReader.getAdded());