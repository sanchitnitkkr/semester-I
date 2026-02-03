#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int capacity;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    Stack *newStack = createStack(capacity);

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
            push(newStack, val);
            break;
        };
        case 2:
        {
            pop(newStack);
            break;
        };
        case 3:
        {
            print(newStack);
            break;
        };
        case -1:
        {
            return 0;
        };
        }
    }
}