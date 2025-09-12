#include <stdio.h>

int main()
{
    printf("Experiment 4 [Sanchit Tewari 525110030]\n");
    int age = 23;
    printf("My age is %d\n", age);
    printf("Sizeof of this age is %d\n", sizeof(age));

    printf("\n______________________________\n");

    float height = 167.5;
    printf("My height is %f cms\n", height);
    printf("Size of float is %d\n", sizeof(height));

    printf("\n______________________________\n");

    char gender = 'M';
    printf("My gender is %c\n", gender);
    printf("Size of char is %d\n", sizeof(gender));

    printf("\n______________________________\n");

    short someShortInt = 120;
    printf("Some short int value %d\n", someShortInt);
    printf("Size of short int is %d", sizeof(someShortInt));

    printf("\n______________________________\n");

    long longInt = 232312;
    printf("Long int value %d\n", longInt);
    printf("Size of long int is %d", sizeof(longInt));

    printf("\n______________________________\n");

    long long longlongInt = 123123123;
    printf("Long long int value %d\n", longlongInt);
    printf("Size of long long int is %d", sizeof(longlongInt));

    printf("\n______________________________\n");
    signed signedInt = -123;
    printf("Signed int value %d\n", signedInt);
    printf("Size of signed int is %d", sizeof(signedInt));

    printf("\n______________________________\n");
    unsigned unsignedInt = 999;
    printf("Unsigned int value %d\n", unsignedInt);
    printf("Size of unsignedInt int is %d", sizeof(unsignedInt));
}
