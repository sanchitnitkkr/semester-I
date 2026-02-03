#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    Queue *newQueue = createQueue();
    while (1)
    {
        int operation;
        printf("What do you want to do?\n");
        printf("1 -> PUSH\n");
        printf("2 -> POP\n");
        printf("3 -> PRINT\n");
        printf("-1 -> EXIT\n");
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
        {
            int val;
            printf("Element to be pushed => ");
            scanf("%d", &val);
            enqueue(newQueue, val);
            break;
        };
        case 2:
        {
            dequeue(newQueue);
            break;
        };
        case 3:
        {
            printQueue(newQueue);
            break;
        };
        case -1:
        {
            return 0;
        };
        }
    }
    return 0;
}
