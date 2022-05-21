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
    if ((q->front == 0 && q->rear == q->size - 1) || (q->front > q->rear))
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
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
    }
}

void Dequeue(struct circularQueue *q)
{
    if (isEmpty(q))
        printf("\nQueue Underflow");
    else
    {
        if (q->front > q->rear)
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
    printf("\n- - - - Displaying - - - - \n");
    int i = q->front;
    while (i <= q->rear)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n- - - - - - - - - - - \n");
}

void queueFront(struct circularQueue *q)
{
    printf("\nFront : %d", q->arr[q->front]);
}

void queueRear(struct circularQueue *q)
{
    printf("\nRear : %d", q->arr[q->rear]);
}

void seek(struct circularQueue *q, int position)
{
    if (position < q->front || position > q->rear)
        printf("\nSeek : %d", q->arr[position]);
    else
        printf("\nInvalide position");
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
    Enqueue(q, 5);
    display(q);
    Dequeue(q);
    display(q);
    return 0;
}
