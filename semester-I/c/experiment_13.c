#include <stdio.h>

int getPositiveIntInput()
{
    int input;
    do
    {
        printf("Please enter a positive integer\n");
        scanf("%d", &input);
    } while (input <= 0);

    printf("Thankyou for your input!");
}

int main()
{
    printf("Experiment 13 [Sanchit Tewari 525110030]\n");
    getPositiveIntInput();
    return 0;
}