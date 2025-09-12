#include <stdio.h>

int sumNNaturalNums(int N)
{
    int sum = 0;

    // Method 1
    for (int i = 0; i < N; i++)
    {
        sum += i;
    }

    // Method 2
    sum = (N * (N + 1)) / 2;

    return sum;
}

int main()
{
    printf("Experiment 12 [Sanchit Tewari 525110030]\n");
    printf("Sum till which number is required?\n");
    int N;
    scanf("%d", &N);
    int sum = sumNNaturalNums(N);
    printf("Sum of %d natural numbers is %d", N, sum);
    return 0;
}