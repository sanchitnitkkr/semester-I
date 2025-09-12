#include <stdio.h>

int isPalindromeNumber(int num)
{
    int result = 0;
    int originalNumber = num;

    while (num != 0)
    {
        int rem = num % 10;
        result = result * 10 + rem;
        num = num / 10;
    }

    if (result == originalNumber)
    {
        printf("Number is a palindrome number");
    }
    else
    {
        printf("Number is not a palindrome number");
    }
}

int main()
{
    printf("Experiment 20 [Sanchit Tewari 525110030]\n");
    printf("Enter the number\n");
    int num;
    scanf("%d", &num);
    isPalindromeNumber(num);
}
