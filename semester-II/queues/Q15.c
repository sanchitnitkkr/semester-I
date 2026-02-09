#include <stdio.h>
#include <stdlib.h>

// Queue using two stacks
typedef struct Stack
{
    int top;
    int capacity;
    int *arr;
} Stack;

Stack *createStack(int capacity)
{
    Stack *newStack = malloc(sizeof(Stack));
    newStack->top = -1;
    newStack->capacity = capacity;
    newStack->arr = malloc(sizeof(int) * capacity);

    return newStack;
}

int isFull(Stack *myStack)
{
    if (myStack->top == myStack->capacity - 1)
    {
        return 1;
    }

    return 0;
}

int isEmpty(Stack *myStack)
{
    if (myStack->top == -1)
    {
        return 1;
    }

    return 0;
}

void push(Stack *myStack, int val)
{
    if (isFull(myStack))
    {
        printf("Overflow!");
        return;
    }

    myStack->arr[++myStack->top] = val;
}

int pop(Stack *myStack)
{
    if (isEmpty(myStack))
    {
        printf("Underflow!");
        return -1;
    }

    return myStack->arr[myStack->top--];
}

typedef struct Queue
{
    Stack *s1;
    Stack *s2;
} Queue;

Queue *createQueue(int capacity)
{

    Stack *s1 = createStack(capacity);
    Stack *s2 = createStack(capacity);

    Queue *newQueue = malloc(sizeof(Queue));
    newQueue->s1 = s1;
    newQueue->s2 = s2;

    return newQueue;
}

void freeQueue(Queue *q)
{
    free(q->s1->arr);
    free(q->s1);

    free(q->s2->arr);
    free(q->s2);

    free(q);
}

void enqueue(Queue *myQueue, int val)
{
    if (isFull(myQueue->s1))
    {
        printf("Overflow!");
        return;
    }

    push(myQueue->s1, val);
};

void dequeue(Queue *myQueue)
{
    if (isEmpty(myQueue->s2))
    {
        while (isEmpty(myQueue->s1) == 0)
        {
            int popped = pop(myQueue->s1);
            push(myQueue->s2, popped);
        }
    }

    if (isEmpty(myQueue->s2))
    {
        printf("Underflow!");
        return;
    }

    pop(myQueue->s2);

    return;
}

int main()
{
    Queue *q1 = createQueue(100);

    return 0;
}