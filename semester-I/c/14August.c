#include <stdio.h>

int main() {
    /*
    Write a program to understand format specifiers
    1) %c 
    2) %s
    3) %d
    4) %f
    5) %o
    6) %x 
    7) %6d
    8) %6f 
    9) %6.2f 
    10) %.2f 
    
    For reading different types of variables
    */    
    
    // For reading characters
    char firstNameInitial = 'S';
    char lastNameInitals= 'T';
    printf("My initials are %c%c\n", firstNameInitial, lastNameInitals);
    
    // For reading strings
    char name[] = "Sanchit";
    printf("My name is %s\n", name);
    
    // For reading integers
    int age = 23;
    printf("My age is %d\n", age);
    
    // For reading float 
    float heightInInches = 5.61;
    printf("I am %f inches tall\n", heightInInches);
    
    // For reading octal numbers
    int ageInOctal = 027;
    printf("My age in octal number system is %o\n", ageInOctal);
    
    // For reading hexadecimal
    int ageInHexaDec = 0x17;
    printf("my age in hexadecimal is %x\n", ageInHexaDec);
    
    // For reading integers with space padded to them
    printf("My age with padding of 4 spaces to the left padded:%6d\n", age);
    
    // For reading float numbers
    float temperature = 102.256;
    // 1) %6f : This prints an output where the minimum width is 6
    printf("The temperature currently is:%6f\n", temperature);
    
    // 2) %10.2f : This prints an output where the min width is 10 places and after decimal 2 numbers only i.e. precision is 2
    float someScientificNumber = 233.5346;
    printf("The scientific number is currently is: %10.2f\n", someScientificNumber);
    
    // 3) %.2f: This prints an output where there are only 2 numbers after the decimal place i.e. precision is 2
    printf("The scientific number is: %.2f\n",someScientificNumber);
    

    return 0;
}

/**
 * Output was:
My initials are ST
My name is Sanchit
My age is 23
I am 5.610000 inches tall
My age in octal number system is 27
my age in hexadecimal is 17
My age with padding of 4 spaces to the left padded     23
The temperature currently is 102.255997
The scientific number is currently is: 233.53
The scientific number is: 233.53
 */