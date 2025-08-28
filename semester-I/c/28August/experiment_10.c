#include <stdio.h>

int largest(int num1, int num2, int num3)
{
    if (num1 >= num2 && num1 >= num3)
    {
        printf("%d is the largest", num1);
    }
    else if (num2 >= num3 && num2 >= num1)
    {
        printf("%d is the largest", num2);
    }
    else
    {
        printf("%d is the largest", num3);
    }
}

int main()
{
    printf("Enter the 3 numbers space separated\n");
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    largest(a,b,c);
    return 0;
}