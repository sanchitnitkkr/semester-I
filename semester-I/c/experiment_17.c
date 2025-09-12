#include <stdio.h>

void printHalfPyramid(int N)
{
    int rows = N;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    printf("Experiment 17 [Sanchit Tewari 525110030]\n");
    int N;
    printf("Enter N for the half pyramid where N is the number of lines/rows: ");
    scanf("%d", &N);
    printHalfPyramid(N);
    return 0;
}