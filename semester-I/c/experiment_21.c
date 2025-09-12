#include <stdio.h>

void fibonacci(long long N)
{
    if (N <= 0)
    {
        printf("Invalid input");
        return;
    }

    long long firstNumber = 0;
    long long secondNumber = 1;

    printf("Fibonacci Series =>\n");

    if (N == 1)
    {
        printf("0");
        return;
    }
    else if (N == 2)
    {
        printf("0,1");
        return;
    }

    printf("0,1");

    int iterator = 3;
    while (iterator <= N)
    {
        long long sum = firstNumber + secondNumber;
        firstNumber = secondNumber;
        secondNumber = sum;
        printf(",%d", sum);
        iterator++;
    }
}

int main()
{
    printf("Experiment 21 [Sanchit Tewari 525110030]\n");
    long long int N;
    printf("Enter the length of sequence of fibonacci: ");
    scanf("%lld", &N);
    fibonacci(N);
}