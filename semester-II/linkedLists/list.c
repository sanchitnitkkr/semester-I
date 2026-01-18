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
    if (index > size || index < 0)
    {
        printf("INVALID INDEX!!!\n");
        return head;
    }
    if (index == 0)
    {
        return unshiftHead(head, data);
    }
    else if (index == size)
    {
        append(head, data);
        return head;
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

Node *moveLastToFront(Node *head)
{
    if (head == NULL || head->link == NULL)
        return head;

    Node *prevNode = head;
    Node *currNode = head->link;

    while (currNode->link != NULL)
    {
        prevNode = prevNode->link;
        currNode = currNode->link;
    }

    prevNode->link = NULL;
    currNode->link = head;
    return currNode;
};

Node *reverse(Node *head, int ascending)
{

    Node *prevNode = NULL;
    Node *currNode = head;

    while (currNode != NULL)
    {
        Node *nextNode = currNode->link;
        currNode->link = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    return prevNode;
};

Node *getMiddle(Node *head)
{
    if (head == NULL || head->link == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->link;

    while (slow != NULL && fast->link != NULL)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    return slow;
};

Node *mergeTwoSortedLists(Node *left, Node *right, int ascending)
{
    Node *tempNode = malloc(sizeof(Node));
    tempNode->data = -1;
    Node *tempIterator = tempNode;

    while (left != NULL && right != NULL)
    {
        if (ascending)
        {
            if (left->data <= right->data)
            {
                tempIterator->link = left;
                left = left->link;
            }
            else
            {
                tempIterator->link = right;
                right = right->link;
            }
        }
        else
        {
            if (left->data > right->data)
            {
                tempIterator->link = left;
                left = left->link;
            }
            else
            {
                tempIterator->link = right;
                right = right->link;
            }
        }

        tempIterator = tempIterator->link;
    }

    while (left != NULL)
    {
        tempIterator->link = left;
        left = left->link;
        tempIterator = tempIterator->link;
    }
    while (right != NULL)
    {
        tempIterator->link = right;
        right = right->link;
        tempIterator = tempIterator->link;
    }

    Node *link = tempNode->link;
    free(tempNode);

    return link;
};

Node *sortList(Node *head, int ascending)
{
    if (head == NULL || head->link == NULL)
    {
        return head;
    }

    Node *midNode = getMiddle(head);

    Node *right = midNode->link;
    midNode->link = NULL;
    Node *left = head;

    left = sortList(left, ascending);
    right = sortList(right, ascending);

    return mergeTwoSortedLists(left, right, ascending);
};

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
        printf("\nEnd of list\n");
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