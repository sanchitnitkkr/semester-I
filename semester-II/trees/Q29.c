#include <stdio.h>

/*
    (2n!)/ ((n+1)! * n!)
*/

int factorial(int n)
{
    if (n <= 1)
        return 1;

    int res = 1;

    while (n > 0)
        res *= n--;

    return res;
}

int noOfBinaryTrees(int n)
{
    return factorial((2 * n)) / (factorial(n + 1) * factorial(n));
}

int main()
{
    int keys;
    printf("Enter the number of unique keys: ");
    scanf("%d", &keys);

    printf("No of binary trees possible with %d keys: %d", keys, noOfBinaryTrees(keys));
    return 0;
}