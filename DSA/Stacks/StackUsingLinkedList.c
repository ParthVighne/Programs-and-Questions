#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

void display(struct stack *top)
{
    printf("\n - - - - - Displaying - - - - - -\n");
    while (top != NULL)
    {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n - - - - - - - - - - - - - - - - -");
}

int isFull(struct stack *top)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    if (s == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct stack *push(struct stack *top, int data)
{
    struct stack *newELement = (struct stack *)malloc(sizeof(struct stack));
    if (isFull(top))
    {
        printf("\nStack Overflow.");
    }
    else
    {
        newELement->data = data;
        newELement->next = top;
        top = newELement;
        printf("\nPushed value %d successfully.", data);
        return top;
    }
}

struct stack *pop(struct stack *top)
{
    if (isEmpty(top))
    {
        printf("\nStack Underflow");
    }
    else
    {
        struct stack *temp = top;
        top = top->next;
        printf("\nPopped value %d successfully.", temp->data);
        free(temp);
        return top;
    }
}

void stackTop(struct stack *top)
{
    printf("\nStack Top : %d", top->data);
}

void stackBottom(struct stack *top)
{
    struct stack *temp = top;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("\nStack bottom : %d", temp->data);
}

void peek(struct stack *top, int position)
{
    struct stack *ptr = top;
    int i = 0;
    while (i < position - 1 && ptr != NULL)
    {
        i++;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\nPeek : Position not Valid.");
    }
    else
    {
        printf("\nPeek at postion %d : %d", position, ptr->data);
    }
}

int main()
{
    struct stack *top = NULL;
    top = push(top, 0);
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    top = push(top, 6);
    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 9);
    top = push(top, 10);

    display(top);

    // top = pop(top);

    // display(top);

    stackBottom(top);
    stackTop(top);
    peek(top, 5);
    return 0;
}