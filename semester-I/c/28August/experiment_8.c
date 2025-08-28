#include <stdio.h>

// Write a program to convert Fahrenheit to Celcius
float convertToCelcius(float fahrenheit)
{
    float cel = (fahrenheit - 32) / 1.8;
    return cel;
}

int main()
{
    float far;
    printf("Enter the fahrenheit number\n");
    scanf("%f", &far);
    float cel = convertToCelcius(far);
    printf("Temperature in celcius is: %f", cel);
    return 0;
}
