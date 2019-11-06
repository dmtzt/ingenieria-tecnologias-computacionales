#include "Priority.h"
#include <iostream>

using namespace std;

int main()
{
    Priority list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(5);
    list.push(4);
    list.push(7);
    list.push(8);
    
    while (!list.empty())
    {
        cout << list.top() << endl;
        list.pop();
    }
    
}