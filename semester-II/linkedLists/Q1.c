// Write a program to perform insert, delete and traverse operations on the singly
// linked list in the  beginning, end and on any specific location
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    ListInputReturnType result = takeListInputFromTheUser();
    Node *head = result.head;
    int noOfElements = result.noOfElements;

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
        printf("Enter which operation you want:\n-1 - Exit\n1 - Add at beginning\n2 - Add at end\n3 - Remove at ith index\n4 - Insert at ith index\n5 - Print the list\nOperation: ");
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
            head = unshiftHead(head, data);
            printLinkedList(head);
            printf("----Operation Ended----\n");
            break;
        }
        case 2:
        {
            printf("=====================\n");
            printf("Operation 2 selected!\n");
            printf("=====================\n");
            int data;
            printf("Enter the element to add at beginning: ");
            scanf("%d", &data);
            // Add the element in ending
            append(head, data);
            printLinkedList(head);
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
            deleteNode(head, index);
            printLinkedList(head);
            printf("----Operation Ended----\n");
            break;
        }
        case 4:
        {
            printf("=====================\n");
            printf("Operation 4 selected!\n");
            printf("=====================\n");
            int index = -1;
            printf("Enter the index to add: ");
            scanf("%d", &index);
            int data;
            printf("Enter the element to add at index %d: ", index);
            scanf("%d", &data);
            head = appendAtIndex(head, data, size(head), index);
            printLinkedList(head);
            printf("----Operation Ended----\n");
            break;
        }
        case 5:
        {
            printf("=====================\n");
            printf("Operation 5 selected!\n");
            printf("=====================\n");
            printLinkedList(head);
            printf("----Operation Ended----\n");
            break;
        }
        case -1: {
            break;
        }
        }
    }

    return 0;
};
