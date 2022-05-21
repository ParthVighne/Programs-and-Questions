#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct circularQueue *q)
{
    if ((q->front == q->rear + 1) || (q->front = 0 && q->rear == q->size - 1))
        return 1;
    else
        return 0;
}

int isEmpty(struct circularQueue *q)
{
    if (q->front == -1)
        return 1;
    else
        return 0;
}

void Enqueue(struct circularQueue *q, int value)
{
    if (isFull(q))
        printf("\nQueue Overflow");
    else
    {
        if (q->front == -1 && q->rear == -1)
        {
            q->front = 0;
            q->rear = (q->rear + 1) % q->size;
            q->arr[q->rear] = value;
        }
        else
        {
            q->rear = (q->rear + 1) % q->size;
            q->arr[q->rear] = value;
        }
    }
}

void Dequeue(struct circularQueue *q)
{
    if (isEmpty(q))
        printf("\nQueue Overflow");
    else
    {
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
            q->front = (q->front + 1) % q->size;
    }
}

void display(struct circularQueue *q)
{
    printf("\n- - - - Dispalying - - - - \n");
    int i = q->front;
    while (i <= q->rear)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n- - - - - - - - - - - - \n");
}

int main()
{
    struct circularQueue *q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    q->size = 10;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    Enqueue(q, 0);
    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    Enqueue(q, 4);
    display(q);
    Dequeue(q);
    Dequeue(q);
    display(q);
    return 0;
}