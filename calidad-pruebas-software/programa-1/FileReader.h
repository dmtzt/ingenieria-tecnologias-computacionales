/*
 * 
 * Abre un archivo indicado por el usuario y cuenta el número de líneas en blanco,
 * con código y con comentarios
 * Al concluir, cierra el archivo y deja preparados los valores para ser
 * provistos al Printer
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de creación: 22/feb/2021
 * Fecha de modificación: 23/feb/2021
*/
#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileReader 
{
    ifstream file;
    string line;
    vector<string> errorLog;
    int blankCount;
    int commentsCount;
    int codeCount;
    bool fileStatus;
    bool isEmptyLine;
    bool isComment;
    bool isMultilineComment;

    public:
        void init();
        void openFile(string);
        void readFile();
        void closeFile();
        bool getFileStatus();
        int getBlankCount();
        int getCommentsCount();
        int getCodeCount();
        vector<string> getErrorLog();
};

/*
 * Inicializa los contadores en 0 y las banderas en false 
*/
void FileReader::init()
{
    blankCount = 0;
    commentsCount = 0;
    codeCount = 0;
    fileStatus = false;
    isMultilineComment = false;
}

/*
 * Abre el archivo y actualizar la bandera de status
 * Si el archivo pudo abrirse, la bandera se actualiza a true, lo cual servirá de
 * indicación para proceder a leer el archivo
 * De otra manera, significa que el archivo no existe
*/

void FileReader::openFile(string filename)
{
    file.open(filename);
    if (file)
        fileStatus = true;
    else
    {
        fileStatus = false;
        errorLog.push_back("El archivo no existe");
    }
        
}

/*
 * Lee el archivo previamente abierto y cuenta el número de líneas el blanco y que 
 * contienen código o comentarios
 * 
 * Contempla los casos en los que el archivo está vacío o contiene un comentario
 * multilínea sin terminar
*/
void FileReader::readFile()
{
    // File is empty: update error log
    if (file.peek() == std::ifstream::traits_type::eof())
        errorLog.push_back("El archivo está vacío");
    // File is not empty
    else
    {
        // Ready line by line
        while (!file.eof())
        {
            getline(file, line);    
            // Assume it is an empty line
            isEmptyLine = true;
            // Asume it is not a comment
            isComment = false;

            if (line.empty() && !isMultilineComment)
            {
                blankCount++;
                continue;
            }

            // Read char by char
            for (int i = 0; i < line.length(); i++)
            {
                // A char different from space or tab was found
                if (line[i] != ' ' && line[i] != '\t')
                {
                    // It is not an empty line
                    isEmptyLine = false;
                    if (line[i] == '/' && i + 1 < line.length())
                    {
                        // Update comments counter and comment flag if a single-line comment is found
                        if (line[i + 1] == '/')
                        {
                            isComment = true;
                            commentsCount++;
                            break;
                        }
                        // Update comments counter, comment flag and and multi-line flag if start of multi-line comment is found
                        else if (line[i + 1] == '*')
                        {
                            isComment = true;
                            isMultilineComment = true;
                            commentsCount++;
                            break;
                        }
                    }
                    else if (line[i] == '*' && i + 1 < line.length())
                    {
                        // Update comments counter and multi-line flag if end of multi-line comment is found
                        if (line[i + 1] == '/')
                        {
                            isComment = true;
                            isMultilineComment = false;
                            commentsCount++;
                            break;
                        }
                    }
                }
            }
            
            // Neither start nor end of single or multi-line comments was found
            // Update comments counter if current line is inside a multi-line comment, neither start nor end
            if (isMultilineComment && !isComment)
                commentsCount++;
            else
            {
                // Update blank counter if no chars different from space were found
                if (isEmptyLine)
                    blankCount++;
                // Update code counter if at least one char different from space was found and it is not a comment
                else if (!isComment)
                    codeCount++;
            }  
        }

        // Alert if a multiline comment remained unfinished
        if (isMultilineComment)
            errorLog.push_back("Se encontró un comentario multilínea sin cerrar");
    }
}

/*
 * Cierra el archivo anteriormente abierto
*/
void FileReader::closeFile()
{
    file.close();
}

/*
 * Devuelve el status del archivo
 * True: el archivo fue abierto exitosamente
 * False: el archivo no fue abierto porque no existe
*/
bool FileReader::getFileStatus()
{
    return fileStatus;
}

/*
 * Devuelve el número de líneas en blanco contadas
*/
int FileReader::getBlankCount()
{
    return blankCount;
}

/*
 * Devuelve el número de líneas con comentarios contadas
*/
int FileReader::getCommentsCount()
{
    return commentsCount;
}

/*
 * Devuelve el número de líneas con código contadas
*/
int FileReader::getCodeCount()
{
    return codeCount;
}

/*
 * Devuelve el log de errores
*/
vector<string> FileReader::getErrorLog()
{
    return errorLog;
}
#endif