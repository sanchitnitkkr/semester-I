
#include <stdio.h>
#include <stdlib.h>

// 10, 13, 16
// Total
typedef struct
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

void printLinkedList(Node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", head->prev);
    printLinkedList(head->next);
};

void addTail(Node *head, int X)
{
    Node *curr = head;

    while (curr && curr->next)
    {
        curr = curr->next;
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->data = X;
    newNode->prev = curr;
    curr->next = newNode;
}

Node *addHead(Node *head, int X)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;

    return newNode;
}

Node *print(Node *head)
{
    if (!head)
    {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    print(head->next);
};

Node *deleteAtIndex(Node *head, int K)
{
    int i = 0;

    Node *prev = NULL;
    Node *curr = head;
    while (i < K && head)
    {
        i++;
        prev = curr;
        curr = curr->next;
    };

    prev->next = curr->next;
    if (curr && curr->next)
    {
        Node *next = curr->next;
        next->prev = prev;
    }
    free(curr);
}

int main()
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
        p->prev = NULL;
        p->next = NULL;

        if (head == NULL)
        {
            head = p;
            prevNode = p;
        }
        else
        {
            prevNode->next = p;
            p->prev = prevNode;
            prevNode = p;
        }
    }

    printLinkedList(head);

    return 0;
}