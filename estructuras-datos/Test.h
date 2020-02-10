#include <iostream>
using namespace std;
class Test
{
private:
    int dato1;
    float dato2;
    double dato3;
public:
    Test();
    Test(int d1, float d2, double d3);
    Test(int dato1, float dato2);
    void setDato1(int d1);
    void recibirTest(Test test);
    void print();
};

Test::Test()
{
    dato1 = 0;
    dato2 = 3.0;
    dato3 = 10.0;
}

Test::Test(int d1, float d2, double d3)
{
    dato1 = d1;
    dato2 = d2;
    dato3 = d3;
}

void Test::print()
{
    cout << dato1 << endl;
    cout << dato2 << endl;
    cout << dato3 << endl;
}


