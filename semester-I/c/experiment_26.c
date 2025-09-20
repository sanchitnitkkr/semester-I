#include <stdio.h>

void getCommonElements(int arr1[], int arr2[], int len1, int len2)
{
    for (int i = 0; i < len1; i++)
    {
        int found = 0;
        for (int j = 0; j < len2; j++)
        {
            if (arr2[j] == arr1[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            printf("The arrays do have a common element => %d", arr1[i]);
            return;
        }
    }
}

int main()
{
    printf("Experiment 26 [Sanchit Tewari 525110030]\n");
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {4, 5, 6, 7, 8};
    getCommonElements(arr1, arr2, sizeof(arr1) / sizeof(int), sizeof(arr2) / sizeof(int));
}