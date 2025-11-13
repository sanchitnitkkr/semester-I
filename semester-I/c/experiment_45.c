// Q45) Write a program to merge the contents of two files into a third file.

#include <stdio.h>

int main()
{
    char *sourceFileOnePath = "experiment_45_1";
    char *sourceFileTwoPath = "experiment_45_2";
    char *destinationFilePath = "experiment_45_destination.txt";

    FILE *sourceFp1 = fopen(sourceFileOnePath, "r");
    FILE *sourceFp2 = fopen(sourceFileTwoPath, "r");
    FILE *destinationFp = fopen(destinationFilePath, "w");

    if (sourceFp1 == NULL || sourceFp2 == NULL)
    {
        printf("Make sure both files are present for merging. Please try again!");
        return 0;
    }

    while (1)
    {
        char buffer1[1000];
        char buffer2[1000];
        char *result1 = fgets(buffer1, sizeof(buffer1), sourceFp1);
        char *result2 = fgets(buffer2, sizeof(buffer2), sourceFp2);

        if (result1 == NULL && result2 == NULL)
        {
            break;
        }
        if (result1 != NULL)
        {
            fprintf(destinationFp, buffer1);
        }
        if (result2 != NULL)
        {
            fprintf(destinationFp, buffer2);
        }
    }

    fclose(sourceFp1);
    fclose(sourceFp2);
    fclose(destinationFp);

    return 0;
}