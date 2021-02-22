/*
 * int_binary.c
 * David Alejandro Martinez Tristan A01610267
 * 19/02/2021
 * 
 * Converts an integer number given by the user in the range 0-255 to its binary representation.
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int number;
    int size;

    printf("Enter an integer number in the range 0-255: ");
    // Read number
    scanf("%i", &number);
    // Check if number is outside the limits 0-255
    if (number < 0 || number > 255)
    {
        printf("Error: Number outside limits 0-255\n");
        return 1;
    }
    // Calculate number of bits needed to store the binary representation
    size = log2(number) + 1;
    // Create array
    int* arr = (int*) malloc(sizeof(int) * size);

    // Check pointer returned to avoid segmentation fault
    if(arr == NULL)
    {
        printf("Error: No memory allocated\n");
        return 1;
    }

    // Create a copy of the value to be used in the conversion
    int n = number;

    // Convert decimal to binary
    for (int i = 0; i < size; i++)
    {
        // Store remainder by 2
        arr[i] = n % 2;
        // Integer division by 2 and repeat
        n /= 2;
    }

    // Print binary representation last-to-first
    printf("The binary representation of %i is ", number);
    for (int i = size - 1; i >= 0; i--)
        printf("%i", arr[i]);
    
    printf("\n");

    // Free allocated memory
    free(arr);
    
    return 0;
}
