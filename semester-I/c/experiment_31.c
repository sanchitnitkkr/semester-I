#include <stdio.h>

int main()
{
    printf("Experiment 31 [Sanchit Tewari 525110030]\n");
    int rows = 3;
    int columns = 3;
    int arr1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[3][3] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr3[3][3] = {};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int sum = 0;
            int k = 0;
            while (k < columns)
            {
                sum += arr1[i][k] * arr2[k][j];
                k++;
            }
            arr3[i][j] = sum;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
}