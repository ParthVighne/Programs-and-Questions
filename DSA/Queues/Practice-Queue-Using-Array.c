#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q);
int isEmpty(struct queue *q);
void Enqueue(struct queue *q, int value);
void Dequeue(struct queue *q);
void queueFront(struct queue *q);
void queueRear(struct queue *q);
void seek(struct queue *q, int position);
void display(struct queue *q);

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
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
    // Dequeue(q);
    // display(q);
    // Dequeue(q);
    // display(q);

    queueRear(q);
    queueFront(q);
    seek(q, 6);

    return 0;
}

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct queue *q)
{
    if ((q->front == -1) || (q->front > q->rear))
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
        if (q->front == -1)
            q->front = 0;

        q->rear++;
        q->arr[q->rear] = value;
        printf("\nEnqueue : %d", value);
    }
}

void Dequeue(struct queue *q)
{
    if (isEmpty(q))
        printf("\nQueue Underflow");
    else
    {
        printf("\nDequeue : %d", q->arr[q->front]);
        q->front = (q->front + 1) % q->size;
    }
}

void display(struct queue *q)
{
    printf("\n- - - - Displaying - - - - - \n");
    int i = q->front;
    while (i <= q->rear)
    {
        printf("%d ", q->arr[i]);
        i++;
    }
    printf("\n- - - - - - - - - - - - - \n");
}

void queueRear(struct queue *q)
{
    printf("\nQueue Rear : %d", q->arr[q->rear]);
}

void queueFront(struct queue *q)
{
    printf("\nQueue Front : %d", q->arr[q->front]);
}

void seek(struct queue *q, int position)
{
    if (position < q->front || position > q->rear)
        printf("\nInvalid Position");
    else
        printf("\nSeek : %d", q->arr[position - 1]);
}
