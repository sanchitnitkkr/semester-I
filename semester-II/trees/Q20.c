#include <stdio.h>

long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

long long noOfBinaryTrees(int n)
{
    long long res;
    res = factorial(2 * n) / (factorial(n + 1) * factorial(n));
    return res;
}

int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Number of binary trees with %d nodes = %lld\n", n, noOfBinaryTrees(n));

    return 0;
}