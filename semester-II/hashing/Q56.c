// Write a program to display hash table after inserting elements 17,16,22,36,33,46,26,144 into
// has table of size 10, using inear probin, where h(x) = x mod 10

#include <stdio.h>
#include <stdlib.h>

int hash(int element)
{
    return element % 10;
}

int main()
{
    // Hash table
    int hashTable[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    int inputElements[8] = {17, 16, 22, 36, 33, 46, 26, 144};

    int sizeHashTable = sizeof(hashTable) / sizeof(int);
    int sizeInput = sizeof(inputElements) / sizeof(int);

    for (int i = 0; i < sizeInput; i++)
    {
        int idx = hash(inputElements[i]);
        int startIdx = idx;

        while (hashTable[idx] != -1)
        {
            idx = (idx + 1) % sizeHashTable;

            if (idx == startIdx)
            {
                printf("Hash table is full!\n");
                return 0;
            }
        }

        hashTable[idx] = inputElements[i];
    }

    for (int i = 0; i < sizeHashTable; i++)
    {
        printf("%d => %d\n", i, hashTable[i]);
    }

    return 0;
}
