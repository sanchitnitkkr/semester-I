// Reverse linked list using iteration
#include <stdio.h>
#include "list.h"

int main()
{
    ListInputReturnType result = takeListInputFromTheUser();
    Node *head = result.head;
    int noOfElements = result.noOfElements;

    head = reverse(head);

    printList(head);
    
    return 0;
}