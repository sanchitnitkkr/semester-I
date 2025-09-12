#include <stdio.h>

int isArmstrong(int num){
    int result = 0;
    int original = num;

    while(num!=0){
        int rem = num % 10;
        num = num / 10;
        result += rem * rem * rem;
    }

    if(result == original){
        printf("Number is armstrong");
    }
    else{
        printf("Number is not armstrong");
    }

}

int main()
{
    printf("Experiment 18 [Sanchit Tewari 525110030]\n");
    printf("Enter the number\n");
    int num;
    scanf("%d", &num);
    isArmstrong(num);
}

