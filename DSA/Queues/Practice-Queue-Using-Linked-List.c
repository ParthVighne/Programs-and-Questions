#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *rear = NULL;
struct node *front = NULL;

int isFull(struct node *);
int isEmpty();
void Enqueue(int value);
void Dequeue();
void display();
void queueFront();
void queueRear();
// void seek();

int main()
{
    Enqueue(0);
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    display();
    Dequeue();
    display();
    Dequeue();
    display();
    Dequeue();
    display();
}

int isFull(struct node *n)
{
    if (n == NULL)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void Enqueue(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (isFull(newNode))
        printf("\nQueue Overflow");
    else
    {
        newNode->data = value;
        newNode->next = NULL;
        if (front == NULL)
            front = rear = newNode;
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        printf("\nEnqueue : %d", value);
    }
}

void Dequeue()
{
    if (isEmpty())
        printf("\nQueue Underflow");
    else
    {
        struct node *ptr = front;
        front = front->next;
        printf("\nDequeue : %d", ptr->data);
        free(ptr);
    }
}

void queueFront()
{
    printf("\nQueue Front : %d", front->data);
}
void queueRear()
{
    printf("\nQueue Rear : %d", rear->data);
}

void display()
{
    printf("\n - - - - Displaying - - - - \n");
    struct node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n - - - - - - - - - - - \n");
}