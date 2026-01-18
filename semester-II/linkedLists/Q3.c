#include <stdio.h>
#include "list.h"

int main()
{
    ListInputReturnType result = takeListInputFromTheUser();
    Node *head = result.head;
    int noOfElements = result.noOfElements;

    Node *newHead = moveLastToFront(head);

    printLinkedList(newHead);

    return 0;
}