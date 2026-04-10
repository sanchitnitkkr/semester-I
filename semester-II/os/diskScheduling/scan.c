#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sortAscending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void scan(int requestQueue[], int size, int head, int diskSize, int rightDirection)
{
    int smaller[size], greater[size];
    int i = 0, j = 0;
    int lastHead = head;
    int totalTrackMovement = 0;

    for (int k = 0; k < size; k++)
    {
        if (requestQueue[k] < head)
            smaller[i++] = requestQueue[k];
        else
            greater[j++] = requestQueue[k];
    }

    sortDescending(smaller, i); // descending
    sortAscending(greater, j);  // ascending

    int seekSequence[size + 2];
    int l = 0;

    seekSequence[l++] = head;

    if (rightDirection == 1)
    {
        // move right first
        for (int k = 0; k < j; k++)
        {
            seekSequence[l++] = greater[k];
            totalTrackMovement += abs(lastHead - greater[k]);
            lastHead = greater[k];
        }

        seekSequence[l++] = diskSize - 1;
        totalTrackMovement += abs(lastHead - (diskSize - 1));
        lastHead = diskSize - 1;

        // then move left
        for (int k = 0; k < i; k++)
        {
            seekSequence[l++] = smaller[k];
            totalTrackMovement += abs(lastHead - smaller[k]);
            lastHead = smaller[k];
        }
    }
    else
    {
        // move left first
        for (int k = 0; k < i; k++)
        {
            seekSequence[l++] = smaller[k];
            totalTrackMovement += abs(lastHead - smaller[k]);
            lastHead = smaller[k];
        }

        seekSequence[l++] = 0;
        totalTrackMovement += abs(lastHead - 0);
        lastHead = 0;
        
        // move right first
        for (int k = 0; k < j; k++)
        {
            seekSequence[l++] = greater[k];
            totalTrackMovement += abs(lastHead - greater[k]);
            lastHead = greater[k];
        }
    }

    printf("Total track movement: %d", totalTrackMovement);
    printf("\nSeek Sequence: ");
    printArray(seekSequence, l);
}

int main()
{
    int diskSize = 200;
    int requestQueue[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int initialHeadPosition = 50;
    int size = sizeof(requestQueue) / sizeof(int);

    scan(requestQueue, size, initialHeadPosition, diskSize, 1);
}