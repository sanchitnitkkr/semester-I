// Write a program to perform insert, delete and traverse operations on the singly
// linked list in the  beginning, end and on any specific location
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

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

int main()
{
    Node *p1 = malloc(sizeof(Node));
    Node *p2 = malloc(sizeof(Node));
    Node *p3 = malloc(sizeof(Node));
    Node *p4 = malloc(sizeof(Node));
    Node *p5 = malloc(sizeof(Node));

    p1->data = 1;
    p2->data = 2;
    p3->data = 3;
    p4->data = 4;
    p5->data = 5;

    p1->link = p2;
    p2->link = p3;
    p3->link = p4;
    p4->link = p5;
    p5->link = NULL;

    Node *head = p1;
    printLinkedList(head);

    // Add the element in starting and update the head
    head = unshiftHead(head, 10);
    printLinkedList(head);

    // Add the element in ending
    append(head, 20);
    printLinkedList(head);

    // Delete element at index
    deleteNode(head, 2);
    printLinkedList(head);

    return 0;
};
