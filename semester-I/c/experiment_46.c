// Write a program to find the largest element of an array using recursion.
#include <stdio.h>

int findLargestNumber(int arr[], int index, int noOfElements, int largestElement)
{
    if (noOfElements == 0)
        return 0;

    if (index == noOfElements)
    {
        return largestElement;
    }

    if (largestElement == NULL || largestElement < arr[index])
    {
        largestElement = arr[index];
    }

    return findLargestNumber(arr, index + 1, noOfElements, largestElement);
}

int main()
{
    int arr[] = {3, 2, 1, 2, 0, -1, 10, 5, 20, 2};

    int highestNumber = findLargestNumber(arr, 0, sizeof(arr) / sizeof(arr[0]), arr[0]);

    printf("%d\n", highestNumber);

    return 0;
}