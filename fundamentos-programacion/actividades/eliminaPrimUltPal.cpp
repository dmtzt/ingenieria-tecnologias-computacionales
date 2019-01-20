/* 
 * eliminaPrimUltPal.cpp
 * 
 * Elimina la primera y la ultima palabra de una frase dada
 *
 * David Alejandro Martinez Tristan
 * 15/11/2018
*/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int pos = 0;
    string frase;

    // Leer frase introducida por el usuario
    getline(cin, frase);

    // Asegurar que la frase no este vacia
    if (frase.empty())
    {
        cout << endl;
        return 0;
    }

    // Encontrar el final de la primera palabra
    pos = frase.find(" ", pos) + 1;

    // Eliminar la primera palabra y el espacio entre la segunda palabra
    frase.erase(0, pos);

    // Iterar por el fin de cada palabra hasta encontrar el fin de la ultima
    // Si despues de una posicion no existe una palabra, se conserva la ultima posicion valida
    while(frase.find(" ", pos + 1) != string::npos && 
          frase[frase.find(" ", pos + 1) + 1] != '\0')
        pos = frase.find(" ", pos + 1);

    // Eliminar la ultima palabra
    frase.erase(pos, frase.length() - 1);

    // Imprimir frase modificada
    cout << frase << endl;

    return 0;
}