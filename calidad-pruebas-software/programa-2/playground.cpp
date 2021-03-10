#include <iostream>
#include <map>
#include <string>
#include "FileReader.h"

using namespace std;

int main(void)
{
    string fileName;
    FileReader fileReader;
    map<string, ClassEntry*> baseClasses;
    map<string, ClassEntry*> newClasses;
    map<string, ClassEntry*> reusedClasses;

    fileReader.reset();
    getline(cin, fileName);

    while (!fileName.empty())
    {
        cout << "|" << fileName << "|" << endl;
        fileReader.openFile(fileName);
        cout << "|" << fileReader.getClassName() << "|" << endl;
        fileReader.closeFile();
        fileReader.reset();

        getline(cin, fileName);
    }
}