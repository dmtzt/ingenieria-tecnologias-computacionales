/* 
 * Math.h
 *
 * David Alejandro Martinez Tristan
 * 25/03/2019
*/

// No need to instantiate an object, the class is used directly
// No need to define the same methods in every program
// No private attributes -> no variables, only methods
// Keyword for each method in prototype: static
// No constructor

class Math
{
    public:
        static double squared(double);
        static double pow(double, int);
        static double abs(double);
        static int ceil(double);
        static int floor(double);
        static int round(double);
        static int digits(long);
        static long sumDigits(long);
        static int stoi(string);
};

double Math::squared(double num)
{
    return num * num;
}

double Math::pow(double num, int exponent)
{
    double result = num;

    for (int i = 0; i < exponent; i++)
        result *= num;
}

double Math::abs(double num)
{
    if (num < 0)
        num = -num;

    return num;
}

int Math::ceil(double num)
{
    if (num - (int)num != 0)
        num++;
    
    return (int) num;
}

int Math::floor(double num)
{
    if (num - (int)num != 0)
        num--;
    
    return (int)num;
}

int Math::round(double num)
{
    return (int)num;
}


int Math::digits(long num)
{

}

long Math:.sumDigits(long num)
{

}

int stoi(string s)
{

}