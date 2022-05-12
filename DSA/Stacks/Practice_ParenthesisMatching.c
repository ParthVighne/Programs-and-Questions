#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("\nStack Overflow.");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\nStack Underflow.");
    }
    else
    {
        ptr->top--;
    }
}

int checkParanthesis(char *exp)
{
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(s)) // to prevent stack underflow
            {
                return 0;
            }
            else
            {
                pop(s);
            }
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "(())(())())()";
    if (checkParanthesis(exp))
    {
        printf("\nParanthesis correct");
    }
    else
    {
        printf("\nParanthesis not correct");
    }
    return 0;
}
