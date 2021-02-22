/*
 * prime_numbers.c
 * David Alejandro Martinez Tristan A01610267
 * 19/02/2021
 * 
 * Finds the first n prime numbers, where n is a value given by the user.
 * The first valid prime number is 2.
 * 
*/
#include <stdio.h>

int main()
{
    int n;
    // First valid prime number
    int curr_no = 2;

    printf("Enter the amount of the first prime numbers to find: ");
    // Read number of values to be found
    scanf("%i", &n);
    // Check if number is outside the limits
    if(n < 1)
    {
        printf("Enter a valid number\n");
        return 1;
    }

    printf("The first %i prime numbers are:\n", n);
    // Find the first n prime numbers starting from the first valid number
    for (int i = 0; i < n; i++)
    {
        // Look for any possible divisors
        for (int j = 2; j < curr_no; j++)
        {
            // The number is not prime: a divisor was found
            if (curr_no % j == 0)
            {
                // Select the next number
                curr_no++;
                // Restart evaluation
                j = 2;
            }   
        }

        // The number is prime: no divisors were found
        // Print number
        printf("%i\n", curr_no);
        // Select the next number
        curr_no++;
    }
    
    return 0;
}
