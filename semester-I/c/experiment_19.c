#include <stdio.h>

int padPrint(int totalChars, int spacesOnEachSide)
{
    for (int i = 0; i < spacesOnEachSide; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < totalChars; i++)
    {
        printf("*");
    }
    for (int i = 0; i < spacesOnEachSide; i++)
    {
        printf(" ");
    }
    printf("\n");
}

int printPattern(int N)
{
    int rows = N;
    int columns = (N * 2) - 1;

    for (int i = 1; i <= rows; i++)
    {
        int starsToBePrinted = (i * 2) - 1;
        int spaces = (columns - (starsToBePrinted)) / 2;
        padPrint(starsToBePrinted, spaces);
    }
}

int main()
{
    printf("Experiment 19 [Sanchit Tewari 525110030]\n");
    printf("Enter the number\n");
    int num;
    scanf("%d", &num);
    printPattern(num);
}
