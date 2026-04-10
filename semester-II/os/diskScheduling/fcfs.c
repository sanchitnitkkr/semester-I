#include <stdio.h>
#include <stdlib.h>

void fcfs(int requestQueue[], int size, int initialHeadPosition)
{
    if (size == 0)
        return;

    int totalHeadMovement = 0;
    int prevTrack = initialHeadPosition;

    printf("Seek sequence: ");
    for (int i = 0; i < size; i++)
    {
        int currTrack = requestQueue[i];
        int diff = abs(currTrack - prevTrack);
        totalHeadMovement += diff;
        prevTrack = currTrack;
        printf("%d ", requestQueue[i]);
    };

    printf("\nTotal tracks travelled: %d", totalHeadMovement);
}

int main()
{
    int requestQueue[] = {82, 170, 43, 140, 24, 16, 190};
    int initialHeadPosition = 50;
    int size = sizeof(requestQueue) / sizeof(int);

    fcfs(requestQueue, size, initialHeadPosition);
};
