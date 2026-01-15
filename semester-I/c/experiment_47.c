#include <stdio.h>


int factorial(int n){
    if(n == 1){
        return 1;
    }

    return n * factorial(n-1);
    
}

int main()
{
    int number = 5;
    int factorialOfTheNumber = factorial(number);
    printf("%d", factorialOfTheNumber);
    return 0;
}