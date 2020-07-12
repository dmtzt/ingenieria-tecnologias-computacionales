/*
 * beagle_ball
 * David Alejandro Martinez Tristan
 * A01610267
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, q, soldier, ball;
    long long int sumSoldiers = 0;
    long long int sumBalls = 0;

    cin >> n >> q;

    vector<long long int> soldiers(n);
    vector<long long int> balls(q);

    cin >> soldier;
    soldiers[0] = soldier;

    // Read and store the cumulative strength of all soldiers
    for (int i = 1; i < n; i++)
    {
        cin >> soldier;
        soldiers[i] = soldiers[i - 1] + soldier;
    }
    
    // Read and store the individual power of each ball
    for (int i = 0; i < q; i++)
    {
        cin >> ball;
        balls[i] = ball;
    }

    // Start evaluation
    for (int i = 0; i < q; i++)
    {
        // Calculate cumulative power of the current ball
        sumBalls += balls[i];
        // Case 1: cumulative power of all soldiers < individual power of the current ball
        if(soldiers[n-1] < balls[i])
        {
            // All soldiers are shot down, raise them all up
            sumBalls = 0;
            sumSoldiers = 0;
            // Print standing soldiers
            cout<< n <<endl;

        }
        // Case 2: cumulative power of all soldiers < cumulative power of the current ball
        else if (soldiers[n-1] < sumBalls)
        {
            // All soldiers are shot down, raise them all up
            sumBalls = 0;
            sumSoldiers = 0;
            // Print standing soldiers
            cout<< n <<endl;
        }
        // Case 3: find the maximum number of soldiers that are shot down with the cumulative ball power
        else
        {
            vector<long long int>::iterator it = upper_bound(soldiers.begin(), soldiers.end(), sumBalls);
            int index = it - soldiers.begin();
            sumSoldiers = (n - 1) - (index - 1);
            // Print standing soldiers
            cout << sumSoldiers << endl;
        }
    }
    return 0;
}