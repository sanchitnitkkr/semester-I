#include <stdio.h>
#include <math.h>

typedef struct
{
    float real;
    float imaginary;
} Complex;

Complex addComplex(Complex num1, Complex num2)
{
    Complex result;
    float sumReal = num1.real + num2.real;
    float sumImaginary = num1.imaginary + num2.imaginary;
    result.real = sumReal;
    result.imaginary = sumImaginary;
    return result;
}

Complex subComplex(Complex num1, Complex num2)
{
    Complex result;
    float subReal = num1.real - num2.real;
    float subImaginary = num1.imaginary - num2.imaginary;
    result.real = subReal;
    result.imaginary = subImaginary;
    return result;
}

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

    Complex complexSum = addComplex(num1, num2);
    Complex complexDiff = subComplex(num1, num2);

    printf("ADDITION\n");
    printf("(%g + %gi) +  (%g + %gi) = (%g + %gi)\n", num1.real, num1.imaginary, num2.real, num2.imaginary, complexSum.real, complexSum.imaginary);
    printf("SUBTRACTION\n");
    printf("(%g + %gi) + (%g + %gi) = (%g + %gi)\n", num1.real, num1.imaginary, num2.real, num2.imaginary, complexDiff.real, complexDiff.imaginary);

    return 0;
}