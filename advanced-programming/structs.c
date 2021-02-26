#include <stdio.h>
#include <stdlib.h>

struct _person 
{
    char* first_name;
    char* last_name;
};

struct _person employee = {"Hector", "Rueda"};

void change(struct _person* p)
{
    sprintf(p->first_name, "Carlos");
}

int main()
{
    printf("%s %s\n", employee.first_name, employee.last_name);
    change(&employee);
    printf("%s %s\n", employee.first_name, employee.last_name);
}