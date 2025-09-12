#include <stdio.h>

int swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("After Swap in swap(): num1 = %d, num2 = %d\n    ", *x,*y);
}

int main()
{
    printf("Experiment 23 [Sanchit Tewari 525110030]\n");
    printf("Enter number 1\n");
    int num1, num2;
    scanf("%d", &num1);
    printf("Enter number 2\n");
    scanf("%d", &num2);

    printf("Before Swap in main(): num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After Swap in main(): num1 = %d, num2 = %d\n", num1, num2);
}