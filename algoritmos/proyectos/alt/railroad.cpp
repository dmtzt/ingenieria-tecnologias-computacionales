#include <iostream>
#include <vector>

using namespace std;

bool checkOrder(int i, int j, int next, vector<int> t1, vector<int> t2, vector<int> dt);

int main(void)
{
    int n1, n2, product;
    bool result;
    vector<bool> results;
    vector<int> t1, t2, dt;

    do
    {
        cin >> n1 >> n2;

        if (n1 > 0 && n2 > 0)
        {
            for (int i = 0; i < n1; i++)
            {
                cin >> product;
                t1.push_back(product);
            }
            
            for (int i = 0; i < n1; i++)
            {
                cin >> product;
                t2.push_back(product);
            }

            for (int i = 0; i < n1 + n2; i++)
            {
                cin >> product;
                dt.push_back(product);
            }

            result = checkOrder(0, 0, 0, t1, t2, dt);
            results.push_back(result);

            t1.clear();
            t2.clear();
            dt.clear();
        }
    }
    while (n1 > 0 && n2 > 0);

    for (int i = 0; i < results.size(); i++)
    {
        if (results[i])
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }

    return 0;
}

// Bactracking approach
bool checkOrder(int i, int j, int next, vector<int> t1, vector<int> t2, vector<int> dt)
{
    // Return true if the end of the desired order has been reached
    if (next == t1.size() + t2.size())
        return true;

    // If the end of the first train has not been reached
    if (i < t1.size())
    {
        // If the product at the front equals the product in the next position
        if (t1[i] == dt[next])
            // Check next possibility
            if (checkOrder(i + 1, j, next + 1, t1, t2, dt))
                // Return true if a solution was found
                return true;
    }

    // If the end of the second train has not been reached
    if (j < t2.size())
    {
        // If the product at the front equals the product in the next position
        if (t2[j] == dt[next])
            // Check next possibility
            if (checkOrder(i, j + 1, next + 1, t1, t2, dt))
                // Return true if a solution was found
                return true;
    }

    // Return false if no solutions were found given the order of the two trains
    return false;
}