#include <stdio.h>
#include <stdlib.h>

struct node *front = NULL;
struct node *rear = NULL;

struct node
{
    int data;
    struct node *next;
};

void Enqueue(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("\nQueue Overflow");
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        if (front == NULL) // if queue is empty
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        printf("\nEnqueud : %d", data);
    }
}

void Dequeue()
{
    if (front == NULL)
        printf("\nQueue Underflow");
    else
    {
        struct node *ptr = front;
        front = front->next;
        printf("\nDequeud : %d", ptr->data);
        free(ptr);
    }
}

void display()
{
    struct node *ptr = front;
    printf(("\n- - - - - Displaying - - - -\n"));
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf(("\n- - - - - - - - - - - - -\n"));
}

int main()
{
    Enqueue(0);
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    display();

    Dequeue();
    // display();
    Dequeue();
    // display();
    Dequeue();
    display();

    return 0;
}