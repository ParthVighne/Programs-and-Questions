#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct queue *q)
{
    if (q->front == -1 || (q->front > q->rear))
        return 1;
    else
        return 0;
}

void Enqueue(struct queue *q, int value)
{
    if (isFull(q))
        printf("\nQueue Overflow");
    else if (q->front == -1)
    {
        q->front = 0;
        q->rear++;
        q->arr[q->rear] = value;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
}

void Dequeue(struct queue *q)
{
    if (isEmpty(q))
        printf("\nQueue Overflow");
    else
    {
        // int val = q->arr[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        // return val;
    }
}

void queueFront(struct queue *q)
{
    if (isEmpty(q))
        printf("\nQueue Empty");
    else
        printf("\nQueue Front : %d\n", q->arr[q->front]);
}

void queueRear(struct queue *q)
{
    if (isEmpty(q))
        printf("\nQueue Empty");
    else
        printf("\nQueue Rear : %d\n", q->arr[q->rear]);
}

void seek(struct queue *q, int position)
{
    if (position > q->rear && position < q->front)
        printf("\nInvalid Position");
    else
        printf("\nSeek : %d\n", q->arr[position]);
}

void display(struct queue *q)
{
    printf("\n - - - - - Displaying - - - - - \n");
    if (isEmpty(q))
        printf("Empty ");
    else
    {
        int i = q->front;
        while (i <= q->rear)
        {
            printf("%d ", q->arr[i]);
            i++;
        }
    }
    printf("\n - - - - - - - - - - - - - - \n");
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    Enqueue(q, 0);
    display(q);
    Enqueue(q, 1);
    display(q);
    Enqueue(q, 2);
    display(q);
    Enqueue(q, 3);
    display(q);
    Enqueue(q, 4);
    display(q);
    Dequeue(q);
    display(q);
    Dequeue(q);
    display(q);
    Dequeue(q);
    display(q);
    Dequeue(q);
    display(q);
    Dequeue(q);
    display(q);
    queueFront(q);
    queueRear(q);

    return 0;
}