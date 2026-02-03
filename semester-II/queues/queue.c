#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    if (!q) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int x)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->data = x;

    if (isEmpty(q)) {
        newNode->next = newNode;  // circular link
        q->front = q->rear = newNode;
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue *q)
{
    if (isEmpty(q)) {
        printf("Underflow: Queue is empty\n");
        return;
    }

    Node *temp = q->front;

    if (q->front == q->rear) {
        // only one element
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    free(temp);
}

int peek(Queue *q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

void printQueue(Queue *q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    Node *temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);

    printf("\n");
}
