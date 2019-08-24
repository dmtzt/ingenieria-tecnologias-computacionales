/*
 * sudoku.cpp
 * 
 * Checks whether a 9x9 sudoku grid is valid or not.
 * 
 * David Alejandro Martinez Tristan
 * 16/08/2019
 * 
*/

#define COLS 9
#define ROWS 9
#include <iostream>

using namespace std;

void resetFound(bool found[ROWS]);

int main(void)
{
    // Arrays to indicate values found in rows and cols
    bool foundRows[ROWS];
    bool foundCols[ROWS];

    // Variables to store current numbers that are being evaluated
    int currentNumRows;
    int currentNumCols;
    int sudoku[ROWS][COLS];

    // Read the 9x9 sudoku grid
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            cin >> sudoku[i][j];
        
    // Iterate over the 9x9 grid
    for (int i = 0; i < ROWS; i++)
    {
        // Reset values found for the next iteration
        resetFound(foundRows);
        resetFound(foundCols);

        for (int j = 0; j < COLS; j++)
        {
            // Check one row and column simultaneously
            currentNumRows = sudoku[i][j] - 1;
            currentNumCols = sudoku[j][i] - 1;

            // If the value was already found in the row, it is invalid
            if (foundRows[currentNumRows])
            {
                cout << "NO" << endl;
                return 0;
            }
            // The value had not been found and now it is
            else
                foundRows[currentNumRows] = true;

            // If the value was already found in the col, it is invalid
            if(foundCols[currentNumCols])
            {
                cout << "NO" << endl;
                return 0;
            }
            // The value had not been found and now it is
            else
                foundCols[currentNumCols] = true;
        }
    }

    // Iterate over each 3x3 subgrid
    for (int i = 0; i < ROWS; i += 3)
    {
        for (int j = 0; j < COLS; j += 3)
        {
            // Reset values found for each iteration
            resetFound(foundRows);

            // Check the values in each subgrid
            for (int k = i; k < i + 3; k++)
            {
                for (int l = j; l < j + 3; l++)
                {
                    // Check row by row
                    currentNumRows = sudoku[k][l] - 1;

                    // If the value was already found in the row, the grid is invalid
                    if (foundRows[currentNumRows])
                    {
                        cout << "NO" << endl;
                        return 0;
                    }
                    // The value had not been found and now it has been
                    else
                        foundRows[currentNumRows] = true;
                }
            }
        }    
    }

    //The 9x9 sudoku grid is valid
    cout << "YES" << endl;
    return 0;
}

/*
 * resetFound
 * Resets array of values found whenever it is necessary.
*/

void resetFound(bool found[ROWS])
{
    for (int i = 0; i < ROWS; i++)
        found[i] = false;
}