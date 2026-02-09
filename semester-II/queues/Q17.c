#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char **tokens, int tokensSize) {
    int *stack = (int *)malloc(tokensSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char *t = tokens[i];

        if (strlen(t) == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/')) {
            int op1 = stack[top--];
            int op2 = stack[top--];
            int result;

            if (t[0] == '+') result = op2 + op1;
            else if (t[0] == '-') result = op2 - op1;
            else if (t[0] == '*') result = op2 * op1;
            else result = op2 / op1;

            stack[++top] = result;
        } else {
            stack[++top] = atoi(t);
        }
    }

    int finalResult = stack[top];
    free(stack);
    return finalResult;
}

int main() {
    char *test1[] = {"4", "13", "5", "/", "+"};
    printf("Result 1: %d\n", evalRPN(test1, 5));

    char *test2[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    printf("Result 2: %d\n", evalRPN(test2, 13));

    return 0;
}