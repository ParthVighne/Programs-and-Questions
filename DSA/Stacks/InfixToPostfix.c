#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
        printf("\nStack overflow.");
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
        printf("\nStack Underflow.");
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-') // if one of these operators ,then return true (1)
        return 1;
    else
        return 0;
}

char *InfixToPostfix(char *infix)
{
    // initializing stack to store operators
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    // initializing a postfix string to store final postfix expression
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition

    while (infix[i] != '\0') // run till infix expression ends
    {
        if (!isOperator(infix[i])) // if element is not an operator , copy it to postfix
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else // if element is an operator
        {
            if (precedence(infix[i]) > precedence(stackTop(s))) // if precedence of operator in infix is greater than the one at the top of the stack , push it to the stack
            {
                push(s, infix[i]);
                i++;
            }
            else // else pop the stack and transfer the element to postfix
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }

    // to copy rest of elements to postfix
    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0'; // ending postfix string
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("\nPostfix is : %s", InfixToPostfix(infix));
    return 0;
}