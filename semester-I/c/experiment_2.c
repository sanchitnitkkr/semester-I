/**
 * Write a program for character input and output (use getchar() and putchar())
 */
#include <stdio.h>

int main()
{
    printf("Expirement 2 [Sanchit Tewari 525110030]\n");
    printf("Enter the suitable character for your age:\n");
    printf("A => Adult\n");
    printf("T => Teenager\n");
    printf("C => Child\n");

    char userInput = getchar();

    while (!(userInput == 'A' || userInput == 'T' || userInput == 'C'))
    {
        userInput = getchar();
        printf("Please enter a valid input!\n");
    }

    printf("Your selected choice is: ");
    putchar(userInput);

    return 0;
}
