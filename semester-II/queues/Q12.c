#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int capacity;
    int front;
    int rear;
    int *arr;
} Queue;

Queue *createQueue(int capacity)
{
    if (capacity <= 0)
        return NULL;

    Queue *q = malloc(sizeof(Queue));
    if (!q)
        return NULL;

    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;

    q->arr = malloc(sizeof(int) * capacity);
    if (!q->arr)
    {
        free(q);
        return NULL;
    }
    return q;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

int isFull(Queue *q)
{
    return ((q->rear + 1) % q->capacity) == q->front;
}

void enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Overflow\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Underflow\n");
        return;
    }

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->capacity;
    }
}

int getFront(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Underflow\n");
        return -1;
    }
    return q->arr[q->front];
}
void printQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    int i = q->front;
    while (1)
    {
        printf("%d ", q->arr[i]);

        if (i == q->rear)
            break;

        i = (i + 1) % q->capacity;
    }

    printf("\n");
}

int main()
{
    int capacity;
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);

    Queue *newQueue = createQueue(capacity);
    if (!newQueue)
    {
        printf("Queue creation failed\n");
        return 1;
    }

    while (1)
    {
        int operation = 0;

        printf("\nEnter which operation you want:\n");
        printf("-1 - Exit\n");
        printf("1  - ENQUEUE\n");
        printf("2  - DEQUEUE\n");
        printf("3  - FRONT\n");
        printf("4  - PRINT\n");
        printf("Operation: ");

        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
        {
            printf("=====================\n");
            printf("ENQUEUE selected!\n");
            printf("=====================\n");

            int data;
            printf("Enter element to enqueue: ");
            scanf("%d", &data);

            enqueue(newQueue, data);

            printf("----Operation Ended----\n");
            break;
        }

        case 2:
        {
            printf("=====================\n");
            printf("DEQUEUE selected!\n");
            printf("=====================\n");

            dequeue(newQueue);

            printf("----Operation Ended----\n");
            break;
        }

        case 3:
        {
            printf("=====================\n");
            printf("FRONT selected!\n");
            printf("=====================\n");

            int front = getFront(newQueue);
            if (front != -1)
                printf("Front element: %d\n", front);

            printf("----Operation Ended----\n");
            break;
        }

        case 4:
        {
            printf("=====================\n");
            printf("PRINT selected!\n");
            printf("=====================\n");

            printQueue(newQueue);

            printf("----Operation Ended----\n");
            break;
        }

        case -1:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid operation\n");
        }
    }
}
