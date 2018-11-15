/* 
 * InsertaCaracter.cpp
 * 
 * Inserta el caracter '%' de manera intercalada en una palabra dada
 *
 * David Alejandro Martinez Tristan
 * 14/11/2018
*/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int pos = 1;
    string palabra;
    
    cin >> palabra;

    int initial_size = (signed) palabra.size();

    for (int i = 0; i < initial_size - 1; i++)
    {
        palabra.insert(pos, "%");
        pos += 2;
    }

    cout << palabra << endl;

    return 0;
}
