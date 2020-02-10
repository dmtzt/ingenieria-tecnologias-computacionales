#include <iostream>

using namespace std;

int main(void)
{
    int* p;
    delete p;
    cout << *p << endl;

    return 0;
}
