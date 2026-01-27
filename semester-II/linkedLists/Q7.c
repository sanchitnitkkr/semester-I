// Write a program to implement a circular linked list

#include <stdio.h>
#include "list.h"

int main()
{
    ListInputReturnType result = takeListInputFromTheUser();
    Node *head = result.head;
    int noOfElements = result.noOfElements;

    int listSize = size(result.head);
    int cycleIdxStart = -1;
    int cycleIdxEnd = -1;
    printf("Enter the position you want to begin the cycle with (b/w %d and %d): ", 0, listSize - 1);
    scanf("%d", &cycleIdxStart);
    printf("Enter the position you want to end the cycle with (b/w %d and %d): ", 0, listSize - 1);
    scanf("%d", &cycleIdxEnd);

    Node *cycleStartNode = NULL;
    Node *cycleEndNode = NULL;

    Node *curr = head;
    int i = 0;

    while (curr)
    {
        if (i == cycleIdxStart)
        {
            cycleStartNode = curr;
        }
        else if (i == cycleIdxEnd)
        {
            cycleEndNode = curr;
        }
        curr = curr->link;
        i++;
    }

    cycleStartNode->link = cycleEndNode;
    
    
    printLinkedList(head);
    return 0;
}