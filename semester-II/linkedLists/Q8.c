// Write a program to check whether the given singly linked list is in non decreasing order or not
#include <stdio.h>
#include "list.h"

int isSortedInAscendingOrder(Node *head)
{
    if (!head || !head->link)
        return 1;

    Node *prev = head;
    Node *curr = head->link;

    while (curr)
    {
        if (curr->data <= prev->data)
        {
            return 0;
        }

        Node *next = curr->link;
        prev = curr;
        curr = next;
    }

    return 1;
}
int main()
{
    ListInputReturnType result = takeListInputFromTheUser();
    Node *head = result.head;
    int noOfElements = result.noOfElements;

    int isSorted = isSortedInAscendingOrder(head);
    if (isSorted == 1)
    {
        printf("The list you provided is sorted in a non decreasing order!");
    }
    else
    {
        printf("The list you provided is not sorted in a non decreasing order!");
    }
    return 0;
}