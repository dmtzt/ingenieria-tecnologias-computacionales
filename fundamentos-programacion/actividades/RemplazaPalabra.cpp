/* 
 * RemplazaPalabra.cpp
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 13/11/2018
*/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int found = 0;
    string frase, palabra1, palabra2;

    getline(cin, frase);
    getline(cin, palabra1);
    getline(cin, palabra2);

    do
    {
        found = frase.find(palabra1);
        frase.replace(found, palabra2.size() - 1, palabra2);
    }
    while();

    return 0;
}
