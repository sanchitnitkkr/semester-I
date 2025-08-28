#include <stdio.h>
#include <math.h>

void isPrime(int num)
{
    if (num <= 1)
    {
        printf("The number is not a prime number\n");
        return;
    }

 
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            printf("The number is not a prime number\n");
            return;
        }
    }
    
    printf("The number is a prime number\n");
}

int main()
{
    printf("Enter the number for which you want to check the primeness\n");
    int num;
    scanf("%d",&num);
    isPrime(num);
    return 0;
}