#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr) // to check wether stack is empty
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

int isFull(struct stack *ptr) // to check wether stack is full
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

void push(struct stack *ptr, char value) // push element in stack
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

void pop(struct stack *ptr) // pop element from stack
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

int checkParanthesis(char *exp) // parenthesis check
{
    // creating an array to store paranthesis
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++) // loop till end of array
    {
        if (exp[i] == '(') // if open paranthesis -> push
        {
            push(s, '(');
        }
        else if (exp[i] == ')') // if close paranthesis -> pop
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

    if (isEmpty(s)) // if final stack is empty -> correct paranthesis
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
    char *exp = "(())(()()";
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
