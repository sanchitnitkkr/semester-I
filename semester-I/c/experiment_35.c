#include <stdio.h>

void reverseString(char sentence[], int size)
{
    int startPtr = 0;
    int endPtr = size - 1;

    while (startPtr <= endPtr)
    {
        char temp = sentence[startPtr];
        sentence[startPtr] = sentence[endPtr];
        sentence[endPtr] = temp;
        
        startPtr++;
        endPtr--;
    }
}

int main()
{
    char sentence[] = "";
    printf("Enter the string please: ");
    scanf("%199[^\n]", sentence); //   fgets(sentence, sizeof(sentence), stdin);  // read with spaces => This could had been used which is more recommended since it handles buffer overflow and whitespaces both.
    reverseString(sentence, strlen(sentence));

    printf("Reversed String is => %s", sentence);
}