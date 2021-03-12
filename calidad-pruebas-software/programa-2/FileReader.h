//.b=2
#ifndef FILEREADER_H
#define FILEREADER_H
#define INVALID_QUANTITY 0
//.b=4
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "ClassCategories.h"
#include "ClassEntry.h"

//.b=5
using namespace std;

class FileReader 
{
    ifstream file;
    string line;
    vector<string> errorLog;

    //.d=3
    bool fileStatus;
    //.d=1
    bool isSingleLineComment; //.m
    bool multiLineStart;
    bool multiLineEnd;
    //.b=1
    bool isMultiLineComment;
    bool isString;

    string fileName;
    string className;
    int category;
    int total;
    int items;
    int base;
    int deleted;
    int modified;
    int added;

    int parseQuantity(string);

    public:
        void reset(); //.m
        //.b=4
        void openFile(string);
        void readFile();
        void closeFile();
        bool getFileStatus();
        //.d=3
        ClassEntry* createClassEntry();
        void updateClassEntry(ClassEntry*);
        int calculateAdded(int, int, int);
        void pushError(string);
        string getClassName();
        int getTotal();
        int getItems();
        int getBase();
        int getDeleted();
        int getModified();
        int getAdded();
        //.b=1
        vector<string> getErrorLog();
};

//.i
void FileReader::reset() //.m
{
    //.d=3
    className = "";
    fileStatus = false;
    isSingleLineComment = false;
    multiLineStart = false;
    multiLineEnd = false;
    isMultiLineComment = false;
    isString = false;
    category = INVALID_CLASS;
    total = items = base = deleted = modified = added = 0;
}

/*
 * Abre el archivo y actualizar la bandera de status
 * Si el archivo pudo abrirse, la bandera se actualiza a true, lo cual servirá de
 * indicación para proceder a leer el archivo
 * De otra manera, significa que el archivo no existe
*/

//.i
//.b=1
void FileReader::openFile(string fileName)
{
    this->fileName = fileName;
    // Get class name from the given file name
    className = fileName.substr(0, fileName.find('.'));
    file.open(fileName); //.m
    //.b=4
    if (file)
        fileStatus = true;
    else
    {
        fileStatus = false;
        pushError("El archivo " + fileName + " no existe"); //.m
    }    
}

/*
 * Lee el archivo previamente abierto y cuenta el número de líneas el blanco y que 
 * contienen código o comentarios
 * 
 * Contempla los casos en los que el archivo está vacío o contiene un comentario
 * multilínea sin terminar
*/
//.i
//.b=1
void FileReader::readFile()
{
    if (!fileStatus)
        return;
    
    // File is empty: update error log
    //.b=1
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        pushError("El archivo " + fileName + " está vacío"); //.m
        return;
    }
        
    // File is not empty
    // Ready line by line
    //.b=1
    while (!file.eof())
    {
        // Assume line is not a single-line comment
        isSingleLineComment = false;
        // Read line
        //.b=1
        getline(file, line);

        //.d=5
        // If line has at least one character
        if (line.length() > 0)
        {
            // Remove all spaces and tabs from indentation
            while(line[0] == ' ' || line[0] == '\t')
                line.erase(line.begin());
        }

        // Exclude line if it is empty after indentation removal
        if (line.empty())
            continue;

        // Remove all consecutive spaces and tabs remaining
        while(line[1] == ' ' || line[1] == '\t')
            line.erase(line.begin());
        
        // Exclude if it only has "{", "}" or "};"
        if ((line.length() == 1 && (line[0] == '{' || line[0] == '}'))
            || (line.length() == 2 && line[0] == '}' && line[1] == ';'))
            continue;
            
        //.b=1
        // Find single and multi-line comments and counting identifiers
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '/' && line.length() > i + 1) //.m
            {
                // Line is the start of a multi-line comment
                //.b=1
                if (line[i + 1] == '*')
                    multiLineStart = true;
                    
                //.d=4
                // Line is a single-line comment and is not inside a multi-line comment or a string
                else if (line[i + 1] == '/' && !isMultiLineComment && !isString) //.m
                {
                    isSingleLineComment = (i + 1 > 1) ? false : true;
                    //.d=1
                    // Check if line contains an identifier 
                    if (line.length() > i + 2)
                    {
                        if (line[i + 2] == '.' && line.length() > i + 3)
                        {
                            // Check if it is an alphabetic identifier
                            if (isalpha(line[i + 3]))
                            {
                                // Update counters according to valid identifiers
                                switch (tolower(line[i + 3]))
                                {
                                    case 'i':
                                        items++;
                                        break;
                                    case 'b':
                                        base += parseQuantity(line.substr(i + 4));
                                        break;
                                    case 'd':
                                        deleted += parseQuantity(line.substr(i + 4));
                                        break;
                                    case 'm':
                                        modified++;
                                        break;
                                    // Undefined identifier
                                    default:
                                        string s(1, line[i + 3]);
                                        pushError("Identificador no válido: //." + s);
                                        break;
                                }
                                //break;
                            }
                            // Undefined identifier
                            else
                            {
                                string s(1, line[i + 3]);
                                pushError("Identificador no válido: //." + s);
                                break;
                            }  
                        }
                    }
                }
                //.d=3
            }
            else if (line[i] == '*' && line.length() > i + 1) //.m
            {
                // Line is the end of a multi-line comment
                //.b=1
                if (line[i + 1] == '/')
                {
                    multiLineEnd = true;
                }
                    
                    
                //.d=4
            }
            // Current read is inside a string
            else if (line[i] == '\"')
            {
                if (!isMultiLineComment && !isSingleLineComment && line[i - 1] != '\\')
                    isString = (isString) ? false : true;
            }

            if (multiLineStart && !isMultiLineComment)
                isMultiLineComment = true;
        }

        // Assume line is a valid line if not inside a multi-line comment
        if (!isSingleLineComment && !isMultiLineComment)
            total++;
            

        if (multiLineEnd)
        {
            isMultiLineComment = false;
            multiLineStart = false;
            multiLineEnd = false;
        }

        //.d=9
    }

    added = calculateAdded(total, base, deleted);

    if (total == 0)
        pushError("El archivo " + fileName + " no contiene líneas de código");
}

/*
 * Cierra el archivo anteriormente abierto
*/
//.i
//.b=2
void FileReader::closeFile()
{
    file.close();
}

/*
 * Devuelve el status del archivo
 * True: el archivo fue abierto exitosamente
 * False: el archivo no fue abierto porque no existe
*/
//.b=2
bool FileReader::getFileStatus()
{
    return fileStatus;
}

//.d=6

/*
 * Devuelve el log de errores
*/
//.b=2
vector<string> FileReader::getErrorLog()
{
    return errorLog;
}

//.i
ClassEntry* FileReader::createClassEntry()
{
    return new ClassEntry(className, total, items, base, deleted, modified, added);
}

//.i
void FileReader::updateClassEntry(ClassEntry* classEntry)
{
    classEntry->setTotal(classEntry->getTotal() + total);
    classEntry->setItems(classEntry->getItems() + items);
    classEntry->setBase(classEntry->getBase() + base);
    classEntry->setDeleted(classEntry->getDeleted() + deleted);
    classEntry->setModified(classEntry->getModified() + modified);
    classEntry->setAdded(calculateAdded(classEntry->getTotal() + total, 
                                        classEntry->getBase() + base, 
                                        classEntry->getDeleted() + deleted));
}

//.i
int FileReader::calculateAdded(int t, int b, int d)
{
    return t - b + d;
}

//.i
void FileReader::pushError(string error)
{
    errorLog.push_back(error);
}

string FileReader::getClassName()
{
    return className;
}

int FileReader::getTotal()
{
    return total;
}

//.i
int FileReader::parseQuantity(string line)
{
    int pos = 0;
    // Delete al blank spaces before '=' character
    while(line[pos] == ' ' || line[pos] == '\t')
        line.erase(pos);
    
    // Skip '=' character
    pos ++;

    // Delete al blank spaces after '=' character
    while(line[pos] == ' ' || line[pos] == '\t')
        line.erase(pos);

    // Extract number and omit spaces or tabs if they exist after the number
    string number = (line.find(' ') > line.find('\t')) ? 
                    line.substr(pos, line.find('\t') - pos) :
                    line.substr(pos, line.find(' ') - pos);

    // Check if all characters are digits
    for (int i = 0; i < number.length(); i++)
    {
        if (!isdigit(number[i]))
        {
            pushError("Invalid quantity found");
            return INVALID_QUANTITY;
        }
    }

    return stoi(number);
}
#endif