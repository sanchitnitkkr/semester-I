#include <stdio.h>

void evenOrOdd(int start, int end)
{
    if (start > end)
        return;
    if (start % 2 == 0)
        printf("%d is even\n", start);
    else
        printf("%d is odd\n", start);
    evenOrOdd(start + 1, end);
}
int main()
{
    int start, end;
    start = 0;
    end = 10;
    printf("\nEven-Odd check from %d to %d:\n", start, end);
    evenOrOdd(start, end);
    return 0;
}