#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    int currSize;
    struct Node *top;
} Stack;

Stack *createStack()
{
    Stack *newStack = malloc(sizeof(Stack));

    if (!newStack)
        return NULL;

    newStack->currSize = 0;
    newStack->top = NULL;

    return newStack;
}

void push(Stack *myStack, int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    newNode->next = myStack->top;
    myStack->top = newNode;

    myStack->currSize++;
};

int pop(Stack *myStack)
{
    if (myStack->top == NULL)
        return -1; // underflow

    Node *temp = myStack->top;
    int val = temp->data;

    myStack->top = temp->next;
    free(temp);
    myStack->currSize--;

    return val;
};

void printElements(Stack *myStack)
{
    Node *temp = myStack->top;

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Stack *newStack = createStack();

    while (1)
    {
        /*
            Operation codes:
           -1 - Exit
            1 - Add at beginning
            2 - Add at end
            3 - Remove at ith index
            4 - Print list
        */
        int operation = 0;
        printf("\nEnter which operation you want:\n-1 - Exit\n1 - PUSH\n2 - POP\n3 - PRINT\nOperation: ");
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
        {
            printf("=====================\n");
            printf("Operation 1 selected!\n");
            printf("=====================\n");
            int data = 0;
            printf("Enter the element to add at beginning: ");
            scanf("%d", &data);
            // Add the element in starting and update the head
            push(newStack, data);
            // printElements(newStack);
            printf("----Operation Ended----\n");
            break;
        }
        case 2:
        {
            printf("=====================\n");
            printf("Operation 2 selected!\n");
            printf("=====================\n");
            pop(newStack);
            printf("----Operation Ended----\n");
            break;
        }
        case 3:
        {
            printf("=====================\n");
            printf("Operation 3 selected!\n");
            printf("=====================\n");
            printElements(newStack);
            printf("----Operation Ended----\n");
            break;
        }
        case -1:
        {
            printf("Exiting...\n");
            return 0;
        }
        }
    }

    return 0;
}

