#include <stdio.h>
#include <stdlib.h>

struct CQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct CQueue *q)
{
    if ((q->rear + 1) % q->size == q->front)
        return 1;
    else
        return 0;
}

int isEmpty(struct CQueue *q)
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

void Enqueue(struct CQueue *q, int value)
{
    if (isFull(q))
        printf("\nQueue Overflow");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
        printf("\nInserted");
    }
}

void Dequeue(struct CQueue *q)
{
    if (isEmpty(q))
        printf("\nQueue Underflow");
    else
    {
        q->front = (q->front + 1) % q->size;
    }
}

void display(struct CQueue *q)
{
    printf("\n- - - - - Displaying - - - - - \n");
    int i = q->front + 1;
    while (i <= q->rear)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n- - - - - - - - - - - - - - \n");
}
int main()
{
    struct CQueue *q = (struct CQueue *)malloc(sizeof(struct CQueue));
    q->size = 10;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    Enqueue(q, 0);
    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    Enqueue(q, 4);
    Enqueue(q, 5);
    display(q);
    Dequeue(q);
    display(q);
    Dequeue(q);
    display(q);
    Dequeue(q);
    display(q);

    return 0;
}