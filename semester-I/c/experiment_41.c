#include <stdio.h>
#include <math.h>

typedef struct
{
    float real;
    float imaginary;
} Complex;

int main()
{
    Complex num1;
    Complex num2;

    printf("Enter real part for first number: ");
    scanf("%f", &num1.real);

    printf("Enter imaginary part for first number: ");
    scanf("%f", &num1.imaginary);

    printf("Enter real part for second number: ");
    scanf("%f", &num2.real);

    printf("Enter imaginary part for second number: ");
    scanf("%f", &num2.imaginary);

    printf("Complex number 1 => %g + %gi\n", num1.real, num1.imaginary);
    printf("Complex number 2 => %g + %gi\n", num1.real, num1.imaginary);


    printf("The required operations's result are as follows:\n");

    float sumReal = num1.real + num2.real;
    float sumImaginary = num1.imaginary + num2.imaginary;

    float differenceReal = num1.real - num2.real;
    float differenceImaginary = num1.imaginary - num2.imaginary;

    printf("ADDITION\n");
    printf("(%g + %gi) +  (%g + %gi) = (%g + %gi)\n", num1.real, num1.imaginary, num2.real, num2.imaginary, sumReal, sumImaginary);
    printf("SUBTRACTION\n");
    printf("(%g + %gi) + (%g + %gi) = (%g + %gi)\n", num1.real, num1.imaginary, num2.real, num2.imaginary, differenceReal, differenceImaginary);

    return 0;
}