#include <stdio.h>

int main()
{
    printf("Experiment 29 [Sanchit Tewari 525110030]\n");
    int arr[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("First Row: %d,Second Column: %d, Element => %d\n", 0, 1, arr[0][1]);
    printf("Third Row: %d,First Column: %d, Element => %d\n", 2, 0, arr[2][0]);
    printf("Second Row: %d,Second Column: %d, Element => %d\n", 1, 1, arr[1][1]);
    return 0;
}