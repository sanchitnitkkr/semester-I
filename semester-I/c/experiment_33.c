#include <stdio.h>
#include <string.h>

int main()
{
    char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char charToCount = 'A';
    int counter = 0;

    for (int i = 0; i < strlen(alphabets); i++)
    {
        if (alphabets[i] == charToCount)
        {
            counter += 1;
        }
    }

    printf("\n%c is present %d times", charToCount, counter);

    return 0;
}