// Write a program for deletion of an element from the specified location in an array and print the resultant array
#include <stdio.h>

// Assumes a valid index is provided
void pop(int arr[], int size, int index)
{
    if (index == size - 1)
    {
    }
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
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

    printf("Experiment 28 [Sanchit Tewari 525110030]\n");
    int arr[] = {10, 50, 30, 40};
    int size = sizeof(arr) / sizeof(int);
    int indexToBeRemoved = 2;

    if (indexToBeRemoved <= 0 || indexToBeRemoved >= size)
    {
        printf("Invalid index was entered. Try again!");
    }

    for (int i = indexToBeRemoved; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    printArray(arr, size);
}