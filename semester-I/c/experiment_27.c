#include <stdio.h>

int reverse(int arr[], int size)
{
    int startPtr = 0;
    int endPtr = size - 1;

    while (startPtr < endPtr)
    {
        int temp = arr[startPtr];
        arr[startPtr] = arr[endPtr];
        arr[endPtr] = temp;
        startPtr++;
        endPtr--;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    printf("Experiment 27 [Sanchit Tewari 525110030]\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(int);
    reverse(arr, size);
    printArray(arr, size);
}