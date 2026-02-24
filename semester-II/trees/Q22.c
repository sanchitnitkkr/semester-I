#include <stdio.h>


int factorial(int n)
{
    int res = 1;

    while (n >= 1)
    {
        res *= n--;
    }

    return res;
}

int getNoOfLabelledBinaryTrees(int n)
{
    return factorial(2 * n) / (factorial(n + 1));
}
int getNoOfUnlabelledBinaryTrees(int n)
{
    return factorial(2 * n) / ((factorial(n + 1)) * factorial(n));
}

int main()
{
    int nodesCount;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodesCount);

    printf("No of unlabelled binary trees: %d\n", getNoOfUnlabelledBinaryTrees(nodesCount));
    printf("No of labelled binary trees: %d", getNoOfLabelledBinaryTrees(nodesCount));
    return 0;
}