#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *createStack(int n)
{
    Stack *newStack = malloc(sizeof(Stack));
    newStack->arr =  malloc(n * sizeof(int));
    newStack->capacity = n;
    newStack->topIndex = -1;
}

int isEmpty(Stack *stack)
{
    if (stack->topIndex == -1)
        return 1;
    return 0;
}

int isFull(Stack *stack)
{
    if (stack->topIndex == stack->capacity - 1)
        return 1;
    return 0;
}

void push(Stack *stack, int x)
{
    // inserts x at the top of the stack
    if (stack->topIndex == stack->capacity - 1)
    {
        printf("Overflow: Cannot push to stack since it's already full!");
        return;
    }

    stack->arr[++(stack->topIndex)] = x;
}

void pop(Stack *stack)
{
    // removes an element from the top of the stack
    if (stack->topIndex < 0)
    {
        printf("Underflow: Cannot pop since stack is already empty");
        return;
    }

    stack->topIndex--;
}

int peek(Stack *stack)
{
    // Returns the top element of the stack
    if (stack->topIndex < 0)
    {
        printf("Stack is empty, nothing to show!");
        return -1;
    }

    return stack->arr[stack->topIndex];
}

void print(Stack *newStack)
{
    printf("Top -> Bottom\n");
    for (int i = newStack->topIndex; i >= 0; i--)
    {
        printf("%d -> ", newStack->arr[i]);
    }
    printf("END\n");
}