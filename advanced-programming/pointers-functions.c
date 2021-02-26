#include <stdio.h>

void hello(char* s1, char* s2)
{
    printf("Hello\n");

    for (int i = 0; s1[i] != '\0'; i++)
    {
        printf("%c", s1[i]);
    }

    printf("\n");

    for (int i = 0; s2[i] != '\0'; i++)
    {
        printf("%c", s2[i]);
    }

    printf("\n");
    
}

int main()
{
    void (*routinePtr) (char*, char*);

    hello("Hola", "Mundo");
    routinePtr = hello;
    (*routinePtr) ("Hola", "Mundo");
}