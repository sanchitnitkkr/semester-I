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

void clook(int requestQueue[], int size, int head,int rightDirection)
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

    // sort safely
    if (i > 0)
        sortAscending(left, i);
    if (j > 0)
        sortAscending(right, j);

    int seekSequence[size + 1];
    int l = 0;

    seekSequence[l++] = head;

    if (rightDirection)
    {
        // move right
        for (int k = 0; k < j; k++)
        {
            seekSequence[l++] = right[k];
            totalTrackMovement += abs(lastHead - right[k]);
            lastHead = right[k];
        }

        // jump to smallest left
        if (i > 0)
        {
            totalTrackMovement += abs(lastHead - left[0]);
            lastHead = left[0];
            seekSequence[l++] = left[0];

            for (int k = 1; k < i; k++)
            {
                seekSequence[l++] = left[k];
                totalTrackMovement += abs(lastHead - left[k]);
                lastHead = left[k];
            }
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

        // jump to largest right
        if (j > 0)
        {
            totalTrackMovement += abs(lastHead - right[j - 1]);
            lastHead = right[j - 1];
            seekSequence[l++] = right[j - 1];

            for (int k = j - 2; k >= 0; k--)
            {
                seekSequence[l++] = right[k];
                totalTrackMovement += abs(lastHead - right[k]);
                lastHead = right[k];
            }
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

    clook(requestQueue, size, initialHeadPosition, 0);
}