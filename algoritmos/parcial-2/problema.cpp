#include <iostream>
#include <vector>

using namespace std;

// Encuentra el más grande y busca el siguiente de adentro hacia afuera
int main(void)
{
    vector<int> tube;
    int n, chocolate, pos, curr, lower, upper;
    int largest = 0;
    int profit = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> chocolate;
        tube.push_back(chocolate);

        if (chocolate > largest)
        {
            largest = chocolate;
            pos = i;
        }
    }

    lower = pos - 1;
    upper = pos + 1;

    while (lower > 0 || upper < tube.size())
    {
        curr = tube[pos];
        
        profit += curr * n;

        if (upper < tube.size())
        {
            if (tube[lower] < tube[upper])
                pos = upper;
                upper++;
        }
        
        if (lower > 0)
        {
            if (tube[lower] > tube[upper])
                pos = lower;
                lower--;
        }
        
        n--;
    }
    
    cout << profit;
}