/*
 * lcs
 * David Alejandro Martinez Tristan
 * A01610267
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int cases;
    string s1, s2;
    vector<int> lcs;

    cin >> cases;

    for (int count = 0; count < cases; count++)
    {
        cin >> s1 >> s2;
        
        // Dynamic Programming approach
        // Create dp array
        int dp[s1.length() + 1][s2.length() + 1];

        // Start finding the longest common subsequence
        // Compare each char of s1 and s2 against each other
        for (int i = 0; i < s1.length() + 1; i++)
        {
            for (int j = 0; j < s2.length() + 1; j++)
            {
                // Fill first row and col with 0
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                // Make comparison, indices are accessed with an offset
                else if (s1[i - 1] == s2[j - 1])
                    // Part of the sequence: update lcs size
                    dp[i][j] = 1 + dp[i - 1][j -1 ];
                else
                    // Not part of the sequence: largest lcs size between the two options
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        // lcs found in bottom-right corner of dp
        // Store result from current case
        lcs.push_back(dp[s1.length()][s2.length()]);
    }
    

    // Print formatted results
    for (int count = 0; count < cases; count++)
        cout << "Case " << (count + 1) << ": " << lcs[count] << endl;
    
    return 0;
}