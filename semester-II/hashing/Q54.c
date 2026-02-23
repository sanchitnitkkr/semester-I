// 54. Insert following keys 5, 28, 19, 15, 20, 33, 12, 17 and 10 in hash table using chaining
// hashing method and find minimum, maximum and average chain length in hash table.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

#define TABLE_SIZE 10

int hash(int element)
{
    return element % 10;
}

int main()
{
    // Hash table
    Node *hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }

    int inputElements[9] = {5, 28, 19, 15, 20, 33, 12, 17, 10};

    int sizeHashTable = TABLE_SIZE;
    int sizeInput = sizeof(inputElements) / sizeof(int);

    for (int i = 0; i < sizeInput; i++)
    {
        int idx = hash(inputElements[i]);
        Node *newNode = malloc(sizeof(Node));
        newNode->data = inputElements[i];

        newNode->link = hashTable[idx];
        hashTable[idx] = newNode;
    }

    int minChainLength = INT_MAX;
    int maxChainLength = 0;
    float avgChainLength = 0;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("%d => ", i);
        Node *temp = hashTable[i];
        int currChainLength = 0;
        while (temp != NULL)
        {
            currChainLength++;
            printf("%d -> ", temp->data);
            temp = temp->link;
        }

        if (minChainLength > currChainLength)
        {
            minChainLength = currChainLength;
        }
        if (maxChainLength < currChainLength)
        {
            maxChainLength = currChainLength;
        }
        avgChainLength += currChainLength;

        printf("NULL\n");
    }

    avgChainLength = avgChainLength / (float)TABLE_SIZE;

    printf("Min Chain Length: %d\n", minChainLength);
    printf("Max Chain Length: %d\n", maxChainLength);
    printf("Avg Chain Length: %.2f\n", avgChainLength);

    return 0;
}
