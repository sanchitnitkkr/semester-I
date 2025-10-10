#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    // Number to string
    int number = 23;
    char a[50];
    int length = 0;

    while (number != 0)
    {
        int remainder = number % 10 + '0';
        a[length++] = remainder;
        number = number / 10;
    }

    int fp = 0;
    int sp = length - 1;

    while (fp <= sp)
    {
        int temp = a[fp];
        a[fp] = a[sp];
        a[sp] = temp;
        fp++;
        sp--;
    }

    a[length] = '\0';

    printf("%s\n", a);

    // String to number
    char numStr[] = "45";
    int strLen = strlen(numStr);
    int newNumber = 0;

    for (int i = 0; i < strlen(numStr); i++)
    {
        newNumber += (numStr[i] - '0') * (pow(10, length - 1 - i));
    }

    printf("New number => %d\n", newNumber);

    return 0;
}