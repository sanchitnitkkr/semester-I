#include <stdio.h>

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int size)
{
    int index = 0;

    for (int i = 1; i < size; i++)
    {
        int j = i;

        while (j > 0 && arr[j] < arr[j - 1])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }

        // printArray(arr, size);
    }
}

int main()
{
    int arr[] = {6, 3, 6, 8, 9, 1, 2, 7};
    int size = sizeof(arr) / sizeof(int);

    insertionSort(arr, size);
    printArray(arr,size);
    return 0;
}