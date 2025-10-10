#include <stdio.h>
#include <string.h>

int main(){
    char string[] = "";
    printf("Enter the string => ");
    scanf("%199[^\n]", string);

    int fp = 0;
    int sp = strlen(string) - 1;

    while(fp<sp){
        if(string[fp] != string[sp]){
            printf("The string isn't palindrome\n");
            return 0;
        }
        fp++;
        sp--;
    }
    
    printf("The string is palindrome\n");

    return 0;
}