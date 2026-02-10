// Write a program to display hash table after inserting elements 17,16,22,36,33,46,26,144 into
// has table of size 10, using double hashing, where h(x) = x mod 10 and h2(x) = x mod 6 + 1

#include <stdio.h>
#include <stdlib.h>

int hash(int element)
{
    return element % 10;
}

int secondHash(int element)
{
    return (element % 6) + 1;
}

// h(x,i)=(h1​(x)+i⋅h2​(x))mod10
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
        int idx2 = secondHash(inputElements[i]);

        int startIdx = idx;
        int j = 1;
        int baseIdx = idx;
        int baseIdx2 = idx2;

        int m = sizeHashTable;
        while (hashTable[idx] != -1)
        {
            // Conflict occured
            idx = ((baseIdx) + (j * baseIdx2)) % sizeHashTable;

            if (m <= 0)
            {
                printf("No insertion spaces left for the key");
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
