#include <stdio.h>
#include <string.h>

int main()
{
    printf("Experiment 36 [Sanchit Tewari 525110030]\n");
    char src[] = "Hello";
    char str2[50];

    int i = 0;
    for (i = 0; i < strlen(src); i++)
    {
        str2[i] = src[i];
    }
    str2[i] = '\0';

    printf("Source: %s\n", src);
    printf("Destination: %s\n", str2);
    return 0;
}