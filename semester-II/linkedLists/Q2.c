#include <stdio.h>
#include "list.h"

int main()
{
    ListInputReturnType result = takeListInputFromTheUser();
    Node *head = result.head;
    int noOfElements = result.noOfElements;

    Node *newHead = sortList(head, 0);
    
    printLinkedList(newHead);

    return 0;
}