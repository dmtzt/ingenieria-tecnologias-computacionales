#include <iostream>
using namespace std;

int divisible(int inf, int sup)
{
    int count = 0;
    
    for (int i = inf; i <= sup; i++)
    {
        // if (i % 15 == 0)
        if (i % 3 == 0 && i % 5 == 0)
            count++;
    }

    return count;
}

/*
 * int divisible(int inf, int sup)
 * {
 *  int count = 0;
 *  int start = inf + (int % 15 == 0 : 0 ? 15 - inf % 15);
 * 
 *  for (int i = start; i <= sup; i += 15)
 *      count++;
 * 
 *  return count;
 * }
 * 
*/

int main(void)
{
    int inf = 15;
    int sup = 95;

    cout << divisible(inf, sup);
    return 0;
}
