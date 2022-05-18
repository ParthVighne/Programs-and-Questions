#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->front == -1 || q->front > q->rear)
        return 1;
    else
        return 0;
}

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
        return 1;
    else
        return 0;
}

void Enqueue(struct queue *q, int value)
{
    if (isFull(q))
        printf("\nQueue Overflow");
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
}

void Dequeue(struct queue *q)
{
    if (isEmpty(q))
        printf("\nQueue Underflow");
    else
    {
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
            q->front++;
    }
}

void display(struct queue *q)
{
    printf("\n- - - - - - Displaying - - - - - - -\n");
    if (isEmpty(q))
    {
        printf("Queue Empty");
    }
    else
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
    }
    printf("\n- - - - - - - - - - - - - - - - - - - ");
}

void front(struct queue *q)
{
    printf("\nFront : %d", q->arr[q->front]);
}

void rear(struct queue *q)
{
    printf("\nRear : %d", q->arr[q->rear]);
}

void seek(struct queue *q, int position)
{
    if (position > q->rear)
        printf("\nSeek : Invalid position");
    else
    {
        int i = q->front;
        while (i <= position)
            i++;

        printf("\nSeek at %d : %d", position, q->arr[position]);
    }
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->front = 0;
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
    Enqueue(q, 5);
    display(q);

    Dequeue(q);
    display(q);
    front(q);
    rear(q);
    seek(q, 6);
    // Dequeue(q);
    // display(q);
    // Dequeue(q);
    // display(q);
    // Dequeue(q);
    // display(q);

    return 0;
}