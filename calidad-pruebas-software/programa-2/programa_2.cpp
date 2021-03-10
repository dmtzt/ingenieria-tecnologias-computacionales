#include <map>
#include <string>
#include "FileReader.h"
#include "ClassEntry.h"
#include "ClassCategories.h"
#include "Printer.h"

using namespace std;

int main(void)
{
    //.b=2
    FileReader fileReader;
    Printer printer;
    map<string, ClassEntry*> baseClasses;
    map<string, ClassEntry*> newClasses;
    map<string, ClassEntry*> reusedClasses;
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
            
            totalGlobal =+ fileReader.getTotal();

            switch (fileReader.getCategory())
            {
                case BASE_CLASS:
                    if (baseClasses.find(fileReader.getClassName()) != baseClasses.end())
                        fileReader.updateClassEntry(baseClasses[fileReader.getClassName()]);
                    else
                        baseClasses[fileReader.getClassName()] = fileReader.createClassEntry();
                    break;
                case NEW_CLASS:
                    if (newClasses.find(fileReader.getClassName()) != newClasses.end())
                        fileReader.updateClassEntry(newClasses[fileReader.getClassName()]);
                    else
                        newClasses[fileReader.getClassName()] = fileReader.createClassEntry();
                    break;
                case REUSED_CLASS:
                    if (reusedClasses.find(fileReader.getClassName()) != reusedClasses.end())
                        fileReader.updateClassEntry(reusedClasses[fileReader.getClassName()]); 
                    else
                        reusedClasses[fileReader.getClassName()] = fileReader.createClassEntry();
                    break;
                default:
                    cout << "INVALID CLASS" << endl;
                    break;
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

    printer.printStats(baseClasses, newClasses, reusedClasses, totalGlobal);
    return 0;
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