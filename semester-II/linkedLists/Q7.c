// Write a program to implement a circular linked list

#include <stdio.h>
#include "list.h"
#include <stdlib.h>

void printCircularLinkedList(Node *head, int limit)
{
    Node *curr = head;
    int count = 0;
    while (curr && count < limit) // limit avoids infinite loops
    {
        printf("%d -> ", curr->data);
        curr = curr->link;
        count++;
    }
    if (curr)
        printf("... (cycle detected)\n");
    else
        printf("NULL\n");
}

Node *insertAtBeginning(Node *head, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;

    if (!head)
    {
        newNode->link = newNode;
        return newNode;
    }

    Node *curr = head;
    while (curr->link != head)
    {
        curr = curr->link;
    }

    newNode->link = head;
    curr->link = newNode;
    return newNode;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (!head)
    {
        newNode->link = newNode;
        return newNode;
    }

    Node *curr = head;
    while (curr->link != head)
    {
        curr = curr->link;
    }

    curr->link = newNode;
    newNode->link = head;

    return head;
}

Node *deleteAtPos(Node *head, int pos)
{
    if (!head)
        return NULL;

    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    if (pos == 0)
    {
        while (curr->link != head)
        {
            curr = curr->link;
        }

        Node *temp = head;
        if (head->link == head)
        {
            free(head);
            return NULL;
        }

        curr->link = head->link;
        head = head->link;
        free(temp);
        return head;
    }

    prev = head;
    curr = head->link;
    count = 1;

    while (curr != head && count < pos)
    {
        prev = curr;
        curr = curr->link;
        count++;
    }

    if (curr == head)
    {
        printf("Position out of bounds\n");
        return head;
    }

    prev->link = curr->link;
    free(curr);
    return head;
}

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
    printf("Enter the position you want to end the cycle with (b/w %d and %d): ", 0, cycleIdxStart);
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
    printCircularLinkedList(head, listSize);

    /*
           Operation codes:
          -1 - Exit
           1 - Add at beginning
           2 - Add at end
           3 - Remove at ith index
           4 - Print list
       */
    int operation = 0;
    printf("\nEnter which operation you want:\n-1 - Exit\n1 - Add at beginning\n2 - Add at end\n3 - Remove at ith index\n4 - Print the list\nOperation: ");
    scanf("%d", &operation);

    while (1)
    {
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
            head = insertAtBeginning(head, data);
            listSize++;
            printCircularLinkedList(head, listSize);
            printf("----Operation Ended----\n");
            break;
        }
        case 2:
        {
            printf("=====================\n");
            printf("Operation 2 selected!\n");
            printf("=====================\n");
            int data;
            printf("Enter the element to add at END: ");
            scanf("%d", &data);
            // Add the element in ending
            listSize++;
            insertAtEnd(head, data);
            printCircularLinkedList(head, listSize);
            printf("----Operation Ended----\n");
            break;
        }
        case 3:
        {
            printf("=====================\n");
            printf("Operation 3 selected!\n");
            printf("=====================\n");
            int index = -1;
            printf("Enter the index to remove (Must be in range): ");
            while (index < 0)
            {
                scanf("%d", &index);
            }
            // Delete element at index
            deleteAtPos(head, index);
            listSize--;
            printCircularLinkedList(head, listSize);
            printf("----Operation Ended----\n");
            break;
        }
        case 4:
        {
            printf("=====================\n");
            printf("Operation 5 selected!\n");
            printf("=====================\n");
            printCircularLinkedList(head, listSize);
            printf("----Operation Ended----\n");
            break;
        }
        case -1:
        {
            break;
        }
        }
    }

    return 0;
}