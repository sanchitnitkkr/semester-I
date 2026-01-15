// Write a program to print, delete and copy contents of one file to another file

#include <stdio.h>

int main()
{
    char *sourcePath = "experiment_44.txt";
    char *destinationPath = "experiment_44_destination.txt";

    FILE *sourceFp = fopen(sourcePath, "r");
    FILE *destinationFp = fopen(destinationPath, "w");

    if (sourceFp == NULL)
    {
        printf("File doesn't exist please make sure the file exists!");
        return 0;
    }

    // Reading the file
    while (1)
    {
        char buffer[1000];
        char *result = fgets(buffer, sizeof(buffer), sourceFp);
        if (result == NULL)
        {
            break;
        }
        printf("%s", buffer);
        fprintf(destinationFp,buffer);
    }

    fclose(sourceFp);
    fclose(destinationFp);
    sourceFp = fopen(sourcePath,"w");
    fclose(sourceFp);

}