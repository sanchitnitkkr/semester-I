#include <stdio.h>
#include <stdlib.h>

typedef struct Result
{
    int value;
    int index;
} Result;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

Result *findSmallestDistanceElement(int arr[], int size, int element)
{
    Result *result = malloc(sizeof(Result));

    int difference = __INT_MAX__;
    int closestElementIndex = -1;
    int lastElement = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == -1)
            continue;

        int currentDifference = abs(arr[i] - element);
        if (currentDifference < difference)
        {
            lastElement = arr[i];
            difference = currentDifference;
            closestElementIndex = i;
        }
    }

    result->value = lastElement;
    result->index = closestElementIndex;

    return result;
}

void sstf(int requestQueue[], int size, int inititalHeadPosition)
{
    int seekSequeunce[size];
    int iter = 0;
    int totalTrackMovement = 0;

    Result *closestInfo = findSmallestDistanceElement(requestQueue, size, inititalHeadPosition);
    int closestIndexForInitialHeadPosition = closestInfo->index;
    int closestElement = closestInfo->value;

    seekSequeunce[iter++] = closestElement;
    requestQueue[closestIndexForInitialHeadPosition] = -1;
    int elementsDone = 1;
    totalTrackMovement += abs(inititalHeadPosition - closestElement);
    
    // Begin for all other elements now
    int lastElement = closestElement;
    
    while (elementsDone < size)
    {
        Result *closestInfo = findSmallestDistanceElement(requestQueue, size, lastElement);
        int closestIndexForInitialHeadPosition = closestInfo->index;
        int closestElement = closestInfo->value;
        totalTrackMovement += abs(lastElement - closestElement);

        lastElement = closestElement;
        seekSequeunce[iter++] = closestElement;
        requestQueue[closestIndexForInitialHeadPosition] = -1;
        elementsDone++;
    }

    printf("\nTotal track movement: %d", totalTrackMovement);
    printf("\nSeek Sequence: %d ", inititalHeadPosition);
    printArray(seekSequeunce, size);
}

int main()
{
    int requestQueue[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int initialHeadPosition = 50;
    int size = sizeof(requestQueue) / sizeof(int);

    sstf(requestQueue, size, initialHeadPosition);
    return 0;
}