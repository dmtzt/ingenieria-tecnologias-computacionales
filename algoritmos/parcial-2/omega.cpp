#include <iostream>
#include <vector>

using namespace std;

// Encuentra el más grande y busca el siguiente de adentro hacia afuera
int main(void)
{
    vector<int> tube;
    int n, chocolate, pos, curr;
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

    while (tube.size() != 0)
    {
        curr = tube[pos];
        
        profit += curr * n;
        tube.erase(tube.begin() + pos);

        if (tube.size() > 2)
        {
            if (tube[pos - 1] > tube[pos])
                    pos--;
        }
        else if (tube.size() == 2)
        {
            if (pos >= 2)
                pos = 1;

            if (pos == 1)
            {
                if (tube[pos] < tube[pos - 1])
                    pos--;
            }
            else if (pos == 0)
            {
                if (tube[pos] < tube[pos + 1])
                    pos++;
            }
        }
        else
            pos = 0;
        
        n--;
    }
    
    cout << profit;
}