#ifndef STACK_H
#define STACK_H

// Define stack structure
typedef struct {
    int* arr;
    int capacity;
    int topIndex;
} Stack;


Stack* createStack(int n);

int isEmpty(Stack* stack);

int isFull(Stack* stack);

void push(Stack* stack, int x);

void pop(Stack* stack);

int peek(Stack* stack);

void print(Stack* stack);

#endif