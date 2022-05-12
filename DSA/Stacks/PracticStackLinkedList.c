#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isFull(struct Node *top)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    };
}

struct Node *push(struct Node *top, int data)
{
    if (isFull(top))
    {
        printf("\nStack overflow. Unable to push item.");
        printf("\nStack overflow. Unable to push item.");
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        printf("\nPushed %d : ", newNode->data);

        return top;
    }
}

void display(struct Node *top)
{
    printf("\n - - - - - - Displaying - - - - - - \n");
    while (top != NULL)
    {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n - - - - - - - - - - - - - - - - - - \n");
}

struct Node *pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("\nStack Underflow.Mothing to delete.");
    }
    else
    {
        struct Node *ptr = top;
        top = top->next;
        printf("\nPopped %d : ", ptr->data);
        free(ptr);
        return top;
    }
}

void stackTop(struct Node *top)
{
    printf("\nStack Top : %d", top->data);
}

void stackBottom(struct Node *top)
{
    struct Node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    printf("\nStack Bottom : %d", ptr->data);
}

void seek(struct Node *top, int position)
{
    struct Node *ptr = top;
    int i = 0;
    while (i < position - 1 && ptr != NULL)
    {
        i++;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\nPosition invalid.");
    }
    else
    {
        printf("\nSeek @ position %d : %d", position, ptr->data);
    }
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 0);
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    display(top);
    top = push(top, 5);
    display(top);
    top = pop(top);
    display(top);
    stackBottom(top);
    stackTop(top);
    seek(top, 3);

    return 0;
}