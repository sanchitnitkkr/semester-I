#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack
char stack[MAX];
int top = -1;

// Stack functions
void push(char c)
{
    if (top == MAX - 1)
        return;
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

char peek()
{
    if (top == -1)
        return -1;
    return stack[top];
}

// Operator precedence
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0')
    {
        // Operand
        if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        // Left parenthesis
        else if (ch == '(')
        {
            push(ch);
        }
        // Right parenthesis
        else if (ch == ')')
        {
            while (peek() != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        // Operator
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// Main
int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
