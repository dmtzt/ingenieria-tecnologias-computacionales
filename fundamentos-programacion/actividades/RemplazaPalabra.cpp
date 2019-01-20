/* 
 * RemplazaPalabra.cpp
 * 
 * Reemplaza todas las incidencias de una palabra original
 * por una palabra nueva en una frase dada
 *
 * David Alejandro Martinez Tristan
 * 13/11/2018
*/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int pos = 0;
    string frase, palabra_original, palabra_nueva;

    // Leer frase y palabras nueva y original
    getline(cin, frase);
    cin >> palabra_original;
    cin >> palabra_nueva;

    // Encontrar una por una las incidencias de la palabra original
    while(frase.find(palabra_original, pos) != string::npos)
    {
        // Actualizar posicion de la incidencia mas proxima
        pos = frase.find(palabra_original, pos);
        // Reemplazar por palabra nueva
        frase.replace(pos, palabra_original.size(), palabra_nueva);
    }

    // Imprimir frase modificada
    cout << frase << endl;

    return 0;
}