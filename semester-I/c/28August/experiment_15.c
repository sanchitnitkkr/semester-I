#include <stdio.h>

int factorial(int N)
{
    int result = 1;
    for (int i = N; i >= 1; i--)
    {
        result *= i;
    }

    printf("The factorial is => %d", result);
}

int main()
{
    printf("Enter the number whose factorial you want to know\n");
    int N;
    scanf("%d", &N);
    factorial(N);
    return 0;
}