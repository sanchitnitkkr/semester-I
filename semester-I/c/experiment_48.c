// Q 48) Write a program to calculate the power of any number using recursion.
#include <stdio.h>

int pow(int base, int exponent){
    if(exponent == 1){
        return base;
    }

    return base * pow(base,exponent-1);
}

int main(){
    int powResult = pow(4,3);
    printf("%d\n",powResult);
    return 0;
}