#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct Node
{
    struct TreeNode *data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    if (!q)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, TreeNode *x)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->data = x;

    if (isEmpty(q))
    {
        newNode->next = newNode; // circular link
        q->front = q->rear = newNode;
    }
    else
    {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Underflow: Queue is empty\n");
        return;
    }

    Node *temp = q->front;

    if (q->front == q->rear)
    {
        // only one element
        q->front = q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    free(temp);
}

TreeNode *peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return NULL;
    }
    return q->front->data;
}

int isComplete(struct TreeNode *root)
{
    if (root == NULL)
        return 1;

    struct Queue *myQueue = createQueue(); // adjust size if needed
    enqueue(myQueue, root);

    int seenNull = 0;

    while (!isEmpty(myQueue))
    {
        struct TreeNode *curr = peek(myQueue);
        dequeue(myQueue);

        if (curr == NULL)
        {
            seenNull = 1;
        }
        else
        {
            if (seenNull)
                return 0;
            enqueue(myQueue, curr->left);
            enqueue(myQueue, curr->right);
        }
    }
    return 1;
}

int main()
{
    TreeNode *root = getTreeFromUserInput();
    int res = isComplete(root);
    if(res == 1){
        printf("Tree is complete!\n");
    }
    else{
        printf("Tree is not complete\n");
    }
    return 0;
}