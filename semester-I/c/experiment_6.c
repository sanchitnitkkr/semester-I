#include <stdio.h>

int main()
{
    printf("Experiment 6 [Sanchit Tewari 525110030]\n");
    // Implicit conversions
    char someChar = 5;
    int someInt = someChar; // Converted to int internally

    int x = 5;
    float y = x; // implicit conversion from int to float

    int a = 10;
    float b = 2.5;
    float result = a + b; // a converted to float before addition

    // Explicit conversions
    char someOtherChar = 5;
    int someOtherInt = (int)someOtherChar;

    int someX = 5;
    float someY = (float)someX; // Explicitly converted someX

    int alpha = 10;
    float beta = 2.5;
    float gamma = ((float)alpha) + beta; // Explicitly converted alpha
}