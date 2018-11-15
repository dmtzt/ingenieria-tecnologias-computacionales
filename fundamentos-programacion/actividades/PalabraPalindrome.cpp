/* 
 * PalabraPalindrome.cpp
 * 
 * Determina si una palabra es palindroma o no
 *
 * David Alejandro Martinez Tristan
 * 13/11/2018
*/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string palabra;

    // Lee la palabra introducida por el usuario
    getline(cin, palabra);

    // Itera a lo largo de la palabra desde los extremos hasta el caracter medio
    for (int i = 0; i < (signed) palabra.size() / 2; i++)
    {
        // Si los caracteres son diferentes, la palabra no es palindroma
        if (palabra[i] != palabra[palabra.size() - 1 - i])
        {
            cout << "No es palindrome" << endl;
            return 0;
        }
    }

    // Si no se encontraron caracteres diferentes, es palindrome
    cout << "Si es palindrome" << endl;

    return 0;
}
