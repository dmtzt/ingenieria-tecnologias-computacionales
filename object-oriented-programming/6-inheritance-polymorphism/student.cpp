/* 
 * student.cpp
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 01/04/2019
*/

#include <iostream>
#include "Student.h"

using namespace std;

int main(void)
{
    Person person("Rosa", "Martinez", 21);
    Student student("Juan", "Ruiz", 18, "ITC", 12345);
    
    person.toString();
    student.toString();
    
    return 0;
}
