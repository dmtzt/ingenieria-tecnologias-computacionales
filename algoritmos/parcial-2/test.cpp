#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        // Check all elements of the grid
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // If unvisited land is found, do a depth-first search (DFS)
                if (grid[i][j] == '1')
                {
                    // The DFS will mark adjacent land as visited with '#'
                    dfs(i, j, grid);
                    // Increment number of islands
                    count++;
                }
            } 
        }
        
        return count;
    }
    
    // Depth-first search
    void dfs(int i, int j, vector<vector<char>>& grid) {
        // Check that the indices are inside the grid and
        // that the current element is unvisited land
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != '1')
            return;
        
        // Mark current element as visited land
        grid[i][j] = '#';

        // DFS with horizontally or vertically adjacent elements
        dfs(i - 1, j, grid);
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
        dfs(i, j + 1, grid);
    }    
};

int main(void)
{
    int person;
    vector<int> groupSizes;

    for (int i = 0; i < 7; i++)
    {
        cin >> person;
        groupSizes.push_back(person);
    }

    
}
