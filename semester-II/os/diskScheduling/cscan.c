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

void cscan(int requestQueue[], int size, int head, int diskSize, int rightDirection)
{
    int left[size], right[size];
    int i = 0, j = 0;
    int lastHead = head;
    int totalTrackMovement = 0;

    for (int k = 0; k < size; k++)
    {
        if (requestQueue[k] < head)
            left[i++] = requestQueue[k];
        else
            right[j++] = requestQueue[k];
    }
    
    sortAscending(left, i);  // ascending
    sortAscending(right, j); // ascending

    int seekSequence[size + 2];
    int l = 0;

    seekSequence[l++] = head;

    if (rightDirection == 1)
    {
        for (int k = 0; k < j; k++)
        {
            seekSequence[l++] = right[k];
            totalTrackMovement += abs(lastHead - right[k]);
            lastHead = right[k];
        }

        if (lastHead != (diskSize - 1))
        {
            seekSequence[l++] = (diskSize - 1);
            totalTrackMovement += abs(lastHead - (diskSize - 1));
            lastHead = (diskSize - 1);
        }

        seekSequence[l++] = 0;
        totalTrackMovement += abs(lastHead - 0);
        lastHead = 0;

        // then move right again from start
        for (int k = 0; k < i; k++)
        {
            seekSequence[l++] = left[k];
            totalTrackMovement += abs(lastHead - left[k]);
            lastHead = left[k];
        }
    }
    else
    {
        // move left
        for (int k = i - 1; k >= 0; k--)
        {
            seekSequence[l++] = left[k];
            totalTrackMovement += abs(lastHead - left[k]);
            lastHead = left[k];
        }

        if (lastHead != 0)
        {
            seekSequence[l++] = 0;
            totalTrackMovement += abs(lastHead - 0);
            lastHead = 0;
        }

        if (lastHead != (diskSize - 1))
        {
            seekSequence[l++] = (diskSize - 1);
            totalTrackMovement += abs(lastHead - (diskSize - 1));
            lastHead = (diskSize - 1);
        }

        for (int k = j - 1; k >= 0; k--)
        {
            seekSequence[l++] = right[k];
            totalTrackMovement += abs(lastHead - right[k]);
            lastHead = right[k];
        }
    }

    printf("Total track movement: %d", totalTrackMovement);
    printf("\nSeek Sequence: ");
    printArray(seekSequence, l);
}

int main()
{
    int requestQueue[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int initialHeadPosition = 50;
    int size = sizeof(requestQueue) / sizeof(int);
    int diskSize = 200;

    cscan(requestQueue, size, initialHeadPosition, diskSize, 0);
}