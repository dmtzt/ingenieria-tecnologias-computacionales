#include <stdio.h>

void uppercase(char*);

int main(int argc, char const *argv[])
{
    char str[] = "change to uppercase";
    printf("Before: %s\n", str);
    uppercase(str);
    printf("After: %s\n", str);
    return 0;
}

void uppercase(char* str)
{
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
            *str -= + ('a' - 'A');

        ++str;
    }
}