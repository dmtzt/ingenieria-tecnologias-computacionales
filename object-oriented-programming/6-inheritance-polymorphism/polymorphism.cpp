/* 
 * polymorphism.cpp
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 11/04/2019
*/

#include <iostream>
#include "Student.h"

using namespace std;

int main(void)
{
    // Solo los punteros pueden experimentar polimorfismo
    Person *person;
    // La clase de un objeto va a ser fija permanentemente
    Student student("Maria", "Gomez", 18, "ITC", 1234);
    person = &student;
    // Metodo de student: imprime todos los datos
    student.toString();
    // Metodo de person original: omite degree y ID
    // Metodo virtual: la funcion es redefinida en la subclase
    // Utilizamos una flecha para acceder a los miembros de un objeto al cual estamos apuntando
    person->toString();
    return 0;
}
