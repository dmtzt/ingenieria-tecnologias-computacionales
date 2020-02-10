#include "Test.h"
int main(int argc, char const *argv[])
{
    Test t1;
    Test t2(2, 3, 4);
    t1.print();
    t2.print();
    return 0;
}
