#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Queue using two stacks
typedef struct Stack
{
    int top;
    int capacity;
    char *arr;
} Stack;

Stack *createStack(int capacity)
{
    Stack *newStack = malloc(sizeof(Stack));
    newStack->top = -1;
    newStack->capacity = capacity;
    newStack->arr = malloc(sizeof(char) * capacity);

    return newStack;
}

char isFull(Stack *myStack)
{
    if (myStack->top == myStack->capacity - 1)
    {
        return 1;
    }

    return 0;
}

char isEmpty(Stack *myStack)
{
    if (myStack->top == -1)
    {
        return 1;
    }

    return 0;
}

void push(Stack *myStack, char val)
{
    if (isFull(myStack))
    {
        printf("Overflow!");
        return;
    }

    myStack->arr[++myStack->top] = val;
}

char pop(Stack *myStack)
{
    if (isEmpty(myStack))
    {
        // printf("Underflow!");
        return -1;
    }

    return myStack->arr[myStack->top--];
}

char top(Stack *myStack)
{
    if (isEmpty(myStack))
    {
        // printf("Underflow!");
        return -1;
    }

    return myStack->arr[myStack->top];
}

int getPrecedence(char character)
{
    if (character == '+' || character == '-')
    {
        return 1;
    }
    if (character == '^')
    {
        return 3;
    }
    if (character == '*' || character == '/')
    {
        return 2;
    }

    return 0;
};

char *infixToPostfix(char *input)
{
    Stack *myStack = createStack(1000);
    char *result = malloc(strlen(input) + 1);
    int k = 0;

    while (*input)
    {
        char character = *input;

        if (isalnum(character))
        {
            result[k++] = character;
        }
        else if (character == '(')
        {
            push(myStack, character);
        }
        else if (character == ')')
        {
            while (top(myStack) != '(')
            {
                result[k++] = pop(myStack);
            }
            pop(myStack);
        }
        else
        {
            int currPrecedence = getPrecedence(character);
            int topElePrecedence = getPrecedence(top(myStack));

            if (character == '^')
            {
                while (isEmpty(myStack) == 0 && getPrecedence(top(myStack)) > currPrecedence)
                {
                    result[k++] = pop(myStack);
                }
            }
            else
            {
                while (isEmpty(myStack) == 0 && getPrecedence(top(myStack)) >= currPrecedence)
                {
                    result[k++] = pop(myStack);
                }
            }

            push(myStack, character);
        }
        // Go to next character
        input = input + 1;
    }

    while (isEmpty(myStack) == 0)
    {
        result[k++] = pop(myStack);
    }

    result[k] = '\0';

    return result;
}

#include <stdio.h>
#include <string.h>

int main()
{
    char *inputs[] = {
        "A+B*C",
        "(A+B)*C",
        "A+B+C",
        "A*(B+C)/D",
        "A^B^C",
        "((A+B)-C*(D/E))+F"};

    int numTests = sizeof(inputs) / sizeof(inputs[0]);

    printf("INFIX TO POSTFIX CONVERSION\n");
    printf("===========================\n");

    for (int i = 0; i < numTests; i++)
    {
        char *postfix = infixToPostfix(inputs[i]);
        printf("Input  : %s\n", inputs[i]);
        printf("Output : %s\n\n", postfix);
    }
    return 0;
}