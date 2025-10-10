#include <stdio.h>
#include <string.h>

int main()
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("Length => %zu\n", strlen(alphabet)); // For getting the length. Same as sizeof except doesn't include the null character

    char str1[20] = "Hello ";
    char str2[] = "World!";

    strcat(str1, str2); // Apoends content of str2 to str1, however there must be enough space in str1 to accomodate str2
    printf("%s\n", str1);

    char str3[] = "Bye";
    // Copy str1 to str2
    strcpy(str1, str3); // Copy contents of str1 to str2
    printf("%s\n", str1);

    printf("%s\n",str1);
    printf("%s\n",str2);
    // Compare str1 and str2, and print the result
    printf("%d\n", strcmp(str2, str1));  // Returns 0 (the strings are equal) [Basically returns the difference in lexicographical order]

    return 0;
}