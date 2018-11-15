/* 
 * InicialesYApellido.cpp
 * 
 * Imprime un nombre recibido con el formato: inicial del nombre, 
 * primer apellido completo e inicial del segundo apellido
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
    string nombre;

    getline(cin, nombre);

    // Encuentra el final del nombre
    pos = nombre.find(' ');
    // Reemplaza sus caracteres excepto la inicial por un punto 
    nombre.replace(1, pos - 1, ".");

    // Encuentra el final del nombre abreviado
    pos = nombre.find(' ');
    // Encuentra el final del primer apellido y el inicio del segundo
    pos = nombre.find(' ', pos + 1);

    // Reemplaza los caracteres del segundo excepto la inicial por un punto
    nombre.replace(pos + 2, nombre.size() - 1, ".");
    
    // Imprime el nombre con el nuevo formato
    cout << nombre << endl;

    return 0;
}
