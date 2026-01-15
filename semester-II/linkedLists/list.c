#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int size(Node *head)
{
    int i = 0;
    while (head != NULL)
    {
        head = head->link;
        i++;
    }

    return i;
}
Node *appendAtIndex(Node *head, int data, int size, int index)
{
    if (index >= size || index < 0)
    {
        printf("INVALID INDEX!!!");
        return head;
    }
    if (index == 0)
    {
        return unshiftHead(head, data);
    }
    else if (index == size - 1)
    {
        return append(head, data);
    }
    else
    {
        Node *prev = head;

        for (int i = 1; i < index; i++)
        {
            prev = prev->link;
        }

        Node *newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->link = prev->link;

        prev->link = newNode;

        return head;
    }
};

Node reverse(Node *head, int ascending)
{
    // if ()
    //     Node *prevNode = NULL;
    Node *currNode = head;
    // Node *nextNode =
}

ListInputReturnType takeListInputFromTheUser()
{
    int noOfElements = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &noOfElements);

    Node *prevNode = NULL;
    Node *head = NULL;

    for (int i = 0; i < noOfElements; i++)
    {
        int data = 0;
        printf("%dth element: ", i);
        scanf("%d", &data);

        Node *p = malloc(sizeof(Node));
        p->data = data;
        p->link = NULL;

        if (head == NULL)
        {
            head = p;
            prevNode = p;
        }
        else
        {
            prevNode->link = p;
            prevNode = p;
        }
    }

    ListInputReturnType result = {head, noOfElements};
    return result;
}

void printLinkedList(Node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    head = head->link;
    printLinkedList(head);
};

Node *getLastNode(Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->link == NULL)
        return head;

    return getLastNode(head->link);
}

Node *unshiftHead(Node *currHead, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = currHead;
    return newNode;
};

Node *append(Node *currHead, int data)
{

    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;

    Node *lastNode = getLastNode(currHead);
    if (lastNode != NULL)
    {
        lastNode->link = newNode;
    }

    return newNode;
};

void deleteNode(Node *head, int index)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->link == NULL)
    {
        if (index == 0)
        {
            free(head);
        }
        else
        {
            return; // Throw error
        }
        return;
    }

    Node *prevNode = NULL;
    Node *currNode = head;
    Node *nextNode = head->link;

    int i = 0;
    while (i <= index)
    {
        if (i == index)
        {
            free(currNode);
            prevNode->link = nextNode;
            break;
        }
        else
        {
            prevNode = currNode;
            currNode = nextNode;
            nextNode = nextNode->link;
            i++;
        }
    }
    return;
};