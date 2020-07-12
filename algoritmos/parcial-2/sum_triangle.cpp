/*
 * Sum in a Triangle
 * David Alejandro Martinez Tristan
 * A01610267
 * Algoritmos grupo 1
 * 
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    int n, rows, num;
    // Vector to store nums with exact cols and rows sizes
    vector< vector<int> > triangle;
    // Vector to store nums of each row
    vector<int> row;
    // Queue to store all results
    queue<int> res;

    cin >> n;
    // Evaluate n test cases
    for (int count = 0; count < n; count++)
    {
        // Read num of rows
        cin >> rows;

        // Read all values per row and store them in vector
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cin >> num;
                row.push_back(num);
            }

            triangle.push_back(row);
            row.clear();
        }
        
        // Find greatest sum between curr num and the nums below and below to the right, from bottom to top
        // Start evaluating from the second-to-last row
        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            // Find greatest sum for all values of the row
            for (int j = 0; j < triangle[i].size(); j++)
            {
                // If num below > num below and one place to the right, add num below
                if (triangle[i + 1][j] > triangle[i + 1][j + 1])
                    triangle[i][j] += triangle[i + 1][j];
                // Else, add num below and one place to the right
                else
                    triangle[i][j] += triangle[i + 1][j + 1];
            }
            
        }

        // Store result found at the top of the triangle
        res.push(triangle[0][0]);
        triangle.clear();
    }   

    // Display all results
    while (!res.empty())
    {
        cout << res.front() << endl;
        res.pop();
    }

    // Success
    return 0;
}