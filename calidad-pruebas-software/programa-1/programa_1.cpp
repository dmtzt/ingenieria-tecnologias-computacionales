/*
 * programa_1
 * Lee un archivo cuyo nombre es provisto por el usuario y cuenta el número de líneas
 * en blanco, con comentarios o con código, mostrando al final los resultados
 * Alerta al usuario cuando un archivo no existe, está vacío o contiene comentarios
 * multilínea inconclusos
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de creación: 22/feb/2021
 * Fecha de modificación: 23/feb/2021
*/
#include <iostream>
#include "FileReader.h"
#include "Printer.h"
#include <string>

using namespace std;

int main(void) 
{
    string filename;
    FileReader fileReader;
    Printer printer;

    // Inicialización del fileReader
    fileReader.init();
    // Lee el nombre del archivo a abrir
    cin >> filename;

    // Abre el archivo
    fileReader.openFile(filename);

    // Proceder si el archivo fue abierto exitosamente
    if (fileReader.getFileStatus())
    {
        // Leer y contar el número de líneas por categoría
        fileReader.readFile();
        fileReader.closeFile();
    }

    // Imprimir estadísticas
    printer.printStats(filename, fileReader.getBlankCount(), fileReader.getCommentsCount(), 
                       fileReader.getCodeCount(), fileReader.getErrorLog());
}