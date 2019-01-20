/* 
 * CuentaPalabras.cpp
 * 
 * Cuenta el numero de palabras en una frase
 *
 * David Alejandro Martinez Tristan
 * 14/11/2018
*/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string frase;

    // Leer frase introducida por el usuario
    getline(cin, frase);

    // Asegurar que la frase no este vacia
    if (frase.empty())
    {
        cout << "0" << endl;
        return 0;
    }

    int pos = 0;
    int palabras = 0;

    // Incrementar contador, en caso de que exista una sola palabra
    // Previo a contar el numero de palabras por el numero de espacios
    if (isalnum(frase[0]))
        palabras++;

    // Encontrar el final de cada palabra iterando por cada espacio encontrado
    while(frase.find(" ", pos + 1) != string::npos)
    {
        pos = frase.find(" ", pos + 1);

        // Si despues de un espacio hay un caracter alnum, hay una palabra
        if (isalnum(frase[pos + 1]))
            palabras++;
            
    }

    // Imprimir numero de palabras    
    cout << palabras << endl;    

    return 0;
}