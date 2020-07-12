/*
 * railroad
 * David Alejandro Martinez Tristan 
 * A01610267
*/
#include <iostream>
#include <vector>

#define OFFSET_VALUE -1

using namespace std;

int main(){
    int n1, n2, product;
    vector<bool> res;

    cin >> n1 >> n2;

    while(n1 != 0 && n2 != 0)
    {   
        vector<int> t1(n1 + 1);
        vector<int> t2(n2 + 1);
        vector<int> t3(n1 + n2 + 1);

        bool dp[n1 + 1][n2 + 1];

        t1[0]= t2[0] = t3[0] = OFFSET_VALUE;

        // Read train 1 products
        for(int i = 1; i <= n1; i++)
        {
            cin >> product;
            t1[i] = product;
        }

        // Read train 2 products
        for(int i = 1; i <= n2; i++)
        {
            cin >> product;
            t2[i] = product;
        }

        // Read output train desired order
        for(int i = 1; i <= n1+n2; i++){
            cin >> product;
            t3[i] = product;
        }

        // Start of evaluation
        // Wildcard value needed for the algorithm to work
        dp[0][0] = true;

        // Check if the products of t1 and t2 match the product of output train at their same indices
        // If any product does not match, the rest of the order will not be valid
        // t1 1
        for(int i = 1; i <= n1; i++)
        {
            // Both products match and it is a valid order
            if (t1[i] == t3[i] && dp[i - 1][0] == true)
                dp[i][0] = true;
            else
                // Either they don't match or it is an invalid order
                dp[i][0] = false;
        }

        // t2
        for(int j = 1; j <= n2; j++)
        {
            // Both products match and it is a valid order
            if (t2[j] == t3[j] && dp[0][j - 1] == true)
                dp[0][j] = true;
            else
                // Either they don't match or it is an invalid order
                dp[0][j] = false;
        }

        // Evaluate combinations between t1 and t2 to produce the desired output
        // Find the possible path of true values that lead to the desired order 
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                if(t3[i + j] == t1[i] && dp[i - 1][j] == true)
                    dp[i][j] = true;
                else if (t3[i + j] == t2[j] && dp[i][j - 1] == true)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }

        // The lower right element will dictate whether it is possible or not
        res.push_back(dp[n1][n2]);
        cin>> n1 >> n2;
    }

    // Print results
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == true)
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }
    
    return 0;
}