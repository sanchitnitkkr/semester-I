#include <stdio.h>

int main()
{
    printf("Experiment 7 [Sanchit Tewari 525110030]\n");
    int firstNumber = 10, secondNumber = 5;

    printf("Original firstNumber = %d\n", firstNumber);

    firstNumber += secondNumber; // firstNumber = firstNumber + secondNumber

    printf("firstNumber += secondNumber -> %d\n", firstNumber);

    firstNumber -= secondNumber; // firstNumber = firstNumber - secondNumber

    printf("firstNumber -= secondNumber -> %d\n", firstNumber);

    firstNumber *= secondNumber; // firstNumber = firstNumber * secondNumber

    printf("firstNumber *= secondNumber -> %d\n", firstNumber);

    firstNumber /= secondNumber; // firstNumber = firstNumber / secondNumber

    printf("firstNumber /= secondNumber -> %d\n", firstNumber);

    firstNumber %= secondNumber; // firstNumber = firstNumber % secondNumber

    printf("firstNumber %%= secondNumber -> %d\n", firstNumber);

    firstNumber &= secondNumber; // firstNumber = firstNumber & secondNumber (bitwise AND)

    printf("firstNumber &= secondNumber -> %d\n", firstNumber);

    firstNumber |= secondNumber; // firstNumber = firstNumber | secondNumber (bitwise OR)

    printf("firstNumber |= secondNumber -> %d\n", firstNumber);

    firstNumber ^= secondNumber; // firstNumber = firstNumber ^ secondNumber (bitwise XOR)

    printf("firstNumber ^= secondNumber -> %d\n", firstNumber);

    firstNumber <<= 1; // firstNumber = firstNumber << 1 (left shift)

    printf("firstNumber <<= 1 -> %d\n", firstNumber);

    firstNumber >>= 1; // firstNumber = firstNumber >> 1 (right shift)

    printf("firstNumber >>= 1 -> %d\n", firstNumber);

    return 0;
}