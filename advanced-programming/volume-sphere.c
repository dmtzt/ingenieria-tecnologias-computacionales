#include <math.h>
#include <stdio.h>

int main()
{
    double radio;
    
    printf("Enter radio of the sphere: ");
    scanf("%d", &radio);

    double volume = (4.0 / 3.0);
    // * M_PI * pow(radio, 3)
    printf("%d\n", radio);
    printf("%d", volume);
}