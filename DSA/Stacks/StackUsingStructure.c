#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s);
int isFull(struct stack *s);
void traverse(struct stack *s);
void push(struct stack *s, int value);
int pop(struct stack *s);
void seek(struct stack *s, int pos);
void stackTop(struct stack *s);
void stackBottom(struct stack *s);

int main()
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->size = 10;
    s1->top = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));
    // traverse(s1);
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
    traverse(s1);
    // pop(s1);
    // pop(s1);
    // pop(s1);
    // traverse(s1);
    // seek(s1, 3);
    stackBottom(s1);

    return 0;
}

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void traverse(struct stack *s)
{
    printf("\n - - - - - - Dispalying - - - - - -\n");
    if (isEmpty(s))
    {
        printf("Stack Empty");
    }
    else
    {
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d ", s->arr[i]);
        }
    }
}

void push(struct stack *s, int value)
{
    if (isFull(s))
    {
        printf("\nStack Overflow ");
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack Underflow");
        return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

void seek(struct stack *s, int pos)
{
    if ((s->top - pos + 1) < 0)
    {
        printf("\nPosition does not exist.");
    }
    else
    {
        printf("\nElement at position %d is %d", pos, s->arr[s->top - pos + 1]);
    }
}

void stackTop(struct stack *s)
{
    printf("\nElement on top of stack is %d", s->arr[s->top]);
}

void stackBottom(struct stack *s)
{
    printf("\nElement at the bottom of stack is %d", s->arr[0]);
}