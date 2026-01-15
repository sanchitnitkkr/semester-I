#ifndef LIST_H
#define LIST_H

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

typedef struct
{
    Node *head;
    int noOfElements;
} ListInputReturnType;

ListInputReturnType takeListInputFromTheUser();

void printLinkedList(Node *head);

Node *getLastNode(Node *head);

Node *unshiftHead(Node *currHead, int data);

Node *append(Node *currHead, int data);

Node *appendAtIndex(Node *head, int data, int size, int index);

void deleteNode(Node *head, int index);

int size(Node *head);

Node *reverse(Node *head, int ascending);
#endif
