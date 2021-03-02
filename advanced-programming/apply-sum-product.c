#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void apply(void (*func) (int**, int, int, int), int** arr, int rows, int cols, int direction);
void sum(int** arr, int rows, int cols, int direction);
void product(int** arr, int rows, int cols, int direction);

enum direction{row_wise, column_wise};

int main()
{
    int **arr;
    int rows, cols;
    enum direction direction_sum;
    enum direction direction_product;
    
    printf("# of rows: ");
    scanf("%i", &rows);
    while (rows < 1)
    {
        printf("Enter a valid value: ");
        scanf("%i", &rows);
    }

    printf("# of columns: ");
    scanf("%i", &cols);
    while (cols < 1)
    {
        printf("Enter a valid value: ");
        scanf("%i", &cols);
    }

    printf("Direction for sum - row-wise (0), column-wise (1): ");
    scanf("%i", &direction_sum);
    while (direction_sum != row_wise && direction_sum != column_wise)
    {
        printf("Enter a valid value - row-wise (0), column-wise (1): ");
        scanf("%i", &direction_sum);
    }

    printf("Direction for product - row-wise (0), column-wise (1): ");
    scanf("%i", &direction_product);
    while (direction_product != row_wise && direction_product != column_wise)
    {
        printf("Enter a valid value - row-wise (0), column-wise (1): ");
        scanf("%i", &direction_product);
    }

    arr = malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++)
    {
        arr[i] = malloc(cols * sizeof(int));

        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = (rand() % (0 - rows * cols + 1)) + 0;
            printf("%i\t", arr[i][j]);
        }

        printf("\n");
    }

    printf("Sum:\n");
    apply(&sum, arr, rows, cols, direction_sum);
    printf("Product:\n");
    apply(&product, arr, rows, cols, direction_product);

    for (int i = 0; i < rows; i++)
        free(arr[i]);

    free(arr);
}

void apply(void (*func) (int**, int, int, int), int** arr, int rows, int cols, int direction)
{
    (*func) (arr, rows, cols, direction);
}

void sum(int** arr, int rows, int cols, int direction)
{
    int res;

    if (direction == row_wise)
    {
        // Column first
        for (int i = 0; i < rows; i++)
        {
            res = 0;

            // Row last
            for (int j = 0; j < cols; j++)
                res += arr[i][j];

            printf("%i ", res);
        }
        printf("\n");
    }
    else if (direction == column_wise)
    {
        // Column first
        for (int i = 0; i < cols; i++)
        {
            res = 0;

            // Column last
            for (int j = 0; j < rows; j++)
                res += arr[j][i];

            printf("%i ", res);
        }
        printf("\n");
    }   
}

void product(int** arr, int rows, int cols, int direction)
{
    int res;

    if (direction == row_wise)
    {
        // Column first
        for (int i = 0; i < rows; i++)
        {
            res = 1;

            // Row last
            for (int j = 0; j < cols; j++)
                res *= arr[i][j];
            
            printf("%i ", res);
        }
        printf("\n");
    }
    else if (direction == column_wise)
    {
        // Row first
        for (int i = 0; i < cols; i++)
        {
            res = 1;

            // Column last
            for (int j = 0; j < rows; j++)
                res *= arr[j][i];

            printf("%i ", res);
        }
        printf("\n");
    }
}