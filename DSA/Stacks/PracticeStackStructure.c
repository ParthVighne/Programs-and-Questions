#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *array;
};

void display(struct stack *ptr)
{
    printf("\n - - - - - - Displaying - - - - - - \n");
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("%d ", ptr->array[i]);
    }
    printf("\n - - - - - - - - - - - - - - - - -");
}

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

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("\nStack Overflow.");
    }
    else
    {
        ptr->top++;
        ptr->array[ptr->top] = value;
        printf("\nPushed : %d", value);
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
        int val = ptr->array[ptr->top];
        ptr->top--;
        printf("\nPopped : %d", val);
    }
}

void stackTop(struct stack *ptr)
{
    printf("\nStack Top : %d", ptr->array[ptr->top]);
}

void stackBottom(struct stack *ptr)
{
    printf("\nStack Bottom : %d", ptr->array[0]);
}

void seek(struct stack *ptr, int position)
{
    int index = ptr->top - position + 1;
    if (index < 0)
    {
        printf("\nPosition invalid.");
    }
    else
    {
        printf("\nPeek @ position %d : %d ", position, ptr->array[index]);
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->array = (int *)malloc(s->size * sizeof(int));
    push(s, 0);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    display(s);
    pop(s);
    display(s);
    stackBottom(s);
    stackTop(s);
    seek(s, 4);

    return 0;
}