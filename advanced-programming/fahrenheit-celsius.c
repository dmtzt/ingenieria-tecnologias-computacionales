#include <stdio.h>

int main()
{
    float fahrenheit;
    float celsius;

    printf("Enter temperature in F°: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * (5.0 / 9.0);
    printf("The temperature is equal to %.2f °C\n", celsius);
}