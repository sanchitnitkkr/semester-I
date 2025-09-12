#include <stdio.h>

int main()
{
    printf("Experiment 25 [Sanchit Tewari 525110030]\n");

    int a[5] = {1, 2, 3, 4, 5};

    int *p[5] = {&a[0], &a[1], &a[2], &a[3], &a[4]};

    int **pp = p;

    (pp)++;

    printf("%d\n", pp - p); // 1
    printf("%d\n", *pp - a); // *pp is p (=&a[1]), a is &a[0]. Difference = 1 element.
    printf("%d\n", **pp);    // *pp is p (=&a[1]), so **pp = *p = a[1] = 2.
    printf("%d\n", ++*pp);   // *pp is p. ++*pp increments p, so p now points to a[2].
    printf("%d\n", ++**pp);    // *pp is p (=&a[2]). **pp = a[2] = 3. ++**pp = 4.

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
}