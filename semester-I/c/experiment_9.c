#include <stdio.h>
#include <stdbool.h>

void isEven(int num)
{
    if (num % 2 == 0)
    {
        printf("The number is even.");
    }
    else
    {
        printf("The number is odd");
    }
}

int main()
{
    printf("Experiment 9 [Sanchit Tewari 525110030]\n");
    printf("Enter the number\n");
    int num;
    scanf("%d", &num);
    isEven(num);
}
