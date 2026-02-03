#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue();
int isEmpty(Queue *q);
void enqueue(Queue *q, int x);
void dequeue(Queue *q);
int peek(Queue *q);
void printQueue(Queue *q);

#endif
