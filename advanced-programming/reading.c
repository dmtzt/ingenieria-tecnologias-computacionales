#include <stdio.h>

FILE *ptrFile;
int studentID;
char fname[100], lname[100];

int main(void)
{
    ptrFile = fopen("myFile.txt", "r");
    if (ptrFile != NULL)
    {
        printf("File opened\n");

        while (!feof(ptrFile))
        {
            fscanf(ptrFile, "%d %s %s", &studentID, &fname, &lname);
            printf("%d %s %s", studentID, fname, lname);
        }
        
        if (fclose(ptrFile) == 0)
            printf("File closed\n");
        else
            printf("Error in fclose operation\n");
    }
    else
        printf("Error in fopen operation\n");
    
    return 0;
}