// C code to convert infix into postfix

#include <stdio.h>
#include <ctype.h>
char stack[50];
int top = -1;
void push(char a)
{
    stack[++top] = a;
}

char pop()
{
    if (top == -1)
        return 1;
    else
        return stack[top--];
}

int precedence(char a)
{
    if (a == '(')
        return 0;
    if (a == '+' || a == '-')
        return 1;
    if (a == '*' || a == '/')
        return 2;
}

int main()
{
    char exp[20];
    char *p, a;
    printf("Enter the expression : ");
    scanf("%s", exp);
    p = exp;
    while (*p != '\0')
    {
        if (isalnum(*p))
            printf("%c", *p);
        else if (*p == '(')
            push(*p);
        else if (*p == ')')
        {
            while ((a = pop()) != '(')

                printf("%c", a);
        }
        else
        {
            while (precedence(stack[top]) >= precedence(*p))
                printf("%c", pop());
            push(*p);
        }
        p++;
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
    return 0;
}
