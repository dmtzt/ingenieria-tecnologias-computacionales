/* 
 * lists.cpp
 *
 * David Alejandro Martinez Tristan
 * 29/04/2019
*/

#include <iostream>
#include "List.h"

using namespace std;

int main(void)
{
    List<int> numbersList;
    List<string> stringList;
    int number, index;

    cin >> number;
    numbersList.addElement(number);
    
    cin >> index;
    if (index < numbersList.getSize())
        cout << "Index out of bounds" << endl;
    else
        cout << numbersList.getByIndex(index);
    return 0;
}
