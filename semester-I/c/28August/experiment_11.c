#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter the 2 numbers space separated (For ex 2 3)\n");
    scanf("%d %d", &a, &b);

    printf("_____________________________\n");

    int operation;
    printf("Select the operation\n");
    printf("1 for addition\n");
    printf("2 for subtraction\n");
    printf("3 for multiplication\n");
    printf("4 for division\n");
    scanf("%d", &operation);

    printf("_____________________________\n");

    switch (operation)
    {
    case 1:
        printf("The sum is %d", a + b);
        break;
    case 2:
        printf("The difference is %d", a - b);
        break;
    case 3:
        printf("The multiplication is %d", a * b);
        break;
    case 4:
        printf("The division is %d", a / b);
        break;
    }

    return 0;
}