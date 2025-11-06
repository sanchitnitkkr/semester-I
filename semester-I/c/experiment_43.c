#include <stdio.h>
#include <string.h>

int isFileEmpty(FILE *fp)
{
    fseek(fp, 0, SEEK_END);    // Move to the end of the file
    long fileSize = ftell(fp); // Get the current position (number of bytes)
    rewind(fp);                // Move back to the beginning

    if (fileSize > 0)
    {
        return 0;
    }
    return 1;
}

int main()
{
    FILE *fp = fopen("experiment_43.txt", "r");
    int lineCount = 0;

    if (fp == NULL)
    {
        printf("Error opening the file please try again!\n");
        return 0;
    }
    printf("Reading lines...\n");

    if (isFileEmpty(fp) == 0)
    {
        // Method 2: Using fgetc()
        while (1)
        {
            char ch = fgetc(fp);
            if (ch == EOF)
            {
                lineCount += 1;
                break;
            }
            if (ch == '\n')
            {
                lineCount += 1;
            }
        }
    }

    printf("Total Lines: %d", lineCount);
    fclose(fp);
    return 0;
}