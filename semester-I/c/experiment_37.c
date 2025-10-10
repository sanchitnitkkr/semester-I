#include <stdio.h>
#include <string.h>

int main()
{
    char alphabets[] = "ABCDAHHHAACXZ";
    char charToBeRemoved = 'A';
    int fp = 0;

    int i = 0;
    for (i = 0; i < strlen(alphabets); i++)
    {
        if (alphabets[i] != charToBeRemoved)
        {
            alphabets[fp] = alphabets[i];
            fp++;
        }
    }

    alphabets[fp] = '\0';

    printf("String after removing occurences => %s\n", alphabets);

    return 0;
}