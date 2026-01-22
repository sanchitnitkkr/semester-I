// WAP to print elements using recursion
#include <stdio.h>
#include "list.h"

int main()
{
    ListInputReturnType result = takeListInputFromTheUser();
    Node *head = result.head;
    int noOfElements = result.noOfElements;

    printList(head);
    return 0;
}