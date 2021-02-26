#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_WISE 0
#define COLUMN_WISE 1

void sum(int direction, int** arr, int rows, int cols)
{
    int res;

    if (direction == ROW_WISE)
    {
        for (int i = 0; i < rows; i++)
        {
            res = 0;

            for (int j = 0; j < cols; i++)
                res += arr[i][j];

            printf("i%\n", res);
        }
    }
    else if (direction == COLUMN_WISE)
    {
        for (int i = 0; i < cols; i++)
        {
            res = 0;

            for (int j = 0; j < rows; i++)
                res += arr[i][j];

            printf("i%\n", res);
        }
    }
}

void product(int direction, int** arr, int rows, int cols)
{
    int res;

    if (direction == ROW_WISE)
    {
        for (int i = 0; i < rows; i++)
        {
            res = 0;

            for (int j = 0; j < cols; j++)
                res *= arr[i][j];

            printf("i%\n", res);
        }
    }
    else if (direction == COLUMN_WISE)
    {
        for (int i = 0; i < cols; i++)
        {
            res = 0;

            for (int j = 0; j < rows; j++)
                res *= arr[i][j];

            printf("i%\n", res);
        }
    }
}

int main()
{
    int direction, rows, cols;
    void (*functPtr) (int, int**, int, int);

    printf("Direction - row-wise (0), column-wise (1): ");
    scanf("%i", &direction);
    printf("# of rows: ");
    scanf("%i", &rows);
    printf("# of columns: ");
    scanf("%i", &cols);

    int arr** = malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            
        }
        
    }
    
}