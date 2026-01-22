// WAP to reverse using recursion
#include <stdio.h>
#include "list.h"

Node *reverseUsingRecursion(Node *prev, Node *curr)
{
    if (curr == NULL)
    {
        return prev;
    }

    Node *next = curr->link;
    curr->link = prev;
    prev = curr;
    curr = next;
    return reverseUsingRecursion(prev, curr);
}

int main()
{
    ListInputReturnType result = takeListInputFromTheUser();
    Node *head = result.head;
    int noOfElements = result.noOfElements;

    head = reverseUsingRecursion(NULL, head);
    printList(head);
    return 0;
}