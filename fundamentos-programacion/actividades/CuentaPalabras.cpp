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
    
    //int palabras = 0;
    string frase;

    getline(cin, frase);

    if (frase.empty())
    {
        cout << "0" << endl;
        return 0;
    }

    int pos = 0;
    int palabras = 1;

    while((unsigned) (pos = frase.find(" ", pos + 1)) != string::npos)
        palabras++;

    cout << palabras << endl;    

    return 0;
}
