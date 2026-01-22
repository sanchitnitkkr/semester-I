#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *getMiddleNode(Node *iter)
{
    if (iter == NULL || iter->link == NULL)
        return iter;

    Node *slow = iter;
    Node *fast = iter->link;

    while (fast != NULL && fast->link != NULL)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    return slow;
}

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
}

Node *mergeSortList(Node *head, int ascending)
{
    if (head == NULL || head->link == NULL)
    {
        return head;
    }

    Node *middleNode = getMiddleNode(head);
    Node *right = middleNode->link;
    middleNode->link = NULL; 
    Node *left = head;

    left = mergeSortList(left, ascending);
    right = mergeSortList(right, ascending);

    return mergeTwoSortedLists(left, right, ascending);
}

int main()
{
    ListInputReturnType result = takeListInputFromTheUser();
    Node *head = result.head;
    int noOfElements = result.noOfElements;

    head = mergeSortList(head, 1);
    printList(head);
    return 0;
}