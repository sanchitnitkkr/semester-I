
/**
 * Write a program to read from keyboard and display on console (use printf() and scanf())
 * 1) string
 * 2) integer
 * 3) character
 * 4) real value
 * 5) double
 * 6) unsigned value of the integer
 * 7) octal value of an integer
 */

#include <stdio.h>

int main()
{
    printf("Experiment 3 [Sanchit Tewari 525110030]\n");
    char name[] = "";
    int age;
    char gender;
    float height;
    double percentile;
    unsigned YOE;
    int octalAge;

    printf("What is your name?\n");
    scanf("%s", name);

    printf("How old are you?\n");
    scanf("%d", &age);

    printf("Your gender (M/F)\n");
    scanf(" %c", &gender); // Tell scanf to skip whitespace before reading a character by adding a space before %c

    printf("Your height? (in cm)\n");
    scanf("%f", &height);

    printf("Your examination percentile?\n");
    scanf("%lf", &percentile);

    printf("How many years of experience do you have?\n");
    scanf("%u", &YOE);

    printf("What is your age in octal?\n");
    scanf("%o", &octalAge);

    printf("Hello %s, you are a %d year old, your gender is %c", name, age, gender);
    printf("\nYou are %f cms tall and your exam percentile was %lf with %u years of experience", height, percentile, YOE);
    printf("\nLast but not the least your age in octal is %o", octalAge);

    return 0;
}