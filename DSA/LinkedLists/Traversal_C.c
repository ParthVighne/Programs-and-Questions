#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    // defining nodes
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    // allocating memory
    second = (struct Node *)malloc(sizeof(struct Node));
    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // giving value
    head->data = 0;
    first->data = 2;
    second->data = 3;
    third->data = 4;

    // linking pointers
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;

    traverseList(head);

    return 0;
}