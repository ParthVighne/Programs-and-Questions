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
        printf("\nStack Overflow");
    }
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

int match(char a, char b) // function for matching closing brackets
{
    if (a == '(' && b == ')')
        return 1;
    else if (a == '{' && b == '}')
        return 1;
    else if (a == '[' && b == ']')
        return 1;
    else
        return 0;
}

int checkParanthesis(char *exp)
{
    // initializing new stack
    struct stack *s;
    s->size = 50;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char popped_char; // char variable for comparing popped bracket to the one in the expression at index i

    for (int i = 0; exp[i] != '\0'; i++) // run loop till end of array
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') // if opening bracket, push to stack
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') // if closing bracket, go to the if-else inside
        {
            if (isEmpty(s)) // if only closing bracket is given and it creates a condition for stack underflow.
            {
                return 0;
            }
            else
            {
                popped_char = pop(s);            // saving popped char
                if (!match(popped_char, exp[i])) // comparing to see if both match , if not then return 0
                {
                    return 0;
                }
            }
        }
    }

    // final test -> if stack is empty then brackets match
    if (isEmpty(s))
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    char *exp = "{}";
    if (checkParanthesis(exp))
    {
        printf("\nParanthesis is matching.");
    }
    else
    {
        printf("\nParanthesis is not  matching.");
    }
    return 0;
}