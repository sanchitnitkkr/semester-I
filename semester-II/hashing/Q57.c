// Write a program to display hash table after inserting elements 17,16,22,36,33,46,26,144 into
// has table of size 10, using quadratic probing, where h(x) = x mod 10

#include <stdio.h>
#include <stdlib.h>

int hash(int element)
{
    return element % 10;
}

// h(k, i) = ( h(k) + c1·i + c2·i² ) mod m
const int c1 = 0;
const int c2 = 1;

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
        int m = sizeHashTable;
        int baseIdx = idx;

        int j = 1;

        while (hashTable[idx] != -1)
        {
            idx = (baseIdx + ((c1 * j)) + (c2 * (j * j))) % sizeHashTable;
            if (m <= 0)
            {
                printf("Failed to insert!\n");
                break;
            }

            j++;
            m--;
        }

        hashTable[idx] = inputElements[i];
    }

    for (int i = 0; i < sizeHashTable; i++)
    {
        printf("%d => %d\n", i, hashTable[i]);
    }

    return 0;
}
