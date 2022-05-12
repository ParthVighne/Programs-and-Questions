#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
        printf("\nStack OverFlow.");
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\nStack Underflow");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    else
        return 0;
}

int checkParanthesis(char *exp)
{
    struct stack *s;
    s->size = 50;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char popped_char;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(s, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(s))
                return 0;
            else
            {
                popped_char = pop(s);
                if (!match(popped_char, exp[i]))
                    return 0;
            }
        }
    }

    if (isEmpty(s))
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "({[({{)]})";
    if (checkParanthesis(exp))
        printf("\nParenthesis match");
    else
        printf("\nParenthesis do not match");

    return 0;
}